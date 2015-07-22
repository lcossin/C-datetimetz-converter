
CREATE OR REPLACE PACKAGE TZCONVERTER_DEMO AS
	
	procedure demo;

	procedure demo_wrongval;
	
END TZCONVERTER_DEMO;
/

show errors;
	
CREATE OR REPLACE PACKAGE BODY TZCONVERTER_DEMO AS 
	
	procedure demo
	IS
		v_in	VARCHAR2(255) ;
		v_val1 VARCHAR2(255) := '2015-10-25 02:01:00';
		v_val2 VARCHAR2(255) := '2015-10-25T02:01:00';
		v_tz1 VARCHAR2(255) := 'Europe/Berlin';
		v_tz2 VARCHAR2(255) := 'UTC';
		v_res VARCHAR2(255) := '';
		v_rc	BINARY_INTEGER;	
	BEGIN
		v_in := TZCONVERTER_FORMAT.FixupToISO8601(v_val1);
		v_rc := TZCONVERTER.CConvertISO8601TZToTZ(v_in, v_res, v_tz1, v_tz2);
		v_res := TZCONVERTER_FORMAT.FixupFromISO8601(v_res, v_val1, v_in);
		dbms_output.put_line('res : '||v_res||' retcode='||v_rc);

		v_in := TZCONVERTER_FORMAT.FixupToISO8601(v_val2);
		v_rc := TZCONVERTER.CConvertISO8601TZToTZ(v_in, v_res, v_tz1, v_tz2);
		v_res := TZCONVERTER_FORMAT.FixupFromISO8601(v_res, v_val2, v_in);
		dbms_output.put_line('res : '||v_res||' retcode='||v_rc);

	END demo;

	procedure demo_wrongval
	IS
		v_in	VARCHAR2(255) ;
		v_val1 VARCHAR2(255) := '2015-03-29 02:01:00';
		v_val2 VARCHAR2(255) := '2015-03-29T02:01:00';
		v_tz1 VARCHAR2(255) := 'Europe/Berlin';
		v_tz2 VARCHAR2(255) := 'UTC';
		v_res VARCHAR2(255) := '';
		v_rc	BINARY_INTEGER;	
	BEGIN
		v_in := TZCONVERTER_FORMAT.FixupToISO8601(v_val1);
		v_rc := TZCONVERTER.CConvertISO8601TZToTZ(v_in, v_res, v_tz1, v_tz2);
		v_res := TZCONVERTER_FORMAT.FixupFromISO8601(v_res, v_val1, v_in);
		dbms_output.put_line('res : '||v_res||' retcode='||v_rc);

		v_in := TZCONVERTER_FORMAT.FixupToISO8601(v_val2);
		v_rc := TZCONVERTER.CConvertISO8601TZToTZ(v_in, v_res, v_tz1, v_tz2);
		v_res := TZCONVERTER_FORMAT.FixupFromISO8601(v_res, v_val2, v_in);
		dbms_output.put_line('res : '||v_res||' retcode='||v_rc);

	END demo_wrongval;
	
END TZCONVERTER_DEMO;
/

show errors;

prompt some tests

prompt first OK
set serveroutput on size unlimited
exec &tests_owner..TZCONVERTER_DEMO.demo;

prompt second FAILED
set serveroutput on size unlimited
exec &tests_owner..TZCONVERTER_DEMO.demo_wrongval;

prompt third OK
set serveroutput on size unlimited
exec &tests_owner..TZCONVERTER_DEMO.demo;
