// Deggendorf Institute of Technology - vhb Exam
// Examination subject:     Programming in C++ / Part 1+2 (3 ECTS)
// Semester:                Winter 2020/21
// Examiner:                Prof. Dr. Herbert Fischer
// Score:                   90 Points
// Additional Materials:    None
// Duration:                90 Minutes

// ----- YOUR INFORMATION -----
// Street+House number: Schumannstraße 16
// Surname, First name: Papadaki Anastasia
// Postcode + City: 90429, Nuremberg
// Matriculation number: 22902210
// E-Mail: anni1302@gmail.com and anastasia.p.papadaki@fau.de
// ----------------------------

// 4.   Operator overloading            (25 minutes)
//
// 4.1  Extend the program by an external function, which examines 2 objects for equality.
//      If both objects are the same, i.e. the two numbers are equal, the user should get the output "objects are equal".
//      If the objects are not equal, then the user should get the output "objects are not equal".
//
// 4.2  Extend the program by overloading the opperators istream >> and ostream <<.
//      With istream, the query should be made for number1 and number2.
//      With ostream, both numbers should be printed on the screen.
//
// 4.3  Create two objects of the class Numbers dynamically.
//      The data should be entered by the user (via istream from 4.2).
//      Output the numbers you entered (via ostream from 4.2).
//      Compare the two objects using the external function from 4.1.

#include <iostream>
using namespace std;

class Numbers {
private:
    int number1, number2;
public:
    Numbers(int n1, int n2): number1(n1), number2(n2) {};
    friend bool operator==( int Numbers number1, int Numbers number2);

};
bool operator==( const Numbers number1, const Numbers number2)
{
    int n;
    if ( n ==number1 && n==number2  )
        return (True);
    else
        return(False);

};

int main()

{



    return 0;
}
