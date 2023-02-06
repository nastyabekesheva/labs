CREATE VIEW [dorm] AS 
    SELECT student.first_name, student.last_name, dormitory.address, room.name FROM registry_book
    JOIN student ON student.Id = student_id
    JOIN dormitory ON dormitory.Id = dormitory_id
    JOIN room ON room.Id = room_id

SELECT * FROM dorm

CREATE VIEW [dorm2] AS 
    SELECT student.first_name, student.last_name, student.students_group, room.name FROM registry_book
    JOIN student ON student.Id = student_id
    JOIN room ON room.Id = room_id

SELECT * FROM dorm2

SELECt room.name, dormitory.address, room.number_of_people FROM registry_book
    JOIN dormitory ON dormitory.Id = dormitory_id
    JOIN room ON room.Id = room_id


