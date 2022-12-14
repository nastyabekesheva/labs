CREATE PROC select_students_e
    @students_group_id INT
AS  
    SELECT student.first_name, student.last_name, subject.name, grade FROM grade_book
        JOIN subject ON subject.Id = grade_book.subject_id
        JOIN student ON student.Id = grade_book.student_id
        JOIN students_group ON students_group.Id = student.students_group_id
            WHERE subject.type = 'exam' AND grade < 60 AND student.students_group_id = @students_group_id

EXEC select_students_e 1

SELECT student.first_name, student.last_name, subject.name, grade FROM grade_book
        JOIN subject ON subject.Id = grade_book.subject_id
        JOIN student ON student.Id = grade_book.student_id
        JOIN students_group ON students_group.Id = student.students_group_id
            WHERE subject.type = 'exam' AND grade < 60 AND student.students_group_id = 1


SELECT * FROM grade_book

