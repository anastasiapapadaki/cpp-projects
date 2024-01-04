// Deggendorf Institute of Technology - vhb Exam
// Examination subject:     Programming in C++ / Part 1+2 (3 ECTS)
// Semester:                Winter 2020/21
// Examiner:                Prof. Dr. Herbert Fischer
// Score:                   90 Points
// Additional Materials:    None
// Duration:                90 Minutes

// ----- YOUR INFORMATION -----
// Street+House number: schumannstraße 16
// Surname, First name: Papadaki Anastasia
// Postcode + City: 90429, Nuremberg
// Matriculation number: 22902210
// E-Mail: anni1302@gmail.com and anastasia.p.papadaki@fau.de
// ----------------------------

// 1. Basics                          (15 minutes)
//
// 1.1 Declare a class Candle with the following data members:
// Height (in cm) and color. Choose appropriate data types. Only derived classes can change these data members.
// Define for the class:
// a) Default constructor
// b) Parameterized constructor with member initialization list
// c) Member function "data_output" for outputting all data of the class. The member function "data_output" should be defined outside of the class.
//
// 1.2 Definition of member functions:
// You know from experience that a candle loses an average of 3 cm in "height" every hour.
// Define a member function "updateHeight" with a parameter "burning_hours" and a suitable data type for it.
// The task of the member function is to update the "height" of the candle based on the hours.
// If the candle has burned down after the update, the user should get a corresponding message,
// otherwise the user gets as the output the current height of the candle.
//
// 1.3 Dynamic instantiation:
// Define two dynamic objects of the class Candle. Since the values of the data members do not have to be queried (=not typed in by the user),
// they can be passed as static members.
// Call the member function "data_output" for the second instance and the member function "updateHeight" for the first instance.

#include <iostream>
using namespace std;

class Candle{
private:
float height;
string color;
public:
    Candle(){};
    Candle(float h, string c): height (h), color (c){}
    float update_height(float burning time);
};
int main()
{
Candle*height= new Candle(10); // creates a dynamic object with overloaded constructor

Candle*brand= new Candle(); // creates a dynamic object with an empty constructor
Candle -> data_output();
    return 0;
}
