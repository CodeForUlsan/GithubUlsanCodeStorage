/*
버전관리 로그
!!!변경후에는 반드시 로그를 수정해주십시오!!!
로그 규칙 - 앞에는 수정한 날자가 들어갑니다. 날자뒤에 붙는 Revision은 해당일 첫번째 판올림의 경우 숫자 1을 두번째일 경우엔 숫자 2를 붙여주시면 됩니다.
ex)2018년 12월 21일 첫번째 개정판 - 2018.12.21.Revision1, 2018년 12월 21일 두번째 개정판 - 2018.12.21.Revision2
2018.12.21.Revision1
*/

--강원도 테이블
create table Gangwon(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--경기도 테이블
create table Gyeonggi(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--경상남도 테이블
create table Gyeongsangnam(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--경상북도 테이블
create table Gyeongsangbuk(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--광주광역시 테이블
create table Gwangju(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--대구광역시 테이블
create table Daegu(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--대전광역시 테이블
create table Daejeon(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--부산광역시 테이블
create table Busan(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--서울특별시 테이블
create table Seoul(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--세종특별자치시 테이블
create table Sejong(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--울산광역시 테이블
create table Ulsan(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--인천광역시 테이블
create table Incheon(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--전라남도 테이블
create table Jeollanam(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--전라북도 테이블
create table Jeollabuk(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--제주특별자치도 테이블
create table Jeju(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--충청남도 테이블
create table Chungcheongnam(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);
--충청북도 테이블
create table Chungcheongbuk(
	zipcode varchar(30),
	city varchar(50),
	cityEng varchar(50),
	country varchar(50),
	countryEng varchar(50),
	town varchar(50),
	townEng varchar(50),
	roadName varchar(50),
	roadNameEng varchar(50),
	buildNumberMain varchar(10),
	buildNumbersub varchar(10),
	deliveryName varchar(50),
	buildName varchar(50),
	villageName varchar(50),
	subTown varchar(50),
	lotNumberMain varchar(10),
	lotNumberSub varchar(10)
);

--테이블 전체 보기
select * from sqlite_master;

--테이블 삭제
--drop table Gangwon;
--drop table Gyeonggi;
--drop table Gyeongsangnam;
--drop table Gyeongsangbuk;
--drop table Gwangju;
--drop table Daegu;
--drop table Daejeon;
--drop table Busan;
--drop table Seoul;
--drop table Sejong;
--drop table Ulsan;
--drop table Incheon;
--drop table Jeollanam;
--drop table Jeollabuk;
--drop table Jeju;
--drop table Chungcheongnam;
--drop table Chungcheongbuk;

--테이블 전체 조회
select * from Gangwon;
select * from Gyeonggi;
select * from Gyeongsangnam;
select * from Gyeongsangbuk;
select * from Gwangju;
select * from Daegu;
select * from Daejeon;
select * from Busan;
select * from Seoul;
select * from Sejong;
select * from Ulsan;
select * from Incheon;
select * from Jeollanam;
select * from Jeollabuk;
select * from Jeju;
select * from Chungcheongnam;
select * from Chungcheongbuk;

--각 테이블별 레코드 전체 삭제
--delete from Gangwon;
--delete from Gyeonggi;
--delete from Gyeongsangnam;
--delete from Gyeongsangbuk;
--delete from Gwangju;
--delete from Daegu;
--delete from Daejeon;
--delete from Busan;
--delete from Seoul;
--delete from Sejong;
--delete from Ulsan;
--delete from Incheon;
--delete from Jeollanam;
--delete from Jeollabuk;
--delete from Jeju;
--delete from Chungcheongnam;
--delete from Chungcheongbuk;


--검색 조건문들
select * from uszip where city = '울산광역시' and country = '남구' and villageName = '달동';

select * from uszip where city like '울산%';

select count(*) from gangwon;

select * from Ulsan where country = '남구' and villageName like '%달동%';

select distinct(country) from Daegu;

select distinct(villagename) from Ulsan;

select * from Ulsan where country = '남구' and villageName = '달동';


select * from (select * from Ulsan where country = '남구' and villageName = '달동')
where buildName like '%130%' or lotNumberMain like '%130%' or lotNumberSub like '%130%';

select count(*) from Ulsan where country = '남구' and villageName like '%달동%';

select count(*) from (select * from Ulsan where country = '남구' and villageName = '달동')
where buildName like '%130%' or lotNumberMain like '%130%' or lotNumberSub like '%130%';

select * from (select * from Ulsan where country = '남구' and roadName = '화합로')
where buildName = '%12%' or buildNumberMain like '%12%' or buildNumberSub like '%12%'; 

select count(*) from (select * from Ulsan where country = '남구' and villageName = '달동')
where buildName like '%%' or lotNumberMain like '%%' or lotNumberSub like '%%';

select * from gangwon where country = '원주시' and villageName = '태장동' and lotNumberMain = '801' and lotNumberSub = '44';

select count(*) from ulsan;
select * from ulsan where rowid = (select count(*) from ulsan);
select * from ulsan where rowid = 98566;

select * from ulsan where roadName like '%모듈%';