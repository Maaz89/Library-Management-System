📚 Library Management System (C++)

A console-based Library Management System built in C++ that allows librarians to manage books and students to register, login, search, and issue books. The system uses file handling to store and retrieve data, making it a simple offline library simulation.

🚀 Features
👨‍💼 Librarian Module
Secure login (password protected)
Add new books to the library
View available books
Modify (add more) books
View issued book records
View registered students
👨‍🎓 Student Module
Student sign-up and login system
View available books
Search for a specific book
Issue books with issue & return dates
🛠️ Technologies Used
C++ Programming Language
Object-Oriented Programming (OOP)
File Handling (ifstream, ofstream)
Console-based UI
Windows-specific _getch() for password masking
📂 File Structure

The system uses simple text files for storage:

bookdata.txt → Stores list of books
students.txt → Stores student usernames and passwords
lirbydata.txt → Stores issued book records
users.txt → Stores librarian data
▶️ How to Run
Clone the repository:
git clone https://github.com/your-username/library-management-system.git
Open the project in any C++ IDE (Code::Blocks / Dev C++ / Visual Studio)
Compile and run:
g++ main.cpp -o library
./library
🔐 Default Admin Access
Password: 13579
📌 System Workflow
Program starts with a main menu:
Librarian Login
Student Login / Sign Up
Exit
Based on role:
Librarian manages books and student records
Students browse and issue books
💡 Concepts Used
Object-Oriented Programming (OOP)
Inheritance (admin → librarian → student)
File Handling in C++
Menu-driven system design
Basic authentication system
📸 Sample Features (Console UI)
PROJECT NAME: LIBRARY MANAGEMENT SYSTEM
1: Librarian Login
2: Student Login
3: Exit
📈 Future Improvements
Database integration (MySQL / SQLite)
GUI-based interface (Qt / SFML)
Fine system for late returns
Book categories & ISBN support
Improved security system
👨‍💻 Author
Maaz Sajid
Abdul Rafay
