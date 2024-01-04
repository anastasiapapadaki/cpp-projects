#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

//*************************************************************************//
//*************************class Moto**************************************//
class Moto{

// friend Declaration
friend class costumer_list;

//*************************************************************************//
//*****************************Attribute***********************************//

private:
string firstName;
string surName;
string address;
int housenumber;
float PLZ;
string city;
float YearOfBirth;
long telephonenumber;



Moto * successor;

//*************************************************************************//
//*****************************Method**************************************//

public:
//*************************************************************************//
//*****************************Constructor*********************************//
    Moto (string fn="0", string sn="0", string add = "0",int hnr=0, float post=0, string city="0", float yob=0, long tel =0) : firstName(fn), surName(sn), address(add), housenumber(hnr), PLZ(post), city(city), YearOfBirth(yob), telephonenumber(tel), successor(0) {}
    string getfirstName () const { return firstName; }
    string getsurName () const { return surName; }
    string getaddress () const { return address; }
    int gethousenumber () const { return housenumber; }
    float getPLZ () const { return PLZ; }
    string getcity () const { return city; }
    float getYearOfBirth () const { return YearOfBirth; }
    long gettelephonenumber () const { return telephonenumber; }

//*************************************************************************//

	Moto *next () { return successor; }
    friend ostream &operator<< (ostream &ostr, Moto &a);
    friend istream &operator>>(istream &istr, Moto &a);
};

//*************************************************************************//
//*************************class Costumer List*****************************//

class costumer_list // List of Costumers
{
private:

//*************************************************************************//
//************************************head pointer*************************//
	Moto * Head;
public:
//*************************************************************************//
//**********************Empty list constructor*****************************//
	costumer_list () : Head (0) { }
//*************************************************************************//
//******************Add a Motorbike to the top of the list*****************//

	void insert (Moto * kp)
	{
		kp->successor = Head;
		Head = kp;
		cout << "Costumer account added :)" << endl;
	}

//*************************************************************************//
//*******************Remove a Motorbike from the top of the list***********//
	Moto * remove ()
	{
		Moto * kp = Head;
		if (kp != 0)
		{
			Head = kp->successor;
			kp->successor = 0;
			cout << "Costumer account deleted :)" << endl;
		}
		return kp;
	}

	Moto * find(string fn, string sn)
	{
		Moto *ap;
		for (ap = begin(); ap != 0; ap = ap->next())
			if (ap->getfirstName() == fn)
                if (ap->getsurName() == sn)
				break;
		return ap;
	}

//*************************************************************************//
//********************start of list (head)*********************************//
	Moto * begin () const { return Head; }

	// Ist die Liste leer
	bool empty () const { return Head == 0; }
};
//*************************************************************************//
//************ostream outputs all attributes of the Motorbike class********//
ostream &operator << (ostream &ostr, Moto &a)
{
    ostr << "Name: " << endl << a.firstName << "Surname: " << a.surName << endl << "Addresse: " << a.address<<  "Housenumber " << a.housenumber<< endl << a.PLZ  << " " << a.city << endl << "Year of Birth: " << a.yob << endl<< "Tel: " << a.telephonenumber << endl;

    return ostr;
}


//*************************************************************************//
//*******************************Main Program******************************//


int main ()

{
//*************************************************************************//
//************Initialization of important variables and expressions********//
    int option = 1;
    Benutzerliste list;
    string fn;
    string sn;
    string str;
    int hnr;
    float post;
    string city;
    float yob;
    long tel;
    bool ClasseA = false;
    bool suzuki = true;
    bool honda = true;
    bool bmw = true;
    bool kawasaki = true;
    Moto *kp;

    do
    {
    	system("cls");
        cout << endl << "Welcome to motorcycle rental:)" << endl;
        cout << "Do you already have a costumer account?" << endl;
        cout << "[0] Exit || [1] No|| [2] Yes|| [3] Output all customers data" << endl;
        cout << "option: ";
        cin >> option;
        cout << endl;
//*************************************************************************************************************************************//
//***************** First a user account must be created. This is the only way to make motorcycle reservations**************************//
// The function [3] serves more to correct that all data are saved correctly, otherwise it would not be so good for data protection :) :)//
        switch (option)
        {
            case 0: // End
            	cout << "Good bye! Have a nice day :)" << endl;
                break;
//*************************************************************************************************************************************//
//********************************************** Input of all attributes **************************************************************//
            case 1:
                cout << "Enter your first name: ";
				cin >> fn;
            	cout << "Enter your last namen: ";
            	cin >> sn;
				cout << "Enter your address : ";
				cin >> add;
				cout << "Enter your housenumber: ";
				cin >> hnr;
            	cout << "Enter your PLZ: ";
            	cin >> post;
				cout << "Enter your City: ";
				cin >> city;
				cout << "Enter your Year of Birth: ";
				cin >> yob;
				cout << "Enter your telephonenumber: ";
				cin >> tel;
				list.insert(new Auto(fn, sn, add, hnr, post, city, yob, tel));
				cout << "Thank you very much:), " << fn << " " << sn << endl;
				cout << "Please log into our system with your details if you want to reserve a motorbike :)";
				system("pause");
				break;
//*************************************************************************************************************************************//
//********************************************** List of all customers ***************************************************************//
            case 2:
				for (kp=list.begin(); kp != 0; kp = kp->next())
                cout << *kp << endl;
				system("pause");
				break;
//*************************************************************************************************************************************//
//***********************Search for user account based on first and last name and, if found, provide available data********************//

			case 3:
				Moto *object;
				cout << "Please log in!" << endl;
				cout << "First Name: ";
				cin >> fn;
				cout << "Surname: ";
				cin >> sn;
				object = list.find(fn, sn);
				if (object == 0){cout << "User not found!" << endl;}
				else {
				    cout << "Willkommen " << object->getfirstName() << " " << object->getsurName()<< endl;
                    cout << "Here are the details you provided." << endl;
                    cout << "Adresse: " << object->getaddress() <<  " " << object->gethousenumber() << endl;
                    cout << object->getPLZ()  << " " << object->getcity() << endl;
                    cout << "YearofBirth: " << object->getyob() << endl;
                    cout << "Tel: " << object->gettelephonenumber() << endl;
                    cout << endl;
                    cout << "What do you want to do next?" << endl;
                    cout << "0. EXIT" << endl;
                    cout << "1.Reserve a motorbike" << endl;
                    cout << "2. Return a motorbike" << endl;
                    cin >> option;
                    switch (option){
//*************************************************************************************************************************************//
//**************** Now you have created an account and have to log in with your first and last name************************************//
                        case 0:
                        break;
                        case 1:
//*************************************************************************************************************************************//
//**************** Only drivers with A license are allowed to rent motorbikes*********************************************************//
                            cout << "Do you have a Class A license??" << endl;
                            cout << "[0] No || [1] Yes" << endl;
                            cout << "option: " << endl;
                            cin >> ClassA;
                            switch (ClassA){
                            case false:
                                cout << "A motorbike reservation is only allowed with a class A license." << endl;
                            break;
                            case true:
//*************************************************************************************************************************************//
//********************************** Only customers without a previous reservation are allowed to reserve a motorbike******************//
                                cout << "A motorbike is already reserved in your name?" << endl;
                                cout << "[0] No|| [1] Yes" << endl;
                                cin >> option;
                                switch (option){
                                    case 1: {
                                        cout << "Sorry, only one motorbike can be reserved per user at a time!" << endl;
                                        break;
                                    }
                                    case 0: {

                                    cout << "Which motorbike do you want to rent?" << endl;
                                    cout << "[0] EXIT" << endl;
                                    if (suzuki==true){
                                        cout << "[1] Suzuki Bandit" << endl;
                                    }
                                    if (honda==true){
                                        cout << "[2] Honda TransAlp" << endl;
                                    }
                                    if (bmw==true){
                                        cout << "[3] BMW F 650 GS" << endl;
                                    }
                                    if (kawasaki==true){
                                    cout << "[4] Kawasaki ZZR1400" << endl;
                                    }
                                    cout << "option: " << endl;
                                    cin >> option;
 //*************************************************************************************************************************************//
 //*******The motorcycles are Boolean expressions that are true if they are available and false if reserved*****************************//
                                    switch (option){
                                        case 0:
                                        break;
                                        case 1:
                                            if (suzuki==true) {
                                                suzuki = false;
                                                cout << "Congrats :) You rented the Suzuki Bandit model!" << endl;
                                            }
                                            else {
                                                cout << "Please select one of the available models!" << endl;
                                                system("pause");
                                                }
                                            break;
                                        case 2:
                                            if (honda==true) {
                                                honda = false;
                                                cout << "Congrats :) You rented the Honda TransAlp model!" << endl;
                                            }
                                            else {
                                                cout << "Please select one of the available models!" << endl;
                                                system("pause");
                                                }
                                            break;
                                        case 3:
                                            if (bmw==true) {
                                                bmw = false;
                                                cout << "Congrats :) You rented the BMW F 650 GS model!" << endl;
                                            }
                                            else {
                                                cout << "Please select one of the available models!" << endl;
                                                system("pause");
                                            }
                                            break;
                                        case 4:
                                            if (kawasaki==true) {
                                                kawasaki = false;
                                                cout << "Congrats :) You rented the Kawasaki ZZR1400 model!" << endl;
                                            }
                                            else {
                                                cout << "Please select one of the available models!" << endl;
                                                system("pause");
                                            }
                                            break;
                                        }

                                    }
                                }
                                }
                            break;
                            case 2:
//*************************************************************************************************************************************//
//******************************************* In your account you also have the option to spend your rented motorcycle****************//
                                if (suzuki ==true && honda == true && bmw ==true && kawasaki == true)
                                {
                                    cout << "There are currently no reservations! Sorry :(" << endl;
                                }
                                else {
                                cout << "The following motorcycles have been reserved:" << endl;
                                cout << "[0] EXIT" << endl;
                                if (suzuki==false){
                                    cout << "[1] Suzuki Bandit" << endl;
                                }
                                if (honda==false){
                                    cout << "[2] Honda TransAlp" << endl;
                                    }
                                if (bmw==false){
                                    cout << "[3] BMW F 650 GS" << endl;
                                    }
                                if (kawasaki==false){
                                    cout << "[4] Kawasaki ZZR1400" << endl;
                                    }
                                cout << "Please select your model:" << endl;
                                cin >> option;
                                switch (option){
                                case 0:
                                    break;
                                case 1:
                                    if (suzuki==false){
                                        cout << "[1] Suzuki Bandit was released! " << endl;
                                        suzuki = true;
                                    }
                                    system("pause");
                                    break;
                                case 2:
                                    if (honda==false){
                                        cout << "[2] Honda TransAlp was released! " << endl;
                                        honda = true;
                                    }
                                    system("pause");
                                    break;
                                case 3:
                                    if (bmw==false){
                                        cout << "[3] BMW F 650 GS was released! " << endl;
                                        bmw = true;
                                    }
                                    system("pause");
                                    break;
                               case 4:
                                    if (kawasaki==false){
                                        cout << "[4] Kawasaki ZZR1400 was released! " << endl;
                                        kawasaki = true;
                                    }
                                    system("pause");
                                    break;
                            }
                        }
                    }
                }
				system("pause");
				break;
            default: // Wrong option
            	cerr << "ERROR: WRONG OPTION :(" << endl;
            	system("pause");
                break;
        }

    } while (option != 0);

//*************************************************************************************************************************************//
//********************************************* Delete all elements in the list********************************************************//
    ofstream f;
    f.open("reservierungen.txt", ios::app); // File should not be overwritten
    f << "The following motorbikes are reserved today:" << endl;
    if (suzuki==false){
        f << "Suzuki Bandit" << endl;
    }
        if (honda==false){
        f << "Honda TransAlp" << endl;
    }
        if (bmw==false){
        f << "BMW F 650 GS" << endl;
    }
        if (kawasaki==false){
        f << "Kawasaki ZZR1400" << endl;
    }
    f << "----------------------------" << endl;
    f << endl;
    f.close();
	while (! list.empty())
		list.remove ();
    system("pause");
    return 0;
}
