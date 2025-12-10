#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

// Student structure
struct Student {
    int id;
    string name;
    int age;
};

// Global storage
vector<Student> students;

// Function to read integer safely
int readInt(const string &prompt) {
    int value;
    string line;
    while (true) {
        cout << prompt;
        getline(cin, line);
        stringstream ss(line);
        if (ss >> value) {
            return value;
        }
        cout << "❗ Invalid input. Please enter a number.\n";
    }
}

// Function to read string safely
string readString(const string &prompt) {
    string line;
    cout << prompt;
    getline(cin, line);
    return line;
}

// Add student
void addStudent() {
    Student s;
    s.id = readInt("\nEnter Student ID: ");
    s.name = readString("Enter Name: ");
    s.age = readInt("Enter Age: ");

    students.push_back(s);
    cout << "✔ Student added successfully!\n";
}

// View all students
void viewStudents() {
    if (students.empty()) {
        cout << "\n❗ No records found.\n";
        return;
    }
    cout << "\n---- Student Records ----\n";
    for (const auto &s : students) {
        cout << "ID: " << s.id << " | Name: " << s.name << " | Age: " << s.age << endl;
    }
}

// Search student by ID
void searchStudent() {
    int searchId = readInt("\nEnter ID to search: ");
    for (const auto &s : students) {
        if (s.id == searchId) {
            cout << "✔ Record Found: "
                 << "ID: " << s.id
                 << " | Name: " << s.name
                 << " | Age: " << s.age << endl;
            return;
        }
    }
    cout << "❗ Student not found.\n";
}

int main() {
    int choice;
    while (true) {
        cout << "\n==== Student Record Manager ====\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        choice = readInt("Choose option: ");

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting...\n"; return 0;
            default: cout << "❗ Invalid choice, try again!\n";
        }
    }
}
