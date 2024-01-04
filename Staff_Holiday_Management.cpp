//Creating a program for the staff holiday management at your college
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Date{
public:
int day;
int month;
int year;

void printDate(){
cout<<day<<"/"<<month<<"/"<<year<<"\n";
}
Date(){
day = 13;
month = 2;
year = 1996;
}
Date(int a , int b, int c){
day = a;
month = b;
year = c;
}
};

class Employee{
private:
string firstName;
string surName;
Date dateOfBirth;
string typeofEmp;
vector<Date> holiDays;
int countHolidays;
int oldAge;

public:
Employee(string s1 , string s2 , Date dob){
surName = s2;
dateOfBirth = dob;
firstName = s1;
if(dob.year < 1970)
oldAge = 1;
else
oldAge = 0;

countHolidays = 0;
cout<<"Employee called\n";
}
Employee(){
firstName = "";
surName = "";
Date dob(0 , 0 ,0);
dateOfBirth = dob;
}
void printEmployee(){
cout<<"|||Employee Name : ";
cout<<firstName<<" "<<surName<<"\n";
cout<<"|||dob :";
dateOfBirth.printDate();
cout<<"Total Leave Taken : "<<countHolidays;
cout<<"\n";
            int totalPossible;
if(oldAge == 0)
totalPossible = 30;
else
totalPossible = 32;
cout<<"Remaining days of holiday : "<<totalPossible - countHolidays;
cout<<"\n";
}
void printAllLeaveDates(){
cout<<"||| Dates on which Employee Taken the Leave\n";
vector<Date> :: iterator it;
for(it = holiDays.begin() ; it !=  holiDays.end() ; it++){
(*it).printDate();
}
}
void setEmp(string s1 , string s2 , Date dob){
firstName = s1;
surName = s2;
dateOfBirth = dob;
if(dob.year < 1970)
oldAge = 1;
else
oldAge = 0;

cout<<"Employee Edited\n";
}
string getFirstName(){
return firstName;
}

string getLastName(){
return surName;
}

int giveLeave(Date leaveDate){
int totalPossible;
if(oldAge == 0)
totalPossible = 30;
else
totalPossible = 32;

if(countHolidays < totalPossible){
holiDays.push_back(leaveDate);
countHolidays++;
cout<<"|||\n";
cout<<"Leave Granted!\n";
return 1;
}
else{
cout<<"### MESSAGE ###\n";
cout<<"You already Crossed the limit of maximum holidays...Sorry :(\n";
return 0;
}
}
};

//Manager
class Manager : public Employee
{
public:
   Manager(){
        profit_sharing=100000; //default_value_100000_euros}
};

   Manager (string s1 , string s2 , Date dob, double new_profit_sharing): Employee(s1 , s2 ,  dob )
{ profit_sharing=new_profit_sharing;
};
 // functions
 double get_profit_sharing( ) const{
        return profit_sharing;
    };
    void set_profit_sharing(double new_profit_sharing){
        profit_sharing =  new_profit_sharing;
    };
void print( ) ;
private:
//data
double profit_sharing; //annually
};

//HourlyEmployee
class HourlyEmployee : public Employee
{
public:
    HourlyEmployee( ){
      //  Employee();
        hourly_wage=0.; //default_value
        hourly_worked=0.; //default_value
    };
    HourlyEmployee (string s1 , string s2 , Date dob, double new_hourly_wage, double new_hours_worked): Employee(s1 , s2 ,  dob)
{
    hourly_wage =  new_hourly_wage;
    hourly_worked= new_hours_worked;
};


    double get_hourly_wage( ) const{
        return hourly_wage;
    };
    void set_hourly_wage(double new_hourly_wage){
        hourly_wage =  new_hourly_wage;
    };

    double get_hours_worked( ) const{
        return hourly_worked;
    };
    void set_hours_worked(double new_hours_worked){
        hourly_worked= new_hours_worked;
    };

    void print( ) ;
private:
    double hourly_wage; //weekly
    double hourly_worked; //weekly
};

//SalariedEmployee
class SalariedEmployee : public Employee
{
public:
    SalariedEmployee( ){
        Employee();
        annual_salary=8500.; //default_value_8500_euros
        };
     SalariedEmployee (string s1 , string s2 , Date dob, double new_annual_salary): Employee(s1 , s2 ,  dob)
{ annual_salary = new_annual_salary;
};
// functions
 double get_annual_salary( ) const{
        return annual_salary;
    };
    void set_annual_salary(double new_annual_salary){
        annual_salary =  new_annual_salary;
    };
void print( ) ;
private:
//data
double annual_salary; //weekly
};


//creating employee
void createEmployee(vector<Manager> &Emp)
{
string s1 , s2;
int a , b, c;
double profit_sharing;
cout<<"Enter Manager Employee First Name :  ";
cin>>s1;
cout<<"Enter Manager Employee SurName :  ";
cin>>s2;
cout<<"Enter Date Of Birth(format : 13 02 1996):  ";
cin>>a;
cin>>b;
cin>>c;
Date dob(a ,b ,c);
cout<<"Enter a profit sharing($):  ";
cin>>profit_sharing;


Manager e1(s1,s2,dob,profit_sharing);
Emp.push_back(e1);
cout<<"Manager Employee Created:)\n\n";
}
void createEmployee(vector<SalariedEmployee> &Emp)
{
string s1 , s2;
int a , b, c;
double annual_salary;;
cout<<"Enter Salaried Employee First Name :  ";
cin>>s1;
cout<<"Enter Salaried Employee Surname :  ";
cin>>s2;
cout<<"Enter Date Of Birth(format : 13 02 1996):  ";
cin>>a;
cin>>b;
cin>>c;
Date dob(a ,b ,c);
cout<<"Enter an annual salary($):  ";
cin>>annual_salary;

SalariedEmployee e1(s1,s2,dob,annual_salary);
Emp.push_back(e1);

cout<<"Salaried Employee Created:)\n\n";
}
 void createEmployee(vector<HourlyEmployee> &Emp)
{

string s1 , s2;
int a , b, c;
double hourly_wage, hourly_worked ;
cout<<"Enter Hourly Employee First Name :  ";
cin>>s1;
cout<<"Enter Hourly Employee SurName :  ";
cin>>s2;
cout<<"Enter Date Of Birth(format : 13 02 1996):  ";
cin>>a;
cin>>b;
cin>>c;
Date dob(a ,b ,c);
cout<<"Enter Hourly wage:  ";
cin>>hourly_wage;
cout<<"Enter Hourly worked:  ";
cin>>hourly_worked;

HourlyEmployee e1(s1,s2,dob,hourly_wage, hourly_worked );
Emp.push_back(e1);

cout<<"Hourly Employee Created:)\n\n";

}



//delete Manager
void deleteEmployee(vector<Manager> &Emp){
int count = Emp.size();
if(count == 0){
cout<<"There is no Manager Employee to Delete\n";
return;
}

string s1,s2;
cout<<"Enter the first name of Manager employee : ";
cin>>s1;
cout<<"Enter the last name of Manager employee : ";
cin>>s2;

vector<Manager> :: iterator target = Emp.begin();
vector<Manager> :: iterator it;
for(it = Emp.begin() ; it != Emp.end() ; it++){
if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
target = it;
break;
}
}
if(target == Emp.begin()){
cout<<"Manager Employee NOT FOUND !!!\n";
}
else{
Emp.erase(target);
cout<<"Manager Employee Deleted!!!\n";
}
}
//delete SalariedEmployee
void deleteEmployee(vector<SalariedEmployee> &Emp){
int count = Emp.size();
if(count == 0){
cout<<"There is no Salaried Employee to Delete\n";
return;
}

string s1,s2;
cout<<"Enter the first name of Salaried employee : ";
cin>>s1;
cout<<"Enter the last name of Salaried employee : ";
cin>>s2;

vector<SalariedEmployee>  :: iterator target = Emp.begin();
vector<SalariedEmployee>  :: iterator it;
for(it = Emp.begin() ; it != Emp.end() ; it++){
if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
target = it;
break;
}
}
if(target == Emp.begin()){
cout<<"Salaried Employee NOT FOUND !!!\n";
}
else{
Emp.erase(target);
cout<<"Salaried Employee Deleted!!!\n";
}
}

//delete HourlyEmployee
void deleteEmployee(vector<HourlyEmployee> &Emp){
int count = Emp.size();
if(count == 0){
cout<<"There is no Hourly Employee to Delete\n";
return;
}

string s1,s2;
cout<<"Enter the first name of Hourly employee : ";
cin>>s1;
cout<<"Enter the last name of Hourly employee : ";
cin>>s2;

vector<HourlyEmployee> :: iterator target = Emp.begin();
vector<HourlyEmployee> :: iterator it;
for(it = Emp.begin() ; it != Emp.end() ; it++){
if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
target = it;
break;
}
}
if(target == Emp.begin()){
cout<<"Hourly Employee NOT FOUND !!!\n";
}
else{
Emp.erase(target);
cout<<"Hourly Employee Deleted!!!\n";
}
}



//display all employees
void displayAllEmployees(vector<Manager> &Emp){
int count =  Emp.size();
if(count == 0)
cout<<"No Manager Employee available!\n";

else{
for(int i = 0 ; i < count ; i++){
cout<<"|||"<<i+1<<".\n";
Emp[i].printEmployee();
cout<<"\n\n";
Emp[i].get_profit_sharing( );
cout<<"Print the profit sharing : "<<Emp[i].get_profit_sharing( );
cout<<"\n\n";
}
}
}

//display all employees
void displayAllEmployees(vector<SalariedEmployee> &Emp){
int count =  Emp.size();
if(count == 0)
cout<<"No Salaried Employee available!\n";

else{
for(int i = 0 ; i < count ; i++){
cout<<"|||"<<i+1<<".\n";
Emp[i].printEmployee();
cout<<"\n\n";
Emp[i].get_annual_salary( );
cout<<"Print the annual profit : "<<Emp[i].get_annual_salary( );
cout<<"\n\n";
}
}
}

//display all employees
void displayAllEmployees(vector<HourlyEmployee> &Emp){
int count =  Emp.size();
if(count == 0)
cout<<"No Hourly Employee available!\n";

else{
for(int i = 0 ; i < count ; i++){
cout<<"|||"<<i+1<<".\n";
Emp[i].printEmployee();
cout<<"\n\n";
Emp[i].get_hourly_wage( );
cout<<"Print the hourly wage : "<<Emp[i].get_hourly_wage( );
cout<<"\n\n";
Emp[i].get_hours_worked( );
cout<<"Print the hours worked : "<<Emp[i].get_hours_worked( );
cout<<"\n\n";
}
}
}


// display one employee by the type of Employee
void displayOneEmployee(vector<Manager> &Emp){
string s1 , s2;
cout<<"Enter the details of that Manager Employee\n";
cout<<"First Name : ";
cin>>s1;
cout<<"Last Name : ";
cin>>s2;

vector<Manager> :: iterator it;
for(it = Emp.begin() ; it != Emp.end() ; it++){
if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
cout<<"|||#\n";
(*it).printEmployee();
(*it).printAllLeaveDates();
break;
}
}
if(it==Emp.end())
cout<<"Manager Employee NOT FOUND !!!\n";
}

// display one employee by the type of Employee
void displayOneEmployee(vector<SalariedEmployee> &Emp){
string s1 , s2;
cout<<"Enter the details of that Salaried Employee\n";
cout<<"First Name : ";
cin>>s1;
cout<<"Last Name : ";
cin>>s2;

vector<SalariedEmployee> :: iterator it;
for(it = Emp.begin() ; it != Emp.end() ; it++){
if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
cout<<"|||#\n";
(*it).printEmployee();
(*it).printAllLeaveDates();
break;
}
}
if(it==Emp.end())
cout<<"Salaried Employee NOT FOUND !!!\n";
}

// display one employee by the type of Employee
void displayOneEmployee(vector<HourlyEmployee> &Emp){
string s1 , s2;
cout<<"Enter the details of that Hourly Employee\n";
cout<<"First Name : ";
cin>>s1;
cout<<"Last Name : ";
cin>>s2;

vector<HourlyEmployee> :: iterator it;
for(it = Emp.begin() ; it != Emp.end() ; it++){
if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
cout<<"|||#\n";
(*it).printEmployee();
(*it).printAllLeaveDates();
break;
}
}
if(it==Emp.end())
cout<<"Hourly Employee NOT FOUND !!!\n";
}


//Give a Leave
void giveALeave(vector <Manager> &Emp){
string s1 , s2;
cout<<"##Enter the Details of Manager Employee\n";
cout<<"First Name : ";
cin>>s1;
cout<<"Last Name : ";
cin>>s2;
cout<<"Enter the date Manager Emoloyee Want Leave For(format : 01 01 2000) : ";
int a,b,c;
cin>>a>>b>>c;
Date leaveDate (a,b,c);

vector<Manager> :: iterator it;
for(it = Emp.begin() ; it !=  Emp.end(); it++){
if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
(*it).giveLeave(leaveDate);
break;
}
}
}

//Give a Leave
void giveALeave(vector <SalariedEmployee> &Emp){
string s1 , s2;
cout<<"##Enter the Details of Salaried Employee\n";
cout<<"First Name : ";
cin>>s1;
cout<<"Last Name : ";
cin>>s2;
cout<<"Enter the date Salaried Emoloyee Want Leave For(format : 01 01 2000) : ";
int a,b,c;
cin>>a>>b>>c;
Date leaveDate (a,b,c);

vector<SalariedEmployee> :: iterator it;
for(it = Emp.begin() ; it !=  Emp.end(); it++){
if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
(*it).giveLeave(leaveDate);
break;
}
}
}

//Give a Leave
void giveALeave(vector <HourlyEmployee> &Emp){
string s1 , s2;
cout<<"##Enter the Details of Hourly Employee\n";
cout<<"First Name : ";
cin>>s1;
cout<<"Last Name : ";
cin>>s2;
cout<<"Enter the date Hourly Emoloyee Want Leave For(format : 01 01 2000) : ";
int a,b,c;
cin>>a>>b>>c;
Date leaveDate (a,b,c);

vector<HourlyEmployee> :: iterator it;
for(it = Emp.begin() ; it !=  Emp.end(); it++){
if((*it).getFirstName() == s1 && (*it).getLastName() == s2){
(*it).giveLeave(leaveDate);
break;
}
}
}

//main
int main(){
int choice = 1;
char choiceOfEmp='s'; // default choice for an employee
vector<Manager> mEmp;
vector<SalariedEmployee> sEmp;
vector<HourlyEmployee> hEmp;
// ***********************************************************************************//
// The options that we have for the program //
// ***********************************************************************************//
while(choice != 0){
cout<<"0 . EXIT\n";
cout<<"1 . Create Employee\n";
cout<<"2 . Delete Employee\n";
cout<<"3 . Display All Employee\n";
cout<<"4 . Show Specific Employee\n";
cout<<"5 . Give a Leave\n";
cin>>choice;

if(choice == 1){
            int numberOfEmp =     mEmp.size() +  sEmp.size() +  hEmp.size();
            if(numberOfEmp > 499){
           cout<<"No more than 500 employees are allowed\n";
                break;
            }
            cout<<"m . Create manager Employee\n";
            cout<<"s . Create salaried Employee\n";
            cout<<"h . Create hourly Employee\n";
            cin>>choiceOfEmp;
            if(choiceOfEmp == 'm')
                createEmployee(mEmp);
            else if(choiceOfEmp == 's')
                createEmployee(sEmp);
            else if(choiceOfEmp == 'h')
                createEmployee(hEmp);
            else {cout<<"Incorrect Choice of type of employee:(\n"; continue;}
}else if(choice == 2){
cout<<"m . Delete manager Employee\n";
            cout<<"s . Delete salaried Employee\n";
            cout<<"h . Delete hourly Employee\n";
            cin>>choiceOfEmp;
            if(choiceOfEmp == 'm')
                deleteEmployee(mEmp);
             else if(choiceOfEmp == 's')
                deleteEmployee(sEmp);
             else if(choiceOfEmp == 'h')
                deleteEmployee(hEmp);
             else {cout<<"Incorrect Choice of type of employee:(\n"; continue;}
}else if(choice == 3){
displayAllEmployees(mEmp);
displayAllEmployees(sEmp);
displayAllEmployees(hEmp);
   }
else if(choice == 4){
cout<<"m . Display manager Employee\n";
            cout<<"s . Display salaried Employee\n";
            cout<<"h . Display hourly Employee\n";
cin>>choiceOfEmp;
            if(choiceOfEmp == 'm')
                displayOneEmployee(mEmp); // Search for an employee
            else if(choiceOfEmp == 's')
                displayOneEmployee(sEmp);
            else if(choiceOfEmp == 'h')
                displayOneEmployee(hEmp);
            else {cout<<"Incorrect Choice of type of employee:(\n"; continue;}
}else if(choice ==5){
cout<<"m . giveALeave to manager Employee\n";
            cout<<"s . giveALeave to salaried Employee\n";
            cout<<"h . giveALeave to hourly Employee\n";
cin>>choiceOfEmp;
if(choiceOfEmp == 'm')
                giveALeave(mEmp); // Entering the days on which the employee wants to take a holiday
            else if(choiceOfEmp == 's')
                giveALeave(sEmp);
            else if(choiceOfEmp == 'h')
                giveALeave(hEmp);
            else {cout<<"Incorrect Choice of type of employee:(\n"; continue;}
}else
cout<<"Incorrect Choice :(\n";

}

}
