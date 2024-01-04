// Deggendorf Institute of Technology - vhb Exam
// Examination subject:     Programming in C++ / Part 1+2 (3 ECTS)
// Semester:                Winter 2020/21
// Examiner:                Prof. Dr. Herbert Fischer
// Score:                   90 Points
// Additional Materials:    None
// Duration:                90 Minutes

// ----- YOUR INFORMATION -----
// Street+House number: Schumannstraﬂe 16
// Surname, First name: Papadaki Anastasia
// Postcode + City: 90429, Nuremberg
// Matriculation number: 22902210
// E-Mail: anni1302@gmail.com and anastasia.p.papadaki@fau.de
// ----------------------------

#include <iostream>
using namespace std;

// 5.   Linked lists                (20 minutes)
//
// 5.1  Add the data members in the class Employee, which are required for a linked list (suitable for the class ListOfEmployees).
//
// 5.2  Add the following to the class Employee:
//      a) Default constructor
//      b) Parameterized constructor with member initialization list
//      c) Member function "data_output" for outputting all employee data
//
// 5.3  In the main function, 3 employee objects have to be added to the list.
//      Output the employee data from the list using a for loop.
//      Extend the program by the member functions, which are required for this.

class Employee
{
private:
    string name;
    short birthYear;
public:
    Employee(){};
    Employee(string na, short boy):name (na),birthYear(boy) {}
    void data_output();

};

class ListOfEmployees{
private:
    Employee *Head;
public:
    ListOfEmployees():Head(0){};
    void insert (Employee *t) {
        string empname;
        short year;
        cout << "Employee name: ";
        cin >> empname;
        cout << endl << "Year of birth: ";
        cin >> year;
        t->name = empname;
        t->birthYear = year;
        t->successor = Head;
        Head = t;
    }

};

int main()
{
for i


    return 0;
}
