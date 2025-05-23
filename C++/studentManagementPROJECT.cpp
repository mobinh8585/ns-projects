#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

// By https://github.com/mobinh8585, Licensed under MIT License, 2025.";


struct Student {
    int studentID;
    string name;
    int age;
    double gpa;
};

const int MAX_STUDENTS = 100;
const string FILENAME = "students.txt";

int studentCount = 0;
Student studentsArray[MAX_STUDENTS];

void loadStudentsFromFile();
void saveStudentsToFile();
void importMultipleStudent();
void addStudent();
void searchStudent();
void editStudent();
void deleteStudent();
void showAllStudents();
void showoneStudent(int index);
void sortStudents();
void mainMenu();
void swap(Student &a, Student &b);
int searchbyID(int id);
int searchbyName(string name);






int main() {

    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);    

    cout << "Welcome to Student Management System App\nMade by https://github.com/mobinh8585, Licensed under MIT License, 2025.\n";
    loadStudentsFromFile();
    mainMenu();
    return 0;
}

void mainMenu() {

    while (true) {

    cout << "\n";
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║           MAIN MENU                  ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║ 1. Import Multiple Student           ║\n";
    cout << "║ 2. Add Student                       ║\n";
    cout << "║ 3. Search Student                    ║\n";
    cout << "║ 4. Edit Student                      ║\n";
    cout << "║ 5. Delete Student                    ║\n";
    cout << "║ 6. Sort Students                     ║\n";
    cout << "║ 7. Show All Students                 ║\n";
    cout << "║ 8. Exit                              ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    cout << "Enter your choice (1-8): ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            system("cls");
            importMultipleStudent();
            break;
        case 2:
            system("cls");
            addStudent();
            break;
        case 3:
            system("cls");
            searchStudent();
            break;
        case 4:
            system("cls");
            editStudent();
            break;
        case 5:
            system("cls");
            deleteStudent();
            break;
        case 6:
            system("cls");
            sortStudents();
            break;
        case 7:
            system("cls");
            showAllStudents();
            break;
        case 8:
            system("cls");
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
    }
}

}

void saveStudentsToFile() {
    
    fstream file;
    file.open(FILENAME, ios::out);
    
    if (file.is_open()) {
        for (int i = 0; i < studentCount; i++) {
            file << studentsArray[i].studentID << ","
                 << studentsArray[i].name << ","
                 << studentsArray[i].age << ","
                 << studentsArray[i].gpa << "\n";
        }
        file.close();
    }
    else {
        cout << "Unable to open file.\n";
        return;
    }
    
    
    cout << "Students saved to file successfully.\n";
    
}

void importMultipleStudent() {

    cout << "\n";
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║           IMPORT MULTIPLE STUDENTS   ║\n";
    cout << "╚══════════════════════════════════════╝\n";

    int numToImport;
    cout << "Enter the number of students you want to import: (max " << MAX_STUDENTS - studentCount << ") ";
    cin >> numToImport;

    if (numToImport > MAX_STUDENTS - studentCount) {
        cout << "Error: Number of students to import exceeds maximum limit.\n";
        return;
    }

    for (int i = 0; i < numToImport; i++) {
        cout << "Enter student " << i + 1 << " ID: ";
        cin >> studentsArray[studentCount + i].studentID;
        cout << "Enter student " << i + 1 << " name: ";
        cin >> studentsArray[studentCount + i].name;
        cout << "Enter student " << i + 1 << " age: ";
        cin >> studentsArray[studentCount + i].age;
        cout << "Enter student " << i + 1 << " GPA: ";
        cin >> studentsArray[studentCount + i].gpa;
    }

    studentCount += numToImport;
    
    saveStudentsToFile();
    
    cout << "Saving data to file...\n";
    cout << "\n" << numToImport << " students imported successfully.\n";
    cout << "Total students now: " << studentCount << "\n";
    
    
}

void searchStudent() {
    
    cout << "\n";
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║           SEARCH STUDENT             ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    
    cout << "Do you want to search by ID or name? (ID/Name): ";
    string choice;
    cin >> choice;

    if (choice == "ID" || choice == "id" || choice == "Id") {

        cout << "Enter student ID: ";
        int id;
        cin >> id;

        int index = searchbyID(id);

        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }   

        showoneStudent(index);
        
        
    } else if (choice == "Name" || choice == "name" || choice == "NAME") {

        cout << "Enter student name: ";
        string name;
        cin >> name;
        
        int index = searchbyName(name);

        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }   

        showoneStudent(index);
        
        
    } else {
        cout << "Invalid choice. Please try again.\n";
    }
    
}


int searchbyID(int id) {

    for (int i = 0; i < studentCount; i++) {
        if (studentsArray[i].studentID == id) {
            return i;
        }
    }
    return -1;
    
}

int searchbyName(string name) {

    for (int i = 0; i < studentCount; i++) {
        if (studentsArray[i].name == name) {
            return  i;
        }
    }
    return -1;
    
}

void editStudent() {

    cout << "\n";
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║              EDIT STUDENT            ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    
    cout << "Do you want to edit by ID or name? (ID/Name): ";
    string choice;
    cin >> choice;
    int index;

    if (choice == "ID" || choice == "id" || choice == "Id") {

        cout << "Enter student ID: ";
        int id;
        cin >> id;

        index = searchbyID(id);

        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }   

        showoneStudent(index);
        
        
    } else if (choice == "Name" || choice == "name" || choice == "NAME") {

        cout << "Enter student name: ";
        string name;
        cin >> name;
        
        index = searchbyName(name);

        if (index == -1) {
            cout << "Student not found.\n";
            return;
        }   

        showoneStudent(index);
        
        
    } else {
        cout << "Invalid choice. Please try again.\n";
        return;
    }

    cin.ignore();
    
    cout << "Enter new student ID (or press Enter to keep current: " << studentsArray[index].studentID << "): ";
    string input;
    getline(cin, input);
    if (!input.empty()) {
        studentsArray[index].studentID = stoi(input);
    }
    
    cout << "Enter new student name (or press Enter to keep current: " << studentsArray[index].name << "): ";
    getline(cin, input);
    if (!input.empty()) {
        studentsArray[index].name = input;
    }
    
    cout << "Enter new student age (or press Enter to keep current: " << studentsArray[index].age << "): ";
    getline(cin, input);
    if (!input.empty()) {
        studentsArray[index].age = stoi(input);
    }
    
    cout << "Enter new student GPA (or press Enter to keep current: " << studentsArray[index].gpa << "): ";
    getline(cin, input);
    if (!input.empty()) {
        studentsArray[index].gpa = stod(input);
    }


    saveStudentsToFile();
    
    cout << "Student updated successfully.\n";
    
}

void deleteStudent() {

    cout << "\n";
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║           DELETE STUDENT             ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    
    cout << "Do you want to delete by ID or name? (ID/Name): ";

    string choice;
    cin >> choice;

    int index = -1;

    if (choice == "ID" || choice == "id" || choice == "Id") {
        cout << "Enter student ID to delete: ";
        int id;
        cin >> id;
        index = searchbyID(id);
    } else if (choice == "Name" || choice == "name" || choice == "NAME") {
        cout << "Enter student name to delete: ";
        string name;
        cin >> name;
        index = searchbyName(name);
    }
    

    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    for (int i = index; i < studentCount - 1; i++) {
        studentsArray[i] = studentsArray[i + 1];
    }
    studentsArray[studentCount - 1] = Student();
    studentCount--;

    saveStudentsToFile();
    cout << "Student deleted successfully.\n";
    
}

void showoneStudent(int index) {

    cout << "\n";
    cout << "----------------------------------------\n";
    cout << "Student " << index + 1 << " ID: " << studentsArray[index].studentID << '\n';
    cout << "Student " << index + 1 << " name: " << studentsArray[index].name << '\n';
    cout << "Student " << index + 1 << " age: " << studentsArray[index].age << '\n';
    cout << "Student " << index + 1 << " GPA: " << studentsArray[index].gpa << '\n';
    cout << "----------------------------------------\n";
    
}

void sortStudents() {

    cout << "\n";
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║      SORT STUDENTS(low to high)      ║\n";
    cout << "╠══════════════════════════════════════╣\n";
    cout << "║ 1. Sort by name                      ║\n";
    cout << "║ 2. Sort by age                       ║\n";
    cout << "║ 3. Sort by GPA                       ║\n";
    cout << "║ 4. Sort by ID                        ║\n";
    cout << "╚══════════════════════════════════════╝\n";
    cout << "Enter your choice (1-4): ";
    
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            for (int i = 0; i < studentCount - 1; i++) {
                for (int j = 0; j < studentCount - i - 1; j++) {
                    if (studentsArray[j].name > studentsArray[j + 1].name) {
                        swap(studentsArray[j], studentsArray[j + 1]);
                    }
                }
            }
            showAllStudents();
            saveStudentsToFile();
            break;
        case 2:
            for (int i = 0; i < studentCount - 1; i++) {
                for (int j = 0; j < studentCount - i - 1; j++) {
                    if (studentsArray[j].age > studentsArray[j + 1].age) {
                        swap(studentsArray[j], studentsArray[j + 1]);
                    }
                }
            }
            showAllStudents();
            saveStudentsToFile();
            break;
        case 3:
            for (int i = 0; i < studentCount - 1; i++) {
                for (int j = 0; j < studentCount - i - 1; j++) {
                    if (studentsArray[j].gpa > studentsArray[j + 1].gpa) {
                        swap(studentsArray[j], studentsArray[j + 1]);
                    }
                }
            }
            showAllStudents();
            saveStudentsToFile();
            break;
        case 4:
            for (int i = 0; i < studentCount - 1; i++) {
                for (int j = 0; j < studentCount - i - 1; j++) {
                    if (studentsArray[j].studentID > studentsArray[j + 1].studentID) {
                        swap(studentsArray[j], studentsArray[j + 1]);
                    }
                }
            }
            showAllStudents();
            saveStudentsToFile();
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
    }

}

void showAllStudents() {
    
    for (int i = 0; i < studentCount; i++) {
        showoneStudent(i);
    }

    
}

void swap(Student &a, Student &b) {
    Student temp = a;
    a = b;
    b = temp;
}   


void addStudent() {

    cout << "\n";
    cout << "╔══════════════════════════════════════╗\n";
    cout << "║           ADD STUDENT                ║\n";
    cout << "╚══════════════════════════════════════╝\n";

    if (studentCount >= MAX_STUDENTS) {
        cout << "Error: Cannot add more students. Maximum limit reached!\n";
        return;
    }

    cout << "Enter student ID: ";
    cin >> studentsArray[studentCount].studentID;
    cout << "Enter student name: ";
    cin >> studentsArray[studentCount].name;
    cout << "Enter student age: ";
    cin >> studentsArray[studentCount].age;
    cout << "Enter student GPA: ";
    cin >> studentsArray[studentCount].gpa;
    
    studentCount++;


    saveStudentsToFile();
    cout << "Student added successfully.\n";

}

void loadStudentsFromFile() {
    fstream file;
    file.open(FILENAME, ios::in);
    if (!file.is_open()) {

        cout << "File not found or could not be opened. Starting with an empty list." << endl;
        return;
    }

    studentCount = 0;
    string line;
    while (getline(file, line) && studentCount < MAX_STUDENTS) {
        stringstream ss(line);
        string tempinfo;

        if (getline(ss, tempinfo, ',')) {
            studentsArray[studentCount].studentID = stoi(tempinfo);
        }
        if (getline(ss, tempinfo, ',')) {
            studentsArray[studentCount].name = tempinfo;
        }
        if (getline(ss, tempinfo, ',')) {
            studentsArray[studentCount].age = stoi(tempinfo);
        }
        if (getline(ss, tempinfo)) {
            studentsArray[studentCount].gpa = stod(tempinfo);
        }
        studentCount++;
    }
    file.close();
    cout << studentCount << " Students loaded from file.\n";
}
