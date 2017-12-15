
extern zend_class_entry *sparrow_lib_sparrow_ce;

ZEPHIR_INIT_CLASS(Sparrow_Lib_Sparrow);

PHP_METHOD(Sparrow_Lib_Sparrow, __construct);
PHP_METHOD(Sparrow_Lib_Sparrow, build);
PHP_METHOD(Sparrow_Lib_Sparrow, parseConnection);
PHP_METHOD(Sparrow_Lib_Sparrow, getStats);
PHP_METHOD(Sparrow_Lib_Sparrow, checkTable);
PHP_METHOD(Sparrow_Lib_Sparrow, checkClass);
PHP_METHOD(Sparrow_Lib_Sparrow, reset);
PHP_METHOD(Sparrow_Lib_Sparrow, parseCondition);
PHP_METHOD(Sparrow_Lib_Sparrow, from);
PHP_METHOD(Sparrow_Lib_Sparrow, join);
PHP_METHOD(Sparrow_Lib_Sparrow, leftJoin);
PHP_METHOD(Sparrow_Lib_Sparrow, rightJoin);
PHP_METHOD(Sparrow_Lib_Sparrow, fullJoin);
PHP_METHOD(Sparrow_Lib_Sparrow, where);
PHP_METHOD(Sparrow_Lib_Sparrow, sortAsc);
PHP_METHOD(Sparrow_Lib_Sparrow, sortDesc);
PHP_METHOD(Sparrow_Lib_Sparrow, orderBy);
PHP_METHOD(Sparrow_Lib_Sparrow, groupBy);
PHP_METHOD(Sparrow_Lib_Sparrow, having);
PHP_METHOD(Sparrow_Lib_Sparrow, limit);
PHP_METHOD(Sparrow_Lib_Sparrow, offset);
PHP_METHOD(Sparrow_Lib_Sparrow, distinct);
PHP_METHOD(Sparrow_Lib_Sparrow, between);
PHP_METHOD(Sparrow_Lib_Sparrow, select);
PHP_METHOD(Sparrow_Lib_Sparrow, insert);
PHP_METHOD(Sparrow_Lib_Sparrow, update);
PHP_METHOD(Sparrow_Lib_Sparrow, delete);
PHP_METHOD(Sparrow_Lib_Sparrow, sql);
PHP_METHOD(Sparrow_Lib_Sparrow, setDb);
PHP_METHOD(Sparrow_Lib_Sparrow, quote);
PHP_METHOD(Sparrow_Lib_Sparrow, getDb);
PHP_METHOD(Sparrow_Lib_Sparrow, getDbType);
PHP_METHOD(Sparrow_Lib_Sparrow, execute);
PHP_METHOD(Sparrow_Lib_Sparrow, many);
PHP_METHOD(Sparrow_Lib_Sparrow, one);
PHP_METHOD(Sparrow_Lib_Sparrow, value);
PHP_METHOD(Sparrow_Lib_Sparrow, min);
PHP_METHOD(Sparrow_Lib_Sparrow, max);
PHP_METHOD(Sparrow_Lib_Sparrow, sum);
PHP_METHOD(Sparrow_Lib_Sparrow, avg);
PHP_METHOD(Sparrow_Lib_Sparrow, count);
PHP_METHOD(Sparrow_Lib_Sparrow, setCache);
PHP_METHOD(Sparrow_Lib_Sparrow, getCache);
PHP_METHOD(Sparrow_Lib_Sparrow, store);
PHP_METHOD(Sparrow_Lib_Sparrow, fetchObject);
PHP_METHOD(Sparrow_Lib_Sparrow, clear);
PHP_METHOD(Sparrow_Lib_Sparrow, flush);
PHP_METHOD(Sparrow_Lib_Sparrow, using);
PHP_METHOD(Sparrow_Lib_Sparrow, load);
PHP_METHOD(Sparrow_Lib_Sparrow, find);
PHP_METHOD(Sparrow_Lib_Sparrow, getProperties);
zend_object *zephir_init_properties_Sparrow_Lib_Sparrow(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_build, 0, 0, 2)
	ZEND_ARG_INFO(0, sql)
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_parseconnection, 0, 0, 1)
	ZEND_ARG_INFO(0, connection)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_parsecondition, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, join)
	ZEND_ARG_INFO(0, escape)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_from, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, reset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_join, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, type)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_leftjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_rightjoin, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_fulljoin, 0, 0, 1)
	ZEND_ARG_INFO(0, table)
	ZEND_ARG_INFO(0, fields)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_where, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_sortasc, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_sortdesc, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_orderby, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, direction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_groupby, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_having, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_limit, 0, 0, 1)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_offset, 0, 0, 1)
	ZEND_ARG_INFO(0, offset)
	ZEND_ARG_INFO(0, limit)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_distinct, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_between, 0, 0, 3)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, value1)
	ZEND_ARG_INFO(0, value2)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_select, 0, 0, 0)
	ZEND_ARG_INFO(0, fields)
	ZEND_ARG_INFO(0, limit)
	ZEND_ARG_INFO(0, offset)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_insert, 0, 0, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_update, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_delete, 0, 0, 0)
	ZEND_ARG_INFO(0, where)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_sql, 0, 0, 0)
	ZEND_ARG_INFO(0, sql)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_setdb, 0, 0, 1)
	ZEND_ARG_INFO(0, db)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_quote, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_getdbtype, 0, 0, 1)
	ZEND_ARG_INFO(0, db)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_execute, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_many, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_one, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_value, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_min, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_max, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_sum, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_avg, 0, 0, 1)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_count, 0, 0, 0)
	ZEND_ARG_INFO(0, field)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_setcache, 0, 0, 1)
	ZEND_ARG_INFO(0, cache)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_store, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, expire)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_fetchobject, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_clear, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_using, 0, 0, 1)
	ZEND_ARG_INFO(0, _class)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_load, 0, 0, 1)
	ZEND_ARG_INFO(0, _object)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_sparrow_lib_sparrow_find, 0, 0, 0)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(sparrow_lib_sparrow_method_entry) {
	PHP_ME(Sparrow_Lib_Sparrow, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Sparrow_Lib_Sparrow, build, arginfo_sparrow_lib_sparrow_build, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, parseConnection, arginfo_sparrow_lib_sparrow_parseconnection, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, getStats, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, checkTable, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, checkClass, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, reset, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, parseCondition, arginfo_sparrow_lib_sparrow_parsecondition, ZEND_ACC_PROTECTED)
	PHP_ME(Sparrow_Lib_Sparrow, from, arginfo_sparrow_lib_sparrow_from, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, join, arginfo_sparrow_lib_sparrow_join, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, leftJoin, arginfo_sparrow_lib_sparrow_leftjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, rightJoin, arginfo_sparrow_lib_sparrow_rightjoin, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, fullJoin, arginfo_sparrow_lib_sparrow_fulljoin, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, where, arginfo_sparrow_lib_sparrow_where, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, sortAsc, arginfo_sparrow_lib_sparrow_sortasc, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, sortDesc, arginfo_sparrow_lib_sparrow_sortdesc, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, orderBy, arginfo_sparrow_lib_sparrow_orderby, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, groupBy, arginfo_sparrow_lib_sparrow_groupby, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, having, arginfo_sparrow_lib_sparrow_having, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, limit, arginfo_sparrow_lib_sparrow_limit, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, offset, arginfo_sparrow_lib_sparrow_offset, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, distinct, arginfo_sparrow_lib_sparrow_distinct, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, between, arginfo_sparrow_lib_sparrow_between, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, select, arginfo_sparrow_lib_sparrow_select, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, insert, arginfo_sparrow_lib_sparrow_insert, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, update, arginfo_sparrow_lib_sparrow_update, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, delete, arginfo_sparrow_lib_sparrow_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, sql, arginfo_sparrow_lib_sparrow_sql, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, setDb, arginfo_sparrow_lib_sparrow_setdb, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, quote, arginfo_sparrow_lib_sparrow_quote, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, getDb, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, getDbType, arginfo_sparrow_lib_sparrow_getdbtype, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, execute, arginfo_sparrow_lib_sparrow_execute, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, many, arginfo_sparrow_lib_sparrow_many, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, one, arginfo_sparrow_lib_sparrow_one, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, value, arginfo_sparrow_lib_sparrow_value, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, min, arginfo_sparrow_lib_sparrow_min, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, max, arginfo_sparrow_lib_sparrow_max, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, sum, arginfo_sparrow_lib_sparrow_sum, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, avg, arginfo_sparrow_lib_sparrow_avg, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, count, arginfo_sparrow_lib_sparrow_count, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, setCache, arginfo_sparrow_lib_sparrow_setcache, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, getCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, store, arginfo_sparrow_lib_sparrow_store, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, fetchObject, arginfo_sparrow_lib_sparrow_fetchobject, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, clear, arginfo_sparrow_lib_sparrow_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, using, arginfo_sparrow_lib_sparrow_using, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, load, arginfo_sparrow_lib_sparrow_load, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, find, arginfo_sparrow_lib_sparrow_find, ZEND_ACC_PUBLIC)
	PHP_ME(Sparrow_Lib_Sparrow, getProperties, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
