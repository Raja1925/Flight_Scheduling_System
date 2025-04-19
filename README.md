# Flight Scheduling System (C Project)

---
## Description
This is a command-line based *Flight Scheduling System* developed in C, using *singly linked lists* and *file handling* for persistent storage. The system allows users to manage flight records through various operations like adding, updating, searching, deleting, and displaying flights.
---

---
## Features
- Add a new flight (auto-sorted by *departure time*)
- Display all scheduled flights
- Search a flight by *Flight Number*
- Update flight details
- Remove a flight
- Save and load flights to/from flights.txt
---

---
## File Structure
FlightScheduling/
│
├── flight.c         # Contains all flight-related logic and API implementations
├── flight.h         # Header file with struct definition and function prototypes
├── main.c           # Menu-driven interface for user interaction
├── flights.txt      # Persistent storage of flight records
├── Makefile         # Build instructions to compile the project
└── README.md        # Project documentation and instructions
---

---
## How to Compile and Run

# Option-1 - If You have make installed in your system :- 

### 1. Navigate to the Project Directory:
Replace "file_location" with the actual path of the folder on your system:

  cd "file_location"\RajaKumarSingh_2101793_CEC_TBL2_M2_06-04-25\FlightScheduling

### 2. Compile the Project:
  make

This will generate the executable scheduler.exe.
### 3. Run the Program:
  ./scheduler.exe


# Option-2 -- If You do not have make installed in your system then :-

### 1. Navigate to the Project Folder/Directory using command prompt(cmd) or PowerShell.

### 2. Run the '.exe' file using :-
        .\scheduler.exe

### 3. If you get an error or nothing appears, try running from 'cmd.exe' instead of PowerShell :
        cmd /c .\scheduler.exe
---

---
## Notes
- Ensure flights.txt is in the same directory as the executable.
- All changes to flights (add/update/remove) are saved to the file after each operation.
- Input is validated to prevent duplicate entries and maintain sorted order by departure time.
---