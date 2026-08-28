//============================================================================
// Name        : EmployeeClass.cpp
// Author      : Mansi Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    int empId;
    string name;
    string department;
    char grade;
    double basicSalary;
    bool isActive;

    static int employeeCount;
    static int nextId;

public:

    // Constructor
    Employee()
    {
        empId = nextId++;
        name = "";
        department = "";
        grade = 'D';
        basicSalary = 10001;
        isActive = true;

        employeeCount++;
    }

    // Set name
    void setName(const string& n)
    {
        if (n.empty())
            cout << "ERROR: Name cannot be empty." << endl;
        else
            name = n;
    }

    // Set department
    void setDepartment(const string& dept)
    {
        if (dept == "Engineering" ||
            dept == "HR" ||
            dept == "Finance" ||
            dept == "Operations")
        {
            department = dept;
        }
        else
        {
            cout << "ERROR: '" << dept
                 << "' is not a registered department." << endl;
        }
    }

    // Set grade
    void setGrade(char g)
    {
        if (g == 'A' || g == 'B' || g == 'C' || g == 'D')
        {
            grade = g;
        }
        else
        {
            cout << "ERROR: Invalid grade '" << g
                 << "'. Accepted values: A, B, C, D." << endl;
        }
    }

    // Set salary
    void setBasicSalary(double salary)
    {
        if (salary > 10000 && salary < 500000)
        {
            basicSalary = salary;
        }
        else
        {
            cout << "ERROR: Salary must be between Rs.10,000 "
                 << "and Rs.5,00,000. Value rejected." << endl;
        }
    }

    // Deactivate employee
    void deactivate()
    {
        isActive = false;
    }

    // Getters
    int getEmpId() const
    {
        return empId;
    }

    string getName() const
    {
        return name;
    }

    string getDepartment() const
    {
        return department;
    }

    char getGrade() const
    {
        return grade;
    }

    double getBasicSalary() const
    {
        return basicSalary;
    }

    bool getIsActive() const
    {
        return isActive;
    }

    // Calculate allowance
    double computeAllowances() const
    {
        if (grade == 'A')
            return basicSalary * 0.40;

        if (grade == 'B')
            return basicSalary * 0.30;

        if (grade == 'C')
            return basicSalary * 0.20;

        return basicSalary * 0.10;
    }

    // Calculate gross salary
    double computeGrossSalary() const
    {
        return basicSalary + computeAllowances();
    }

    // Calculate tax
    double computeTax() const
    {
        double gross = computeGrossSalary();

        if (gross <= 50000)
            return 0;

        else if (gross <= 100000)
            return (gross - 50000) * 0.10;

        else
            return 5000 + (gross - 100000) * 0.20;
    }

    // Calculate net salary
    double computeNetSalary() const
    {
        return computeGrossSalary() - computeTax();
    }

    // Accept employee details
    void acceptDetails()
    {
        string n, dept;
        char g;
        double salary;

        cout << "Enter name: ";
        cin >> n;
        setName(n);

        cout << "Enter department: ";
        cin >> dept;
        setDepartment(dept);

        cout << "Enter grade: ";
        cin >> g;
        setGrade(g);

        cout << "Enter basic salary: ";
        cin >> salary;
        setBasicSalary(salary);
    }

    // Print payslip
    void printPayslip() const
    {
        cout << "\n============================================" << endl;
        cout << "           EMPLOYEE PAYSLIP" << endl;
        cout << "============================================" << endl;

        cout << "Emp ID : " << empId << endl;
        cout << "Name : " << name << endl;
        cout << "Department : " << department << endl;
        cout << "Grade : " << grade << endl;

        if (isActive)
            cout << "Status : Active" << endl;
        else
            cout << "Status : Inactive" << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Basic Salary : Rs. " << basicSalary << endl;
        cout << "Allowances : Rs. " << computeAllowances() << endl;
        cout << "Gross Salary : Rs. " << computeGrossSalary() << endl;

        cout << "--------------------------------------------" << endl;

        cout << "Tax Deduction : Rs. " << computeTax() << endl;
        cout << "Net Salary : Rs. " << computeNetSalary() << endl;

        cout << "============================================" << endl;
    }

    // Static function
    static int getEmployeeCount()
    {
        return employeeCount;
    }
};


// Initialize static variables
int Employee::employeeCount = 0;
int Employee::nextId = 1001;


int main()
{
    // Stack object
    Employee e1;

    // Heap objects
    Employee* e2 = new Employee();
    Employee* e3 = new Employee();

    // Enter details
    e1.acceptDetails();
    e2->acceptDetails();
    e3->acceptDetails();

    // These would give compiler errors because
    // empId and basicSalary are private.
    //
    // e1.empId = 999;
    // e1.basicSalary = -1000;

    // Print payslips
    e1.printPayslip();
    e2->printPayslip();
    e3->printPayslip();

    // Resignation
    e3->deactivate();

    if (!e3->getIsActive())
    {
        cout << e3->getName()
             << " is no longer active. Payroll skipped."
             << endl;
    }

    // Employee count
    cout << "Total Employees : "
         << Employee::getEmployeeCount()
         << endl;

    // Delete heap objects
    delete e2;
    delete e3;

    return 0;
}
