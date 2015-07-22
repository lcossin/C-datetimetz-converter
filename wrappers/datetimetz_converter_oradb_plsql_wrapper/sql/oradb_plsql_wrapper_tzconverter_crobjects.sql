@@parameters.sql

prompt create the library

alter session set current_schema=&lib_owner.;

create or replace library &lib_objname. as '&lib_so.'
/

grant execute on &lib_owner..&lib_objname. to &pkg_owner.;


prompt create the PLSQL objects

alter session set current_schema=&pkg_owner.;

@@oradb_plsql_wrapper_tzconverter_pkgspec.sql

@@oradb_plsql_wrapper_tzconverter_pkgbody.sql

alter session set current_schema=&tests_owner.;

@@oradb_plsql_wrapper_tzconverter_demo.sql
