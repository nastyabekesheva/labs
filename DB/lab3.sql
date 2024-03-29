DELETE FROM subject;
DELETE FROM students_group;
DELETE FROM student;
DELETE FROM grade_book;

INSERT INTO subject (Id, name) VALUES (1, 'Data bases');
INSERT INTO subject (Id, name) VALUES (2, 'Discrete math');
INSERT INTO subject (Id, name) VALUES (3, 'Physics');
INSERT INTO subject (Id, name) VALUES (4, 'English');
INSERT INTO subject (Id, name) VALUES (5, 'Probability theory');
INSERT INTO subject (Id, name) VALUES (6, 'Control theory');
INSERT INTO subject (Id, name) VALUES (7, 'Quantum mechanics');
INSERT INTO subject (Id, name) VALUES (8, 'Data analysis');
INSERT INTO subject (Id, name) VALUES (9, 'Cryptography');
INSERT INTO subject (Id, name) VALUES (10, 'Complexity theory');

INSERT INTO students_group (Id, name, course, semester) VALUES (1, 'FI-12', 2, 1);
INSERT INTO students_group (Id, name, course, semester) VALUES (2, 'FI-23', 1, 1);
INSERT INTO students_group (Id, name, course, semester) VALUES (3, 'FI-11', 2, 1);
INSERT INTO students_group (Id, name, course, semester) VALUES (4, 'FI-01', 3, 1);
INSERT INTO students_group (Id, name, course, semester) VALUES (5, 'FI-04', 3, 1);
INSERT INTO students_group (Id, name, course, semester) VALUES (6, 'FI-92', 4, 1);
INSERT INTO students_group (Id, name, course, semester) VALUES (7, 'FI-21mn', 5, 1);
INSERT INTO students_group (Id, name, course, semester) VALUES (8, 'FI-91', 4, 1);
INSERT INTO students_group (Id, name, course, semester) VALUES (9, 'FI-93', 4, 1);
INSERT INTO students_group (Id, name, course, semester) VALUES (10, 'FI-13', 2, 1);

INSERT INTO student (Id, first_name, middle_name, last_name, sex,  birthday, address, students_group_id) VALUES (1, 'Rebekah', 'Junior', 'Lynn', 'female', '1993-06-01', '4108 Woodrow Way', 1);
INSERT INTO student (Id, first_name, middle_name, last_name, sex,  birthday, address, students_group_id) VALUES (2, 'Jess', 'Augusta', 'Serafini', 'female', '1991-10-11', '3965 Wright Court', 2);
INSERT INTO student (Id, first_name, middle_name, last_name, sex,  birthday, address, students_group_id) VALUES (3, 'Rosella', 'Reimund', 'Reimund', 'female', '1993-04-27', '4255 Richison Drive', 3);
INSERT INTO student (Id, first_name, middle_name, last_name, sex,  birthday, address, students_group_id) VALUES (4, 'Calla', 'Augusto', 'Stauss', 'female', '1994-06-24', '1430 Lewis Street', 4);
INSERT INTO student (Id, first_name, middle_name, last_name, sex,  birthday, address, students_group_id) VALUES (5, 'Alesia', 'Dee', 'Eads', 'female', '1994-07-29', '1437 Woodridge Lane', 5);
INSERT INTO student (Id, first_name, middle_name, last_name, sex,  birthday, address, students_group_id) VALUES (6, 'Westley', 'Carter', 'Liam', 'male', '1995-02-14', '758 Progress Way', 6);
INSERT INTO student (Id, first_name, middle_name, last_name, sex,  birthday, address, students_group_id) VALUES (7, 'Dillan', 'Scotty', 'Jae', 'male', '1996-04-23', '3504 Daffodil Lane', 7);
INSERT INTO student (Id, first_name, middle_name, last_name, sex,  birthday, address, students_group_id) VALUES (8, 'Julyan', 'Tyberiy', 'Case', 'male', '2003-07-18', '1322 Pearl Street', 8);
INSERT INTO student (Id, first_name, middle_name, last_name, sex,  birthday, address, students_group_id) VALUES (9, 'Rowland', 'Grayson', 'Chet', 'male', '2004-12-17', '2441 O Conner Street', 9);
INSERT INTO student (Id, first_name, middle_name, last_name, sex,  birthday, address, students_group_id) VALUES (10, 'Rokuro', 'Langdon', 'Conrad', 'male', '2005-08-12', '4435 Briercliff Road', 10);

INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (1, 1, 1, 100);
INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (2, 2, 2, 70);
INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (3, 3, 3, 63);
INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (4, 4, 4, 100);
INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (5, 5, 5, 86);
INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (6, 6, 6, 79);
INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (7, 7, 7, 91);
INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (8, 8, 8, 99);
INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (9, 9, 9, 78);
INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (10, 10, 10, 94);

SELECT * FROM subject
SELECT * FROM students_group
SELECT * FROM student
SELECT * FROM grade_book