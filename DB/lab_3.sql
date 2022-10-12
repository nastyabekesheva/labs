DELETE FROM student
DELETE FROM dormitory
DELETE FROM room
DELETE FROM registry_book

INSERT INTO student (Id, first_name, middle_name, last_name, students_group) VALUES (1, 'Sherman', 'Heidi', 'Marcie', 'of-11')
INSERT INTO student (Id, first_name, middle_name, last_name, students_group) VALUES (2, 'Osborn', 'Breana', 'Abe', 'jf-32')
INSERT INTO student (Id, first_name, middle_name, last_name, students_group) VALUES (3, 'Montague', 'Price', 'Matilda', 'sd-93')
INSERT INTO student (Id, first_name, middle_name, last_name, students_group) VALUES (4, 'Alea', 'Chauncey', 'Chauncey', 'ji-93')
INSERT INTO student (Id, first_name, middle_name, last_name, students_group) VALUES (5, 'Nonie', 'Jaylah', 'Merton', 'kd-06')
INSERT INTO student (Id, first_name, middle_name, last_name, students_group) VALUES (6, 'Emelia', 'Kenton', 'Elma', 'ks-29')
INSERT INTO student (Id, first_name, middle_name, last_name, students_group) VALUES (7, 'Keira', 'Denzil', 'Edgar', 'ls-37')
INSERT INTO student (Id, first_name, middle_name, last_name, students_group) VALUES (8, 'Mindy', 'Parnel', 'Gayelord', 'pw-02')
INSERT INTO student (Id, first_name, middle_name, last_name, students_group) VALUES (9, 'Connell', 'Dolores', 'Zayden', 'ho-23')
INSERT INTO student (Id, first_name, middle_name, last_name, students_group) VALUES (10, 'Pearlie', 'Kristy', 'Aureole', 'of-11')

INSERT INTO dormitory (Id, name, address) VALUES (1, '1', ' Kotovskogo Ul., bld. 99')
INSERT INTO dormitory (Id, name, address) VALUES (2, '2', ' CHerepіna, Vul., bld. 64')
INSERT INTO dormitory (Id, name, address) VALUES (3, '3', ' Eniseyskaya Ul., bld. 22')
INSERT INTO dormitory (Id, name, address) VALUES (4, '4', ' Geroev Stalingrada Ul., bld. 86/1')
INSERT INTO dormitory (Id, name, address) VALUES (5, '5', ' 50 Let Oktyabrya Kv., bld. 15')
INSERT INTO dormitory (Id, name, address) VALUES (6, '6', ' Podgornaya Ul., bld. 27')
INSERT INTO dormitory (Id, name, address) VALUES (7, '7', ' CHernyakhovskogo Vul., bld. 7')
INSERT INTO dormitory (Id, name, address) VALUES (8, '8', ' Kotlyarevskogo Ul., bld. 78')
INSERT INTO dormitory (Id, name, address) VALUES (9, '9', ' SHatіlo Vul., bld. 3/А')
INSERT INTO dormitory (Id, name, address) VALUES (10, '10', ' Gvardeytsev-SHironintsev Ul., bld. 127')

INSERT INTO room (Id, name, floor) VALUES (1, '00-01', 0)
INSERT INTO room (Id, name, floor) VALUES (2, '01-02', 1)
INSERT INTO room (Id, name, floor) VALUES (3, '02-03', 2)
INSERT INTO room (Id, name, floor) VALUES (4, '03-04', 3)
INSERT INTO room (Id, name, floor) VALUES (5, '04-05', 4)
INSERT INTO room (Id, name, floor) VALUES (6, '05-06', 5)
INSERT INTO room (Id, name, floor) VALUES (7, '06-07', 7)
INSERT INTO room (Id, name, floor) VALUES (8, '07-08', 8)
INSERT INTO room (Id, name, floor) VALUES (9, '08-09', 9)
INSERT INTO room (Id, name, floor) VALUES (10, '09-09', 10)

UPDATE room 
    SET number_of_people = number_of_people + 1
        WHERE Id = 1
INSERT INTO registry_book (Id, student_id, dormitory_id, room_id) VALUES (1, 1, 1, 1)
UPDATE room 
    SET number_of_people = number_of_people + 1
        WHERE Id = 2
INSERT INTO registry_book (Id, student_id, dormitory_id, room_id) VALUES (2, 2, 2, 2)
UPDATE room 
    SET number_of_people = number_of_people + 1
        WHERE Id = 1
INSERT INTO registry_book (Id, student_id, dormitory_id, room_id) VALUES (3, 3, 1, 1)
UPDATE room 
    SET number_of_people = number_of_people + 1
        WHERE Id = 4
INSERT INTO registry_book (Id, student_id, dormitory_id, room_id) VALUES (4, 4, 4, 4)
UPDATE room 
    SET number_of_people = number_of_people + 1
        WHERE Id = 1
INSERT INTO registry_book (Id, student_id, dormitory_id, room_id) VALUES (5, 5, 1, 1)
UPDATE room 
    SET number_of_people = number_of_people + 1
        WHERE Id = 2
INSERT INTO registry_book (Id, student_id, dormitory_id, room_id) VALUES (6, 6, 1, 2)
UPDATE room 
    SET number_of_people = number_of_people + 1
        WHERE Id = 7
INSERT INTO registry_book (Id, student_id, dormitory_id, room_id) VALUES (7, 7, 7, 7)
UPDATE room 
    SET number_of_people = number_of_people + 1
        WHERE Id = 1
INSERT INTO registry_book (Id, student_id, dormitory_id, room_id) VALUES (8, 8, 1, 1)
UPDATE room 
    SET number_of_people = number_of_people + 1
        WHERE Id = 4
INSERT INTO registry_book (Id, student_id, dormitory_id, room_id) VALUES (9, 9, 4, 4)
UPDATE room 
    SET number_of_people = number_of_people + 1
        WHERE Id = 10 
INSERT INTO registry_book (Id, student_id, dormitory_id, room_id) VALUES (10, 10, 10, 10)

SELECT * FROM student
SELECT * FROM dormitory
SELECT * FROM room
SELECT * FROM registry_book