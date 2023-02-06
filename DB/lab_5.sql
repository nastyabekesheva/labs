

SELECT name, floor, number_of_people FROM room 
        WHERE (SELECT AVG(number_of_people) FROM room) < number_of_people

SELECT name, floor, number_of_people FROM room 
    WHERE number_of_people = (SELECT MIN(number_of_people) FROM room)

SELECT name, floor, number_of_people FROM room 
    WHERE number_of_people = (SELECT MAX(number_of_people) FROM room)

SELECT student.last_name, dormitory.address, room.name from registry_book
    JOIN student ON student.Id = student_id
    JOIN dormitory ON dormitory.Id = dormitory_id
    JOIN room ON room.Id = room_id
        WHERE dormitory_id = 1
        
    
