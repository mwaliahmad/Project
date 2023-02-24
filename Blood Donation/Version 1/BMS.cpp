#include <iostream>
#include <windows.h>
#include <conio.h>
#include <iomanip>
#include <ctime>
#include <string>

using namespace std;

// prototypes
void menuName(string menu, string subMenu);
string setcolor(unsigned short color);
string isAlpha(string input);
string isNum(string input);
string isBG(string input);
string contactCheck(string contact);
string cnicCheck(string cnic);
string usercheck(string username);
int choiceCheck(int choice);
void gotoxy(int x, int y);
void printHeader();
int login();
void adminMenu();
void employeeMenu();
void addDonor();
void deleteDonor();
void updateDonor();
void searchDonor();
void viewDonor();
void addRecipient();
void deleteRecipient();
void updateRecipient();
void searchRecipient();
void viewRecipient();
void addEmployee();
void deleteEmployee();
void updateEmployee();
void searchEmployee();
void viewEmployee();
void searchDonorbyAdmin();
void viewDonorbyAdmin();
void searchRecipientbyAdmin();
void viewRecipientbyAdmin();

// employee data
string nameE[100] = {"wali", "ahmad", "ali"};
string ageE[100] = {"20", "20", "18", "18"};
string usernameE[100] = {"wali1", "ahmad1", "e"};
string passwordE[100] = {"12121212", "13131313", "e"};
string cnicE[100] = {"3520175851022", "0101010101015", "0101010101015"};
string contactE[100] = {"03232323243", "03454545455", "03454545455"};
string contributer;
int indexE = 3;

// donor data
string nameD[100] = {"wali", "ahmad", "ali"};
string ageD[100] = {"20", "20", "18"};
string bloodgroupD[100] = {"A+", "A+", "AB+"};
string cityD[100] = {"lahore", "lahore", "karachi"};
string statusD[100] = {"available", "unavailable", "available"};
string contactD[100] = {"03232323243", "03454545455", "12121211212"};
string contributerD[100] = {"wali1", "ahmad1", "e"};
int indexD = 2;

// recipient data
string nameR[100] = {"wali", "ahmad"};
string ageR[100] = {"20", "20"};
string bloodgroupR[100] = {"A+", "A+"};
string cityR[100] = {"lahore", "lahore"};
string contactR[100] = {"03878787887", "03454545455"};
string contributerR[100] = {"wali1", "ahmad1", "e"};
int indexR = 2;

main()
{
    while (true)
    {

        system("cls");
        printHeader();
        int user = login();
        if (user == 1)
        {

            system("cls");
            printHeader();
            adminMenu();
        }

        else if (user == 2)
        {
            system("cls");
            printHeader();
            employeeMenu();
        }

        else if (user == 3)
        {
            cout << endl;
            cout << "Wrong Credentials!! Try again!!";
            Sleep(350);
        }
    }
}

void printHeader()
{
    time_t now = time(0);
    char *date_time = ctime(&now);
    gotoxy(78, 1);
    cout << date_time << endl;
    cout << endl;
    setcolor(12);
    cout << "             ____  _                 _   _____                    _   _              " << endl;
    cout << "            |  _ \\| |               | | |  __ \\                  | | (_)                  " << endl;
    cout << "            | |_) | | ___   ___   __| | | |  | | ___  _ __   __ _| |_ _  ___  _ __         " << endl;
    cout << "            |  _ <| |/ _ \\ / _ \\ / _` | | |  | |/ _ \\| '_ \\ / _` | __| |/ _ \\| '_ \\         " << endl;
    cout << "            | |_) | | (_) | (_) | (_| | | |__| | (_) | | | | (_| | |_| | (_) | | | |         " << endl;
    cout << "            |____/|_|\\___/ \\___/ \\__,_| |_____/ \\___/|_| |_|\\__,_|\\__|_|\\___/|_| |_|          " << endl;
    setcolor(11);
    cout << "  __  __                                                   _      _____           _               " << endl;
    cout << " |  \\/  |                                                 | |    / ____|         | |               " << endl;
    cout << " | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___ _ __ ___  " << endl;
    cout << " | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\  " << endl;
    cout << " | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \\__ \\ ||  __/ | | | | | " << endl;
    cout << " |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |_____/ \\__, |___/\\__\\___|_| |_| |_| " << endl;
    cout << "                            __/ |                                        __/ |                       " << endl;
    cout << "                           |___/                                        |___/                      " << endl;
    setcolor(15);
}

int login()
{
    string username, password;
    int choice;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Welcome to Blood Donation Management System";
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;
    if (username == "admin" && password == "admin")
    {
        choice = 1;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (username == usernameE[i] && password == passwordE[i])
            {
                contributer = username;
                choice = 2;
                break;
            }
            else
            {
                choice = 3;
            }
        }
    }
    return choice;
}

void adminMenu()
{
    int choice = 0;
    while (choice != 10)
    {
        system("cls");
        printHeader();
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "1.  Add New Employee..." << endl;
        cout << "2.  Delete Employee... " << endl;
        cout << "3.  Update Employee Details... " << endl;
        cout << "4.  Search For Employee... " << endl;
        cout << "5.  View all Employees... " << endl;
        cout << endl;
        cout << "6.  Search For Donor... " << endl;
        cout << "7.  View all Donors... " << endl;
        cout << endl;
        cout << "8.  Search For Recipient... " << endl;
        cout << "9.  View all Recipient... " << endl;
        cout << endl;
        cout << "10. Log out... " << endl;
        cout << endl;
        cout << "Enter Your Option: ";

        choice = choiceCheck(choice);
        if (choice == 1)
        {
            system("cls");
            printHeader();
            addEmployee();
        }
        if (choice == 2)
        {
            system("cls");
            printHeader();
            deleteEmployee();
        }
        if (choice == 3)
        {
            system("cls");
            printHeader();
            updateEmployee();
        }
        if (choice == 4)
        {
            system("cls");
            printHeader();
            searchEmployee();
        }
        if (choice == 5)
        {
            system("cls");
            printHeader();
            viewEmployee();
        }
        if (choice == 6)
        {
            system("cls");
            printHeader();
            searchDonorbyAdmin();
        }
        if (choice == 7)
        {
            system("cls");
            printHeader();
            viewDonorbyAdmin();
        }
        if (choice == 8)
        {
            system("cls");
            printHeader();
            searchRecipientbyAdmin();
        }
        if (choice == 9)
        {
            system("cls");
            printHeader();
            viewRecipientbyAdmin();
        }
    }
}

void employeeMenu()
{
    int choice = 0;
    while (choice != 11)
    {
        system("cls");
        printHeader();
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "1.  Add New Donor..." << endl;
        cout << "2.  Delete Donor... " << endl;
        cout << "3.  Update Donor Details... " << endl;
        cout << "4.  Search For Donor... " << endl;
        cout << "5.  View Details of all Donors... " << endl;
        cout << endl;
        cout << "6.  Add New Recipient..." << endl;
        cout << "7.  Delete Recipient... " << endl;
        cout << "8.  Update Recipient Details... " << endl;
        cout << "9.  Search For Recipient... " << endl;
        cout << "10. View Details of all Recipients... " << endl;
        cout << endl;
        cout << "11. Log out... " << endl;
        cout << endl;
        cout << "Enter Your Option: ";
        choice = choiceCheck(choice);
        if (choice == 1)
        {
            system("cls");
            printHeader();
            addDonor();
        }
        if (choice == 2)
        {
            system("cls");
            printHeader();
            deleteDonor();
        }
        if (choice == 3)
        {
            system("cls");
            printHeader();
            updateDonor();
        }
        if (choice == 4)
        {
            system("cls");
            printHeader();
            searchDonor();
        }
        if (choice == 5)
        {
            system("cls");
            printHeader();
            viewDonor();
        }
        if (choice == 6)
        {
            system("cls");
            printHeader();
            addRecipient();
        }
        if (choice == 7)
        {
            system("cls");
            printHeader();
            deleteRecipient();
        }
        if (choice == 8)
        {
            system("cls");
            printHeader();
            updateRecipient();
        }
        if (choice == 9)
        {
            system("cls");
            printHeader();
            searchRecipient();
        }
        if (choice == 10)
        {
            system("cls");
            printHeader();
            viewRecipient();
        }
    }
}

void addDonor()
{

    cout << endl;
    cout << "Employee Menu > Add Donor " << endl;
    cout << "--------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Details of the New Donor:-" << endl;
    cout << endl;
    cout << "Enter Name: ";
    nameD[indexD] = isAlpha(nameD[indexD]);

    cout << "Enter Age(+18): ";
    ageD[indexD] = isNum(ageD[indexD]);

    cout << "Enter Bloodgroup: ";
    bloodgroupD[indexD] = isBG(bloodgroupD[indexD]);

    cout << "Enter City: ";
    cityD[indexD] = isAlpha(cityD[indexD]);

    cout << "Enter Contact No.(11 numbers): ";
    contactD[indexD] = contactCheck(contactD[indexD]);

    contributerD[indexD] = contributer;
    indexD++;

    cout << endl;
    cout << "Donor Added Sucessfully...";
    Sleep(400);
    cout << endl;
    cout << "Press any key for back...";
    getch();
}

void deleteDonor()
{

    int index;
    string deleteName;
    cout << endl;
    cout << "Employee Menu > Delete Donor " << endl;
    cout << "-----------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Name of the Donor: ";
    cin >> deleteName;
    cout << endl;
    bool notFound = true;
    for (int idx = 0; idx < 50; idx++)
    {
        if ((deleteName == nameD[idx]) && (contributer == contributerD[idx]))
        {
            index = idx;
            cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << endl;
            cout << endl;
            cout << left << setw(20) << nameD[index] << left << setw(20) << ageD[index] << left << setw(20) << bloodgroupD[index] << left << setw(20) << cityD[index] << left << setw(20) << contactD[index] << endl;
            for (int j = idx; j <= 5 - 1; j++)
            {
                nameD[j] = nameD[j + 1];
                ageD[j] = ageD[j + 1];
                bloodgroupD[j] = bloodgroupD[j + 1];
                cityD[j] = cityD[j + 1];
                contactD[j] = contactD[j + 1];
                contributerD[j] = contributerD[j + 1];
            }
            cout << endl;
            cout << "Donor Removed..." << endl;
            notFound = true;
            break;
        }
        else
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << endl;
        cout << "Donor Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void updateDonor()
{
    int index;
    string updateName;
    cout << endl;
    cout << "Employee Menu > Update Donor " << endl;
    cout << "-----------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Name of the Donor: ";
    cin >> updateName;
    cout << endl;
    bool notFound = true;
    for (int idx = 0; idx < 50; idx++)
    {
        if (updateName == nameD[idx] && (contributer == contributerD[idx]))
        {
            index = idx;
            cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << endl;
            cout << endl;
            cout << left << setw(20) << nameD[index] << left << setw(20) << ageD[index] << left << setw(20) << bloodgroupD[index] << left << setw(20) << cityD[index] << left << setw(20) << contactD[index] << endl;
            cout << endl;
            cout << "Enter Name: ";
            nameD[index] = isAlpha(nameD[index]);

            cout << "Enter Age(+18): ";
            ageD[index] = isNum(ageD[index]);

            cout << "Enter Bloodgroup: ";
            bloodgroupD[index] = isBG(bloodgroupD[index]);

            cout << "Enter City: ";
            cityD[index] = isAlpha(cityD[index]);

            cout << "Enter Contact No. (11 numbers): ";
            contactD[index] = contactCheck(contactD[index]);
            contributerD[index] = contributer;
            cout << endl;
            cout << "Donor Updated..." << endl;
            notFound = true;
            break;
        }
        else
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << "Donor Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void searchDonor()
{
    int index;
    string searchBG;
    string check;
    cout << endl;
    cout << "Employee Menu > Search Donor " << endl;
    cout << "------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Bloodgroup of the Donor: ";
    cin >> searchBG;
    bool notFound = true;
    bool one = false;
    cout << endl;
    cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << endl;
    cout << endl;

    for (int idx = 0; idx < 50; idx++)
    {

        if (searchBG == bloodgroupD[idx] && (contributer == contributerD[idx]))
        {
            index = idx;
            cout << left << setw(20) << nameD[index] << left << setw(20) << ageD[index] << left << setw(20) << bloodgroupD[index] << left << setw(20) << cityD[index] << left << setw(20) << contactD[index] << endl;
            notFound = true;
            one = true;
        }
        else if (one == false)
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << "Donor Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void viewDonor()
{
    cout << endl;
    cout << "Employee Menu > View All Donors " << endl;
    cout << "--------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Following Are the Donors: " << endl;
    cout << endl;
    cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << endl;
    cout << endl;

    for (int index = 0; index < 50; index++)
    {
        if ((nameD[index] != "") && (contributer == contributerD[index]))
        {
            cout << left << setw(20) << nameD[index] << left << setw(20) << ageD[index] << left << setw(20) << bloodgroupD[index] << left << setw(20) << cityD[index] << left << setw(20) << contactD[index] << endl;
        }
    }
    cout << endl;
    cout << "Press any key for back...";
    getch();
}

void addRecipient()
{

    cout << endl;
    cout << "Employee Menu > Add Recipient " << endl;
    cout << "------------------------------" << endl;

    cout << endl;
    cout << endl;
    cout << "Enter Details of the New Recipient:-" << endl;
    cout << endl;
    cout << "Enter Name: ";
    nameR[indexR] = isAlpha(nameR[indexR]);

    cout << "Enter Age(+18): ";
    ageR[indexR] = isNum(ageR[indexR]);

    cout << "Enter Bloodgroup: ";
    bloodgroupR[indexR] = isBG(bloodgroupR[indexR]);

    cout << "Enter City: ";
    cityR[indexR] = isAlpha(cityR[indexR]);

    cout << "Enter Contact No.(11 numbers): ";
    contactR[indexR] = contactCheck(contactR[indexR]);

    contributerR[indexR] = contributer;
    indexR++;
    cout << endl;
    cout << "Recipient Added Sucessfully...";
    Sleep(350);
    cout << endl;
    cout << "Press any key for back...";
    getch();
}

void deleteRecipient()
{
    int index;
    string deleteName;
    cout << endl;
    cout << "Employee Menu > Delete Recipient " << endl;
    cout << "---------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Name of the Recipient: ";
    cin >> deleteName;
    cout << endl;
    bool notFound = true;
    for (int idx = 0; idx < 50; idx++)
    {
        if (deleteName == nameR[idx] && (contributer == contributerR[idx]))
        {
            index = idx;
            cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << endl;
            cout << endl;
            cout << left << setw(20) << nameR[index] << left << setw(20) << ageR[index] << left << setw(20) << bloodgroupR[index] << left << setw(20) << cityR[index] << left << setw(20) << contactR[index] << endl;
            for (int j = idx; j <= 5 - 1; j++)
            {
                nameR[j] = nameR[j + 1];
                ageR[j] = ageR[j + 1];
                bloodgroupR[j] = bloodgroupR[j + 1];
                cityR[j] = cityR[j + 1];
                contactR[j] = contactR[j + 1];
                contributerR[j] = contributerR[j + 1];
            }
            cout << endl;
            cout << "Recipient Removed..." << endl;
            notFound = true;
            break;
        }
        else
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << endl;
        cout << "Recipient Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void updateRecipient()
{
    int index;
    string updateName;
    cout << endl;
    cout << "Employee Menu > Update Recipient " << endl;
    cout << "---------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Name of the Recipient: ";
    cin >> updateName;
    cout << endl;
    bool notFound = true;
    for (int idx = 0; idx < 50; idx++)
    {
        if (updateName == nameR[idx] && (contributer == contributerR[idx]))
        {
            index = idx;
            cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << endl;
            cout << endl;
            cout << left << setw(20) << nameR[index] << left << setw(20) << ageR[index] << left << setw(20) << bloodgroupR[index] << left << setw(20) << cityR[index] << left << setw(20) << contactR[index] << endl;
            cout << endl;
            cout << "Enter Name: ";
            nameR[index] = isAlpha(nameR[index]);

            cout << "Enter Age(+18): ";
            ageR[index] = isNum(ageR[index]);

            cout << "Enter Bloodgroup: ";
            bloodgroupR[index] = isBG(bloodgroupR[index]);

            cout << "Enter City: ";
            cityR[index] = isAlpha(cityR[index]);

            cout << "Enter Contact No.(11 numbers): ";
            contactR[index] = contactCheck(contactR[index]);
            contributerR[index] = contributer;
            cout << endl;
            cout << "Recipient Updated..." << endl;
            notFound = true;
            break;
        }
        else
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << "Recipient Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void searchRecipient()
{
    int index;
    string searchName;
    cout << endl;
    cout << "Employee Menu > Search Recipient " << endl;
    cout << "---------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Bloodgroup of the Recipient: ";
    cin >> searchName;
    bool notFound = true;
    bool one = false;
    cout << endl;
    cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << endl;
    cout << endl;

    for (int idx = 0; idx < 50; idx++)
    {
        if (searchName == bloodgroupR[idx] && (contributer == contributerR[idx]))
        {
            index = idx;
            cout << left << setw(20) << nameR[index] << left << setw(20) << ageR[index] << left << setw(20) << bloodgroupR[index] << left << setw(20) << cityR[index] << left << setw(20) << contactR[index] << endl;
            notFound = true;
            one = true;
        }
        else if (one == false)
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << "Recipient Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void viewRecipient()
{
    cout << endl;
    cout << "Employee Menu > View All Recipients " << endl;
    cout << "------------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Following Are the Recipients: " << endl;
    cout << endl;
    cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << endl;
    cout << endl;
    for (int index = 0; index < 50; index++)
    {
        if ((nameR[index] != "") && (contributer == contributerR[index]))
        {
            cout << left << setw(20) << nameR[index] << left << setw(20) << ageR[index] << left << setw(20) << bloodgroupR[index] << left << setw(20) << cityR[index] << left << setw(20) << contactR[index] << endl;
        }
    }
    cout << endl;
    cout << "Press any key for back...";
    getch();
}

void addEmployee()
{

    cout << endl;
    string menu = "Admin Menu";
    string subMenu = "Add Employee";
    menuName(menu, subMenu);
    cout << endl;
    cout << endl;
    cout << "Enter Details of the New Employee:-" << endl;
    cout << endl;
    cout << "Enter Name: ";
    nameE[indexE] = isAlpha(nameE[indexE]);

    cout << "Enter Age(+18): ";
    ageE[indexE] = isNum(ageE[indexE]);

    cout << "Enter CNIC(13 numbers): ";
    cnicE[indexE] = cnicCheck(cnicE[indexE]);

    cout << "Enter Contact No(11 numbers): ";
    contactE[indexE] = contactCheck(contactE[indexE]);

    cout << "Enter Username: ";
    usernameE[indexE] = usercheck(usernameE[indexE]);

    cout << "Enter Password: ";
    cin >> passwordE[indexE];

    indexE++;
    cout << endl;
    cout << "Employee Added Sucessfully...";
    Sleep(300);
    cout << endl;
    cout << "Press any key for back...";
    getch();
}

void deleteEmployee()
{
    int index;
    string deleteName;
    cout << endl;
    string menu = "Admin Menu";
    string subMenu = "Delete Employee";
    menuName(menu, subMenu);
    cout << endl;
    cout << endl;
    cout << "Enter Username of the Employee: ";
    cin >> deleteName;
    cout << endl;
    bool notFound = true;
    for (int idx = 0; idx < 50; idx++)
    {
        if (deleteName == usernameE[idx])
        {
            index = idx;
            cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "CNIC" << left << setw(20) << "Contact No." << left << setw(20) << "Username" << left << setw(20) << "Password" << endl;
            cout << endl;
            cout << left << setw(20) << nameE[index] << left << setw(20) << ageE[index] << left << setw(20) << cnicE[index] << left << setw(20) << contactE[index] << left << setw(20) << usernameE[index] << left << setw(20) << passwordE[index] << endl;

            for (int j = idx; j <= 5 - 1; j++)
            {
                nameE[j] = nameE[j + 1];
                ageE[j] = ageE[j + 1];
                cnicE[j] = cnicE[j + 1];
                contactE[j] = contactE[j + 1];
                usernameE[j] = usernameE[j + 1];
                passwordE[j] = passwordE[j + 1];
            }

            cout << endl;
            cout << "Employee Removed..." << endl;
            notFound = true;
            break;
        }
        else
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << endl;
        cout << "Employee Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void updateEmployee()
{
    int index;
    string updateName;
    cout << endl;
    string menu = "Admin Menu";
    string subMenu = "Update Employee";
    menuName(menu, subMenu);
    cout << endl;
    cout << endl;
    cout << "Enter CNIC of the Employee: ";
    cin >> updateName;
    cout << endl;
    bool notFound = true;
    for (int idx = 0; idx < 50; idx++)
    {
        if (updateName == cnicE[idx])
        {
            index = idx;
            cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "CNIC" << left << setw(20) << "Contact No." << left << setw(20) << "Username" << left << setw(20) << "Password" << endl;
            cout << endl;
            cout << left << setw(20) << nameE[index] << left << setw(20) << ageE[index] << left << setw(20) << cnicE[index] << left << setw(20) << contactE[index] << left << setw(20) << usernameE[index] << left << setw(20) << passwordE[index] << endl;
            cout << endl;
            cout << "Enter Name: ";
            nameE[index] = isAlpha(nameE[index]);

            cout << "Enter Age(+18): ";
            ageE[index] = isNum(ageE[index]);

            cout << "Enter CNIC(13 numbers): ";
            cnicE[index] = cnicCheck(cnicE[index]);

            cout << "Enter Contact No(11 numbers): ";
            contactE[index] = contactCheck(contactE[index]);

            cout << "Enter Username: ";
            usernameE[index] = usercheck(usernameE[index]);

            cout << "Enter Password: ";
            cin >> passwordE[index];
            notFound = true;
            break;
        }
        else
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << "Employee Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void searchEmployee()
{
    int index;
    string searchName;
    cout << endl;
    string menu = "Admin Menu";
    string subMenu = "Search Employee";
    menuName(menu, subMenu);
    cout << endl;
    cout << endl;
    cout << "Enter CNIC of the Employee: ";
    cin >> searchName;
    bool notFound = true;
    bool one = false;
    cout << endl;
    cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "CNIC" << left << setw(20) << "Contact No." << left << setw(20) << "Username" << left << setw(20) << "Password" << endl;
    cout << endl;
    for (int idx = 0; idx < 50; idx++)
    {
        if (searchName == cnicE[idx])
        {
            index = idx;
            cout << left << setw(20) << nameE[index] << left << setw(20) << ageE[index] << left << setw(20) << cnicE[index] << left << setw(20) << contactE[index] << left << setw(20) << usernameE[index] << left << setw(20) << passwordE[index] << endl;
            notFound = true;
            one = true;
        }
        else if (one == false)
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << "Employee Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void viewEmployee()
{
    cout << endl;
    string menu = "Admin Menu";
    string subMenu = "View All Employees";
    menuName(menu, subMenu);
    cout << endl;
    cout << endl;
    cout << "Following Are the Employees: " << endl;
    cout << endl;
    cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "CNIC" << left << setw(20) << "Contact No." << left << setw(20) << "Username" << left << setw(20) << "Password" << endl;
    cout << endl;
    for (int index = 0; index < 50; index++)
    {
        if (nameE[index] != "")
        {
            cout << left << setw(20) << nameE[index] << left << setw(20) << ageE[index] << left << setw(20) << cnicE[index] << left << setw(20) << contactE[index] << left << setw(20) << usernameE[index] << left << setw(20) << passwordE[index] << endl;
        }
    }
    cout << endl;
    cout << "Press any key for back...";
    getch();
}

void searchDonorbyAdmin()
{
    int index;
    string searchName;
    cout << endl;
    cout << "Admin Menu > Search Donor " << endl;
    cout << "--------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Bloodgroup of the Donor: ";
    cin >> searchName;
    bool notFound = true;
    bool one = false;
    cout << endl;
    cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << left << setw(20) << "Contributer" << endl;
    cout << endl;
    for (int idx = 0; idx < 50; idx++)
    {
        if (searchName == bloodgroupD[idx])
        {
            index = idx;
            cout << left << setw(20) << nameD[index] << left << setw(20) << ageD[index] << left << setw(20) << bloodgroupD[index] << left << setw(20) << cityD[index] << left << setw(20) << contactD[index] << left << setw(20) << contributerD[index] << endl;
            notFound = true;
            one = true;
        }
        else if (one == false)
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << "Donor Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void viewDonorbyAdmin()
{
    {
        cout << endl;
        cout << "Admin Menu > View All Donors " << endl;
        cout << endl;
        cout << endl;
        cout << "Following Are the Donors: " << endl;
        cout << endl;
        cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << left << setw(20) << "Contributer" << endl;
        cout << endl;
        for (int index = 0; index < 50; index++)
        {
            if (nameD[index] != "")
            {
                cout << left << setw(20) << nameD[index] << left << setw(20) << ageD[index] << left << setw(20) << bloodgroupD[index] << left << setw(20) << cityD[index] << left << setw(20) << contactD[index] << left << setw(20) << contributerD[index] << endl;
            }
        }
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void searchRecipientbyAdmin()
{

    int index;
    string searchName;
    cout << endl;
    cout << "Admin Menu > Search Recipient " << endl;
    cout << "------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Enter Bloodgroup of the Recipient: ";
    cin >> searchName;
    bool notFound = true;
    bool one = false;
    cout << endl;
    cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << left << setw(20) << "Contributer" << endl;
    cout << endl;

    for (int idx = 0; idx < 50; idx++)
    {
        if (searchName == bloodgroupR[idx])
        {
            index = idx;
            cout << left << setw(20) << nameR[index] << left << setw(20) << ageR[index] << left << setw(20) << bloodgroupR[index] << left << setw(20) << cityR[index] << left << setw(20) << contactR[index] << left << setw(20) << contributerR[index] << endl;
            notFound = true;
            one = true;
        }
        else if (one == false)
        {
            notFound = false;
        }
    }
    if (notFound == false)
    {
        cout << "Recipient Not Found" << endl;
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
    else
    {
        cout << endl;
        cout << "Press any key for back...";
        getch();
    }
}

void viewRecipientbyAdmin()
{
    cout << endl;
    cout << "Admin Menu > View All Recipients " << endl;
    cout << "---------------------------------" << endl;
    cout << endl;
    cout << endl;
    cout << "Following Are the Recipients: " << endl;
    cout << endl;
    cout << left << setw(20) << "Name" << left << setw(20) << "Age" << left << setw(20) << "Bloodgroup" << left << setw(20) << "City" << left << setw(20) << "Contact No." << left << setw(20) << "Contributer" << endl;
    cout << endl;
    for (int index = 0; index < 50; index++)
    {
        if (nameD[index] != "")
        {
            cout << left << setw(20) << nameR[index] << left << setw(20) << ageR[index] << left << setw(20) << bloodgroupR[index] << left << setw(20) << cityR[index] << left << setw(20) << contactR[index] << left << setw(20) << contributerR[index] << endl;
        }
    }
    cout << endl;
    cout << "Press any key for back...";
    getch();
}

void menuName(string menu, string subMenu)
{
    cout << menu << " > " << subMenu << endl;
    cout << "-------------------------" << endl;
}

string setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    return "";
}

string isAlpha(string input)
{

    cin >> input;
    int size;
    int check;
    bool flap;
    while (true)
    {
        size = input.length();
        for (int i = 0; i < size; i++)
        {
            if (input[i] != ' ')
            {
                check = int(input[i]);
                if ((check >= 65 && check <= 90) || (check >= 97 && check <= 122))
                {
                    flap = true;
                }
                else
                {
                    flap = false;
                    break;
                }
            }
        }
        if (flap == true)
        {
            return input;
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Wrong Charater..." << endl;
            cout << "Enter Again: ";
            cin >> input;
        }
    }
}

string isNum(string input)
{

    cin >> input;
    int x;
    int size;
    int check;
    bool flap;
    while (true)
    {
        size = input.length();
        for (int i = 0; i < size; i++)
        {
            if (input[i] != ' ')
            {
                check = int(input[i]);
                if ((check >= 48 && check <= 57))
                {
                    flap = true;
                }
                else
                {
                    flap = false;
                    break;
                }
            }
        }
        if (flap == true)
        {
            x = stoi(input);
            if (x >= 18 && x <= 60)
            {
                return input;
            }
            else
            {
                cin.clear();
                cin.ignore();
                cout << "Wrong Age..." << endl;
                cout << "Enter age: ";
                cin >> input;
            }
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Wrong Age..." << endl;
            cout << "Enter age: ";
            cin >> input;
        }
    }
    return 0;
}

string isBG(string input)
{

    cin >> input;
    while (true)
    {
        if (input == "A+" || input == "A-" || input == "B+" || input == "B-" || input == "AB+" || input == "AB-" || input == "O+" || input == "O-")
        {
            break;
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Wrong Bloodgroup..." << endl;
            cout << "Enter Blood: ";
            cin >> input;
        }
    }

    return input;
}

string contactCheck(string contact)
{
    cin >> contact;
    int size;
    int check;
    bool flap;
    while (true)
    {
        size = contact.length();
        for (int i = 0; i < size; i++)
        {
            if (contact[i] != ' ')
            {
                check = int(contact[i]);
                if ((check >= 48 && check <= 57) && (size == 11))
                {
                    flap = true;
                }
                else
                {
                    flap = false;
                    break;
                }
            }
        }
        if (flap == true)
        {
            return contact;
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Wrong Contact info..." << endl;
            cout << "Enter Contact No (11 numbers): ";
            cin >> contact;
        }
    }
}

string cnicCheck(string cnic)
{
    cin >> cnic;
    int size;
    int check;
    bool flap;
    while (true)
    {
        size = cnic.length();
        for (int i = 0; i < size; i++)
        {
            if (cnic[i] != ' ')
            {
                check = int(cnic[i]);
                if ((check >= 48 && check <= 57) && (size == 13))
                {
                    flap = true;
                }
                else
                {
                    flap = false;
                    break;
                }
            }
        }
        if (flap == true)
        {
            return cnic;
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Wrong CNIC..." << endl;
            cout << "Enter CNIC (13 numbers): ";
            cin >> cnic;
        }
    }
}

int choiceCheck(int choice)
{

    cin >> choice;
    while (true)
    {
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Wrong Option..." << endl;
            cout << "Enter Option: ";
            cin >> choice;
        }
        if (!cin.fail())
        {
            break;
        }
    }
    return choice;
}
string usercheck(string username)
{
    cin >> username;
    for (int i = 0; i < 50; i++)
    {
        if (username == usernameE[i])
        {
            cin.clear();
            cin.ignore();
            cout << "Username Already Present..." << endl;
            cout << "Enter Username: ";
            cin >> username;
        }
        else
        {
            break;
        }
    }
    return username;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
