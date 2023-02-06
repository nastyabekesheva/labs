CREATE PROC floor_numberr
    @dormitory_id INT
AS  
    SELECT room.floor FROM registry_book
        JOIN room ON room.Id = room_id
        JOIN dormitory ON dormitory.Id = dormitory_id
        WHERE room.number_of_people = (SELECT MIN(number_of_people) FROM room) AND dormitory_id = @dormitory_id

EXEC floor_numberr 1




