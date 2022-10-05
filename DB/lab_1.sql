CREATE TABLE student (
    Id int NOT NULL PRIMARY KEY,
    last_name VARCHAR(200) NOT NULL,
    first_name VARCHAR(200) NOT NULL,
    middle_name VARCHAR(200) NOT NULL,
    students_group VARCHAR(5) NOT NULL
)

CREATE TABLE dormitory (
    Id int NOT NULL PRIMARY KEY,
    name VARCHAR(200) NOT NULL,
    address VARCHAR(200) NOT NULL
)

CREATE TABLE room (
    Id int NOT NULL PRIMARY KEY,
    name VARCHAR(5) NOT NULL,
    floor VARCHAR(2) NOT NULL,
    number_of_people INT DEFAULT 0
)

CREATE TABLE registry_book (
    Id int NOT NULL PRIMARY KEY,
    student_id INTEGER REFERENCES student(Id),
    dormitory_id INTEGER REFERENCES dormitory(Id),
    room_id INTEGER REFERENCES room(Id)
)
