CREATE VIEW [progress] AS 
    SELECT student.first_name, student.last_name, subject.name, subject.hours, subject.type, grade FROM grade_book
        JOIN student ON student.Id = grade_book.student_id
        JOIN subject ON subject.Id = grade_book.subject_id

SELECT * FROM progress

CREATE VIEW [students_groups_progress] AS
    SELECT subject.name AS subject, SUM(grade) sum, student.last_name, students_group.name FROM grade_book
    JOIN subject ON subject.Id = grade_book.subject_id
    JOIN student ON student.Id = grade_book.student_id
    JOIN students_group ON students_group.Id = student.students_group_id
    GROUP BY subject.name, student.last_name, students_group.name

SELECT * FROM students_groups_progress

CREATE VIEW [subjects] AS
    SELECT DISTINCT subject.name, students_group.course, students_group.semester FROM grade_book
    JOIN subject ON subject.Id = grade_book.subject_id
    JOIN student ON student.Id = grade_book.student_id
    JOIN students_group ON students_group.Id = student.students_group_id

SELECT * FROM subjects

