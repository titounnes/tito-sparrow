namespace Sparrow\Lib;

class Sparrow {

	protected table;
	protected where;
	protected joins;
	protected order;
	protected groups;
	protected having;
	protected distinct;
	protected limit;
	protected offset;
	protected sql;

	protected db;
	protected db_type;
	protected cache;
	protected cache_type;
	protected stats = [];
	protected query_time;
	protected _class;
	protected db_types;
	protected cache_types;

	public last_query;
	public num_rows;
	public insert_id;
	public affected_rows;
	public is_cached;
	public stats_enabled;
	public show_sql;
	public key_prefix;
	public err_message = [];

	public function __construct() {
		let this->db_types = [
			"pdo", "mysqli", "pgsql"
			];
		let this->cache_types = [
			"memcached", "memcache", "xcache"
		];
	}

	/*** Core Methods ***/

	/*
	 * Joins string tokens into a SQL statement.
	 *
	 * @param string $sql SQL statement
	 * @param string $input Input string to append
	 * @return string New SQL statement
	 */
	 public function build(sql, input)
	 {
			 return (strlen(input) > 0) ? (sql." ".input) : sql;
	 }

	/*
	 * Parses a connection string into an object.
	 *
	 * @param string $connection Connection string
	 * @return array Connection information
	 * @throws Exception For invalid connection string
	 */
	public function parseConnection(connection) {
		var url = [];
		let url = parse_url(connection);

		if (empty(url)) {
			throw new \Exception("Invalid connection string");
		}

		var cfg = [];
		let cfg["type"] = url["scheme"] ? url["scheme"] : url["path"];
		let cfg["hostname"] = url["host"] ? url["host"] : null;
		let cfg["database"] = url["path"] ? substr(url["path"], 1) : null;
		let cfg["username"] = url["user"] ? url["user"] : null;
		let cfg["password"] = url["pass"] ? url["pass"] : null;
		let cfg["port"] = url["port"] ? url["port"] : null;

		return cfg;
	}

	/**
	 * Gets the query statistics.
	 */
	public function getStats() {
			let this->stats["total_time"] = 0;
			let this->stats["num_queries"] = 0;
			let this->stats["num_rows"] = 0;
			let this->stats["num_changes"] = 0;


			if (isset(this->stats["queries"]) && is_array(this->stats["queries"])) {

				var query = [];

				for query in this->stats["queries"] {
					let this->stats["total_time"] += query["time"];
					let this->stats["num_queries"] += 1;
					let this->stats["num_rows"] += query["rows"];
					let this->stats["num_changes"] += query["changes"];
				}
			}

			let this->stats["avg_query_time"] =
					this->stats["total_time"] /
					(float)((this->stats["num_queries"] > 0) ? this->stats["num_queries"] : 1);

			return this->stats;
	}

	/**
	 * Checks whether the table property has been set.
	 */
	public function checkTable() {
			if (this->table == null) {
				throw new \Exception("Table is not defined.");
			}
	}

	/**
	 * Checks whether the class property has been set.
	 */

	 public function checkClass() {
			if (this->_class == null) {
					throw new \Exception("Class is not defined.");
			}
	}

	/**
	 * Resets class properties.
	 */
	public function reset() {
			let this->where = "";
			let this->joins = "";
			let this->order = "";
			let this->groups = "";
			let this->having = "";
			let this->distinct = "";
			let this->limit = "";
			let this->offset = "";
			let this->sql = "";
	}


    /*** SQL Builder Methods ***/

	    /*
	     * Parses a condition statement.
	     *
	     * @param string $field Database field
	     * @param string $value Condition value
	     * @param string $join Joining word
	     * @param boolean $escape Escape values setting
	     * @return string Condition as a string
	     * @throws Exception For invalid where condition
	     */
	 protected function parseCondition(field, value = null, join = "", escape = true) {

					if (is_string(field)) {
	            if (value === null) {
								 return join." ".trim(field);
							}

	            var operator = "";
							var condition;

	            if (strpos(field, " ") !== false) {
								var arr = explode(" ", field);
								let field = arr[0];
								let operator = trim(arr[1]);
	            }

	            if (!empty(operator)) {
	                switch (operator) {
	                    case "%":
	                        let condition = " LIKE ";
	                        break;

	                    case "!%":
	                        let condition = " NOT LIKE ";
	                        break;

	                    case "@":
	                        let condition = " IN ";
	                        break;

	                    case '!@':
	                        let condition = " NOT IN ";
	                        break;

	                    default:
	                        let condition = operator;
	                }
	            }
	            else {
	                let condition = "=";
	            }

	            if (empty(join)) {
	                let join = (substr(field,0) == "|") ? " OR" : " AND";
	            }

	            if (is_array(value)) {
	                if (strpos(operator, "@") === false){
										let condition = " IN ";
									}
	                let value ="(".implode(",", array_map([this, "quote"], value)).")";
	            }
	            else {
	                let value = (escape && !is_numeric(value)) ? this->quote(value) : value;
	            }

	            return join . " " . str_replace("|", "", field) . condition . value;
	        }
	        elseif (is_array(field)) {
	            string str = "";
							var key, value, join;

	            for key, value in field {
	                let str .= this->parseCondition(key, value, join, escape);
	                let join = "";
	            }
	            return str;
	        }
	        else {
	            throw new \Exception("Invalid where condition.");
	        }
	    }

			/**
	     * Sets the table.
	     *
	     * @param string $table Table name
	     * @param boolean $reset Reset class properties
	     * @return object Self reference
	     */
	    public function from(table, reset = true) {
	        let this->table = table;
	        if (reset) {
	            this->reset();
	        }
	        return this;
	    }

			/**
	     * Adds a table join.
	     *
	     * @param string $table Table to join to
	     * @param array $fields Fields to join on
	     * @param string $type Type of join
	     * @return object Self reference
	     * @throws Exception For invalid join type
	     */
	    public function join(table, fields = [], type = "INNER") {
	        var joins = [
	            "INNER",
	            "LEFT OUTER",
	            "RIGHT OUTER",
	            "FULL OUTER"
	        ];

	        if (!in_array(type, joins)) {
	            throw new \Exception("Invalid join type.");
	        }

	        let this->joins .= " " . type . " JOIN " . table . this->parseCondition(fields, null, " ON", false);

	        return this;
	    }

			/**
	     * Adds a left table join.
	     *
	     * @param string $table Table to join to
	     * @param array $fields Fields to join on
	     * @return object Self reference
	     */
	    public function leftJoin(table, fields = []) {
	        return this->join(table, fields, "LEFT OUTER");
	    }

			/**
			 * Adds a right table join.
			 *
			 * @param string $table Table to join to
			 * @param array $fields Fields to join on
			 * @return object Self reference
			 */
			public function rightJoin(table, fields = []) {
					return this->join(table, fields, "RIGHT OUTER");
			}


			    /**
			     * Adds a full table join.
			     *
			     * @param string $table Table to join to
			     * @param array $fields Fields to join on
			     * @return object Self reference
			     */
			    public function fullJoin(table, fields = []) {
			        return this->join(table, fields, "FULL OUTER");
			    }

					/*
			     * Adds where conditions.
			     *
			     * @param string|array $field A field name or an array of fields and values.
			     * @param string $value A field value to compare to
			     * @return object Self reference
			     */
			    public function where(field, value = null) {
						string join = "";
			        let join = (empty(this->where)) ? "WHERE" : "";
			        let this->where .= this->parseCondition(field, value, join);

			        return this;
			    }

					/*
			     * Adds an ascending sort for a field.
			     *
			     * @param string $field Field name
			     * @return object Self reference
			     */
			    public function sortAsc(field) {
			        return this->orderBy(field, "ASC");
			    }

			    /*
			     * Adds an descending sort for a field.
			     *
			     * @param string $field Field name
			     * @return object Self reference
			     */
			    public function sortDesc(field) {
			        return this->orderBy(field, "DESC");
			    }

					/**
			     * Adds fields to order by.
			     *
			     * @param string $field Field name
			     * @param string $direction Sort direction
			     * @return object Self reference
			     */
			    public function orderBy(field, direction = "ASC") {
						string join = "";
			        let join = (empty(this->order)) ? "ORDER BY" : ",";

			        if (is_array(field)) {
							var key, value;

			            for key, value in field {
			                let field[key] = value . " " . direction;
			            }
			        }
			        else {
			            let field .= " " . direction;
			        }

							string fields = "";
			        let fields = (is_array(field)) ? implode(', ', field) : field;

			        let this->order .= join . " " . fields;

			        return this;
			    }

					/**
			     * Adds fields to group by.
			     *
			     * @param string|array $field Field name or array of field names
			     * @return object Self reference
			     */
			    public function groupBy(field) {
						var join, fields;
			        let join = (empty(this->order)) ? "GROUP BY" :",";
			        let fields = (is_array(field)) ? implode(",", field) : field;

			        let this->groups .= join . " " . fields;

			        return this;
			    }

					/**
			     * Adds having conditions.
			     *
			     * @param string|array $field A field name or an array of fields and values.
			     * @param string $value A field value to compare to
			     * @return object Self reference
			     */
			    public function having(field, value = null) {
						var join;
			      let join = (empty(this->having)) ? "HAVING" : "";
			       let this->having .= this->parseCondition(field, value, join);

			        return this;
			    }

			    /**
			     * Adds a limit to the query.
			     *
			     * @param int $limit Number of rows to limit
			     * @param int $offset Number of rows to offset
			     * @return object Self reference
			     */
			    public function limit(limit, offset = null) {
			        if (limit !== null) {
			            let this->limit = "LIMIT " . limit;
			        }
			        if (offset !== null) {
			            this->offset(offset);
			        }

			        return this;
			    }

					/**
			     * Adds an offset to the query.
			     *
			     * @param int $offset Number of rows to offset
			     * @param int $limit Number of rows to limit
			     * @return object Self reference
			     */
			    public function offset(offset, limit = null) {
			        if (offset !== null) {
			            let this->offset = "OFFSET " . offset;
			        }
			        if (limit !== null) {
			            this->limit(limit);
			        }

			        return this;
			    }

					/**
			     * Sets the distinct keyword for a query.
			     */
			    public function distinct(value = true) {
			        let this->distinct = (value) ? "DISTINCT" : "";

			        return this;
			    }

			    /**
			     * Sets a between where clause.
			     *
			     * @param string $field Database field
			     * @param string $value1 First value
			     * @param string $value2 Second value
			     */
			    public function between(field, value1, value2) {
			        this->where(sprintf(
			            "%s BETWEEN %s AND %s",
			            field,
			            this->quote(value1),
			            this->quote(value2)
			        ));
			    }

					public function select(fields = "*", limit = null, offset = null) {

							this->checkTable();

							let fields = (is_array(fields)) ? implode(",", fields) : fields;
			        this->limit(limit, offset);

			        this->sql([
			            "SELECT",
			            this->distinct,
			            fields,
			            "FROM",
			            this->table,
			            this->joins,
			            this->where,
			            this->groups,
			            this->having,
			            this->order,
			            this->limit,
			            this->offset
			        ]);

			        return this;
			    }

					/**
			     * Builds an insert query.
			     *
			     * @param array $data Array of key and values to insert
			     * @return object Self reference
			     */
			    public function insert(data = []) {
			        this->checkTable();

			        if (empty(data)){
								return this;
							}
							var keys, values;

							let keys = implode(",", array_keys(data));

			        let values = implode(",", array_values(
			            array_map([this, "quote"], data )
			        ));

			        this->sql([
			            "INSERT INTO",
			            $this->table,
			            "(" . keys . ")",
			            "VALUES",
			            "(" . values . ")"
			        ]);

			        return this;
			    }

			    /**
			     * Builds an update query.
			     *
			     * @param string|array $data Array of keys and values, or string literal
			     * @return object Self reference
			     */
			    public function update(data) {
			        this->checkTable();

			        if (empty(data)){
							 return this;
							}

			        var values, key, value;

			        if (is_array(data)) {
			            for key, value in data {
			                let values[] = (is_numeric(key)) ? value : key . "=" . this->quote(value);
			            }
			        }
			        else {
			            let values[] = (string) data;
			        }

			        $this->sql([
			            "UPDATE",
			            this->table,
			            "SET",
			            implode(",", values),
			            this->where
			        ]);

			        return this;
			    }

					/**
			     * Builds a delete query.
			     *
			     * @param array $where Where conditions
			     * @return object Self reference
			     */
			    public function delete(where = null) {
			        $this->checkTable();

			        if (where !== null) {
			            this->where(where);
			        }

			        this->sql([
			            "DELETE FROM",
			            this->table,
			            this->where
			        ]);

			        return this;
			    }

					/*
			     * Gets or sets the SQL statement.
			     *
			     * @param string|array SQL statement
			     * @return string SQL statement
			     */
			    public function sql(sql = null) {
			        if (sql !== null) {
			            let this->sql = trim(
			                (is_array(sql)) ?
			                    array_reduce(sql, [this, "build"]) :
			                    sql
			            );

			            return this;
			        }

			        return this->sql;
			    }

					/*** Database Access Methods ***/

			    /*
			     * Sets the database connection.
			     *
			     * @param string|array|object $db Database connection string, array or object
			     * @throws Exception For connection error
			     */
			    public function setDb(db) {
						var error, type;
							let this->db = null;

			        if (is_string(db)) {
			            this->setDb(this->parseConnection(db));
			        }

			        elseif (is_array(db)) {
			            switch (db["type"]) {
			                case "mysqli":
			                    let this->db = new mysqli(
			                        db["hostname"],
			                        db["username"],
			                        db["password"],
			                        db["database"]
			                    );

			                    if (this->db->connect_error) {
			                        throw new \Exception("Connection error: " . this->db->connect_error);
			                    }

			                    break;

			                case "pgsql":
												var str;
			                    let str = sprintf(
			                        "host=%s dbname=%s user=%s password=%s",
			                        db["hostname"],
			                        db["database"],
			                        db["username"],
			                        db["password"]
			                    );

			                    let this->db = pg_connect(str);

			                    break;

			                case "pdomysql":
												var dsn;
			                    let dsn = sprintf(
			                        "mysql:host=%s;port=%d;dbname=%s",
			                        db["hostname"],
			                        isset(db["port"]) ? db["port"] : 3306,
			                        db["database"]
			                    );

			                    let this->db = new \PDO(dsn, db["username"], db["password"]);
			                    let db["type"] = "pdo";

			                    break;

			                case "pdopgsql":
												var dsn;
			                    let dsn = sprintf(
			                        "pgsql:host=%s;port=%d;dbname=%s;user=%s;password=%s",
			                        db["hostname"],
			                        isset(db["port"]) ? db["port"] : 5432,
			                        db["database"],
			                        db["username"],
			                        db["password"]
			                    );

			                    let this->db = new \PDO(dsn);
			                    let db["type"] = "pdo";

			                    break;

			            }

			            if (this->db == null) {
			                throw new \Exception("Undefined database.");
			            }

			            let this->db_type = db["type"];
			        }
			        else {
			            let type = this->getDbType(db);

			            if (!in_array(type, this->db_types)) {
			                throw new \Exception("Invalid database type.");
			            }

			            let this->db = db;
			            let this->db_type = type;
			        }
			    }

					public function quote(value) {
							if (value === null) {
								return "NULL";
							}
							if (is_string(value)) {
									if (this->db !== null) {
											switch (this->db_type) {
													case "pdo":
															return this->db->quote(value);

													case "mysqli":
															return "'".this->db->real_escape_string(value)."'";

													case "pgsql":
															return "'".pg_escape_string(this->db, value)."'";
											}
									}

									/*let value = str_replace(
											["\\", "\0", "\n", "\r", "'", '"', "\x1a"],
											["\\\\", "\\0", "\\n", "\\r", "\'", "\"", '\\Z'],
											value
									);*/
									//let value = addslash(value);

									return "'". value. "'";
							}

							return value;
					}

					    /**
					     * Gets the database connection.
					     *
					     * @return object Database connection
					     */
					    public function getDb() {
					        return this->db;
					    }

					    /**
					     * Gets the database type.
					     *
					     * @param object|resource $db Database object or resource
					     * @return string Database type
					     */
					    public function getDbType(db) {
					        if (is_object(db)) {
					            return strtolower(get_class(db));
					        }
					        elseif (is_resource($db)) {
					            switch (get_resource_type(db)) {
					                case "mysql link":
					                    return "mysql";

					                case "pgsql link":
					                    return "pgsql";
					            }
					        }

					        return null;
					    }
							/**
					     * Executes a sql statement.
					     *
					     * @param string $key Cache key
					     * @param int $expire Expiration time in seconds
					     * @return object Query results object
					     * @throws Exception When database is not defined
					     */
					    public function execute(key = null, expire = 0) {
								var result;
									if (!this->db) {
					            throw new \Exception("Database is not defined.");
					        }

					        if (key !== null) {
					            let result = this->fetchObject(key);

					            if (this->is_cached) {
					                return result;
					            }
					        }

					        let result = null;

					        let this->is_cached = false;
					        let this->num_rows = 0;
					        let this->affected_rows = 0;
					        let this->insert_id = -1;
					        let this->last_query = $this->sql;

					        if (this->stats_enabled) {
					            if (empty(this->stats)) {
					                let this->stats["queries"] = [];
					            }

					            let this->query_time = microtime(true);
					        }

					        if (!empty(this->sql)) {
										var error;
					            let error = null;

					            switch (this->db_type) {
					                case "pdo":
					                    try {
					                        let result = this->db->prepare(this->sql);

					                        if ($result) {
					                            let error = this->db->errorInfo();
					                        }
					                        else {
					                            result->execute();

					                            let this->num_rows = result->rowCount();
					                            let this->affected_rows = result->rowCount();
					                            let this->insert_id = this->db->lastInsertId();
					                        }
					                    }
					                    /*catch \PDOException, ex {
					                        let error = ex->getMessage();

																	}*/
					                    break;

					                case "mysqli":
					                    let result = this->db->query(this->sql);

					                    if (! result) {
					                        let error = this->db->error;
					                    }
					                    else {
					                        if (is_object(result)) {
					                            let this->num_rows = result->num_rows;
					                        }
					                        else {
					                            let this->affected_rows = this->db->affected_rows;
					                        }
					                        let this->insert_id = this->db->insert_id;
					                    }

					                    break;

					                case "pgsql":
					                    let result = pg_query(this->db, this->sql);

					                    if (! result) {
					                       let error = pg_last_error(this->db);
					                    }
					                    else {
					                        let this->num_rows = pg_num_rows(result);
					                        let this->affected_rows = pg_affected_rows(result);
					                        let this->insert_id = pg_last_oid(result);
					                    }

					                    break;

					            }

					            if (error !== null) {
					                if (this->show_sql) {
					                    let error .= "\nSQL: " . this->sql;
					                }
					                throw new \Exception("Database error: " . error);
					            }
					        }

					        if (this->stats_enabled) {
										var time, timer;
					            let time = microtime(true) - this->query_time;
											let timer["query"] = this->sql;
											let timer["time"] = time;
											let timer["rows"] = (int) this->num_rows;
											let timer["changes"] = (int) this->affected_rows;
											let this->stats["queries"][] = timer;
					        }

					        return result;
					    }

							/**
					     * Fetch multiple rows from a select query.
					     *
					     * @param string $key Cache key
					     * @param int $expire Expiration time in seconds
					     * @return array Rows
					     */
					    public function many(key = null, expire = 0) {
					        if (empty(this->sql)) {
					            this->select();
					        }

					        var data = [], result;

					        let result = this->execute(key, expire);

					        if (this->is_cached) {
					            let data = result;

					            if (this->stats_enabled) {
					                let this->stats["cached"][this->key_prefix . key] = this->sql;
					            }
					        }
					        else {
					            switch (this->db_type) {
					                case "pdo":
					                    let data = result->fetchAll(\PDO::FETCH_ASSOC);
					                    let this->num_rows = sizeof(data);

					                    break;

					                case "mysqli":
					                    if (function_exists("mysqli_fetch_all")) {
					                        let data = result->fetch_all(MYSQLI_ASSOC);
					                    }
					                    /*else {
					                        while (row = result->fetch_assoc()) {
					                            array_push(data, row);
					                        }
					                    }*/
					                    result->close();
					                    break;

					                case "pgsql":
					                    let data = pg_fetch_all(result);
					                    pg_free_result(result);
					                    break;

					            }
					        }

					        if (! this->is_cached && key !== null) {
					            this->store(key, data, expire);
					        }

					        return data;
					    }

							public function one(key = null, expire = 0) {
					        if (empty(this->sql)) {
					            this->limit(1)->select();
					        }
									var data;
					        let data = this->many(key, expire);

					        return (!empty(data)) ? data[0] : [];

					    }

					    /**
					     * Fetch a value from a field.
					     *
					     * @param string $name Database field name
					     * @param string $key Cache key
					     * @param int $expire Expiration time in seconds
					     * @return mixed Row value
					     */
					    public function value(name, key = null, expire = 0) {
									var row;
					        let row = this->one(key, expire);

					        return (!empty(row)) ? row[name] : null;

					    }

					    /**
					     * Gets the min value for a specified field.
					     *
					     * @param string $field Field name
					     * @param int $expire Expiration time in seconds
					     * @param string $key Cache key
					     * @return object Self reference
					     */
					    public function min(field, key = null, expire = 0) {
					        this->select("MIN(".field.") min_value");

					        return this->value(
					            "min_value",
					            key,
					            expire
					        );
					    }

					    /**
					     * Gets the max value for a specified field.
					     *
					     * @param string $field Field name
					     * @param int $expire Expiration time in seconds
					     * @param string $key Cache key
					     * @return object Self reference
					     */
					    public function max(field, key = null, expire = 0) {
					        this->select("MAX(".field.") max_value");

					        return this->value(
					            "max_value",
					            key,
					            expire
					        );
					    }

					    /**
					     * Gets the sum value for a specified field.
					     *
					     * @param string $field Field name
					     * @param int $expire Expiration time in seconds
					     * @param string $key Cache key
					     * @return object Self reference
					     */
					    public function sum(field, key = null, expire = 0) {
					        this->select("SUM(".field.") sum_value");

					        return $this->value(
					            "sum_value",
					            key,
					            expire
					        );
					    }

					    /**
					     * Gets the average value for a specified field.
					     *
					     * @param string $field Field name
					     * @param int $expire Expiration time in seconds
					     * @param string $key Cache key
					     * @return object Self reference
					     */
					    public function avg(field, key = null, expire = 0) {
					        this->select("AVG(".field.") avg_value");

					        return this->value(
					            "avg_value",
					            key,
					            expire
					        );
					    }

					    /**
					     * Gets a count of records for a table.
					     *
					     * @param string $field Field name
					     * @param string $key Cache key
					     * @param int $expire Expiration time in seconds
					     * @return object Self reference
					     */
					    public function count(field = "*", key = null, expire = 0) {
					        this->select("COUNT(".field.") num_rows");

					        return this->value(
					            "num_rows",
					            key,
					            expire
					        );
					    }

							/*** Cache Methods ***/

					    /*
					     * Sets the cache connection.
					     *
					     * @param string|object $cache Cache connection string or object
					     * @throws Exception For invalid cache type
					     */
					    public function setCache(cache)
					    {
					        let this->cache = null;

					        // Connection string
					        if (is_string(cache)) {
					            if (cache[0] == "." || cache[0] == "/") {
					                let this->cache = cache;
					                let this->cache_type = "file";
					            } else {
					                this->setCache(this->parseConnection(cache));
					            }
					        }
					        // Connection information
					        elseif (is_array(cache)) {
					            switch (cache["type"]) {
					                case "memcache":
					                    let this->cache = new \Memcache;
					                    this->cache->connect(
					                        cache["hostname"],
					                        cache["port"]
					                    );
					                    break;

					                case "memcached":
					                    let this->cache = new \Memcached;
					                    this->cache->addServer(
					                        cache["hostname"],
					                        cache["port"]
					                    );
					                    break;

					                default:
					                    let this->cache = cache["type"];
					            }

					            let this->cache_type = cache["type"];
					        }
					        // Cache object
					        elseif (is_object(cache)) {
											var type;
					            let type = strtolower(get_class(cache));

					            if (!in_array(type, this->cache_types)) {
					                throw new \Exception("Invalid cache type.");
					            }

					            let this->cache = cache;
					            let this->cache_type = type;
					        }
					    }

					    /**
					     * Gets the cache instance.
					     *
					     * @return object Cache instance
					     */
					    public function getCache()
					    {
					        return this->cache;
					    }

					    /**
					     * Stores a value in the cache.
					     *
					     * @param string $key Cache key
					     * @param mixed $value Value to store
					     * @param int $expire Expiration time in seconds
					     */
					    public function store(key, value, expire = 0)
					    {
					        let key = this->key_prefix.key;

					        switch (this->cache_type) {
					            case "memcached":
					                this->cache->set(key, value, expire);
					                break;

					            case "memcache":
					                this->cache->set(key, value, 0, expire);
					                break;

					            case "apc":
					                apc_store(key, value, expire);
					                break;

					            case "xcache":
					                xcache_set(key, value, expire);
					                break;

					            case "file":
												var file, data;
					                let file = this->cache."/".md5(key);
					                let data["value"] = value;
													let data["expire"] = (expire > 0) ? (time() + expire) : 0;

					                file_put_contents(file, serialize(data));
					                break;

					            default:
					                let this->cache[key] = value;
					        }
					    }

							/**
					     * Fetches a value from the cache.
					     *
					     * @param string $key Cache key
					     * @return mixed Cached value
					     */
					    public function fetchObject(key) {
					        let key = this->key_prefix . key;
									var value;
					        switch (this->cache_type) {
					            case "memcached":
					                let value = this->cache->get(key);
					                //let this->is_cached = (this->cache->getResultCode() == Memcached::RES_SUCCESS);
					                return value;

					            case "memcache":
					                let value = this->cache->get(key);
					                let this->is_cached = (value !== false);
					                return value;

					            case "apc":
					                return apc_fetch(key, this->is_cached);

					            case "xcache":
					                let this->is_cached = xcache_isset(key);
					                return cache_get(key);

					            case "file":
												var file;
					                let file = this->cache."/".md5(key);

					                if (this->is_cached == file_exists(file)) {
														var data;
					                    let data = unserialize(file_get_contents(file));
					                    if (data["expire"] == 0 || time() < data["expire"]) {
					                        return data["value"];
					                    }
					                    else {
					                        let this->is_cached = false;
					                    }
					                }
					                break;

					            default:
					                return this->cache[key];
					        }
					        return null;
					    }

							    /**
							     * Clear a value from the cache.
							     *
							     * @param string $key Cache key
							     * @return object Self reference
							     */
							    public function clear(key)
							    {
							        let key = this->key_prefix.key;

							        switch (this->cache_type) {
							            case "memcached":
							                return this->cache->delete(key);

							            case "memcache":
							                return this->cache->delete(key);

							            case "apc":
							                return apc_delete(key);

							            case "xcache":
							                return xcache_unset(key);

							            case "file":
														var file;
							                let file = this->cache."/".md5(key);
							                if (file_exists(file)) {
							                    return unlink(file);
							                }
							                return false;

							            default:
							                if (isset(this->cache[key])) {
							                    unset(this->cache[key]);
							                    return true;
							                }
							                return false;
							        }
							    }

							    /**
							     * Flushes out the cache.
							     */
							    public function flush()
							    {
							        switch (this->cache_type) {
							            case "memcached":
							                this->cache->flush();
							                break;

							            case "memcache":
							                this->cache->flush();
							                break;

							            case "apc":
							                apc_clear_cache();
							                break;
													/*
							            case "xcache":
							                xcache_clear_cache();
							                break;
													*/
							            case "file":
														var handle, file;
														let handle = opendir(this->cache);
							                if (handle) {
																let file = readdir(handle);
							                    while (false !== (file)) {
							                        if (file != "." && file != "..") {
							                            unlink(this->cache."/".file);
							                        }
							                    }
							                    closedir(handle);
							                }
							                break;

							            default:
							                let this->cache = [];
							                break;
							        }
							    }

							    /*** Object Methods ***/

							    /*
							     * Sets the class.
							     *
							     * @param string|object $class Class name or instance
							     * @return object Self reference
							     */
							    public function using(_class)
							    {
							        if (is_string(_class)) {
							            let this->_class = _class;
							        } elseif (is_object(_class)) {
							            let this->_class = get_class(_class);
							        }

							        this->reset();

							        return this;
							    }

							    /**
							     * Loads properties for an object.
							     *
							     * @param object $object Class instance
							     * @param array $data Property data
							     * @return object Populated object
							     */
							    public function load(_object, data = [])
							    {
											var key, value;
							        for key, value in data {
							            if (property_exists(_object, key)) {
							                let _object->{key} = value;
							            }
							        }

							        return _object;
							    }

							    /**
							     * Finds and populates an object.
							     *
							     * @param int|string|array Search value
							     * @param string $key Cache key
							     * @return object Populated object
							     */
							    public function find(value = null, key = null)
							    {
							        this->checkClass();
											var properties, row, data, objects;
							        let properties = this->getProperties();

							        this->from(properties->table, false);

							        if (value !== null) {
							            if (is_int(value) && property_exists(properties, "id_field")) {
							                this->where(properties->id_field, value);
							            } elseif (is_string(value) && property_exists(properties, "name_field")) {
							                this->where(properties->name_field, value);
							            } elseif (is_array(value)) {
							                this->where(value);
							            }
							        }

							        if (empty(this->sql)) {
							            this->select();
							        }

							        let data = this->many(key);
							        let objects = [];

							        for row in data {
												var _class ;
												let _class = this->_class;
							            array_push(objects, this->load(_class, row));
							        }

							        return (sizeof(objects) == 1) ? objects[0] : objects;
							    }

							    /**
							     * Saves an object to the database.
							     *
							     * @param object $object Class instance
							     * @param array $fields Select database fields to save
							     */
							    /*public function save(_object, fields = null)
							    {
							        this->using(_object);
											var properties, data, id, keys;
							        let properties = this->getProperties();

							        this->from(properties->table);

							        let data = get_object_vars(_object);
							        let id = _object->{properties->id_field};

							        unset(data[properties->id_field]);

							        if (id === null) {
							            this->insert(data)
							                ->execute();

							            let _object->{properties->id_field} = this->insert_id;
							        } else {
							            if (fields !== null) {
							                let keys = array_flip(fields);
							                let data = array_intersect_key(data, keys);
							            }

							            this->where(properties->id_field, id)
							                ->update(data)
							                ->execute();
							        }

							        return this->_class;
							    }
									*/
							    /*
							     * Removes an object from the database.
							     *
							     * @param object $object Class instance
							     */
									 /*
							    public function remove(object)
							    {
							        this->using(object);
											var properties, id;
							        let properties = this->getProperties();

							        this->from(properties->table);

							        let id = object->{properties->id_field};

							        if (id !== null) {
							            this->where(properties->id_field, id)
							                ->delete()
							                ->execute();
							        }
							    }
									*/
							    /*
							     * Gets class properties.
							     *
							     * @return object Class properties
							     */
							    public function getProperties()
							    {
							        var properties = [];

							        if (!$this->_class) {
							            return [];
							        }

							        if (!isset(properties[this->_class])) {
												var defaults, reflection, config;
												let defaults["table"] = null;
												let defaults["id_field"] = null;
												let defaults["name_field"] = null;

							          let reflection = new \ReflectionClass(this->_class);
							          let config = reflection->getStaticProperties();

							           let properties[$this->_class] = (object)array_merge(defaults, config);
							        }

							        return (object) properties[this->_class];
							    }

}
