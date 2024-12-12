#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class Student; // Forward declaration of the Student class

class Database {
private:
    static int totalStudents; // Static member to count total students

public:
    static void incrementCount() { totalStudents++; }
    static int getTotalStudents() { return totalStudents; }
};

int Database::totalStudents = 0; // Initialize static member

class Student {
private:
    string name;
    int rollNumber;
    string classDivision;
    string division;
    string dob; // Date of Birth
    string bloodGroup;
    string contactAddress;
    string telephoneNumber;
    string drivingLicenseNo;

public:
    // Default constructor
    Student() {
        name = "";
        rollNumber = 0;
        classDivision = "";
        division = "";
        dob = "";
        bloodGroup = "";
        contactAddress = "";
        telephoneNumber = "";
        drivingLicenseNo = "";
        Database::incrementCount();
    }

    // Parameterized constructor
    Student(string n, int roll, string cls, string div, string dob,
            string bg, string addr, string tel, string dl) {
        name = n;
        rollNumber = roll;
        classDivision = cls;
        division = div;
        this->dob = dob; // Using this pointer
        bloodGroup = bg;
        contactAddress = addr;
        telephoneNumber = tel;
        drivingLicenseNo = dl;
        Database::incrementCount();
    }

    // Copy constructor
    Student(const Student &s) {
        name = s.name;
        rollNumber = s.rollNumber;
        classDivision = s.classDivision;
        division = s.division;
        dob = s.dob;
        bloodGroup = s.bloodGroup;
        contactAddress = s.contactAddress;
        telephoneNumber = s.telephoneNumber;
        drivingLicenseNo = s.drivingLicenseNo;
        Database::incrementCount();
    }

    // Destructor
    ~Student() {
        // No dynamic memory to release in this case
    }

    // Inline member function to display student information
    inline void displayInfo() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Class: " << classDivision << endl;
        cout << "Division: " << division << endl;
        cout << "Date of Birth: " << dob << endl;
        cout << "Blood Group: " << bloodGroup << endl;
        cout << "Contact Address: " << contactAddress << endl;
        cout << "Telephone Number: " << telephoneNumber << endl;
        cout << "Driving License No.: " << drivingLicenseNo << endl;
        cout << endl;
    }

    // Function to get student details (can throw an exception)
    void getStudentDetails() {
        cout << "Enter student details:\n";
        cout << "Name: ";
        cin >> name;
        cout << "Roll Number: ";
        cin >> rollNumber;
        if (rollNumber <= 0) throw invalid_argument("Invalid Roll Number.");
        cout << "Class: ";
        cin >> classDivision;
        cout << "Division: ";
        cin >> division;
        cout << "Date of Birth (DD/MM/YYYY): ";
        cin >> dob;
        cout << "Blood Group: ";
        cin >> bloodGroup;
        cout << "Contact Address: ";
        cin.ignore(); // To ignore the newline after the roll number
        getline(cin, contactAddress);
        cout << "Telephone Number: ";
        cin >> telephoneNumber;
        cout << "Driving License No.: ";
        cin >> drivingLicenseNo;
    }
};

// Friend class example (for demonstration)
class Admin {
public:
    void viewStudentInfo(Student &s) {
        s.displayInfo(); // Accessing the displayInfo function of Student
    }
};

int main() {
    const int MAX_STUDENTS = 100; // Maximum number of students
    Student* students[MAX_STUDENTS]; // Dynamic array of student pointers
    int count = 0;

    try {
        while (count < MAX_STUDENTS) {
            students[count] = new Student(); // Dynamic allocation

            students[count]->getStudentDetails(); // Get student details
            count++;

            char choice;
            cout << "Do you want to add another student? (y/n): ";
            cin >> choice;
            if (choice != 'y') break; // Exit loop if not adding more
        }
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    cout << "\nTotal Students in Database: " << Database::getTotalStudents() << endl;

    // Display all students
    for (int i = 0; i < count; i++) {
        cout << "\nStudent " << (i + 1) << " Information:\n";
        students[i]->displayInfo();
        delete students[i]; // Free dynamic memory
    }

    return 0;
}
