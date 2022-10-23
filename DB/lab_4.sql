SELECT student.first_name, student.middle_name, student.last_name, dormitory.name, room.name FROM registry_book
    JOIN student ON student.Id = registry_book.student_id
    JOIN dormitory ON dormitory.Id = registry_book.dormitory_id
    JOIN room ON room.Id = registry_book.room_id
        WHERE dormitory_id = 1

SELECT student.first_name, student.middle_name, student.last_name, dormitory.name, room.name FROM registry_book
    JOIN student ON student.Id = registry_book.student_id
    JOIN dormitory ON dormitory.Id = registry_book.dormitory_id
    JOIN room ON room.Id = registry_book.room_id
        WHERE student.students_group = 'of-11'

SELECT student.first_name, student.middle_name, student.last_name, room.name, room.number_of_people, dormitory.name FROM registry_book
    JOIN student ON student.Id = registry_book.student_id
    JOIN dormitory ON dormitory.Id = registry_book.dormitory_id
    JOIN room ON room.Id = registry_book.room_id
        WHERE room.Id = 1