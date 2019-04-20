create table documents(
  document_id int(11) not null auto_increment primary key,
  url varchar(200),
  title varchar(200),
  publication_date date,
  modified_date date,
  author varchar(200),
  publisher varchar(40),
  notes varchar(2000),
  unique key url(`url`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
