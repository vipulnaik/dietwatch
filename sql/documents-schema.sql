create table documents(
  document_id int(11) not null auto_increment primary key,
  url varchar(200),
  title varchar(200),
  publication_date date,
  modified_date date,
  author varchar(200),
  publisher varchar(40),
  other_participants_and_mentioned_people varchar(2000),
  tags varchar(2000), /* Pipe-separated list taking values from "Animal consciousness", "Animal harm per unit food consumption", "Personal journey", "Exhortation against animal consumption", "Dealing with moral uncertainty", "Skepticism of case for vegetarianism", "Health effects of veganism", "Practical vegan and vegetarian food advice", "Skepticism of advocacy" */
  animal_types varchar(200), /* Pipe-separated list taking values from "Fish", "Insect", "Bivalve", "Poultry", "Cattle", "Pig" */
  people_clusters varchar(2000), /* Effective altruist, Libertarian, Negative utilitarian, Tomasik, Caplan, Hanson */
  notes varchar(2000),
  unique key url(`url`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
