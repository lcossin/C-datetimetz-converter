@@parameters.sql

prompt create the schema that owns the external library

create user &lib_owner. identified externally;
alter user &lib_owner. account lock;
grant create library to &lib_owner.;

prompt create the schema that owns the PLSQL API

create user &pkg_owner. identified externally;
alter user &pkg_owner. account lock;
grant create procedure to &pkg_owner.;
