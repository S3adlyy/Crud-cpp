--------------------------------------------------------
--  File created - Thursday-February-27-2025   
--------------------------------------------------------
--------------------------------------------------------
--  DDL for Table ETABLISSEMENT
--------------------------------------------------------

  CREATE TABLE "SENTRA"."ETABLISSEMENT" 
   (	"ID" NUMBER GENERATED ALWAYS AS IDENTITY MINVALUE 1 MAXVALUE 9999999999999999999999999999 INCREMENT BY 1 START WITH 1 CACHE 20 NOORDER  NOCYCLE  NOKEEP  NOSCALE , 
	"ETABLISMENT_NAME" VARCHAR2(50 BYTE), 
	"CODEPOSTAL" NUMBER, 
	"REGION" VARCHAR2(50 BYTE), 
	"PROVINCE" VARCHAR2(50 BYTE), 
	"EMAIL" VARCHAR2(150 BYTE), 
	"PHONE_NUMBRE" NUMBER, 
	"DIRECTEUR" VARCHAR2(50 BYTE), 
	"NOMBRE_OF_ROOMS" NUMBER
   ) SEGMENT CREATION IMMEDIATE 
  PCTFREE 10 PCTUSED 40 INITRANS 1 MAXTRANS 255 
 NOCOMPRESS LOGGING
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1
  BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
REM INSERTING into SENTRA.ETABLISSEMENT
SET DEFINE OFF;
Insert into SENTRA.ETABLISSEMENT (ID,ETABLISMENT_NAME,CODEPOSTAL,REGION,PROVINCE,EMAIL,PHONE_NUMBRE,DIRECTEUR,NOMBRE_OF_ROOMS) values (4,'grand',7000,'bizerte','northtunisie','grandlycee@gmail.com',94193305,'wassim',142);
--------------------------------------------------------
--  DDL for Index SYS_C008455
--------------------------------------------------------

  CREATE UNIQUE INDEX "SENTRA"."SYS_C008455" ON "SENTRA"."ETABLISSEMENT" ("ID") 
  PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1
  BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS" ;
--------------------------------------------------------
--  Constraints for Table ETABLISSEMENT
--------------------------------------------------------

  ALTER TABLE "SENTRA"."ETABLISSEMENT" MODIFY ("ID" NOT NULL ENABLE);
  ALTER TABLE "SENTRA"."ETABLISSEMENT" MODIFY ("ETABLISMENT_NAME" NOT NULL ENABLE);
  ALTER TABLE "SENTRA"."ETABLISSEMENT" MODIFY ("CODEPOSTAL" NOT NULL ENABLE);
  ALTER TABLE "SENTRA"."ETABLISSEMENT" MODIFY ("REGION" NOT NULL ENABLE);
  ALTER TABLE "SENTRA"."ETABLISSEMENT" MODIFY ("PROVINCE" NOT NULL ENABLE);
  ALTER TABLE "SENTRA"."ETABLISSEMENT" MODIFY ("EMAIL" NOT NULL ENABLE);
  ALTER TABLE "SENTRA"."ETABLISSEMENT" MODIFY ("PHONE_NUMBRE" NOT NULL ENABLE);
  ALTER TABLE "SENTRA"."ETABLISSEMENT" MODIFY ("DIRECTEUR" NOT NULL ENABLE);
  ALTER TABLE "SENTRA"."ETABLISSEMENT" MODIFY ("NOMBRE_OF_ROOMS" NOT NULL ENABLE);
  ALTER TABLE "SENTRA"."ETABLISSEMENT" ADD PRIMARY KEY ("ID")
  USING INDEX PCTFREE 10 INITRANS 2 MAXTRANS 255 
  STORAGE(INITIAL 65536 NEXT 1048576 MINEXTENTS 1 MAXEXTENTS 2147483645
  PCTINCREASE 0 FREELISTS 1 FREELIST GROUPS 1
  BUFFER_POOL DEFAULT FLASH_CACHE DEFAULT CELL_FLASH_CACHE DEFAULT)
  TABLESPACE "USERS"  ENABLE;
