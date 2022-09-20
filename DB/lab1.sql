CREATE TABLE "group" (
    Id int NOT NULL PRIMARY KEY,
    name VARCHAR(5) UNIQUE,
    course INTEGER,
    semester INTEGER
);

CREATE TABLE subject (
    Id int NOT NULL PRIMARY KEY,
    name VARCHAR(255) UNIQUE
);

CREATE TABLE gender (
    Id int NOT NULL PRIMARY KEY,
    name VARCHAR(255) UNIQUE
);

CREATE table student (
    Id int NOT NULL PRIMARY KEY,
    last_name VARCHAR(255),
    first_name VARCHAR(255),
    middle_name VARCHAR(255),
    gender INTEGER,
    birthday DATE,
    address VARCHAR(255),
    "group" INTEGER
);

CREATE TABLE work_type (
    Id int NOT NULL PRIMARY KEY,
    name VARCHAR(255) UNIQUE
);

CREATE TABLE progress (
    student INTEGER,
    subject INTEGER,
    score INTEGER,
    hours REAL,
    work_type INTEGER,
    PRIMARY KEY (student, subject, work_type)
);
