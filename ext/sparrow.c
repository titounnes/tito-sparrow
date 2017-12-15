
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "sparrow.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *sparrow_lib_sparrow_ce;

ZEND_DECLARE_MODULE_GLOBALS(sparrow)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(sparrow)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Sparrow_Lib_Sparrow);
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(sparrow)
{
	zephir_deinitialize_memory(TSRMLS_C);
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_sparrow_globals *sparrow_globals TSRMLS_DC)
{
	sparrow_globals->initialized = 0;

	/* Memory options */
	sparrow_globals->active_memory = NULL;

	/* Virtual Symbol Tables */
	sparrow_globals->active_symbol_table = NULL;

	/* Cache Enabled */
	sparrow_globals->cache_enabled = 1;

	/* Recursive Lock */
	sparrow_globals->recursive_lock = 0;

	/* Static cache */
	memset(sparrow_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);


}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_sparrow_globals *sparrow_globals TSRMLS_DC)
{

}

static PHP_RINIT_FUNCTION(sparrow)
{

	zend_sparrow_globals *sparrow_globals_ptr;
#ifdef ZTS
	tsrm_ls = ts_resource(0);
#endif
	sparrow_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(sparrow_globals_ptr TSRMLS_CC);
	zephir_initialize_memory(sparrow_globals_ptr TSRMLS_CC);


	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(sparrow)
{
	
	zephir_deinitialize_memory(TSRMLS_C);
	return SUCCESS;
}

static PHP_MINFO_FUNCTION(sparrow)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_SPARROW_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_SPARROW_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_SPARROW_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_SPARROW_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_SPARROW_ZEPVERSION);
	php_info_print_table_end();

	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(sparrow)
{
	php_zephir_init_globals(sparrow_globals TSRMLS_CC);
	php_zephir_init_module_globals(sparrow_globals TSRMLS_CC);
}

static PHP_GSHUTDOWN_FUNCTION(sparrow)
{

}


zend_function_entry php_sparrow_functions[] = {
ZEND_FE_END

};

zend_module_entry sparrow_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	NULL,
	PHP_SPARROW_EXTNAME,
	php_sparrow_functions,
	PHP_MINIT(sparrow),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(sparrow),
#else
	NULL,
#endif
	PHP_RINIT(sparrow),
	PHP_RSHUTDOWN(sparrow),
	PHP_MINFO(sparrow),
	PHP_SPARROW_VERSION,
	ZEND_MODULE_GLOBALS(sparrow),
	PHP_GINIT(sparrow),
	PHP_GSHUTDOWN(sparrow),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_SPARROW
ZEND_GET_MODULE(sparrow)
#endif
