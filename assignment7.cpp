#include <iostream>
#include <fstream>
#include <string>  // For using std::string
using namespace std;

class Employee {
    string name;
    int ID;
    double salary;

public:
    // Function to get employee data from the user
    void getData() {
        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the ID: ";
        cin >> ID;
        cout << "Enter the salary: ";
        cin >> salary;
    }

    // Function to display employee data
    void displayData() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Salary: " << salary << endl;
    }

    // Function to write employee data to file
    void writeToFile(fstream &file) const {
        file << "Name: " << name << endl;
        file << "ID:" <<ID << endl;
        file <<"Salary: "<< salary << endl;
        file << endl;
    }

    // Function to read employee data from file
    void readFromFile(fstream &file) {
        file >> name;
        file >> ID;
        file >> salary;
    }
};

int main() {
    int n;

    // Asking user for the number of employees
    cout << "Enter the number of employees: ";
    cin >> n;

    Employee e[n];  // Dynamic creation of employee array
    fstream file;

    // Open file for writing
    file.open("demo.txt", ios::out);

    // Get data for each employee and write it to the file
    for (int i = 0; i < n; i++) {
        cout << "\nEnter information of employee " << i + 1 << endl;
        e[i].getData();
        e[i].writeToFile(file);  // Write data to file
    }
    file.close();  // Close the file after writing

    // Open file for reading
    file.open("demo.txt", ios::in);

    cout << "\nInformation of Employees is as follows:\n";

    // Read data from file and display for each employee
    for (int i = 0; i < n; i++) {
        cout << "\nEmployee " << i + 1 << ":\n";
        e[i].readFromFile(file);  // Read data from file
        e[i].displayData();       // Display the data
    }

    file.close();  // Close the file after reading

    return 0;
}
