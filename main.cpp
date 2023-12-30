#include <iostream>
#include<string>
#include<fstream>
using namespace std;
void mainmenu();
const int CREATE_CUSTOMER = 1;
const int BOOK_FLIGHT = 2;
const int SEE_BILL = 3;
const int EXIT = 4;
const int USA = 1;
const int ITALY = 2;
const int JAPAN = 3;

class Customer {
public:
    string First_Name;
    string Last_Name;
    int age;
    int id=0;
    string Gender;
    void check() const {
        int IDr;
        if (age < 18) {
            cout << "\t You Cant Fly With Us Alone,Make Sure To Enter The Responsible Person Id You are flying with" << endl;
            cout << "Enter His/Her Id" << endl;
            cin >> IDr;


            ifstream file("save.txt");
            if (!file.is_open()) {
                cout << "There is Problem Opening Your File Returning to Main Menu" << endl;
                cout << "Returning to Main Menu..." << endl;
                mainmenu();
            }
            bool found = false;
            int numt;
            while (file >> numt) {
                if (numt == IDr) {
                    found = true;
                    break;
                }
            }
            file.close();
            if (found) {
                cout << "The Responsible Person Of You Id Is found" << endl;
                cout << "\t\tYou May Continue\n\t\tHave a Safe Flight :)" << endl;

            }
            else {
                int x;
                cout << "The Responsible Person Of You Id Is Not found" << endl;
                cout << "Make Sure He/She Register First and Then Continue" << endl;
                cout << "Press 1 to Return Main Menu" << endl;
                cin >> x;
                if (x == 1) {
                    mainmenu();
                }
            }

        }
    }

    void regrister() {
        cout << "First Name:" << endl;
        cin>>First_Name;
        cout << "Last Name:" << endl;
        cin >> Last_Name;
        cout << "Age:" << endl;
        cin >> age;
        check();
        cout << "Gender:" << endl;
        cin >> Gender;
        id = id + 1;
        cout << "\t\t Your Id is:" << id << " Make Sure To Save it\n\n" << endl;
        Save_DETAILS();
    }
    void Save_DETAILS() {
        ofstream File_ID;
        File_ID.open("id.txt");
        ofstream File_NAME;
        File_NAME.open("name.txt");
        ofstream File_GENDER;
        File_GENDER.open("gender.txt");
        ofstream File_AGE;
        File_AGE.open("age.txt");
        {
            File_ID << "\t\tID: " << id << endl;
            File_NAME << "\t\tName: " << First_Name <<" "<<Last_Name<< endl;
            File_GENDER << "\tGender: " << Gender << endl;
            File_AGE << "\tAge: " << age << endl;
        }
        File_NAME.close();
        File_GENDER.close();
        File_ID.close();
        File_AGE.close();
    }
};

class Flight {
public:
    int Choice;
    int flight_CHOICE;
    string fly;
    string cost;
    void flights() {
        cout << "\t\t Country Avaliable:" << endl;
        cout << "\t\t Press 1 for USA" << endl;
        cout << "\t\t Press 2 for Italy " << endl;
        cout << "\t\t Press 3 for Japan" << endl;
        cout << "Your choice: ";
        string input = "";
        cin >> input;
        try {
            Choice = stoi(input);
            if (Choice <= 0 || Choice > 4) {
                stoi("a");
            }
        }
        catch (exception excption) {
            cout << "\t\t INVALID INPUT" << endl;
            flights();

        }
        switch (Choice) {
        case USA:
            cout << "\t\t Flights Avaliable For USA" << endl;
            cout << "\t\t Press 1 for:USA-MEA-112-12/12/2023-6:00pm-400$" << endl;
            cout << "\t\t Press 2 for:USA-MEA-123-25/12/2023-12:00am-380$" << endl;
            cout << "\t\t Press 3 for:USA-MEA-113-2/1/2024-6:00pm-400$" << endl;
            cin >> flight_CHOICE;
            if (flight_CHOICE == 1) {
                cout << "\t\t You Have Booked USA-MEA-112" << endl;
                fly = "USA-MEA-112";
                cost = "400 $";
                Save_FLIGHT();
                
            }
            else if (flight_CHOICE = 2) {
                cout << "\t\t You Have Booked USA-MEA-123" << endl;
                fly = "USA-MEA-123";
                cost = "380 $";
                Save_FLIGHT();
            }
            else if (flight_CHOICE = 3) {
                cout << "\t\t You Have Booked USA-MEA-113" << endl;
                fly = "USA-MEA-113";
                cost = "400 $";
                Save_FLIGHT();
            }
            else {
                cout << "\t\t INVALID INPUT" << endl;
                flights();
            }
            break;
        case ITALY:
            cout << "\t\t Flights Avaliable For Italy" << endl;
            cout << "\t\t Press 1 for:Italy-MEA-212-12/12/2023-7:00pm-300$" << endl;
            cout << "\t\t Press 2 for:Italy-MEA-223-22/12/2023-12:00am-290$" << endl;
            cout << "\t\t Press 3 for:Italy-MEA-213-3/1/2024-4:00pm-350$" << endl;
            if (flight_CHOICE = 1) {
                cout << "\t\t You Have Booked Italy-MEA-212" << endl;
                fly = "Italy-MEA-212";
                cost = "300 $";
                Save_FLIGHT();
            }
            else if (flight_CHOICE = 2) {
                cout << "\t\t You Have Booked Italy-MEA-223" << endl;
                fly = "Italy-MEA-223";
                cost = "290 $";
                Save_FLIGHT();
            }
            else if (flight_CHOICE = 3) {
                cout << "\t\t You Have Booked Italy-MEA-213" << endl;
                fly = "Italy-MEA-213";
                cost = "350 $";
                Save_FLIGHT();
            }

            else {
                cout << "\t\t INVALID INPUT" << endl;
                flights();
            }
            break;
        case JAPAN:
            cout << "\t\t Flights Avaliable For Japan" << endl;
            cout << "\t\t Press 1 for:Japan-MEA-312-12/12/2023-5:00pm-500$" << endl;
            cout << "\t\t Press 1 for:Japan-MEA-323-22/12/2023-12:00am-480$" << endl;
            cout << "\t\t Press 1 for:Japan-MEA-313-1/1/2024-4:00pm-550$" << endl;
            if (flight_CHOICE = 1) {
                cout << "\t\t You Have Booked Japan-MEA-312" << endl;
                fly = "Japan-MEA-312";
                cost = "500 $";
                Save_FLIGHT();

            }
            else if (flight_CHOICE = 2) {
                cout << "\t\t You Have Booked Japan-MEA-323" << endl;
                fly = "Japan-MEA-323";
                cost = "480 $";
                Save_FLIGHT();
            }
            else if (flight_CHOICE = 3) {
                cout << "\t\t You Have Booked Japan-MEA-313" << endl;
                fly = "Japan-MEA-313";
                cost = "550 $";
                Save_FLIGHT();
            }
            else {
                cout << "\t\t INVALID INPUT" << endl;
                flights();
                cost = "400 $";
                Save_FLIGHT();
            }
            break;
        }

    }
    void Save_FLIGHT() {
        ofstream File_FLIGHT;
          File_FLIGHT.open("FLIGHT.txt");
        ofstream File_COST;
        File_COST.open("cost.txt");
        {
            File_FLIGHT << "\tBooked Flight" << fly << endl;
            File_COST << "\tCost" << cost << endl;
        }
        File_FLIGHT.close();
        File_COST.close();
    }
};
class Mangament {
    

};
class Bill{
public:
    char arr[100];
    Customer customer;
    Flight flight;
    void dispBill() {
        ifstream File_ID;
        File_ID.open("id.txt");
        ifstream File_NAME;
        File_NAME.open("name.txt");
        ifstream File_GENDER;
        File_GENDER.open("gender.txt");
        ifstream File_AGE;
        File_AGE.open("age.txt");

        {
           if (!File_ID &&!File_NAME&&!File_AGE&&!File_GENDER) {
                cout << "There is Problem Opening Your File Returning to Main Menu" << endl;
                cout << "Returning to Main Menu..." << endl;
                mainmenu();
            }
            else {
               cout << "\t\tBILL" << endl;
               
                
            }

        }
    }
};
    void mainmenu() {
        int Choice;
        Customer customer;
        Flight flight;
        Bill bill;
        int x = 0;
        cout << "\n\n\t--------- Welcome to MEA Airline------------" << endl;
        cout << "\t\t Press 1 to Create Customer Data" << endl;
        cout << "\t\t Press 2 to See Flight Avaliablities" << endl;
        cout << "\t\t Press 3 for Seeing Bill" << endl;
        cout << "\t\t Press 4 to Exit" << endl;
        cout << "Your choice: ";
        cout << "\n";
        string input = "";
        cin >> input;

        try {
            Choice = stoi(input);
            if (Choice <= 0 || Choice > 4) {
                stoi("a");
            }
        }
        catch (exception excption) {
            cout << "\t\t INVALID INPUT" << endl;
            mainmenu();

        }


        switch (Choice) {
        case CREATE_CUSTOMER:
            customer.regrister();
            cout << "Press 1 to Return To Main Menu" << endl;
            cin >> x;
            mainmenu();
            break;

        case BOOK_FLIGHT:
            flight.flights();
            cout << "Press 1 to Return To Main Menu" << endl;
            cin >> x;
            if (x == 1) {
                mainmenu();
            }
            break;
        case SEE_BILL:
            bill.dispBill();
            cout << "Press 1 to Return To Main Menu" << endl;
            cin >> x;
            if (x == 1) {
                mainmenu();
            }
            break;
        case EXIT:
            cout << "\t\t Thank You!" << endl;
            break;
        }
    }
    int main() {
        mainmenu();
        return 0;
    }