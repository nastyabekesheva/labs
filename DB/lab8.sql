CREATE TRIGGER delete_subject ON subject
    FOR DELETE
AS
    IF EXISTS (
        SELECT 'True' FROM grade_book
            JOIN subject ON subject.Id = grade_book.subject_id
            WHERE grade IS NOT NULL 
    )
    BEGIN 
        RAISERROR('Deletion fo non-empty record is not allowed', 16, 1)
        ROLLBACK TRAN
    END

DELETE FROM subject where Id = 1

SELECT * FROM subject

CREATE VIEW [unable_to_keep_up] AS
    SELECT student.Id, last_name, grade_book.subject_id, COUNT(*) count FROM student
        JOIN grade_book ON student.Id = grade_book.student_id
        JOIN subject ON subject.Id = grade_book.subject_id
            WHERE subject.type = 'exam' AND grade_book.grade < 60
                GROUP BY student.Id, last_name, grade_book.subject_id

SELECT * FROM unable_to_keep_up

CREATE TRIGGER on_insert_update ON grade_book
    FOR INSERT, UPDATE
AS
    IF EXISTS (
        SELECT 'True' FROM grade_book
    )
    BEGIN 
        RAISERROR('Insert/alter is not allowed', 16, 1)
        ROLLBACK TRAN
    END

INSERT INTO grade_book (Id, student_id, subject_id, grade) VALUES (11, 1, 3, 95)
