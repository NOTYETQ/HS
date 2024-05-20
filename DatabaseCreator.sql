-- Drop existing database if it exists (optional)
DROP DATABASE IF EXISTS hurricane_system;

CREATE DATABASE hurricane_system;

USE hurricane_system;

-- Roles table
CREATE TABLE Roles (
  Role_ID integer PRIMARY KEY,
  Role varchar(20) NOT NULL UNIQUE  -- Enforce unique role names
);

-- Users table
CREATE TABLE Users (
  User_ID integer PRIMARY KEY AUTO_INCREMENT,
  SSN char(9) NOT NULL UNIQUE,  -- Enforce unique usernames
  Role integer DEFAULT 1,
  First_Name varchar(50) NOT NULL,
  Middle_Name varchar(50) NOT NULL DEFAULT '',
  Last_Name varchar(50) NOT NULL,
  Address varchar(100) NOT NULL,
  Contact_Number varchar(10) NOT NULL,
  Blocked bool NOT NULL DEFAULT 0,
  Password varchar(25) NOT NULL,
  FOREIGN KEY (Role) REFERENCES Roles(Role_ID)
);


-- Conditions table
CREATE TABLE Conditions (
  Condition_ID integer PRIMARY KEY,
  `Condition` varchar(25) NOT NULL
);

-- Regions table
CREATE TABLE Regions (
  Region_ID integer PRIMARY KEY,
  Region varchar(25) NOT NULL
);

-- Locations table 
CREATE TABLE Locations (
  Location_ID integer PRIMARY KEY AUTO_INCREMENT,
  Region integer NOT NULL,
  Location varchar(100) NOT NULL,
  FOREIGN KEY (Region) REFERENCES Regions(Region_ID)
);

-- Shelters table
CREATE TABLE Shelters (
  Shelter_ID integer PRIMARY KEY AUTO_INCREMENT,
  Shelter varchar(50) NOT NULL,
  Location int NOT NULL,
  Address varchar(100) NULL,
  `Condition` int NOT NULL,
  Latitude varchar(20) NOT NULL,
  Longitude varchar(20) NOT NULL,
  Capacity int NOT NULL,
  FOREIGN KEY (Location) REFERENCES Locations(Location_ID),
  FOREIGN KEY (`Condition`) REFERENCES Conditions(Condition_ID)
);

-- Status table
CREATE TABLE Status (
  Status_ID integer PRIMARY KEY AUTO_INCREMENT,
  Status varchar(255) NOT NULL
);

-- Flags table (Option A: Store Image Paths)
CREATE TABLE Flags (
  Flag_ID int PRIMARY KEY,
  Flag varchar(20) NOT NULL,
  Description varchar(255) NOT NULL
);


-- Categories table
CREATE TABLE Categories (
  Category_ID integer PRIMARY KEY,
  Sustained_Winds varchar(20) NOT NULL,
  Storm_Surge varchar(20) NOT NULL,
  Description varchar(255) NOT NULL
);


-- Hurricanes table
CREATE TABLE Hurricanes (
  Hurricane_ID integer PRIMARY KEY AUTO_INCREMENT,
  Hurricane varchar(50) NOT NULL, 
  Category int NOT NULL,
  HurricaneDate DATE,  
  Flag int NOT NULL,
  Active bool NOT NULL DEFAULT 0,
  FOREIGN KEY (Category) REFERENCES Categories(Category_ID),
  FOREIGN KEY (Flag) REFERENCES Flags(Flag_ID)
);


-- Permissions table 
CREATE TABLE Permissions (
  Permission_ID integer PRIMARY KEY AUTO_INCREMENT,
  Role integer NOT NULL, -- Who 
  Entity varchar(25) NOT NULL, -- Where
  Permission varchar(25) NOT NULL, -- What
  Has_Permission bool NOT NULL DEFAULT 0, -- Yes or no
  FOREIGN KEY (Role) REFERENCES Roles(Role_ID)
);

-- Bookings table
CREATE TABLE Bookings (
  Booking_ID integer PRIMARY KEY AUTO_INCREMENT,
  Hurricane integer NOT NULL,
  User integer NOT NULL,
  Status integer NOT NULL,
  Shelter integer NOT NULL,
  Booking_Date_Time DATETIME NOT NULL, 
  FOREIGN KEY (Shelter) REFERENCES Shelters(Shelter_ID),
  FOREIGN KEY (User) REFERENCES Users(User_ID),
  FOREIGN KEY (Status) REFERENCES Status(Status_ID),
  FOREIGN KEY (Hurricane) REFERENCES Hurricanes(Hurricane_ID)
);

