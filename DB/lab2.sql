ALTER TABLE students_group
    ADD CONSTRAINT semester
        CHECK (semester BETWEEN 1 AND 2);

ALTER TABLE students_group
    ADD CONSTRAINT course
        CHECK (course BETWEEN 1 AND 7);

ALTER TABLE student
    ADD CONSTRAINT UniqueName UNIQUE (first_name, last_name, middle_name, birthday, students_group_id)

ALTER TABLE student
    ADD CONSTRAINT birthday
        CHECK (birthday BETWEEN '1900.01.01' AND GETDATE());

ALTER TABLE grade_book
    ADD CONSTRAINT grade
        CHECK (grade BETWEEN 0 AND 100);

ALTER TABLE student
    ADD CONSTRAINT students_group_id FOREIGN KEY (Id) REFERENCES students_group (Id) ON DELETE CASCADE

ALTER TABLE grade_book
    ADD CONSTRAINT student_id FOREIGN KEY (Id) REFERENCES student (Id) ON DELETE CASCADE

ALTER TABLE grade_book
    ADD CONSTRAINT subject_id FOREIGN KEY (Id) REFERENCES subject (Id) ON DELETE CASCADE

ALTER TABLE grade_book
    NOCHECK CONSTRAINT grade

INSERT INTO subject (Id, name) VALUES (1, 'DB');
INSERT INTO students_group (Id, name, course, semester) VALUES (1, 'FI-12', 2, 1);
INSERT INTO student (Id, first_name, last_name, middle_name, sex,  birthday, address, students_group_id) VALUES (1, 'Nastya', 'Bekesheva', 'Alexandr', 'female', '09-06-2004', 'Osinnia st.', 1);
INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (1, 1, 1, 120);

SELECT * FROM student

ALTER TABLE grade_book WITH CHECK
    CHECK CONSTRAINT grade

DELETE FROM grade_book WHERE grade > 100;

SELECT * FROM grade_book

ALTER TABLE grade_book WITH CHECK
    CHECK CONSTRAINT grade

INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (1, 1, 1, 120);

SELECT * FROM grade_book

ALTER TABLE students_group 
    ALTER COLUMN name VARCHAR(7) 

ALTER TABLE students_group 
    DROP CONSTRAINT semester

ALTER TABLE students_group
    ADD CONSTRAINT semester
        CHECK (semester BETWEEN 1 AND 3)

INSERT INTO students_group (Id, name, course, semester) VALUES (2, 'FI-11mn', 5, 3);

SELECT * FROM students_group

ALTER TABLE student
    ADD SINGLE VARCHAR(3)

SELECT * FROM student

ALTER TABLE student
    DROP COLUMN SINGLE 

SELECT * FROM student



INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (1, 1, 1, 95)

EXEC sp_rename 'dbo.grade_book', 'diary';

SELECT * FROM diary

EXEC sp_rename 'dbo.diary', 'grade_book';

SELECT * FROM grade_book

