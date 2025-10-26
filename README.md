# CS 210 Project Three – Corner Grocer

## Overview
This project, **Corner Grocer Item-Tracking Program**, analyzes text records of grocery transactions to determine how often each item was purchased during the day. The program reads data from an input file (`CS210_Project_Three_Input_File.txt`) and provides users with several menu options to explore item-frequency information. This project demonstrates the use of **C++ Maps**, **file input/output operations**, **modular programming**, and **object-oriented design principles** to solve real-world data-analysis problems.

---

## Functionalities

### Menu Option 1: Search Item Frequency
- Prompts the user to enter an item name.  
- Displays the number of times that specific item appears in the transaction file.

### Menu Option 2: Display All Items and Frequencies
- Outputs a complete list of items and their purchase counts.  
Example: 
Potatoes 4
Pumpkins 5
Onions 3

### Menu Option 3: Display Histogram
- Shows a histogram of item frequencies using asterisks (`*`) to visualize frequency counts.  
Example:
Potatoes ****
Pumpkins *****
Onions ***

### Menu Option 4: Exit
- Closes the program gracefully.

---

## Data File Creation
The program automatically creates a backup file named **`frequency.dat`** when executed. This file stores each item and its corresponding frequency, allowing for data persistence and recovery.

---

## Technical Implementation
- **Language:** C++  
- **Core Structures:** `std::map<std::string, int>`  
- **File Operations:** Read input file, write backup data file  
- **Design Pattern:** Modular and object-oriented (uses a dedicated class for frequency operations)  
- **Development Environment:** Visual Studio / Command Prompt  

---

## Reflection

### Project Summary
This project involved building a grocery item tracker that processes daily transaction data and reports item frequencies through text and histogram outputs. It was designed to help the Corner Grocer optimize their store layout based on purchasing patterns.

### What I Did Well
I implemented clean and modular code, especially through the use of the C++ `map` container to efficiently track and display item frequencies. Each function is purpose-driven, improving readability and maintainability.

### Enhancements
Possible improvements include:  
- Adding input validation (e.g., handling capitalization and spacing)  
- Improving user feedback for invalid or missing items  
- Extending the program to support database integration for long-term tracking  

### Challenges
Managing file input/output and ensuring accurate frequency counting was challenging. Debugging line reads and correctly handling whitespace required careful use of `getline()` and stream checks.

### Transferable Skills
This project strengthened my understanding of file handling, data structures, and modular design in C++. These skills are directly applicable to other data-processing, analytics, and software-engineering projects.

### Maintainability and Readability
Consistent naming conventions, inline documentation, and logical separation of functionality were applied throughout. The code is easily extensible for future features such as graphical output or user data filtering.

---

## How to Run
1. Extract all files into a single directory.  
2. Open a terminal or Command Prompt in that directory.  
3. Compile the program: g++ -o CornerGrocer main.cpp ItemTracker.cpp
4. Run the executable: ./CornerGrocer
5. Follow the on-screen menu prompts.

---

## Author
**David Alawoe**  
Southern New Hampshire University  
Course: CS 210 – Programming Languages 
