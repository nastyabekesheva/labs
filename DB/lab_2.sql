ALTER TABLE room
    ADD CONSTRAINT floor
        CHECK (floor BETWEEN 1 AND 20);

ALTER TABLE room
    ADD CONSTRAINT number_of_people
        CHECK (number_of_people BETWEEN 0 AND 4);

ALTER TABLE student
    ADD CONSTRAINT UniqueName 
        UNIQUE (first_name, last_name, middle_name, students_group);

ALTER TABLE registry_book
    ADD CONSTRAINT student_id 
        FOREIGN KEY (Id) REFERENCES student (Id) ON DELETE CASCADE

ALTER TABLE registry_book
    ADD CONSTRAINT dormitory_id 
        FOREIGN KEY (Id) REFERENCES dormitory (Id) ON DELETE CASCADE

ALTER TABLE registry_book
    ADD CONSTRAINT room_id 
        FOREIGN KEY (Id) REFERENCES room (Id) ON DELETE CASCADE

ALTER TABLE room
    NOCHECK CONSTRAINT floor

INSERT INTO room (Id, name, floor) VALUES (1, '02-13', 2)
INSERT INTO room (Id, name, floor) VALUES (2, '22-13', 22)

SELECT * FROM room

ALTER TABLE room WITH CHECK
    CHECK CONSTRAINT floor

DELETE FROM room WHERE floor > 20;

SELECT * FROM room

ALTER TABLE room 
    DROP CONSTRAINT floor

ALTER TABLE room
    ADD CONSTRAINT floor
        CHECK (floor BETWEEN 0 AND 20)

INSERT INTO room (Id, name, floor) VALUES (2, '00-13', 0)

SELECT * FROM room

ALTER TABLE room
    ADD SINGLE VARCHAR(3) DEFAULT 'yes'

SELECT * FROM room

ALTER TABLE room
    DROP CONSTRAINT DF__room__SINGLE__4E88ABD4

ALTER TABLE room
    DROP COLUMN SINGLE
    
INSERT INTO room (Id, name, floor) VALUES (1, '02-13', 2)
INSERT INTO room (Id, name, floor) VALUES (2, '00-13', 0)

SELECT * FROM room

EXEC sp_rename 'dbo.room', 'kimnata'

SELECT * FROM kimnata

EXEC sp_rename 'dbo.kimnata', 'room';

SELECT * FROM room









