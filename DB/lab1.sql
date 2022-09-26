CREATE TABLE subject (
    Id int NOT NULL PRIMARY KEY,
    name VARCHAR(255) UNIQUE
);

CREATE TABLE students_group (
    Id int NOT NULL PRIMARY KEY,
    name VARCHAR(5) UNIQUE,
    course INTEGER,
    semester INTEGER
);

CREATE TABLE student (
    Id int NOT NULL PRIMARY KEY,
    last_name VARCHAR(255) NOT NULL,
    first_name VARCHAR(255) NOT NULL,
    middle_name VARCHAR(255) NOT NULL,
    sex VARCHAR(255) UNIQUE,
    birthday DATE,
    address VARCHAR(255),
    students_group INTEGER REFERENCES students_group(Id)
);

CREATE TABLE grade_book (
    Id int NOT NULL PRIMARY KEY,
    student_id INTEGER REFERENCES student(Id),
    subject_id INTEGER REFERENCES subject(Id),
    grade INTEGER 
);