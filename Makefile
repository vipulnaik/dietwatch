MYSQL_ARGS=
DATABASE=dietwatch

.PHONY: init
init:
	mysql $(MYSQL_ARGS) -e "create database $(DATABASE);"

.PHONY: reset
reset:
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists documents;"
	mysql $(MYSQL_ARGS) -e "use $(DATABASE); drop table if exists people;"

.PHONY: read
read:
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/documents-schema.sql
	mysql $(MYSQL_ARGS) $(DATABASE) < sql/documents/documents.sql
