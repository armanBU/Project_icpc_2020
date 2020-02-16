--Part A--

--authors table creation--

create table authors(
author_id number(11) primary key,
author_name varchar2(255),
author_address varchar2(255)
);

create sequence auto_inc_author start with 1 increment by 1;
create or replace TRIGGER author_trigger
  BEFORE INSERT ON authors
  for each row
BEGIN
  select auto_inc_author.nextval
  into :new.author_id
  from dual;
END;

--insert into author table--
--select * from authors;
--drop table authors;
insert into authors values(null, 'Kazi Nazrul', 'A');
insert into authors values(null, 'Rabindranath Tagur', 'B');
insert into authors values(null, 'Jasim-Uddin', 'C');
insert into authors values(null, 'Shakespeer', 'D');
insert into authors values(null, 'Humayun Ahmed', 'E');

--publisher table creation--

create table publisher(
publisher_id number(11) primary key,
publisher_name varchar2(255),
publisher_address varchar2(255)
);

create sequence auto_inc_publisher start with 1 increment by 1;
create or replace TRIGGER publisher_trigger
  BEFORE INSERT ON publisher
  for each row
BEGIN
  select auto_inc_publisher.nextval
  into :new.publisher_id
  from dual;
END;
--select * from publisher;
--insert into publisher table--

insert into publisher values(null, 'sakib', 'Mongla');
insert into publisher values(null, 'Taha', 'Khulna');
insert into publisher values(null, 'protap', 'Rajshahi');
insert into publisher values(null, 'Armaan', 'Satkhira');
insert into publisher values(null, 'Amir', 'Barishal');
--select * from publisher;

--borrowers table creation--

create table borrowers(
borrower_id number(11) primary key,
firstname varchar2(255),
lastname varchar2(255),
address varchar2(255),
email varchar2(255),
phone varchar2(255),
department varchar2(255)
);

create sequence auto_inc_borrower start with 1 increment by 1;

create or replace TRIGGER borrower_trigger
  BEFORE INSERT ON borrowers
  for each row
BEGIN
  select auto_inc_borrower.nextval
  into :new.borrower_id
  from dual;
END;

--insert into borrowers table--
insert into borrowers values(null, 'amantu', 'Amir', 'Barishal', 'amir.cse4.bu@gmail.com', '01728 245789', 'Computer Science and Engineering');
insert into borrowers values(null, 'Taha', 'Hussain', 'Khulna', 't.cse4.bu@gmail.com', '01728 787698', 'Computer Science and Engineering');
insert into borrowers values(null, 'Sarwar', 'Hossain', 'Rajshahi', 's.cse4.bu@gmail.com', '01728 123456', 'Computer Science and Engineering');
insert into borrowers values(null, 'Armaan', 'Ali', 'Satkhira', 'a.cse4.bu@gmail.com', '01728 678900', 'Computer Science and Engineering');

--select * from borrowers;
--books table creation--

create table books( 
book_id number(11) primary key, 
book_title varchar2(255),
no_of_copies number(11),
author_id number(11), 
publisher_id number(11), 
FOREIGN KEY(author_id) REFERENCES authors(author_id), 
FOREIGN KEY(publisher_id) REFERENCES publisher(publisher_id) 
);

create sequence auto_inc_book start with 1 increment by 1;

create or replace TRIGGER book_trigger
  BEFORE INSERT ON books
  for each row
BEGIN
  select auto_inc_book.nextval
  into :new.book_id
  from dual;
END;

--insert into books table--

insert into books values(null, 'C++', '4', 21, 1);
insert into books values(null, 'C Programming', '4', 22, 2);
insert into books values(null, 'Python', '3', 23, 3);
insert into books values(null, 'Java', '3', 24, 4);
insert into books values(null, 'c#', '10', 4, 4);
--select * from books;
--booking table creation--

create table booking( 
booking_id number(11) primary key, 
booking_date date,
available_date date,
book_id number(11), 
borrower_id number(11), 
FOREIGN KEY(book_id) REFERENCES books(book_id), 
FOREIGN KEY(borrower_id) REFERENCES borrowers(borrower_id) 
);

create sequence auto_inc_booking start with 1 increment by 1;

create or replace TRIGGER booking_trigger
  BEFORE INSERT ON booking
  for each row
BEGIN
  select auto_inc_booking.nextval
  into :new.booking_id
  from dual;
END;

--insert into booking table--
--select * from booking;
insert into booking values(null, to_date('12/02/2020', 'dd/mm/yyyy'), to_date('17/02/2020', 'dd/mm/yyyy'), 51, 1);
insert into booking values(null, to_date('12/02/2020', 'dd/mm/yyyy'), to_date('17/02/2020', 'dd/mm/yyyy'), 52, 2);
insert into booking values(null, to_date('12/02/2020', 'dd/mm/yyyy'), to_date('17/02/2020', 'dd/mm/yyyy'), 53, 3);
insert into booking values(null, to_date('12/02/2020', 'dd/mm/yyyy'), to_date('17/02/2020', 'dd/mm/yyyy'), 54, 4);
insert into booking values(null, to_date('12/02/2020', 'dd/mm/yyyy'), to_date('17/02/2020', 'dd/mm/yyyy'), 55, 4);
--select * from booking;
--borrow_book table creation--

create table borrow_book( 
borrow_book_id number(11) primary key, 
borrowing_date date,
due_date date,
book_id number(11), 
borrower_id number(11), 
FOREIGN KEY(book_id) REFERENCES books(book_id), 
FOREIGN KEY(borrower_id) REFERENCES borrowers(borrower_id) 
);

create sequence auto_inc_borrow_book start with 1 increment by 1;

create or replace TRIGGER borrow_book_trigger
  BEFORE INSERT ON borrow_book
  for each row
BEGIN
  select auto_inc_borrow_book.nextval
  into :new.borrow_book_id
  from dual;
END;
--select * from dual;

--insert into borrow_book table--

insert into borrow_book values(null, to_date('17/02/2020', 'dd/mm/yyyy'), to_date('20/02/2020', 'dd/mm/yyyy'), 51, 1);
insert into borrow_book values(null, to_date('17/02/2020', 'dd/mm/yyyy'), to_date('20/02/2020', 'dd/mm/yyyy'), 52, 2);
insert into borrow_book values(null, to_date('17/02/2020', 'dd/mm/yyyy'), to_date('20/02/2020', 'dd/mm/yyyy'), 53, 3);
insert into borrow_book values(null, to_date('17/02/2020', 'dd/mm/yyyy'), to_date('20/02/2020', 'dd/mm/yyyy'), 54, 4);
insert into borrow_book values(null, to_date('17/02/2020', 'dd/mm/yyyy'), to_date('20/02/2020', 'dd/mm/yyyy'), 55, 4);
--select * from borrow_book;

--Part B--

--Query 1--
     select * from borrowers;
--Query 2--
     select b.book_title as Title, auth.author_name as Author, pub.name from books b
        INNER JOIN authors auth On auth.author_id = b.author_id 
        INNER JOIN publisher pub on pub.publisher_id = b.publisher_id;

--Query 3--
        SELECT DISTINCT(b.book_title) FROM books b
        INNER JOIN borrow_book bb ON 
        bb.book_id = b.book_id;
--Query 4--
        SELECT b.* 
        FROM books b,authors
        where b.author_id = authors.author_id AND authors.author_name='Kazi Nazrul';

--Query 5--
        SELECT * FROM authors
        WHERE author_name LIKE 'M%'
        OR author_name LIKE 'S%'
        OR author_name LIKE 'R%'
--Query 6--
    SELECT borrowers.borrower_id,borrowers.firstname,borrowers.address,borrowers.phone,borrowers.email
FROM borrowers borrowers, borrow_book 
WHERE borrowers.borrower_id = library_borrow_book.borrower_id
GROUP by borrowers.borrower_id,borrowers.firstname,borrowers.address,borrowers.phone,borrowers.email,borrow_book.borrower_id
HAVING COUNT() >= ALL ( SELECT COUNT() FROM borrow_book GROUP BY borrower_id );
--Query 7--

SELECT DISTINCT borrowers.*
From borrowers borrowers, borrow_book borrow
where borrowers.borrower_id=borrow.borrower_id;

--Query 8--

--Query 9--
    --set serveroutput on
    CREATE OR REPLACE PROCEDURE  Author_Details
    (id number)
    IS
       tm authors%ROWTYPE;
    BEGIN
        SELECT a.* INTO tm
        FROM authors a,books b
        where a.author_id = b.author_id AND b.book_id=id;
        dbms_output.put_line( tm.author_name || ' ' ||
         tm.author_address );
    END;
    EXECUTE Author_Details(51);
    
--Query 10--

--Query 11--
    CREATE OR REPLACE VIEW borrower_list as 
    select CONCAT(bor.firstname,bor.lastname) as Bor_NAME ,b.book_title as BOOK_title ,cc.booking_date  as B_Date
    FROM booking cc, books b,borrowers bor
    where cc.book_id=b.book_id and cc.borrower_id=bor.borrower_id;
    select * from borrower_list;

--Query 12(a)--

--Query 12(b)--

--Query 13--
select * from ( 
	select * from borrow_book order by borrow_book_id asc 
) where rownum <=3;

--Query 14--
SELECT * FROM (
    SELECT * FROM borrowers ORDER BY borrower_id DESC
) WHERE ROWNUM = 1;

--Part C--
CREATE OR REPLACE PROCEDURE  Primality_TEST
    (id number)
    IS
       ck number:=0;
    BEGIN
         for i in 2..id/2 
             loop 
                 if mod(id, i) = 0 
                    then
                         ck := 1; 
                         exit; 
                 end if; 
            end loop;
        if ck=0
        then 
            dbms_output.put_line( id || ' is Prime ' );
        else 
           dbms_output.put_line( id || ' is not Prime ' );
        end if; 
    END;
    EXECUTE Primality_TEST(11);
    
    CREATE OR REPLACE FUNCTION  Primality
    (id number)
    RETURN varchar2
    IS
       ck number:=0;st varchar2(100);
    BEGIN
         for i in 2..id/2 
             loop 
                 if mod(id, i) = 0 
                    then
                         ck := 1; 
                         exit; 
                 end if; 
            end loop;
        if ck=0
        then 
            st:='Prime';
        else 
           st:='Not Prime';
        end if; 
        return st;
    END;
    EXECUTE Primality_TEST(11);
    select author_id as ID,EXECUTE Primality(author_id) as primality 
    from authors;
    
