ALTER TABLE subject
    ADD hours INT NOT NULL DEFAULT(0)

UPDATE subject
    SET ContactName = 'Alfred Schmidt', City= 'Frankfurt'
    WHERE CustomerID = 1;

ALTER TABLE subject
    ADD type VARCHAR(255);

UPDATE subject
    SET hours = 108, type = 'test'
        WHERE Id = 1;

UPDATE subject
    SET hours = 270, type = 'exam'
        WHERE Id = 2;

UPDATE subject
    SET hours = 198, type = 'exam'
        WHERE Id = 3;

UPDATE subject
    SET hours = 54, type = 'test'
        WHERE Id = 4;

UPDATE subject
    SET hours = 162, type = 'exam'
        WHERE Id = 5;

UPDATE subject
    SET hours = 126, type = 'exam'
        WHERE Id = 6;

UPDATE subject
    SET hours = 200, type = 'exam'
        WHERE Id = 7;

UPDATE subject
    SET hours = 162, type = 'exam'
        WHERE Id = 8;

UPDATE subject
    SET hours = 198, type = 'test'
        WHERE Id = 9;

UPDATE subject
    SET hours = 144, type = 'test'
        WHERE Id = 10;

SELECT name, grade FROM grade_book JOIN subject ON subject.Id = grade_book.subject_id
    WHERE student_id = 1 AND hours = 108 AND type = 'test' 

SELECT student.first_name, student.middle_name, student.last_name, subject.name, grade_book.grade FROM grade_book 
    JOIN subject ON subject.Id = grade_book.subject_id
    JOIN student ON student.Id = grade_book.student_id
    JOIN students_group ON students_group.Id = student.students_group_id
        WHERE students_group_id = 2 AND subject_id = 2

SELECT DISTINCT subject.name FROM grade_book
    JOIN subject ON subject.Id = grade_book.subject_id
    JOIN student ON student.Id = grade_book.student_id
    JOIN students_group ON students_group.Id = student.students_group_id
        WHERE course = 2 OR semester = 3