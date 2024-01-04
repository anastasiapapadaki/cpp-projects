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

// 2. Arrays                          (10 minutes)
//
// In the program below, a two-dimensional array named "expenditure" is defined, in which the expenditure of the last three years over 12 months is stored.
// In the second year the expenditure increased by exactly 20% compared to the previous year and in the third year by exactly 10% compared to the previous year for each month.
// Expand the program with exactly this adjustment of the expenses in the second and third year and store them accordingly in the array "expenditure".
// Finally, output the data using a for loop.

int main()
{
    double expenditure[3][12] = {{10,15,20,36,15,45,20,35,24,64,52,12},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
    double expenditure2[3][12] = {{10,15,20,36,15,45,20,35,24,64,52,12},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};
    double expenditure3[3][12] = {{10,15,20,36,15,45,20,35,24,64,52,12},{0,0,0,0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,0,0}};

    int i;
    int j;
    for (i=0; i<3++i)
    for (j=0; j<12++i)
     double expenditure[i][j] =i;j;
 // Second Month= 0,2 *First Year
    int i;
    int j;
    for (i=0; i<3++i)
    for (j=0; j<12++i)
     double expenditure2[i][j] = double expenditure[i][j] *0.2;

// Third Month= 0,1 *First Year
    int i;
    int j;
    for (i=0; i<12++i)
    for (j=0; j<3++i)
     double expenditure3[i][j] = double expenditure[i][j] *0.1;

    return 0;
}
