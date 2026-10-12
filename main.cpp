#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Blueprint for a student
class Student {
public:
    int id;
    string name;
    float marks;

    Student(int i, string n, float m) {
        id = i;
        name = n;
        marks = m;
    }

    char getGrade() const {
        if (marks >= 90) return 'A';
        if (marks >= 80) return 'B';
        if (marks >= 70) return 'C';
        if (marks >= 60) return 'D';
        return 'F';
    }

    void display() const {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Marks: " << marks
             << " | Grade: " << getGrade() << '\n';
    }
};

vector<Student> students;

// Add a new student
void addStudent() {
    int id;
    string name;
    float marks;

    cout << "Enter student ID: ";
    cin >> id;

    // Check whether ID already exists
    auto it = find_if(students.begin(), students.end(),
        [id](const Student& s) {
            return s.id == id;
        });

    if (it != students.end()) {
        cout << "Student ID already exists!\n";
        return;
    }

    cout << "Enter student name: ";
    getline(cin >> ws, name);

    cout << "Enter marks (0-100): ";
    cin >> marks;

    if (!cin || marks < 0 || marks > 100) {
        cout << "Invalid marks!\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    students.emplace_back(id, name, marks);
    cout << "Student added successfully!\n";
}

// Display all students
void displayStudents() {
    if (students.empty()) {
        cout << "No student records found.\n";
        return;
    }

    for (const Student& s : students) {
        s.display();
    }
}

// Search using student ID
void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    auto it = find_if(students.begin(), students.end(),
        [id](const Student& s) {
            return s.id == id;
        });

    if (it != students.end()) {
        it->display();
    } else {
        cout << "Student not found!\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Please enter a valid number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 0:
                cout << "Goodbye!\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}