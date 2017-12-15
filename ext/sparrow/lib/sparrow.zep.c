
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/pdo/php_pdo_driver.h"
#include "kernel/time.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(Sparrow_Lib_Sparrow) {

	ZEPHIR_REGISTER_CLASS(Sparrow\\Lib, Sparrow, sparrow, lib_sparrow, sparrow_lib_sparrow_method_entry, 0);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("table"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("where"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("joins"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("order"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("groups"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("having"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("distinct"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("limit"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("offset"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("sql"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("db"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("db_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("cache"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("cache_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("stats"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("query_time"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("_class"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("db_types"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("cache_types"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("last_query"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("num_rows"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("insert_id"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("affected_rows"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("is_cached"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("stats_enabled"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("show_sql"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("key_prefix"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(sparrow_lib_sparrow_ce, SL("err_message"), ZEND_ACC_PUBLIC TSRMLS_CC);

	sparrow_lib_sparrow_ce->create_object = zephir_init_properties_Sparrow_Lib_Sparrow;
	return SUCCESS;

}

PHP_METHOD(Sparrow_Lib_Sparrow, __construct) {

	zval _1;
	zval _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "pdo");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "mysqli");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "pgsql");
	zephir_array_fast_append(&_0, &_1);
	zephir_update_property_zval(this_ptr, SL("db_types"), &_0);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "memcached");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "memcache");
	zephir_array_fast_append(&_2, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "xcache");
	zephir_array_fast_append(&_2, &_1);
	zephir_update_property_zval(this_ptr, SL("cache_types"), &_2);
	ZEPHIR_MM_RESTORE();

}

/*** Core Methods ***/
PHP_METHOD(Sparrow_Lib_Sparrow, build) {

	zval *sql, sql_sub, *input, input_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql_sub);
	ZVAL_UNDEF(&input_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &sql, &input);



	ZEPHIR_INIT_VAR(&_0);
	if (zephir_fast_strlen_ev(input) > 0) {
		ZEPHIR_CONCAT_VSV(&_0, sql, " ", input);
	} else {
		ZEPHIR_CPY_WRT(&_0, sql);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(Sparrow_Lib_Sparrow, parseConnection) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, url, cfg, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&cfg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &connection);



	ZEPHIR_INIT_VAR(&url);
	array_init(&url);
	ZEPHIR_CALL_FUNCTION(&url, "parse_url", NULL, 1, connection);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&url)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Invalid connection string", "sparrow/lib/sparrow.zep", 71);
		return;
	}
	ZEPHIR_INIT_VAR(&cfg);
	array_init(&cfg);
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_fetch_string(&_1, &url, SL("scheme"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 75 TSRMLS_CC);
	if (zephir_is_true(&_1)) {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch_string(&_0, &url, SL("scheme"), PH_NOISY, "sparrow/lib/sparrow.zep", 75 TSRMLS_CC);
	} else {
		ZEPHIR_OBS_NVAR(&_0);
		zephir_array_fetch_string(&_0, &url, SL("path"), PH_NOISY, "sparrow/lib/sparrow.zep", 75 TSRMLS_CC);
	}
	zephir_array_update_string(&cfg, SL("type"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_2);
	zephir_array_fetch_string(&_3, &url, SL("host"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 76 TSRMLS_CC);
	if (zephir_is_true(&_3)) {
		ZEPHIR_OBS_NVAR(&_2);
		zephir_array_fetch_string(&_2, &url, SL("host"), PH_NOISY, "sparrow/lib/sparrow.zep", 76 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_NULL(&_2);
	}
	zephir_array_update_string(&cfg, SL("hostname"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_4);
	zephir_array_fetch_string(&_5, &url, SL("path"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 77 TSRMLS_CC);
	if (zephir_is_true(&_5)) {
		zephir_array_fetch_string(&_6, &url, SL("path"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 77 TSRMLS_CC);
		ZVAL_LONG(&_7, 1);
		ZEPHIR_INIT_NVAR(&_4);
		zephir_substr(&_4, &_6, 1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
	} else {
		ZEPHIR_INIT_NVAR(&_4);
		ZVAL_NULL(&_4);
	}
	zephir_array_update_string(&cfg, SL("database"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_8);
	zephir_array_fetch_string(&_9, &url, SL("user"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 78 TSRMLS_CC);
	if (zephir_is_true(&_9)) {
		ZEPHIR_OBS_NVAR(&_8);
		zephir_array_fetch_string(&_8, &url, SL("user"), PH_NOISY, "sparrow/lib/sparrow.zep", 78 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_NULL(&_8);
	}
	zephir_array_update_string(&cfg, SL("username"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_10);
	zephir_array_fetch_string(&_11, &url, SL("pass"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 79 TSRMLS_CC);
	if (zephir_is_true(&_11)) {
		ZEPHIR_OBS_NVAR(&_10);
		zephir_array_fetch_string(&_10, &url, SL("pass"), PH_NOISY, "sparrow/lib/sparrow.zep", 79 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_10);
		ZVAL_NULL(&_10);
	}
	zephir_array_update_string(&cfg, SL("password"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_12);
	zephir_array_fetch_string(&_13, &url, SL("port"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 80 TSRMLS_CC);
	if (zephir_is_true(&_13)) {
		ZEPHIR_OBS_NVAR(&_12);
		zephir_array_fetch_string(&_12, &url, SL("port"), PH_NOISY, "sparrow/lib/sparrow.zep", 80 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_NULL(&_12);
	}
	zephir_array_update_string(&cfg, SL("port"), &_12, PH_COPY | PH_SEPARATE);
	RETURN_CCTOR(&cfg);

}

/**
 * Gets the query statistics.
 */
PHP_METHOD(Sparrow_Lib_Sparrow, getStats) {

	zend_bool _9;
	zval _0, _1, _2, _3, _4, _5, _6, _7, _8, _10, _11, _21, _22, _23, _24, _25, _26, _27, _28, query$$3, _12$$3, _13$$3, *_14$$3, _15$$4, _16$$4, _17$$4, _18$$4, _19$$4, _20$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&query$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "total_time");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_array(this_ptr, SL("stats"), &_0, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "num_queries");
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_LONG(&_3, 0);
	zephir_update_property_array(this_ptr, SL("stats"), &_2, &_3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "num_rows");
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_LONG(&_5, 0);
	zephir_update_property_array(this_ptr, SL("stats"), &_4, &_5 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "num_changes");
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_LONG(&_7, 0);
	zephir_update_property_array(this_ptr, SL("stats"), &_6, &_7 TSRMLS_CC);
	zephir_read_property(&_8, this_ptr, SL("stats"), PH_NOISY_CC | PH_READONLY);
	_9 = zephir_array_isset_string(&_8, SL("queries"));
	if (_9) {
		zephir_read_property(&_10, this_ptr, SL("stats"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_11, &_10, SL("queries"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 95 TSRMLS_CC);
		_9 = Z_TYPE_P(&_11) == IS_ARRAY;
	}
	if (_9) {
		ZEPHIR_INIT_VAR(&query$$3);
		array_init(&query$$3);
		zephir_read_property(&_12$$3, this_ptr, SL("stats"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_13$$3, &_12$$3, SL("queries"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 99 TSRMLS_CC);
		zephir_is_iterable(&_13$$3, 0, "sparrow/lib/sparrow.zep", 105);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_13$$3), _14$$3)
		{
			ZEPHIR_INIT_NVAR(&query$$3);
			ZVAL_COPY(&query$$3, _14$$3);
			zephir_array_fetch_string(&_15$$4, &query$$3, SL("time"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 100 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_16$$4);
			ZVAL_STRING(&_16$$4, "total_time");
			zephir_update_property_array(this_ptr, SL("stats"), &_16$$4, &_15$$4 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_17$$4);
			ZVAL_STRING(&_17$$4, "num_queries");
			ZEPHIR_INIT_NVAR(&_18$$4);
			ZVAL_LONG(&_18$$4, 1);
			zephir_update_property_array(this_ptr, SL("stats"), &_17$$4, &_18$$4 TSRMLS_CC);
			zephir_array_fetch_string(&_15$$4, &query$$3, SL("rows"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 102 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_19$$4);
			ZVAL_STRING(&_19$$4, "num_rows");
			zephir_update_property_array(this_ptr, SL("stats"), &_19$$4, &_15$$4 TSRMLS_CC);
			zephir_array_fetch_string(&_15$$4, &query$$3, SL("changes"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 103 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_20$$4);
			ZVAL_STRING(&_20$$4, "num_changes");
			zephir_update_property_array(this_ptr, SL("stats"), &_20$$4, &_15$$4 TSRMLS_CC);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&query$$3);
	}
	zephir_read_property(&_21, this_ptr, SL("stats"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_22, &_21, SL("total_time"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 108 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_23);
	zephir_read_property(&_24, this_ptr, SL("stats"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_25, &_24, SL("num_queries"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 109 TSRMLS_CC);
	if (ZEPHIR_GT_LONG(&_25, 0)) {
		zephir_read_property(&_26, this_ptr, SL("stats"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_NVAR(&_23);
		zephir_array_fetch_string(&_23, &_26, SL("num_queries"), PH_NOISY, "sparrow/lib/sparrow.zep", 109 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_23);
		ZVAL_LONG(&_23, 1);
	}
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_STRING(&_27, "avg_query_time");
	ZEPHIR_INIT_VAR(&_28);
	ZVAL_DOUBLE(&_28, zephir_safe_div_zval_double(&_22, zephir_get_doubleval(&_23) TSRMLS_CC));
	zephir_update_property_array(this_ptr, SL("stats"), &_27, &_28 TSRMLS_CC);
	RETURN_MM_MEMBER(getThis(), "stats");

}

/**
 * Checks whether the table property has been set.
 */
PHP_METHOD(Sparrow_Lib_Sparrow, checkTable) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("table"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "Table is not defined.", "sparrow/lib/sparrow.zep", 119);
		return;
	}

}

/**
 * Checks whether the class property has been set.
 */
PHP_METHOD(Sparrow_Lib_Sparrow, checkClass) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("_class"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "Class is not defined.", "sparrow/lib/sparrow.zep", 129);
		return;
	}

}

/**
 * Resets class properties.
 */
PHP_METHOD(Sparrow_Lib_Sparrow, reset) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("where"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("joins"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("order"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("groups"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("having"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("distinct"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("limit"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("offset"), &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "");
	zephir_update_property_zval(this_ptr, SL("sql"), &_0);
	ZEPHIR_MM_RESTORE();

}

/*** SQL Builder Methods ***/
PHP_METHOD(Sparrow_Lib_Sparrow, parseCondition) {

	zend_string *_19$$17;
	zend_ulong _18$$17;
	zval str$$17;
	zend_bool _13$$16;
	zval _9$$14;
	zephir_fcall_cache_entry *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL, field_sub, *value = NULL, value_sub, *join = NULL, join_sub, *escape = NULL, escape_sub, __$null, __$true, _0$$4, operator$$3, condition$$3, _1$$3, _2$$3, _14$$3, _15$$3, _16$$3, arr$$5, _3$$5, _4$$13, _5$$13, _6$$14, _7$$14, _8$$14, _10$$14, _11$$14, _12$$16, key$$17, value$$17, join$$17, *_17$$17, _20$$18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&join_sub);
	ZVAL_UNDEF(&escape_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&operator$$3);
	ZVAL_UNDEF(&condition$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&arr$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$13);
	ZVAL_UNDEF(&_5$$13);
	ZVAL_UNDEF(&_6$$14);
	ZVAL_UNDEF(&_7$$14);
	ZVAL_UNDEF(&_8$$14);
	ZVAL_UNDEF(&_10$$14);
	ZVAL_UNDEF(&_11$$14);
	ZVAL_UNDEF(&_12$$16);
	ZVAL_UNDEF(&key$$17);
	ZVAL_UNDEF(&value$$17);
	ZVAL_UNDEF(&join$$17);
	ZVAL_UNDEF(&_20$$18);
	ZVAL_UNDEF(&_9$$14);
	ZVAL_UNDEF(&str$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &field, &value, &join, &escape);

	ZEPHIR_SEPARATE_PARAM(field);
	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}
	if (!join) {
		join = &join_sub;
		ZEPHIR_INIT_VAR(join);
		ZVAL_STRING(join, "");
	} else {
		ZEPHIR_SEPARATE_PARAM(join);
	}
	if (!escape) {
		escape = &escape_sub;
		escape = &__$true;
	}


	if (Z_TYPE_P(field) == IS_STRING) {
		if (Z_TYPE_P(value) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_0$$4);
			zephir_fast_trim(&_0$$4, field, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
			ZEPHIR_CONCAT_VSV(return_value, join, " ", &_0$$4);
			RETURN_MM();
		}
		ZEPHIR_INIT_VAR(&operator$$3);
		ZVAL_STRING(&operator$$3, "");
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, " ");
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_fast_strpos(&_2$$3, field, &_1$$3, 0 );
		if (!ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
			ZEPHIR_INIT_VAR(&arr$$5);
			zephir_fast_explode_str(&arr$$5, SL(" "), field, LONG_MAX TSRMLS_CC);
			ZEPHIR_OBS_NVAR(field);
			zephir_array_fetch_long(field, &arr$$5, 0, PH_NOISY, "sparrow/lib/sparrow.zep", 173 TSRMLS_CC);
			zephir_array_fetch_long(&_3$$5, &arr$$5, 1, PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 174 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&operator$$3);
			zephir_fast_trim(&operator$$3, &_3$$5, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		}
		if (!(ZEPHIR_IS_EMPTY(&operator$$3))) {
			do {
				if (ZEPHIR_IS_STRING(&operator$$3, "%")) {
					ZEPHIR_INIT_VAR(&condition$$3);
					ZVAL_STRING(&condition$$3, " LIKE ");
					break;
				}
				if (ZEPHIR_IS_STRING(&operator$$3, "!%")) {
					ZEPHIR_INIT_NVAR(&condition$$3);
					ZVAL_STRING(&condition$$3, " NOT LIKE ");
					break;
				}
				if (ZEPHIR_IS_STRING(&operator$$3, "@")) {
					ZEPHIR_INIT_NVAR(&condition$$3);
					ZVAL_STRING(&condition$$3, " IN ");
					break;
				}
				if (ZEPHIR_IS_LONG(&operator$$3, '!@')) {
					ZEPHIR_INIT_NVAR(&condition$$3);
					ZVAL_STRING(&condition$$3, " NOT IN ");
					break;
				}
				ZEPHIR_CPY_WRT(&condition$$3, &operator$$3);
			} while(0);

		} else {
			ZEPHIR_INIT_NVAR(&condition$$3);
			ZVAL_STRING(&condition$$3, "=");
		}
		if (ZEPHIR_IS_EMPTY(join)) {
			ZVAL_LONG(&_4$$13, 0);
			ZEPHIR_INIT_VAR(&_5$$13);
			zephir_substr(&_5$$13, field, 0 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
			if (ZEPHIR_IS_STRING(&_5$$13, "|")) {
				ZEPHIR_INIT_NVAR(join);
				ZVAL_STRING(join, " OR");
			} else {
				ZEPHIR_INIT_NVAR(join);
				ZVAL_STRING(join, " AND");
			}
		}
		if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_6$$14);
			ZVAL_STRING(&_6$$14, "@");
			ZEPHIR_INIT_VAR(&_7$$14);
			zephir_fast_strpos(&_7$$14, &operator$$3, &_6$$14, 0 );
			if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$14)) {
				ZEPHIR_INIT_NVAR(&condition$$3);
				ZVAL_STRING(&condition$$3, " IN ");
			}
			ZEPHIR_INIT_VAR(&_8$$14);
			ZEPHIR_INIT_VAR(&_9$$14);
			zephir_create_array(&_9$$14, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_9$$14, this_ptr);
			ZEPHIR_INIT_VAR(&_10$$14);
			ZVAL_STRING(&_10$$14, "quote");
			zephir_array_fast_append(&_9$$14, &_10$$14);
			ZEPHIR_CALL_FUNCTION(&_11$$14, "array_map", NULL, 2, &_9$$14, value);
			zephir_check_call_status();
			zephir_fast_join_str(&_8$$14, SL(","), &_11$$14 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(value);
			ZEPHIR_CONCAT_SVS(value, "(", &_8$$14, ")");
		} else {
			ZEPHIR_INIT_VAR(&_12$$16);
			_13$$16 = zephir_is_true(escape);
			if (_13$$16) {
				_13$$16 = !(zephir_is_numeric(value));
			}
			if (_13$$16) {
				ZEPHIR_CALL_METHOD(&_12$$16, this_ptr, "quote", NULL, 0, value);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&_12$$16, value);
			}
			ZEPHIR_CPY_WRT(value, &_12$$16);
		}
		ZEPHIR_INIT_VAR(&_14$$3);
		ZEPHIR_INIT_VAR(&_15$$3);
		ZVAL_STRING(&_15$$3, "|");
		ZEPHIR_INIT_VAR(&_16$$3);
		ZVAL_STRING(&_16$$3, "");
		zephir_fast_str_replace(&_14$$3, &_15$$3, &_16$$3, field TSRMLS_CC);
		ZEPHIR_CONCAT_VSVVV(return_value, join, " ", &_14$$3, &condition$$3, value);
		RETURN_MM();
	} else if (Z_TYPE_P(field) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&str$$17);
		ZVAL_STRING(&str$$17, "");
		zephir_is_iterable(field, 0, "sparrow/lib/sparrow.zep", 227);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(field), _18$$17, _19$$17, _17$$17)
		{
			ZEPHIR_INIT_NVAR(&key$$17);
			if (_19$$17 != NULL) { 
				ZVAL_STR_COPY(&key$$17, _19$$17);
			} else {
				ZVAL_LONG(&key$$17, _18$$17);
			}
			ZEPHIR_INIT_NVAR(&value$$17);
			ZVAL_COPY(&value$$17, _17$$17);
			ZEPHIR_CALL_METHOD(&_20$$18, this_ptr, "parsecondition", &_21, 3, &key$$17, &value$$17, &join$$17, escape);
			zephir_check_call_status();
			zephir_concat_self(&str$$17, &_20$$18 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&join$$17);
			ZVAL_STRING(&join$$17, "");
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value$$17);
		ZEPHIR_INIT_NVAR(&key$$17);
		RETURN_CTOR(&str$$17);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Invalid where condition.", "sparrow/lib/sparrow.zep", 230);
		return;
	}

}

/**
 * Sets the table.
 *
 * @param string $table Table name
 * @param boolean $reset Reset class properties
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, from) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *reset = NULL, reset_sub, __$true;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&reset_sub);
	ZVAL_BOOL(&__$true, 1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &reset);

	if (!reset) {
		reset = &reset_sub;
		reset = &__$true;
	}


	zephir_update_property_zval(this_ptr, SL("table"), table);
	if (zephir_is_true(reset)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "reset", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_THIS();

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
PHP_METHOD(Sparrow_Lib_Sparrow, join) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *fields = NULL, fields_sub, *type = NULL, type_sub, joins, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&joins);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &table, &fields, &type);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}
	if (!type) {
		type = &type_sub;
		ZEPHIR_INIT_VAR(type);
		ZVAL_STRING(type, "INNER");
	}


	ZEPHIR_INIT_VAR(&joins);
	zephir_create_array(&joins, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "INNER");
	zephir_array_fast_append(&joins, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "LEFT OUTER");
	zephir_array_fast_append(&joins, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "RIGHT OUTER");
	zephir_array_fast_append(&joins, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "FULL OUTER");
	zephir_array_fast_append(&joins, &_0);
	if (!(zephir_fast_in_array(type, &joins TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Invalid join type.", "sparrow/lib/sparrow.zep", 267);
		return;
	}
	ZVAL_NULL(&_2);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, " ON");
	ZVAL_BOOL(&_3, 0);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "parsecondition", NULL, 0, fields, &_2, &_0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSVV(&_4, " ", type, " JOIN ", table, &_1);
	zephir_update_property_zval(this_ptr, SL("joins"), &_4);
	RETURN_THIS();

}

/**
 * Adds a left table join.
 *
 * @param string $table Table to join to
 * @param array $fields Fields to join on
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, leftJoin) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *fields = NULL, fields_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &fields);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "LEFT OUTER");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, 0, table, fields, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a right table join.
 *
 * @param string $table Table to join to
 * @param array $fields Fields to join on
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, rightJoin) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *fields = NULL, fields_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &fields);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "RIGHT OUTER");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, 0, table, fields, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds a full table join.
 *
 * @param string $table Table to join to
 * @param array $fields Fields to join on
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, fullJoin) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *fields = NULL, fields_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &fields);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_INIT_VAR(fields);
		array_init(fields);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "FULL OUTER");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "join", NULL, 0, table, fields, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Sparrow_Lib_Sparrow, where) {

	zval join;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *value = NULL, value_sub, __$null, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&join);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field, &value);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_INIT_VAR(&join);
	ZVAL_STRING(&join, "");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("where"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "WHERE");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	}
	zephir_get_strval(&join, &_0);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "parsecondition", NULL, 0, field, value, &join);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("where"), &_2);
	RETURN_THIS();

}

PHP_METHOD(Sparrow_Lib_Sparrow, sortAsc) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "ASC");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "orderby", NULL, 0, field, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Sparrow_Lib_Sparrow, sortDesc) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DESC");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "orderby", NULL, 0, field, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Adds fields to order by.
 *
 * @param string $field Field name
 * @param string $direction Sort direction
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, orderBy) {

	zend_string *_4$$3;
	zend_ulong _3$$3;
	zval join, fields, _9;
	zval *field, field_sub, *direction = NULL, direction_sub, _0, _1, _7, _8, key$$3, value$$3, *_2$$3, _5$$4, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&direction_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&key$$3);
	ZVAL_UNDEF(&value$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field, &direction);

	ZEPHIR_SEPARATE_PARAM(field);
	if (!direction) {
		direction = &direction_sub;
		ZEPHIR_INIT_VAR(direction);
		ZVAL_STRING(direction, "ASC");
	}


	ZEPHIR_INIT_VAR(&join);
	ZVAL_STRING(&join, "");
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("order"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "ORDER BY");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, ",");
	}
	zephir_get_strval(&join, &_0);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		zephir_is_iterable(field, 1, "sparrow/lib/sparrow.zep", 361);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(field), _3$$3, _4$$3, _2$$3)
		{
			ZEPHIR_INIT_NVAR(&key$$3);
			if (_4$$3 != NULL) { 
				ZVAL_STR_COPY(&key$$3, _4$$3);
			} else {
				ZVAL_LONG(&key$$3, _3$$3);
			}
			ZEPHIR_INIT_NVAR(&value$$3);
			ZVAL_COPY(&value$$3, _2$$3);
			ZEPHIR_INIT_LNVAR(_5$$4);
			ZEPHIR_CONCAT_VSV(&_5$$4, &value$$3, " ", direction);
			zephir_array_update_zval(field, &key$$3, &_5$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value$$3);
		ZEPHIR_INIT_NVAR(&key$$3);
	} else {
		ZEPHIR_INIT_VAR(&_6$$5);
		ZEPHIR_CONCAT_SV(&_6$$5, " ", direction);
		zephir_concat_self(field, &_6$$5 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(&fields);
	ZVAL_STRING(&fields, "");
	ZEPHIR_INIT_VAR(&_7);
	if (Z_TYPE_P(field) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_STRING(&_8, ", ");
		ZEPHIR_INIT_NVAR(&_7);
		zephir_fast_join(&_7, &_8, field TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_7, field);
	}
	zephir_get_strval(&fields, &_7);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_VSV(&_9, &join, " ", &fields);
	zephir_update_property_zval(this_ptr, SL("order"), &_9);
	RETURN_THIS();

}

/**
 * Adds fields to group by.
 *
 * @param string|array $field Field name or array of field names
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, groupBy) {

	zval *field, field_sub, join, fields, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &field);



	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("order"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_VAR(&join);
		ZVAL_STRING(&join, "GROUP BY");
	} else {
		ZEPHIR_INIT_NVAR(&join);
		ZVAL_STRING(&join, ",");
	}
	if (Z_TYPE_P(field) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&fields);
		zephir_fast_join_str(&fields, SL(","), field TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&fields, field);
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VSV(&_1, &join, " ", &fields);
	zephir_update_property_zval(this_ptr, SL("groups"), &_1);
	RETURN_THIS();

}

/**
 * Adds having conditions.
 *
 * @param string|array $field A field name or an array of fields and values.
 * @param string $value A field value to compare to
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, having) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *value = NULL, value_sub, __$null, join, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&join);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &field, &value);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("having"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_INIT_VAR(&join);
		ZVAL_STRING(&join, "HAVING");
	} else {
		ZEPHIR_INIT_NVAR(&join);
		ZVAL_STRING(&join, "");
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "parsecondition", NULL, 0, field, value, &join);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("having"), &_1);
	RETURN_THIS();

}

/**
 * Adds a limit to the query.
 *
 * @param int $limit Number of rows to limit
 * @param int $offset Number of rows to offset
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, limit) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *limit, limit_sub, *offset = NULL, offset_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&limit_sub);
	ZVAL_UNDEF(&offset_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &limit, &offset);

	if (!offset) {
		offset = &offset_sub;
		offset = &__$null;
	}


	if (Z_TYPE_P(limit) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, "LIMIT ", limit);
		zephir_update_property_zval(this_ptr, SL("limit"), &_0$$3);
	}
	if (Z_TYPE_P(offset) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "offset", NULL, 0, offset);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Adds an offset to the query.
 *
 * @param int $offset Number of rows to offset
 * @param int $limit Number of rows to limit
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, offset) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *offset, offset_sub, *limit = NULL, limit_sub, __$null, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&limit_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &offset, &limit);

	if (!limit) {
		limit = &limit_sub;
		limit = &__$null;
	}


	if (Z_TYPE_P(offset) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_CONCAT_SV(&_0$$3, "OFFSET ", offset);
		zephir_update_property_zval(this_ptr, SL("offset"), &_0$$3);
	}
	if (Z_TYPE_P(limit) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "limit", NULL, 0, limit);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

/**
 * Sets the distinct keyword for a query.
 */
PHP_METHOD(Sparrow_Lib_Sparrow, distinct) {

	zval *value = NULL, value_sub, __$true, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &value);

	if (!value) {
		value = &value_sub;
		value = &__$true;
	}


	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(value)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "DISTINCT");
	} else {
		ZEPHIR_INIT_NVAR(&_0);
		ZVAL_STRING(&_0, "");
	}
	zephir_update_property_zval(this_ptr, SL("distinct"), &_0);
	RETURN_THIS();

}

/**
 * Sets a between where clause.
 *
 * @param string $field Database field
 * @param string $value1 First value
 * @param string $value2 Second value
 */
PHP_METHOD(Sparrow_Lib_Sparrow, between) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *value1, value1_sub, *value2, value2_sub, _0, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&value1_sub);
	ZVAL_UNDEF(&value2_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &field, &value1, &value2);



	ZEPHIR_CALL_METHOD(&_0, this_ptr, "quote", &_1, 0, value1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "quote", &_1, 0, value2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "%s BETWEEN %s AND %s");
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 4, &_3, field, &_0, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Sparrow_Lib_Sparrow, select) {

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *fields = NULL, fields_sub, *limit = NULL, limit_sub, *offset = NULL, offset_sub, __$null, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&fields_sub);
	ZVAL_UNDEF(&limit_sub);
	ZVAL_UNDEF(&offset_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &fields, &limit, &offset);

	if (!fields) {
		fields = &fields_sub;
		ZEPHIR_INIT_VAR(fields);
		ZVAL_STRING(fields, "*");
	} else {
		ZEPHIR_SEPARATE_PARAM(fields);
	}
	if (!limit) {
		limit = &limit_sub;
		limit = &__$null;
	}
	if (!offset) {
		offset = &offset_sub;
		offset = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktable", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(fields) == IS_ARRAY) {
		ZEPHIR_INIT_NVAR(&_0);
		zephir_fast_join_str(&_0, SL(","), fields TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_0, fields);
	}
	ZEPHIR_CPY_WRT(fields, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "limit", NULL, 0, limit, offset);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 12, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "SELECT");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_OBS_VAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("distinct"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_3);
	zephir_array_fast_append(&_1, fields);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "FROM");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("table"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("joins"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("where"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("groups"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("having"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("order"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("limit"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_OBS_NVAR(&_3);
	zephir_read_property(&_3, this_ptr, SL("offset"), PH_NOISY_CC);
	zephir_array_fast_append(&_1, &_3);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sql", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Builds an insert query.
 *
 * @param array $data Array of key and values to insert
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, insert) {

	zval _1, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL, data_sub, keys, values, _0, _2, _3, _4, _6, _7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&keys);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);

	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktable", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(data)) {
		RETURN_THIS();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_array_keys(&_0, data TSRMLS_CC);
	ZEPHIR_INIT_VAR(&keys);
	zephir_fast_join_str(&keys, SL(","), &_0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_1, this_ptr);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "quote");
	zephir_array_fast_append(&_1, &_2);
	ZEPHIR_CALL_FUNCTION(&_3, "array_map", NULL, 2, &_1, data);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "array_values", NULL, 5, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&values);
	zephir_fast_join_str(&values, SL(","), &_4 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "INSERT INTO");
	zephir_array_fast_append(&_5, &_2);
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("table"), PH_NOISY_CC);
	zephir_array_fast_append(&_5, &_6);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVS(&_7, "(", &keys, ")");
	zephir_array_fast_append(&_5, &_7);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "VALUES");
	zephir_array_fast_append(&_5, &_2);
	ZEPHIR_INIT_LNVAR(_7);
	ZEPHIR_CONCAT_SVS(&_7, "(", &values, ")");
	zephir_array_fast_append(&_5, &_7);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sql", NULL, 0, &_5);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Builds an update query.
 *
 * @param string|array $data Array of keys and values, or string literal
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, update) {

	zval _6$$6;
	zend_string *_2$$4;
	zend_ulong _1$$4;
	zval _7;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, values, key, value, _8, _9, *_0$$4, _3$$5, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktable", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(data)) {
		RETURN_THIS();
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		zephir_is_iterable(data, 0, "sparrow/lib/sparrow.zep", 541);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _1$$4, _2$$4, _0$$4)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_2$$4 != NULL) { 
				ZVAL_STR_COPY(&key, _2$$4);
			} else {
				ZVAL_LONG(&key, _1$$4);
			}
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_COPY(&value, _0$$4);
			ZEPHIR_INIT_LNVAR(_3$$5);
			if (zephir_is_numeric(&key)) {
				ZEPHIR_CPY_WRT(&_3$$5, &value);
			} else {
				ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "quote", &_5, 0, &value);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_3$$5);
				ZEPHIR_CONCAT_VSV(&_3$$5, &key, "=", &_4$$5);
			}
			zephir_array_append(&values, &_3$$5, PH_SEPARATE, "sparrow/lib/sparrow.zep", 539);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&value);
		ZEPHIR_INIT_NVAR(&key);
	} else {
		zephir_get_strval(&_6$$6, data);
		zephir_array_append(&values, &_6$$6, PH_SEPARATE, "sparrow/lib/sparrow.zep", 543);
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 5, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "UPDATE");
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_OBS_VAR(&_9);
	zephir_read_property(&_9, this_ptr, SL("table"), PH_NOISY_CC);
	zephir_array_fast_append(&_7, &_9);
	ZEPHIR_INIT_NVAR(&_8);
	ZVAL_STRING(&_8, "SET");
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_INIT_NVAR(&_8);
	zephir_fast_join_str(&_8, SL(","), &values TSRMLS_CC);
	zephir_array_fast_append(&_7, &_8);
	ZEPHIR_OBS_NVAR(&_9);
	zephir_read_property(&_9, this_ptr, SL("where"), PH_NOISY_CC);
	zephir_array_fast_append(&_7, &_9);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sql", NULL, 0, &_7);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Builds a delete query.
 *
 * @param array $where Where conditions
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, delete) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *where = NULL, where_sub, __$null, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&where_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &where);

	if (!where) {
		where = &where_sub;
		where = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checktable", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(where) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", NULL, 0, where);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "DELETE FROM");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("table"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_OBS_NVAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("where"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "sql", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(Sparrow_Lib_Sparrow, sql) {

	zval _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *sql = NULL, sql_sub, __$null, _0$$3, _1$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sql_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sql);

	if (!sql) {
		sql = &sql_sub;
		sql = &__$null;
	}


	if (Z_TYPE_P(sql) != IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZEPHIR_INIT_VAR(&_1$$3);
		if (Z_TYPE_P(sql) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&_2$$3);
			zephir_create_array(&_2$$3, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_2$$3, this_ptr);
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "build");
			zephir_array_fast_append(&_2$$3, &_3$$3);
			ZEPHIR_CALL_FUNCTION(&_1$$3, "array_reduce", NULL, 6, sql, &_2$$3);
			zephir_check_call_status();
		} else {
			ZEPHIR_CPY_WRT(&_1$$3, sql);
		}
		zephir_fast_trim(&_0$$3, &_1$$3, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("sql"), &_0$$3);
		RETURN_THIS();
	}
	RETURN_MM_MEMBER(getThis(), "sql");

}

/*** Database Access Methods ***/
PHP_METHOD(Sparrow_Lib_Sparrow, setDb) {

	zend_class_entry *_3$$5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *db, db_sub, __$null, type, _0$$3, _1$$4, _34$$4, _35$$4, _2$$5, _4$$5, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, _10$$6, _11$$6, _12$$6, _13$$6, str$$7, _14$$7, _15$$7, _16$$7, _17$$7, _18$$7, _19$$7, dsn$$8, _20$$8, _21$$8, _22$$8, _23$$8, _24$$8, _25$$8, _26$$8, dsn$$9, _27$$9, _28$$9, _29$$9, _30$$9, _31$$9, _32$$9, _33$$9, _36$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&db_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_34$$4);
	ZVAL_UNDEF(&_35$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&str$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&dsn$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&dsn$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_31$$9);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_33$$9);
	ZVAL_UNDEF(&_36$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &db);



	zephir_update_property_zval(this_ptr, SL("db"), &__$null);
	if (Z_TYPE_P(db) == IS_STRING) {
		ZEPHIR_CALL_METHOD(&_0$$3, this_ptr, "parseconnection", NULL, 0, db);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdb", NULL, 7, &_0$$3);
		zephir_check_call_status();
	} else if (Z_TYPE_P(db) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&_1$$4);
		zephir_array_fetch_string(&_1$$4, db, SL("type"), PH_NOISY, "sparrow/lib/sparrow.zep", 616 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_STRING(&_1$$4, "mysqli")) {
				ZEPHIR_INIT_VAR(&_2$$5);
				if (!_3$$5) {
				_3$$5 = zephir_fetch_class_str_ex(SL("Sparrow\\Lib\\mysqli"), ZEND_FETCH_CLASS_AUTO);
				}
				object_init_ex(&_2$$5, _3$$5);
				if (zephir_has_constructor(&_2$$5 TSRMLS_CC)) {
					zephir_array_fetch_string(&_4$$5, db, SL("hostname"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 619 TSRMLS_CC);
					zephir_array_fetch_string(&_5$$5, db, SL("username"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 620 TSRMLS_CC);
					zephir_array_fetch_string(&_6$$5, db, SL("password"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 621 TSRMLS_CC);
					zephir_array_fetch_string(&_7$$5, db, SL("database"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 623 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 0, &_4$$5, &_5$$5, &_6$$5, &_7$$5);
					zephir_check_call_status();
				}
				zephir_update_property_zval(this_ptr, SL("db"), &_2$$5);
				zephir_read_property(&_8$$5, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_9$$5, &_8$$5, SL("connect_error"), PH_NOISY_CC | PH_READONLY);
				if (zephir_is_true(&_9$$5)) {
					ZEPHIR_INIT_VAR(&_10$$6);
					object_init_ex(&_10$$6, zend_exception_get_default(TSRMLS_C));
					zephir_read_property(&_11$$6, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_12$$6, &_11$$6, SL("connect_error"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_INIT_VAR(&_13$$6);
					ZEPHIR_CONCAT_SV(&_13$$6, "Connection error: ", &_12$$6);
					ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", NULL, 8, &_13$$6);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_10$$6, "sparrow/lib/sparrow.zep", 626 TSRMLS_CC);
					ZEPHIR_MM_RESTORE();
					return;
				}
				break;
			}
			if (ZEPHIR_IS_STRING(&_1$$4, "pgsql")) {
				zephir_array_fetch_string(&_14$$7, db, SL("hostname"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 635 TSRMLS_CC);
				zephir_array_fetch_string(&_15$$7, db, SL("database"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 636 TSRMLS_CC);
				zephir_array_fetch_string(&_16$$7, db, SL("username"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 637 TSRMLS_CC);
				zephir_array_fetch_string(&_17$$7, db, SL("password"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 639 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_18$$7);
				ZVAL_STRING(&_18$$7, "host=%s dbname=%s user=%s password=%s");
				ZEPHIR_CALL_FUNCTION(&str$$7, "sprintf", NULL, 4, &_18$$7, &_14$$7, &_15$$7, &_16$$7, &_17$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_19$$7, "pg_connect", NULL, 0, &str$$7);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("db"), &_19$$7);
				break;
			}
			if (ZEPHIR_IS_STRING(&_1$$4, "pdomysql")) {
				zephir_array_fetch_string(&_20$$8, db, SL("hostname"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 649 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_21$$8);
				if (zephir_array_isset_string(db, SL("port"))) {
					ZEPHIR_OBS_NVAR(&_21$$8);
					zephir_array_fetch_string(&_21$$8, db, SL("port"), PH_NOISY, "sparrow/lib/sparrow.zep", 650 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(&_21$$8);
					ZVAL_LONG(&_21$$8, 3306);
				}
				zephir_array_fetch_string(&_22$$8, db, SL("database"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 652 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_23$$8);
				ZVAL_STRING(&_23$$8, "mysql:host=%s;port=%d;dbname=%s");
				ZEPHIR_CALL_FUNCTION(&dsn$$8, "sprintf", NULL, 4, &_23$$8, &_20$$8, &_21$$8, &_22$$8);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_23$$8);
				object_init_ex(&_23$$8, php_pdo_get_dbh_ce());
				zephir_array_fetch_string(&_24$$8, db, SL("username"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 654 TSRMLS_CC);
				zephir_array_fetch_string(&_25$$8, db, SL("password"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 654 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, &_23$$8, "__construct", NULL, 0, &dsn$$8, &_24$$8, &_25$$8);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("db"), &_23$$8);
				ZEPHIR_INIT_VAR(&_26$$8);
				ZVAL_STRING(&_26$$8, "pdo");
				zephir_array_update_string(db, SL("type"), &_26$$8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (ZEPHIR_IS_STRING(&_1$$4, "pdopgsql")) {
				zephir_array_fetch_string(&_27$$9, db, SL("hostname"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 663 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_28$$9);
				if (zephir_array_isset_string(db, SL("port"))) {
					ZEPHIR_OBS_NVAR(&_28$$9);
					zephir_array_fetch_string(&_28$$9, db, SL("port"), PH_NOISY, "sparrow/lib/sparrow.zep", 664 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(&_28$$9);
					ZVAL_LONG(&_28$$9, 5432);
				}
				zephir_array_fetch_string(&_29$$9, db, SL("database"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 665 TSRMLS_CC);
				zephir_array_fetch_string(&_30$$9, db, SL("username"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 666 TSRMLS_CC);
				zephir_array_fetch_string(&_31$$9, db, SL("password"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 668 TSRMLS_CC);
				ZEPHIR_INIT_VAR(&_32$$9);
				ZVAL_STRING(&_32$$9, "pgsql:host=%s;port=%d;dbname=%s;user=%s;password=%s");
				ZEPHIR_CALL_FUNCTION(&dsn$$9, "sprintf", NULL, 4, &_32$$9, &_27$$9, &_28$$9, &_29$$9, &_30$$9, &_31$$9);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_32$$9);
				object_init_ex(&_32$$9, php_pdo_get_dbh_ce());
				ZEPHIR_CALL_METHOD(NULL, &_32$$9, "__construct", NULL, 0, &dsn$$9);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("db"), &_32$$9);
				ZEPHIR_INIT_VAR(&_33$$9);
				ZVAL_STRING(&_33$$9, "pdo");
				zephir_array_update_string(db, SL("type"), &_33$$9, PH_COPY | PH_SEPARATE);
				break;
			}
		} while(0);

		zephir_read_property(&_34$$4, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_34$$4) == IS_NULL) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Undefined database.", "sparrow/lib/sparrow.zep", 678);
			return;
		}
		zephir_array_fetch_string(&_35$$4, db, SL("type"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 681 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("db_type"), &_35$$4);
	} else {
		ZEPHIR_CALL_METHOD(&type, this_ptr, "getdbtype", NULL, 0, db);
		zephir_check_call_status();
		zephir_read_property(&_36$$11, this_ptr, SL("db_types"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_fast_in_array(&type, &_36$$11 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Invalid database type.", "sparrow/lib/sparrow.zep", 687);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("db"), db);
		zephir_update_property_zval(this_ptr, SL("db_type"), &type);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Sparrow_Lib_Sparrow, quote) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, _0$$4, _1$$5, _2$$6, _3$$7, _4$$7, _5$$8, _6$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_MM_STRING("NULL");
	}
	if (Z_TYPE_P(value) == IS_STRING) {
		zephir_read_property(&_0$$4, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0$$4) != IS_NULL) {
			ZEPHIR_OBS_VAR(&_1$$5);
			zephir_read_property(&_1$$5, this_ptr, SL("db_type"), PH_NOISY_CC);
			do {
				if (ZEPHIR_IS_STRING(&_1$$5, "pdo")) {
					zephir_read_property(&_2$$6, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_RETURN_CALL_METHOD(&_2$$6, "quote", NULL, 0, value);
					zephir_check_call_status();
					RETURN_MM();
				}
				if (ZEPHIR_IS_STRING(&_1$$5, "mysqli")) {
					zephir_read_property(&_3$$7, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&_4$$7, &_3$$7, "real_escape_string", NULL, 0, value);
					zephir_check_call_status();
					ZEPHIR_CONCAT_SVS(return_value, "'", &_4$$7, "'");
					RETURN_MM();
				}
				if (ZEPHIR_IS_STRING(&_1$$5, "pgsql")) {
					zephir_read_property(&_5$$8, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_FUNCTION(&_6$$8, "pg_escape_string", NULL, 0, &_5$$8, value);
					zephir_check_call_status();
					ZEPHIR_CONCAT_SVS(return_value, "'", &_6$$8, "'");
					RETURN_MM();
				}
			} while(0);

		}
		ZEPHIR_CONCAT_SVS(return_value, "'", value, "'");
		RETURN_MM();
	}
	RETVAL_ZVAL(value, 1, 0);
	RETURN_MM();

}

/**
 * Gets the database connection.
 *
 * @return object Database connection
 */
PHP_METHOD(Sparrow_Lib_Sparrow, getDb) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "db");

}

/**
 * Gets the database type.
 *
 * @param object|resource $db Database object or resource
 * @return string Database type
 */
PHP_METHOD(Sparrow_Lib_Sparrow, getDbType) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *db, db_sub, _0$$3, _1$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&db_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &db);



	if (Z_TYPE_P(db) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_class(&_0$$3, db, 0 TSRMLS_CC);
		zephir_fast_strtolower(return_value, &_0$$3);
		RETURN_MM();
	} else if (Z_TYPE_P(db) == IS_RESOURCE) {
		ZEPHIR_CALL_FUNCTION(&_1$$4, "get_resource_type", NULL, 9, db);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_STRING(&_1$$4, "mysql link")) {
				RETURN_MM_STRING("mysql");
			}
			if (ZEPHIR_IS_STRING(&_1$$4, "pgsql link")) {
				RETURN_MM_STRING("pgsql");
			}
		} while(0);

	}
	RETURN_MM_NULL();

}

/**
 * Executes a sql statement.
 *
 * @param string $key Cache key
 * @param int $expire Expiration time in seconds
 * @return object Query results object
 * @throws Exception When database is not defined
 */
PHP_METHOD(Sparrow_Lib_Sparrow, execute) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *expire = NULL, expire_sub, __$true, __$false, __$null, result, _0, _2, _3, _8, _37, _1$$4, _4$$6, _7$$6, _5$$7, _6$$7, error$$8, _9$$8, _10$$10, _11$$10, _12$$11, _13$$12, _14$$12, _15$$12, _16$$12, _17$$13, _18$$13, _19$$14, _20$$14, _21$$16, _22$$17, _23$$17, _24$$15, _25$$15, _26$$18, _27$$18, _28$$19, _29$$20, _30$$20, _31$$20, _32$$21, _35$$21, _36$$21, _33$$22, _34$$22, time$$23, timer$$23, _38$$23, _39$$23, _40$$23, _41$$23, _42$$23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&error$$8);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$12);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$13);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&time$$23);
	ZVAL_UNDEF(&timer$$23);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_39$$23);
	ZVAL_UNDEF(&_40$$23);
	ZVAL_UNDEF(&_41$$23);
	ZVAL_UNDEF(&_42$$23);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key, &expire);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}


	zephir_read_property(&_0, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Database is not defined.", "sparrow/lib/sparrow.zep", 768);
		return;
	}
	if (Z_TYPE_P(key) != IS_NULL) {
		ZEPHIR_CALL_METHOD(&result, this_ptr, "fetchobject", NULL, 0, key);
		zephir_check_call_status();
		zephir_read_property(&_1$$4, this_ptr, SL("is_cached"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_1$$4)) {
			RETURN_CCTOR(&result);
		}
	}
	ZEPHIR_INIT_NVAR(&result);
	ZVAL_NULL(&result);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("is_cached"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("is_cached"), &__$false);
	}
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, 0);
	zephir_update_property_zval(this_ptr, SL("num_rows"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, 0);
	zephir_update_property_zval(this_ptr, SL("affected_rows"), &_2);
	ZEPHIR_INIT_ZVAL_NREF(_2);
	ZVAL_LONG(&_2, -1);
	zephir_update_property_zval(this_ptr, SL("insert_id"), &_2);
	zephir_read_property(&_2, this_ptr, SL("sql"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("last_query"), &_2);
	zephir_read_property(&_3, this_ptr, SL("stats_enabled"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_3)) {
		ZEPHIR_OBS_VAR(&_4$$6);
		zephir_read_property(&_4$$6, this_ptr, SL("stats"), PH_NOISY_CC);
		if (ZEPHIR_IS_EMPTY(&_4$$6)) {
			ZEPHIR_INIT_VAR(&_5$$7);
			array_init(&_5$$7);
			ZEPHIR_INIT_VAR(&_6$$7);
			ZVAL_STRING(&_6$$7, "queries");
			zephir_update_property_array(this_ptr, SL("stats"), &_6$$7, &_5$$7 TSRMLS_CC);
		}
		ZEPHIR_INIT_VAR(&_7$$6);
		zephir_microtime(&_7$$6, &__$true TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("query_time"), &_7$$6);
	}
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, SL("sql"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_8))) {
		ZEPHIR_INIT_VAR(&error$$8);
		ZVAL_NULL(&error$$8);
		ZEPHIR_OBS_VAR(&_9$$8);
		zephir_read_property(&_9$$8, this_ptr, SL("db_type"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_STRING(&_9$$8, "pdo")) {

				/* try_start_1: */

					zephir_read_property(&_10$$10, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_11$$10, this_ptr, SL("sql"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(&result, &_10$$10, "prepare", NULL, 0, &_11$$10);
					zephir_check_call_status_or_jump(try_end_1);
					if (zephir_is_true(&result)) {
						zephir_read_property(&_12$$11, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(&error$$8, &_12$$11, "errorinfo", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
					} else {
						ZEPHIR_CALL_METHOD(NULL, &result, "execute", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						ZEPHIR_CALL_METHOD(&_13$$12, &result, "rowcount", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_update_property_zval(this_ptr, SL("num_rows"), &_13$$12);
						ZEPHIR_CALL_METHOD(&_14$$12, &result, "rowcount", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_update_property_zval(this_ptr, SL("affected_rows"), &_14$$12);
						zephir_read_property(&_15$$12, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_CALL_METHOD(&_16$$12, &_15$$12, "lastinsertid", NULL, 0);
						zephir_check_call_status_or_jump(try_end_1);
						zephir_update_property_zval(this_ptr, SL("insert_id"), &_16$$12);
					}

				try_end_1:

				zend_clear_exception(TSRMLS_C);
				break;
			}
			if (ZEPHIR_IS_STRING(&_9$$8, "mysqli")) {
				zephir_read_property(&_17$$13, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_18$$13, this_ptr, SL("sql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&result, &_17$$13, "query", NULL, 0, &_18$$13);
				zephir_check_call_status();
				if (!zephir_is_true(&result)) {
					zephir_read_property(&_19$$14, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_20$$14, &_19$$14, SL("error"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CPY_WRT(&error$$8, &_20$$14);
				} else {
					if (Z_TYPE_P(&result) == IS_OBJECT) {
						zephir_read_property(&_21$$16, &result, SL("num_rows"), PH_NOISY_CC | PH_READONLY);
						zephir_update_property_zval(this_ptr, SL("num_rows"), &_21$$16);
					} else {
						zephir_read_property(&_22$$17, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
						zephir_read_property(&_23$$17, &_22$$17, SL("affected_rows"), PH_NOISY_CC | PH_READONLY);
						zephir_update_property_zval(this_ptr, SL("affected_rows"), &_23$$17);
					}
					zephir_read_property(&_24$$15, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					zephir_read_property(&_25$$15, &_24$$15, SL("insert_id"), PH_NOISY_CC | PH_READONLY);
					zephir_update_property_zval(this_ptr, SL("insert_id"), &_25$$15);
				}
				break;
			}
			if (ZEPHIR_IS_STRING(&_9$$8, "pgsql")) {
				zephir_read_property(&_26$$18, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_27$$18, this_ptr, SL("sql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&result, "pg_query", NULL, 0, &_26$$18, &_27$$18);
				zephir_check_call_status();
				if (!zephir_is_true(&result)) {
					zephir_read_property(&_28$$19, this_ptr, SL("db"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_FUNCTION(&error$$8, "pg_last_error", NULL, 0, &_28$$19);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_FUNCTION(&_29$$20, "pg_num_rows", NULL, 0, &result);
					zephir_check_call_status();
					zephir_update_property_zval(this_ptr, SL("num_rows"), &_29$$20);
					ZEPHIR_CALL_FUNCTION(&_30$$20, "pg_affected_rows", NULL, 0, &result);
					zephir_check_call_status();
					zephir_update_property_zval(this_ptr, SL("affected_rows"), &_30$$20);
					ZEPHIR_CALL_FUNCTION(&_31$$20, "pg_last_oid", NULL, 0, &result);
					zephir_check_call_status();
					zephir_update_property_zval(this_ptr, SL("insert_id"), &_31$$20);
				}
				break;
			}
		} while(0);

		if (Z_TYPE_P(&error$$8) != IS_NULL) {
			zephir_read_property(&_32$$21, this_ptr, SL("show_sql"), PH_NOISY_CC | PH_READONLY);
			if (zephir_is_true(&_32$$21)) {
				zephir_read_property(&_33$$22, this_ptr, SL("sql"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_INIT_VAR(&_34$$22);
				ZEPHIR_CONCAT_SV(&_34$$22, "\nSQL: ", &_33$$22);
				zephir_concat_self(&error$$8, &_34$$22 TSRMLS_CC);
			}
			ZEPHIR_INIT_VAR(&_35$$21);
			object_init_ex(&_35$$21, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(&_36$$21);
			ZEPHIR_CONCAT_SV(&_36$$21, "Database error: ", &error$$8);
			ZEPHIR_CALL_METHOD(NULL, &_35$$21, "__construct", NULL, 8, &_36$$21);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_35$$21, "sparrow/lib/sparrow.zep", 859 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property(&_37, this_ptr, SL("stats_enabled"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_37)) {
		ZEPHIR_INIT_VAR(&_38$$23);
		zephir_microtime(&_38$$23, &__$true TSRMLS_CC);
		zephir_read_property(&_39$$23, this_ptr, SL("query_time"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&time$$23);
		zephir_sub_function(&time$$23, &_38$$23, &_39$$23);
		zephir_read_property(&_39$$23, this_ptr, SL("sql"), PH_NOISY_CC | PH_READONLY);
		zephir_array_update_string(&timer$$23, SL("query"), &_39$$23, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&timer$$23, SL("time"), &time$$23, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_VAR(&_40$$23);
		zephir_read_property(&_40$$23, this_ptr, SL("num_rows"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(&_38$$23);
		ZVAL_LONG(&_38$$23, zephir_get_intval(&_40$$23));
		zephir_array_update_string(&timer$$23, SL("rows"), &_38$$23, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_VAR(&_41$$23);
		zephir_read_property(&_41$$23, this_ptr, SL("affected_rows"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(&_42$$23);
		ZVAL_LONG(&_42$$23, zephir_get_intval(&_41$$23));
		zephir_array_update_string(&timer$$23, SL("changes"), &_42$$23, PH_COPY | PH_SEPARATE);
		zephir_update_property_array_multi(this_ptr, SL("stats"), &timer$$23 TSRMLS_CC, SL("sa"), 3, SL("queries"));
	}
	RETURN_CCTOR(&result);

}

/**
 * Fetch multiple rows from a select query.
 *
 * @param string $key Cache key
 * @param int $expire Expiration time in seconds
 * @return array Rows
 */
PHP_METHOD(Sparrow_Lib_Sparrow, many) {

	zend_bool _11;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *expire = NULL, expire_sub, __$null, _0, data, result, _1, _10, _2$$4, _3$$5, _4$$5, _5$$5, _6$$6, _7$$7, _8$$7, _9$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key, &expire);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("sql"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "select", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&data);
	array_init(&data);
	ZEPHIR_CALL_METHOD(&result, this_ptr, "execute", NULL, 0, key, expire);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("is_cached"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_1)) {
		ZEPHIR_CPY_WRT(&data, &result);
		zephir_read_property(&_2$$4, this_ptr, SL("stats_enabled"), PH_NOISY_CC | PH_READONLY);
		if (zephir_is_true(&_2$$4)) {
			zephir_read_property(&_3$$5, this_ptr, SL("sql"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_4$$5, this_ptr, SL("key_prefix"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_5$$5);
			ZEPHIR_CONCAT_VV(&_5$$5, &_4$$5, key);
			zephir_update_property_array_multi(this_ptr, SL("stats"), &_3$$5 TSRMLS_CC, SL("sz"), 3, SL("cached"), &_5$$5);
		}
	} else {
		ZEPHIR_OBS_VAR(&_6$$6);
		zephir_read_property(&_6$$6, this_ptr, SL("db_type"), PH_NOISY_CC);
		do {
			if (ZEPHIR_IS_STRING(&_6$$6, "pdo")) {
				ZVAL_LONG(&_7$$7, 2);
				ZEPHIR_CALL_METHOD(&data, &result, "fetchall", NULL, 0, &_7$$7);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_8$$7, "sizeof", NULL, 10, &data);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("num_rows"), &_8$$7);
				break;
			}
			if (ZEPHIR_IS_STRING(&_6$$6, "mysqli")) {
				if ((zephir_function_exists_ex(SL("mysqli_fetch_all") TSRMLS_CC) == SUCCESS)) {
					ZVAL_LONG(&_9$$9, 1);
					ZEPHIR_CALL_METHOD(&data, &result, "fetch_all", NULL, 0, &_9$$9);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, &result, "close", NULL, 0);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_6$$6, "pgsql")) {
				ZEPHIR_CALL_FUNCTION(&data, "pg_fetch_all", NULL, 0, &result);
				zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(NULL, "pg_free_result", NULL, 0, &result);
				zephir_check_call_status();
				break;
			}
		} while(0);

	}
	zephir_read_property(&_10, this_ptr, SL("is_cached"), PH_NOISY_CC | PH_READONLY);
	_11 = !zephir_is_true(&_10);
	if (_11) {
		_11 = Z_TYPE_P(key) != IS_NULL;
	}
	if (_11) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "store", NULL, 0, key, &data, expire);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&data);

}

PHP_METHOD(Sparrow_Lib_Sparrow, one) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *expire = NULL, expire_sub, __$null, _0, data, _3, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &key, &expire);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("sql"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZVAL_LONG(&_2$$3, 1);
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "limit", NULL, 0, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "select", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "many", NULL, 0, key, expire);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	if (!(ZEPHIR_IS_EMPTY(&data))) {
		zephir_array_fetch_long(&_3, &data, 0, PH_NOISY, "sparrow/lib/sparrow.zep", 941 TSRMLS_CC);
	} else {
		array_init(&_3);
	}
	RETURN_CCTOR(&_3);

}

/**
 * Fetch a value from a field.
 *
 * @param string $name Database field name
 * @param string $key Cache key
 * @param int $expire Expiration time in seconds
 * @return mixed Row value
 */
PHP_METHOD(Sparrow_Lib_Sparrow, value) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *key = NULL, key_sub, *expire = NULL, expire_sub, __$null, row, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &name, &key, &expire);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}


	ZEPHIR_CALL_METHOD(&row, this_ptr, "one", NULL, 0, key, expire);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (!(ZEPHIR_IS_EMPTY(&row))) {
		zephir_array_fetch(&_0, &row, name, PH_NOISY, "sparrow/lib/sparrow.zep", 957 TSRMLS_CC);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Gets the min value for a specified field.
 *
 * @param string $field Field name
 * @param int $expire Expiration time in seconds
 * @param string $key Cache key
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, min) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *key = NULL, key_sub, *expire = NULL, expire_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &field, &key, &expire);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "MIN(", field, ") min_value");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "select", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "min_value");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "value", NULL, 0, &_1, key, expire);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the max value for a specified field.
 *
 * @param string $field Field name
 * @param int $expire Expiration time in seconds
 * @param string $key Cache key
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, max) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *key = NULL, key_sub, *expire = NULL, expire_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &field, &key, &expire);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "MAX(", field, ") max_value");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "select", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "max_value");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "value", NULL, 0, &_1, key, expire);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the sum value for a specified field.
 *
 * @param string $field Field name
 * @param int $expire Expiration time in seconds
 * @param string $key Cache key
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, sum) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *key = NULL, key_sub, *expire = NULL, expire_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &field, &key, &expire);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "SUM(", field, ") sum_value");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "select", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "sum_value");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "value", NULL, 0, &_1, key, expire);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets the average value for a specified field.
 *
 * @param string $field Field name
 * @param int $expire Expiration time in seconds
 * @param string $key Cache key
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, avg) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field, field_sub, *key = NULL, key_sub, *expire = NULL, expire_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &field, &key, &expire);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "AVG(", field, ") avg_value");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "select", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "avg_value");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "value", NULL, 0, &_1, key, expire);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Gets a count of records for a table.
 *
 * @param string $field Field name
 * @param string $key Cache key
 * @param int $expire Expiration time in seconds
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, count) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *field = NULL, field_sub, *key = NULL, key_sub, *expire = NULL, expire_sub, __$null, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&field_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &field, &key, &expire);

	if (!field) {
		field = &field_sub;
		ZEPHIR_INIT_VAR(field);
		ZVAL_STRING(field, "*");
	}
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVS(&_0, "COUNT(", field, ") num_rows");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "select", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "num_rows");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "value", NULL, 0, &_1, key, expire);
	zephir_check_call_status();
	RETURN_MM();

}

/*** Cache Methods ***/
PHP_METHOD(Sparrow_Lib_Sparrow, setCache) {

	zend_bool _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cache, cache_sub, __$null, _0$$3, _2$$3, _3$$4, _4$$5, _5$$6, _15$$6, _6$$7, _7$$7, _8$$7, _9$$7, _10$$8, _11$$8, _12$$8, _13$$8, _14$$9, type$$10, _16$$10, _17$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cache_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&type$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cache);



	zephir_update_property_zval(this_ptr, SL("cache"), &__$null);
	if (Z_TYPE_P(cache) == IS_STRING) {
		zephir_array_fetch_long(&_0$$3, cache, 0, PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1065 TSRMLS_CC);
		_1$$3 = ZEPHIR_IS_STRING(&_0$$3, ".");
		if (!(_1$$3)) {
			zephir_array_fetch_long(&_2$$3, cache, 0, PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1065 TSRMLS_CC);
			_1$$3 = ZEPHIR_IS_STRING(&_2$$3, "/");
		}
		if (_1$$3) {
			zephir_update_property_zval(this_ptr, SL("cache"), cache);
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_INIT_NVAR(&_3$$4);
			ZVAL_STRING(&_3$$4, "file");
			zephir_update_property_zval(this_ptr, SL("cache_type"), &_3$$4);
		} else {
			ZEPHIR_CALL_METHOD(&_4$$5, this_ptr, "parseconnection", NULL, 0, cache);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setcache", NULL, 11, &_4$$5);
			zephir_check_call_status();
		}
	} else if (Z_TYPE_P(cache) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&_5$$6);
		zephir_array_fetch_string(&_5$$6, cache, SL("type"), PH_NOISY, "sparrow/lib/sparrow.zep", 1074 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_STRING(&_5$$6, "memcache")) {
				ZEPHIR_INIT_VAR(&_6$$7);
				object_init_ex(&_6$$7, zephir_get_internal_ce(SL("memcache")));
				if (zephir_has_constructor(&_6$$7 TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				zephir_update_property_zval(this_ptr, SL("cache"), &_6$$7);
				zephir_read_property(&_7$$7, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch_string(&_8$$7, cache, SL("hostname"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1078 TSRMLS_CC);
				zephir_array_fetch_string(&_9$$7, cache, SL("port"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1080 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, &_7$$7, "connect", NULL, 0, &_8$$7, &_9$$7);
				zephir_check_call_status();
				break;
			}
			if (ZEPHIR_IS_STRING(&_5$$6, "memcached")) {
				ZEPHIR_INIT_VAR(&_10$$8);
				object_init_ex(&_10$$8, zephir_get_internal_ce(SL("memcached")));
				ZEPHIR_CALL_METHOD(NULL, &_10$$8, "__construct", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_zval(this_ptr, SL("cache"), &_10$$8);
				zephir_read_property(&_11$$8, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch_string(&_12$$8, cache, SL("hostname"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1086 TSRMLS_CC);
				zephir_array_fetch_string(&_13$$8, cache, SL("port"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1088 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, &_11$$8, "addserver", NULL, 0, &_12$$8, &_13$$8);
				zephir_check_call_status();
				break;
			}
			zephir_array_fetch_string(&_14$$9, cache, SL("type"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1092 TSRMLS_CC);
			zephir_update_property_zval(this_ptr, SL("cache"), &_14$$9);
		} while(0);

		zephir_array_fetch_string(&_15$$6, cache, SL("type"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1095 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("cache_type"), &_15$$6);
	} else if (Z_TYPE_P(cache) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_16$$10);
		zephir_get_class(&_16$$10, cache, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&type$$10);
		zephir_fast_strtolower(&type$$10, &_16$$10);
		zephir_read_property(&_17$$10, this_ptr, SL("cache_types"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_fast_in_array(&type$$10, &_17$$10 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Invalid cache type.", "sparrow/lib/sparrow.zep", 1103);
			return;
		}
		zephir_update_property_zval(this_ptr, SL("cache"), cache);
		zephir_update_property_zval(this_ptr, SL("cache_type"), &type$$10);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Gets the cache instance.
 *
 * @return object Cache instance
 */
PHP_METHOD(Sparrow_Lib_Sparrow, getCache) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cache");

}

/**
 * Stores a value in the cache.
 *
 * @param string $key Cache key
 * @param mixed $value Value to store
 * @param int $expire Expiration time in seconds
 */
PHP_METHOD(Sparrow_Lib_Sparrow, store) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, *value, value_sub, *expire = NULL, expire_sub, _0, _1, _2, _3$$3, _4$$4, _5$$4, file$$7, data$$7, _6$$7, _7$$7, _8$$7, _9$$7, _10$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&expire_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&file$$7);
	ZVAL_UNDEF(&data$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key, &value, &expire);

	ZEPHIR_SEPARATE_PARAM(key);
	if (!expire) {
		expire = &expire_sub;
		ZEPHIR_INIT_VAR(expire);
		ZVAL_LONG(expire, 0);
	}


	zephir_read_property(&_0, this_ptr, SL("key_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, key);
	ZEPHIR_CPY_WRT(key, &_1);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("cache_type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(&_2, "memcached")) {
			zephir_read_property(&_3$$3, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_3$$3, "set", NULL, 0, key, value, expire);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "memcache")) {
			zephir_read_property(&_4$$4, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZVAL_LONG(&_5$$4, 0);
			ZEPHIR_CALL_METHOD(NULL, &_4$$4, "set", NULL, 0, key, value, &_5$$4, expire);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "apc")) {
			ZEPHIR_CALL_FUNCTION(NULL, "apc_store", NULL, 12, key, value, expire);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "xcache")) {
			ZEPHIR_CALL_FUNCTION(NULL, "xcache_set", NULL, 13, key, value, expire);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_2, "file")) {
			zephir_read_property(&_6$$7, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_7$$7);
			zephir_md5(&_7$$7, key);
			ZEPHIR_INIT_VAR(&file$$7);
			ZEPHIR_CONCAT_VSV(&file$$7, &_6$$7, "/", &_7$$7);
			zephir_array_update_string(&data$$7, SL("value"), value, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_VAR(&_8$$7);
			if (ZEPHIR_GT_LONG(expire, 0)) {
				ZEPHIR_INIT_VAR(&_9$$7);
				zephir_time(&_9$$7);
				ZEPHIR_INIT_NVAR(&_8$$7);
				zephir_add_function(&_8$$7, &_9$$7, expire);
			} else {
				ZEPHIR_INIT_NVAR(&_8$$7);
				ZVAL_LONG(&_8$$7, 0);
			}
			zephir_array_update_string(&data$$7, SL("expire"), &_8$$7, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_FUNCTION(&_10$$7, "serialize", NULL, 14, &data$$7);
			zephir_check_call_status();
			zephir_file_put_contents(NULL, &file$$7, &_10$$7 TSRMLS_CC);
			break;
		}
		zephir_update_property_array(this_ptr, SL("cache"), key, value TSRMLS_CC);
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Fetches a value from the cache.
 *
 * @param string $key Cache key
 * @return mixed Cached value
 */
PHP_METHOD(Sparrow_Lib_Sparrow, fetchObject) {

	zend_bool _12$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, __$true, __$false, _0, _1, value, _2, _3$$3, _4$$4, _5$$5, _6$$6, file$$7, _7$$7, _8$$7, _9$$7, data$$8, _10$$8, _11$$8, _13$$8, _14$$8, _15$$9, _16$$11, _17$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&file$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&data$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	zephir_read_property(&_0, this_ptr, SL("key_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, key);
	ZEPHIR_CPY_WRT(key, &_1);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("cache_type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(&_2, "memcached")) {
			zephir_read_property(&_3$$3, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&value, &_3$$3, "get", NULL, 0, key);
			zephir_check_call_status();
			RETURN_CCTOR(&value);
		}
		if (ZEPHIR_IS_STRING(&_2, "memcache")) {
			zephir_read_property(&_4$$4, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&value, &_4$$4, "get", NULL, 0, key);
			zephir_check_call_status();
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&value)) {
				zephir_update_property_zval(this_ptr, SL("is_cached"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("is_cached"), &__$false);
			}
			RETURN_CCTOR(&value);
		}
		if (ZEPHIR_IS_STRING(&_2, "apc")) {
			zephir_read_property(&_5$$5, this_ptr, SL("is_cached"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_MAKE_REF(&_5$$5);
			ZEPHIR_RETURN_CALL_FUNCTION("apc_fetch", NULL, 15, key, &_5$$5);
			ZEPHIR_UNREF(&_5$$5);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&_2, "xcache")) {
			ZEPHIR_CALL_FUNCTION(&_6$$6, "xcache_isset", NULL, 16, key);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("is_cached"), &_6$$6);
			ZEPHIR_RETURN_CALL_FUNCTION("cache_get", NULL, 0, key);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&_2, "file")) {
			zephir_read_property(&_7$$7, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_8$$7);
			zephir_md5(&_8$$7, key);
			ZEPHIR_INIT_VAR(&file$$7);
			ZEPHIR_CONCAT_VSV(&file$$7, &_7$$7, "/", &_8$$7);
			zephir_read_property(&_9$$7, this_ptr, SL("is_cached"), PH_NOISY_CC | PH_READONLY);
			if (ZEPHIR_IS_FALSE(&_9$$7)) {
				ZEPHIR_INIT_VAR(&_10$$8);
				zephir_file_get_contents(&_10$$8, &file$$7 TSRMLS_CC);
				ZEPHIR_CALL_FUNCTION(&data$$8, "unserialize", NULL, 17, &_10$$8);
				zephir_check_call_status();
				zephir_array_fetch_string(&_11$$8, &data$$8, SL("expire"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1197 TSRMLS_CC);
				_12$$8 = ZEPHIR_IS_LONG(&_11$$8, 0);
				if (!(_12$$8)) {
					ZEPHIR_INIT_VAR(&_13$$8);
					zephir_time(&_13$$8);
					zephir_array_fetch_string(&_14$$8, &data$$8, SL("expire"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1197 TSRMLS_CC);
					_12$$8 = ZEPHIR_LT(&_13$$8, &_14$$8);
				}
				if (_12$$8) {
					zephir_array_fetch_string(&_15$$9, &data$$8, SL("value"), PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1198 TSRMLS_CC);
					RETURN_CTOR(&_15$$9);
				} else {
					if (0) {
						zephir_update_property_zval(this_ptr, SL("is_cached"), &__$true);
					} else {
						zephir_update_property_zval(this_ptr, SL("is_cached"), &__$false);
					}
				}
			}
			break;
		}
		zephir_read_property(&_16$$11, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_17$$11, &_16$$11, key, PH_NOISY | PH_READONLY, "sparrow/lib/sparrow.zep", 1207 TSRMLS_CC);
		RETURN_CTOR(&_17$$11);
	} while(0);

	RETURN_MM_NULL();

}

/**
 * Clear a value from the cache.
 *
 * @param string $key Cache key
 * @return object Self reference
 */
PHP_METHOD(Sparrow_Lib_Sparrow, clear) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, _0, _1, _2, _3$$3, _4$$4, file$$7, _5$$7, _6$$7, _7$$9, _8$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&file$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	zephir_read_property(&_0, this_ptr, SL("key_prefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VV(&_1, &_0, key);
	ZEPHIR_CPY_WRT(key, &_1);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("cache_type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(&_2, "memcached")) {
			zephir_read_property(&_3$$3, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_RETURN_CALL_METHOD(&_3$$3, "delete", NULL, 0, key);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&_2, "memcache")) {
			zephir_read_property(&_4$$4, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_RETURN_CALL_METHOD(&_4$$4, "delete", NULL, 0, key);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&_2, "apc")) {
			ZEPHIR_RETURN_CALL_FUNCTION("apc_delete", NULL, 18, key);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&_2, "xcache")) {
			ZEPHIR_RETURN_CALL_FUNCTION("xcache_unset", NULL, 19, key);
			zephir_check_call_status();
			RETURN_MM();
		}
		if (ZEPHIR_IS_STRING(&_2, "file")) {
			zephir_read_property(&_5$$7, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_6$$7);
			zephir_md5(&_6$$7, key);
			ZEPHIR_INIT_VAR(&file$$7);
			ZEPHIR_CONCAT_VSV(&file$$7, &_5$$7, "/", &_6$$7);
			if ((zephir_file_exists(&file$$7 TSRMLS_CC) == SUCCESS)) {
				ZEPHIR_RETURN_CALL_FUNCTION("unlink", NULL, 20, &file$$7);
				zephir_check_call_status();
				RETURN_MM();
			}
			RETURN_MM_BOOL(0);
		}
		zephir_read_property(&_7$$9, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset(&_7$$9, key)) {
			zephir_read_property(&_8$$10, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			zephir_array_unset(&_8$$10, key, PH_SEPARATE);
			RETURN_MM_BOOL(1);
		}
		RETURN_MM_BOOL(0);
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Flushes out the cache.
 */
PHP_METHOD(Sparrow_Lib_Sparrow, flush) {

	zend_bool _4$$8;
	zval _0, _1$$3, _2$$4, handle$$6, file$$6, _3$$6, _5$$9, _6$$9, _8$$10;
	zephir_fcall_cache_entry *_7 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&handle$$6);
	ZVAL_UNDEF(&file$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$9);
	ZVAL_UNDEF(&_8$$10);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("cache_type"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_STRING(&_0, "memcached")) {
			zephir_read_property(&_1$$3, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "flush", NULL, 0);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "memcache")) {
			zephir_read_property(&_2$$4, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_2$$4, "flush", NULL, 0);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "apc")) {
			ZEPHIR_CALL_FUNCTION(NULL, "apc_clear_cache", NULL, 21);
			zephir_check_call_status();
			break;
		}
		if (ZEPHIR_IS_STRING(&_0, "file")) {
			zephir_read_property(&_3$$6, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&handle$$6, "opendir", NULL, 22, &_3$$6);
			zephir_check_call_status();
			if (zephir_is_true(&handle$$6)) {
				ZEPHIR_CALL_FUNCTION(&file$$6, "readdir", NULL, 23, &handle$$6);
				zephir_check_call_status();
				while (1) {
					if (!(!ZEPHIR_IS_FALSE_IDENTICAL(&file$$6))) {
						break;
					}
					_4$$8 = !ZEPHIR_IS_STRING(&file$$6, ".");
					if (_4$$8) {
						_4$$8 = !ZEPHIR_IS_STRING(&file$$6, "..");
					}
					if (_4$$8) {
						zephir_read_property(&_5$$9, this_ptr, SL("cache"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_INIT_LNVAR(_6$$9);
						ZEPHIR_CONCAT_VSV(&_6$$9, &_5$$9, "/", &file$$6);
						ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_7, 20, &_6$$9);
						zephir_check_call_status();
					}
				}
				ZEPHIR_CALL_FUNCTION(NULL, "closedir", NULL, 24, &handle$$6);
				zephir_check_call_status();
			}
			break;
		}
		ZEPHIR_INIT_VAR(&_8$$10);
		array_init(&_8$$10);
		zephir_update_property_zval(this_ptr, SL("cache"), &_8$$10);
		break;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/*** Object Methods ***/
PHP_METHOD(Sparrow_Lib_Sparrow, using) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *_class, _class_sub, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_class_sub);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &_class);



	if (Z_TYPE_P(_class) == IS_STRING) {
		zephir_update_property_zval(this_ptr, SL("_class"), _class);
	} else if (Z_TYPE_P(_class) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_get_class(&_0$$4, _class, 0 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_class"), &_0$$4);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reset", NULL, 0);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Loads properties for an object.
 *
 * @param object $object Class instance
 * @param array $data Property data
 * @return object Populated object
 */
PHP_METHOD(Sparrow_Lib_Sparrow, load) {

	zend_string *_2;
	zend_ulong _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL;
	zval *_object, _object_sub, *data = NULL, data_sub, key, value, *_0, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_object_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &_object, &data);

	ZEPHIR_SEPARATE_PARAM(_object);
	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	}


	zephir_is_iterable(data, 0, "sparrow/lib/sparrow.zep", 1331);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(data), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_COPY(&value, _0);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "property_exists", &_4, 25, _object, &key);
		zephir_check_call_status();
		if (zephir_is_true(&_3$$3)) {
			zephir_update_property_zval_zval(_object, &key, &value TSRMLS_CC);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&value);
	ZEPHIR_INIT_NVAR(&key);
	RETVAL_ZVAL(_object, 1, 0);
	RETURN_MM();

}

/**
 * Finds and populates an object.
 *
 * @param int|string|array Search value
 * @param string $key Cache key
 * @return object Populated object
 */
PHP_METHOD(Sparrow_Lib_Sparrow, find) {

	zend_bool _2$$3, _5$$3;
	zephir_fcall_cache_entry *_13 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value = NULL, value_sub, *key = NULL, key_sub, __$null, properties, row, data, objects, _0, _1, _9, *_10, _15, _16, _3$$3, _4$$3, _6$$3, _7$$4, _8$$5, _class$$8, _11$$8, _12$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&objects);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_class$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &value, &key);

	if (!value) {
		value = &value_sub;
		value = &__$null;
	}
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "checkclass", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&properties, this_ptr, "getproperties", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, &properties, SL("table"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_1, 0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "from", NULL, 0, &_0, &_1);
	zephir_check_call_status();
	if (Z_TYPE_P(value) != IS_NULL) {
		_2$$3 = Z_TYPE_P(value) == IS_LONG;
		if (_2$$3) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "id_field");
			ZEPHIR_CALL_FUNCTION(&_4$$3, "property_exists", NULL, 25, &properties, &_3$$3);
			zephir_check_call_status();
			_2$$3 = zephir_is_true(&_4$$3);
		}
		_5$$3 = Z_TYPE_P(value) == IS_STRING;
		if (_5$$3) {
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "name_field");
			ZEPHIR_CALL_FUNCTION(&_6$$3, "property_exists", NULL, 25, &properties, &_3$$3);
			zephir_check_call_status();
			_5$$3 = zephir_is_true(&_6$$3);
		}
		if (_2$$3) {
			zephir_read_property(&_7$$4, &properties, SL("id_field"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", NULL, 0, &_7$$4, value);
			zephir_check_call_status();
		} else if (_5$$3) {
			zephir_read_property(&_8$$5, &properties, SL("name_field"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", NULL, 0, &_8$$5, value);
			zephir_check_call_status();
		} else if (Z_TYPE_P(value) == IS_ARRAY) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "where", NULL, 0, value);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_VAR(&_9);
	zephir_read_property(&_9, this_ptr, SL("sql"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_9)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "select", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&data, this_ptr, "many", NULL, 0, key);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&objects);
	array_init(&objects);
	zephir_is_iterable(&data, 0, "sparrow/lib/sparrow.zep", 1372);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&data), _10)
	{
		ZEPHIR_INIT_NVAR(&row);
		ZVAL_COPY(&row, _10);
		zephir_read_property(&_11$$8, this_ptr, SL("_class"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&_class$$8, &_11$$8);
		ZEPHIR_CALL_METHOD(&_12$$8, this_ptr, "load", &_13, 0, &_class$$8, &row);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&objects);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", &_14, 26, &objects, &_12$$8);
		ZEPHIR_UNREF(&objects);
		zephir_check_call_status();
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&row);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CALL_FUNCTION(&_16, "sizeof", NULL, 10, &objects);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_16, 1)) {
		zephir_array_fetch_long(&_15, &objects, 0, PH_NOISY, "sparrow/lib/sparrow.zep", 1372 TSRMLS_CC);
	} else {
		ZEPHIR_CPY_WRT(&_15, &objects);
	}
	RETURN_CCTOR(&_15);

}

/**
 * Saves an object to the database.
 *
 * @param object $object Class instance
 * @param array $fields Select database fields to save
 */
PHP_METHOD(Sparrow_Lib_Sparrow, getProperties) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$null, properties, _0, _1, _5, _6, defaults$$4, reflection$$4, config$$4, _2$$4, _3$$4, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&defaults$$4);
	ZVAL_UNDEF(&reflection$$4);
	ZVAL_UNDEF(&config$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&properties);
	array_init(&properties);
	zephir_read_property(&_0, this_ptr, SL("_class"), PH_NOISY_CC | PH_READONLY);
	if (!zephir_is_true(&_0)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_read_property(&_1, this_ptr, SL("_class"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&properties, &_1))) {
		zephir_array_update_string(&defaults$$4, SL("table"), &__$null, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&defaults$$4, SL("id_field"), &__$null, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&defaults$$4, SL("name_field"), &__$null, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&reflection$$4);
		object_init_ex(&reflection$$4, zephir_get_internal_ce(SL("reflectionclass")));
		zephir_read_property(&_2$$4, this_ptr, SL("_class"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &reflection$$4, "__construct", NULL, 27, &_2$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&config$$4, &reflection$$4, "getstaticproperties", NULL, 28);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_fast_array_merge(&_3$$4, &defaults$$4, &config$$4 TSRMLS_CC);
		zephir_convert_to_object(&_3$$4);
		ZEPHIR_OBS_VAR(&_4$$4);
		zephir_read_property(&_4$$4, this_ptr, SL("_class"), PH_NOISY_CC);
		zephir_array_update_zval(&properties, &_4$$4, &_3$$4, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_OBS_VAR(&_5);
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("_class"), PH_NOISY_CC);
	zephir_array_fetch(&_5, &properties, &_6, PH_NOISY, "sparrow/lib/sparrow.zep", 1461 TSRMLS_CC);
	zephir_convert_to_object(&_5);
	RETURN_CCTOR(&_5);

}

zend_object *zephir_init_properties_Sparrow_Lib_Sparrow(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("err_message"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("err_message"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("stats"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("stats"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

