USE master
GO
/*DROP DATABASE StudensDB, Students, StudentDB ;  
GO*/ 
IF NOT EXISTS (
 SELECT name
 FROM sys.databases
 WHERE name = N'DormitoryDB'
)
 CREATE DATABASE [DormitoryDB];
GO
IF SERVERPROPERTY('ProductVersion') > '12'
 ALTER DATABASE [DormitoryDB] SET QUERY_STORE=ON;
GO


