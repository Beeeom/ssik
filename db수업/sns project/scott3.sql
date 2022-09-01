drop table user_table;
CREATE TABLE user_table
(
user_num int PRIMARY key,
user_id VARCHAR2(30) UNIQUE,
user_pass VARCHAR2(30) not null,
user_nickname VARCHAR2(30) unique ,
user_name VARCHAR2(30) not null,
user_birth VARCHAR2(20) not null,
user_phonenum VARCHAR2(15) unique not null,
user_mail VARCHAR2(50) unique not null,
user_regdate date not null,
user_profilfile varchar2(200),
user_profilfileroute varchar2(50),
post_count int,
comment_count int,
like_count int,
following_count int,
follower_count int,
gender varchar2(6),
FOREIGN KEY (gender) REFERENCES gender_table(gender)

);
drop table gender_table;
CREATE table gender_table
(
gender varchar2(6) primary key,
gendertype VARCHAR2(20) UNIQUE not null

);
drop table Favoritefield_table;
create table Favoritefield_table
(
Favoritefield_num int primary key,
Favoritefield_hobby varchar2(50) unique not null
);

drop table post_table;
create table post_table
(
post_num int PRIMARY key,
create_at TIMESTAMP not null,
post_name varchar2(50) not null,
post_content varchar2(250) not null,
tag_content varchar2(250),
location varchar2(250),
post_commentcount int,
post_like int,
user_id varchar2(30),
FOREIGN KEY (user_id) REFERENCES user_table(user_id)
);
drop table comment_table;
create table comment_table
(
comment_num int primary key,
comment_reg_time varchar2(30) not null,
comment_content varchar2(200),
user_id VARCHAR2(30),
post_num int,
FOREIGN KEY (user_id) REFERENCES user_table(user_id),
FOREIGN KEY (post_num) REFERENCES post_table(post_num)
);

insert into gender_table values (1,'m');
insert into gender_table values (2,'f');
insert into gender_table values (3,'?');

SELECT * from gender_table;

