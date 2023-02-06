CREATE LOGIN Bill WITH PASSWORD = 'Qwe12rty'
CREATE USER Bill FOR LOGIN Bill
GRANT SELECT, UPDATE TO Bill
GRANT EXECUTE TO Bill

REVOKE CONNECT, SELECT, UPDATE, EXECUTE FROM Bill
DROP LOGIN Bill
DROP USER Bill

CREATE MASTER KEY ENCRYPTION BY PASSWORD = 'Qwe12rty'
CREATE CERTIFICATE students WITH SUBJECT = 'students'

CREATE SYMMETRIC KEY students_key
    WITH ALGORITHM = AES_256
    ENCRYPTION BY CERTIFICATE students

ALTER TABLE students_group
    ADD name_encrypted varbinary(160)

OPEN SYMMETRIC KEY students_key
    DECRYPTION BY CERTIFICATE students
UPDATE students_group
    SET name_encrypted = EncryptByKey
    (Key_GUID('Students_Key'), name)

FROM students_group
CLOSE SYMMETRIC KEY students_key


OPEN SYMMETRIC KEY students_key
DECRYPTION BY CERTIFICATE students;
SELECT Id, name_encrypted AS 'Encrypted name', CONVERT(varchar, DecryptByKey(name_encrypted)) AS 'Decrypted name'
FROM students_group
CLOSE SYMMETRIC KEY Students_Key






