USE master
GO
/*DROP DATABASE StudentsDB;  
GO*/

IF NOT EXISTS (
 SELECT name
 FROM sys.databases
 WHERE name = N'StudentsDB'
)
 CREATE DATABASE [StudentsDB];
GO
IF SERVERPROPERTY('ProductVersion') > '12'
 ALTER DATABASE [StudentsDB] SET QUERY_STORE=ON;
GO



