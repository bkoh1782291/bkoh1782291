CREATE TABLE User (
    UserID INT,
    AssignedTasks VARCHAR(255),
    Avaliability VARCHAR(255),
    PRIMARY KEY (UserID)
);

CREATE TABLE Manager (
    ManagerID INT,
    TaskName VARCHAR(255),
    PRIMARY KEY (ManagerID)
);

CREATE TABLE Task (
    TaskID INT,
    TaskName VARCHAR(255) NOT NULL,
    UserResponsible VARCHAR(255) NOT NULL,
    TaskPriority VARCHAR(255) NOT NULL,
    TimeLeft INT,
    Progress INT,
    PRIMARY KEY (TaskID)
);

CREATE TABLE ManagerProfile (
    ManagerID INT,
    Age INT,
    CompanyEmail VARCHAR(255) NOT NULL,
    ManagerPassword VARCHAR(255) NOT NULL,
    ManagerName VARCHAR(255) NOT NULL,
    ManagePeople VARCHAR(255) NOT NULL,
    PRIMARY KEY (ManagerID)
);

CREATE TABLE UserProfile (
    UserID INT,
    UserName VARCHAR(255) NOT NULL,
    UserPassword VARCHAR(255) NOT NULL,
    Age INT,
    Email VARCHAR(255) NOT NULL,
    Department VARCHAR(255) NOT NULL,
    PRIMARY KEY (UserID)
);

/* draft queries */

SELECT UserID FROM UserProfile;
SELECT ManagerID FROM UserProfile;

SELECT AssignedTasks, Avaliability FROM User;
SELECT TaskName, UserResponsible, TaskPriority, TimeLeft, Progress FROM Task;

SELECT TaskName, UserResponsible FROM Task WHERE TaskPriority = 'High';
SELECT TaskName, UserResponsible FROM Task WHERE TaskPriority = 'Medium';
SELECT TaskName, UserResponsible FROM Task WHERE TaskPriority = 'Low';

SELECT UserID, UserName, UserPassword FROM UserProfile";

SELECT Age, ManagerName, ManagePeople FROM ManagerProfile;
SELECT Age, UserName, Department FROM UserProfile;

INSERT INTO Task (TaskName, UserResponsible, TaskPriority, TimeLeft, Progress)
    VALUES ('','','',int,int);

INSERT INTO User (AssignedTasks, Avaliability)
    VALUES ('','');

INSERT INTO UserProfile (UserID, UserName, Age, UserPassword,)
    VALUES(int,'',int,'');


INSERT INTO ManagerProfile (ManagerID, Age, ManagerName, ManagerPassword)
    VALUES (int,int,'','');





