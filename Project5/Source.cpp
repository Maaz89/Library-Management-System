#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h> 

using namespace std;

class admin {
protected:
    string librarian;
    vector<string> add_book;
public:
    void add_libra(string l) {
        ofstream user("users.txt", ios::app);
        librarian = l;
        user << librarian << endl;
    }

    void view_libra() {
        ifstream user("users.txt");
        getline(user, librarian);
        cout << librarian << endl;
    }

    void add() {
        cout << "* Enter The Number of Books *" << endl;
        int num_books;
        cin >> num_books;
        for (int i = 0; i < num_books; i++) {
            cout << "* Enter The Book " << i + 1 << " *" << endl;
            string book;
            cin >> book;
            add_book.push_back(book);
        }
        ofstream myfile("bookdata.txt");
        for (const string& book : add_book) {
            myfile << book << endl;
        }
    }

    void view_add() {
        cout << "-----AVAILABLE BOOKS-----" << endl;
        ifstream myfile("bookdata.txt");
        string book;
        while (getline(myfile, book)) {
            cout << book << endl;
        }
    }
};

class library {
public:
    library() {
        cout << "-----WELCOME TO BUI LIBRARY-----" << endl;
    }
};

class librarian : public admin {
protected:
    int password;
    string issue_date;

    int getPassword() {
        int p = 0;
        char ch;
        while ((ch = _getch()) != '\r') {
            if (ch == '\b') { 
                if (p > 0) {
                    p /= 10;
                    cout << "\b \b";
                }
            }
            else if (isdigit(ch)) {
                p = p * 10 + (ch - '0');
                cout << '*';
            }
        }
        cout << endl;
        return p;
    }

public:
    library la;

    bool setlogin(int p) {
        cout << "* Enter Your Password To Proceed *" << endl;
        password = getPassword();
        if (password == p) {
            cout << "* Login Successful! *" << endl;
            return true;
        }
        else {
            cout << "* Wrong Password! Exiting... *" << endl;
            return false;
        }
    }

    void issue(string student_name, string book_name, string issue_date, string return_date) {
        ofstream librariandata("lirbydata.txt", ios::app); 
        librariandata << "Student Name: " << student_name << endl;
        librariandata << "Book Name: " << book_name << endl;
        librariandata << "Issue Date: " << issue_date << endl;
        librariandata << "Return Date: " << return_date << endl;
    }

    void modify() {
        int num_books;
        cout << "* Enter the number of books to modify: ";
        cin >> num_books;

        cout << "* Enter Books to Add *" << endl;
        string book;
        ofstream myfile("bookdata.txt", ios::app);
        for (int i = 0; i < num_books; i++) {
            cout << "Enter book " << i + 1 << ": ";
            cin >> book;
            myfile << book << endl;
        }
    }

    void view_modify() {
        ifstream myfile("bookdata.txt");
        add_book.clear();
        string temp;
        while (getline(myfile, temp)) {
            add_book.push_back(temp);
        }
        for (const string& book : add_book) {
            cout << book << endl;
        }
    }

    void view_issued_books() {
        cout << "-----ISSUED BOOKS-----" << endl;
        ifstream librariandata("lirbydata.txt");
        string line;
        while (getline(librariandata, line)) {
            cout << line << endl;
        }
    }

    void view_signed_up_students() {
        cout << "-----SIGNED UP STUDENTS-----" << endl;
        ifstream studentFile("students.txt");
        string name;
        int pass;
        while (studentFile >> name >> pass) {
            cout << "Name: " << name << ", Password: " << pass << endl;
        }
    }
};

class student : public librarian {
protected:
    string student_name;
    string search_book;
    int check = 0;
    string return_date;
    int password;

    int getPassword() {
        int p = 0;
        char ch;
        while ((ch = _getch()) != '\r') { 
            if (ch == '\b') { 
                if (p > 0) {
                    p /= 10;
                    cout << "\b \b"; 
                }
            }
            else if (isdigit(ch)) {
                p = p * 10 + (ch - '0');
                cout << '*';
            }
        }
        cout << endl;
        return p;
    }

public:
    student(string c, string s, string r, int pass) {
        student_name = c;
        search_book = s;
        return_date = r;
        password = pass;
    }

    string signIn() {
        cout << "Enter your name: ";
        cin >> student_name;
        cout << "Enter your password: ";
        password = getPassword();
        
        ifstream studentFile("students.txt");
        string name;
        int pass;
        while (studentFile >> name >> pass) {
            if (name == student_name && pass == password) {
                cout << "* Login Successful! *" << endl;
                return name; 
            }
        }
        cout << "* Student not found or wrong password! *" << endl;
        return "";     }

    void signUp() {
        cout << "Enter your name: ";
        cin >> student_name;
        cout << "Set your password: ";
        password = getPassword();
        
        ofstream studentFile("students.txt", ios::app);
        studentFile << student_name << " " << password << endl;
    }

    void view_add() {
        cout << "-----AVAILABLE BOOKS-----" << endl;
        ifstream myfile("bookdata.txt");
        string book;
        while (getline(myfile, book)) {
            cout << book << endl;
        }
    }

    void search_b(string s) {
        check = 0;
        ifstream myfile("bookdata.txt");
        add_book.clear();
        string temp;
        while (getline(myfile, temp)) {
            add_book.push_back(temp);
        }
        for (const string& book : add_book) {
            if (s == book) {
                cout << book << endl;
                check = 1;
            }
        }
        if (check == 1) {
            cout << "Book Found!" << endl;
        }
        else {
            cout << "Book Not Found!" << endl;
        }
    }
};
int main() {
    system("color 10");
    cout << "\t\t\t\t\tPROJECT NAME: LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "\t\t\t\t\t\tGroup members:" << endl;
    cout << "\t\t\t\t\t\t1: Abdul Rafay(006)" << endl;
    cout << "\t\t\t\t\t\t2: Maaz Sajid(126)" << endl;

    bool exit_program = false;
    while (!exit_program) {
        int ch;
        cout << "* Enter 1 If You Want To Login As Librarian *" << endl;
        cout << "* Enter 2 If You Want To Login As Student *" << endl;
        cout << "* Enter 3 If You Want To Exit *" << endl;
        cin >> ch;

        if (ch == 1) {
            librarian l;
            if (l.setlogin(13579)) {
                int choice;
                cout << "* Enter 1 If You Want To Add Books *" << endl;
                cout << "* Enter 2 If You Want To View Books *" << endl;
                cout << "* Enter 3 If You Want To Modify Books Or Add New Books *" << endl;
                cout << "* Enter 4 If You Want To View Modified Books *" << endl;
                cout << "* Enter 5 If You Want To View Issued Books *" << endl;
                cout << "* Enter 6 If You Want To View Signed Up Students *" << endl;
                cin >> choice;

                if (choice == 1) {
                    l.add();
                }
                else if (choice == 2) {
                    l.view_add();
                }
                else if (choice == 3) {
                    l.modify();
                }
                else if (choice == 4) {
                    l.view_modify();
                }
                else if (choice == 5) {
                    l.view_issued_books();
                }
                else if (choice == 6) {
                    l.view_signed_up_students();
                }
                else {
                    cout << "Invalid choice!" << endl;
                }
            }
        }
        else if (ch == 2) {
            library l2;
            int student_choice;
            cout << "Enter 1 for Sign Up, 2 for Login: ";
            cin >> student_choice;
            student s1("", "", "", 0); 
            if (student_choice == 1) {
                s1.signUp();
            }
            else if (student_choice == 2) {
                string student_name = s1.signIn();
                if (!student_name.empty()) { 
                    int student_action;
                    cout << "Enter 1 to View Available Books, 2 to Issue a Book: ";
                    cin >> student_action;

                    if (student_action == 1) {
                        s1.view_add();
                    }
                    else if (student_action == 2) {
                        string s, return_date, issue_date;
                        cout << "* Enter The Name Of Your Book! *" << endl;
                        cin >> s;
                        cout << "* Enter the issue date (dd/mm/yyyy or dd-mm-yyyy) *" << endl;
                        cin >> issue_date;
                        cout << "* Enter the return date (dd/mm/yyyy or dd-mm-yyyy) *" << endl;
                        cin >> return_date;
                        s1.issue(student_name, s, issue_date, return_date);
                    }
                    else {
                        cout << "Invalid choice!" << endl;
                    }
                }
            }
            else {
                cout << "Invalid choice!" << endl;
            }
        }
        else if (ch == 3) {
            exit_program = true;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
