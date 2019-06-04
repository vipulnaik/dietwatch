create table documents(
  document_id int(11) not null auto_increment primary key,
  url varchar(200),
  title varchar(200),
  publication_date date,
  modified_date date,
  author varchar(200),
  publisher varchar(40),
  other_participants_or_mentioned_people varchar(2000),
  tags varchar(2000), /* Pipe-separated list taking values from "Animal consciousness", "Animal harm per unit food consumption", "Personal journey", "Exhortation against animal consumption", "Dealing with moral uncertainty", "Skepticism of case for vegetarianism", "Health effects of veganism", "Practical vegan and vegetarian food advice"
  notes varchar(2000),
  unique key url(`url`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;
