// We'll build a Employee Management System (EMS) in C++14. The EMS will allow users to add, view, and manage employee records. 

#include<iostream>
using namespace std;

class Employee{
    private:
        int id;
        string name;
        string position;
        int salary;

    public:
        Employee(int emp_id , string emp_name , string emp_position , int emp_salary){
            id = emp_id;
            name=emp_name;
            position=emp_position;
            salary=emp_salary;
        }
};

void addEmployee(){
    int id;
    string name;
    string position;
    int salary;

    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Employee Name: ";
    cin >> name;
    cout << "Enter Employee Position: ";
    cin >> position;
    cout << "Enter Employee Salary: ";
    cin >> salary;

    Employee newEmployee(id, name, position, salary);
    // Here you would typically add the new employee to a collection (like a vector) to manage them.
}

void viewEmployees(){
    
}

void manageEmployees(){
   int n; cout<<"Enter the number of employees to manage: "; cin>>n;
    for(int i=0; i<n; i++){
        int id; string name; string position; int salary;
        cout << "Enter Employee ID: "; cin >> id;
        cout << "Enter Employee Name: "; cin >> name;
        cout << "Enter Employee Position: "; cin >> position;
        cout << "Enter Employee Salary: "; cin >> salary;
        cout << "Managing Employee ID: " << id << ", Name: " << name << ", Position: " << position << ", Salary: " << salary << endl;
    }
}

void deleteEmployee(){
    int id;
    cout << "Enter Employee ID to delete: ";
    cin >> id;
    // Here you would typically remove the employee from a collection (like a vector) based on the ID.
    cout << "Employee with ID " << id << " has been deleted." << endl;
}

void displayMenu(){
    cout << "Employee Management System (EMS)" << endl;
    cout << "1. Add Employee" << endl;
    cout << "2. View Employees" << endl;
    cout << "3. Manage Employees" << endl;
    cout << "4. Delete Employee" << endl;
    cout << "5. Exit" << endl;
}

void handleUserChoice(int choice){
    switch(choice){
        case 1:
            addEmployee();
            break;
        case 2:
            viewEmployees();
            break;
        case 3:
            manageEmployees();
            break;
        case 4:
            deleteEmployee();
            break;
        case 5:
            cout << "Exiting the system." << endl;
            exit(0);
        default:
            cout << "Invalid choice. Please try again." << endl;
    }
}

void runEMS(){
    while(true){
        displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        handleUserChoice(choice);
    }
}

int main(){
    runEMS();
    return 0;
}