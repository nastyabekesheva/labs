/*USE master
GO
DROP DATABASE StudensDB, Students, StudentDB ;  
GO 
IF NOT EXISTS (
 SELECT name
 FROM sys.databases
 WHERE name = N'StudentsDB'
)
 CREATE DATABASE [StudentDB];
GO
IF SERVERPROPERTY('ProductVersion') > '12'
 ALTER DATABASE [StudentDB] SET QUERY_STORE=ON;
GO*/


