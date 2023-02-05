#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void printHeader();
int login();
void adminMenu();
void employeeMenu();
void addDonor();
void deleteDonor();
void updateDonor();
void searchDonor();
void viewDonor();
string name[100] = {"wali", "ahmad"};
string age[100] = {"20", "20"};
string bloodgroup[100] = {"A+", "O-"};
string city[100] = {"lahore", "lahore"};
string status[100] = {"available", "unavailable"};

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
    cout << "             ____  _                 _   _____                    _   _              " << endl;
    cout << "            |  _ \\| |               | | |  __ \\                  | | (_)                  " << endl;
    cout << "            | |_) | | ___   ___   __| | | |  | | ___  _ __   __ _| |_ _  ___  _ __         " << endl;
    cout << "            |  _ <| |/ _ \\ / _ \\ / _` | | |  | |/ _ \\| '_ \\ / _` | __| |/ _ \\| '_ \\         " << endl;
    cout << "            | |_) | | (_) | (_) | (_| | | |__| | (_) | | | | (_| | |_| | (_) | | | |         " << endl;
    cout << "            |____/|_|\\___/ \\___/ \\__,_| |_____/ \\___/|_| |_|\\__,_|\\__|_|\\___/|_| |_|          " << endl;
    cout << "  __  __                                                   _      _____           _               " << endl;
    cout << " |  \\/  |                                                 | |    / ____|         | |               " << endl;
    cout << " | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___ _ __ ___  " << endl;
    cout << " | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\  " << endl;
    cout << " | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \\__ \\ ||  __/ | | | | | " << endl;
    cout << " |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |_____/ \\__, |___/\\__\\___|_| |_| |_| " << endl;
    cout << "                            __/ |                                        __/ |                       " << endl;
    cout << "                           |___/                                        |___/                      " << endl;
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
    if (username == "a" && password == "a")
    {
        choice = 1;
    }
    else if (username == "e" && password == "e")
    {
        choice = 2;
    }
    else if ((username != "a" || username != "e") && (password != "a" || password != "e"))
    {
        choice = 3;
    }
    return choice;
}

void adminMenu()
{
    int choice;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "1. Add New Employee..." << endl;
    cout << "2. Delete Employee... " << endl;
    cout << "3. Update Employee Details... " << endl;
    cout << "4. Search For Employee... " << endl;
    cout << "5. View all Employees... " << endl;
    cout << endl;
    cout << "6. Search For Donor... " << endl;
    cout << "7. View all Donors... " << endl;
    cout << endl;
    cout << "8. Search For Recipient... " << endl;
    cout << "9. View all Recipient... " << endl;
    cout << endl;
    cout << "10. Log out... " << endl;
    cout << endl;
    cout << "Enter Your Option: ";
    cin >> choice;
}

void employeeMenu()
{
    int choice;
    while (true)
    {
        system("cls");
        printHeader();
        cout << endl;
        cout << endl;
        cout << endl;
        cout << "1. Add New Donor..." << endl;
        cout << "2. Delete Donor... " << endl;
        cout << "3. Update Donor Details... " << endl;
        cout << "4. Search For Donor... " << endl;
        cout << "5. View Details of all Donors... " << endl;
        cout << endl;
        cout << "6. Add New Recipient..." << endl;
        cout << "7. Delete Recipient... " << endl;
        cout << "8. Update Recipient Details... " << endl;
        cout << "9. Search For Recipient... " << endl;
        cout << "10. View Details of all Recipients... " << endl;
        cout << endl;
        cout << "11. Log out... " << endl;
        cout << endl;
        cout << "Enter Your Option: ";
        cin >> choice;
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
    }
}

void addDonor()
{
    int index = 2;
    cout << endl;
    cout << "Enter Name: ";
    cin >> name[index];
    cout << "Enter Age: ";
    cin >> age[index];
    cout << "Enter Bloodgroup: ";
    cin >> bloodgroup[index];
    cout << "Enter City: ";
    cin >> city[index];
    cout << "Enter Status: ";
    cin >> status[index];
    index++;
    cout << endl;
    cout << "Press any key for back...";
    getch();
}

void deleteDonor()
{

    int index;
    string deleteName;
    cout << endl;
    cout << "Enter Name of the Donor: ";
    cin >> deleteName;
    bool notFound = true;
    for (int idx = 0; idx < 5; idx++)
    {
        if (deleteName == name[idx])
        {
            index = idx;
            cout << "Name\t\tAge\t\tBloodgroup\tCity\t\tStatus" << endl;
            cout << name[index] << "\t\t" << age[index] << "\t\t" << bloodgroup[index] << "\t\t" << city[index] << "\t\t" << status[index] << endl;
            name[index] = " ";
            age[index] = " ";
            bloodgroup[index] = " ";
            city[index] = " ";
            status[index] = " ";
            cout << endl;
            cout << "Donor Removed...";
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
    cout << "Enter Name of the Donor: ";
    cin >> updateName;
    bool notFound = true;
    for (int idx = 0; idx < 5; idx++)
    {
        if (updateName == name[idx])
        {
            index = idx;
            cout << "Name\t\tAge\t\tBloodgroup\tCity\t\tStatus" << endl;
            cout << name[index] << "\t\t" << age[index] << "\t\t" << bloodgroup[index] << "\t\t" << city[index] << "\t\t" << status[index] << endl;
            cout << endl;
            cout << "Enter Name: ";
            cin >> name[index];
            cout << "Enter Age: ";
            cin >> age[index];
            cout << "Enter Bloodgroup: ";
            cin >> bloodgroup[index];
            cout << "Enter City: ";
            cin >> city[index];
            cout << "Enter Status: ";
            cin >> status[index];
            cout << endl;
            cout << "Donor Updated...";
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
    string searchName;
    cout << endl;
    cout << "Enter Name of the Donor: ";
    cin >> searchName;
    bool notFound = true;
    for (int idx = 0; idx < 5; idx++)
    {
        if (searchName == name[idx])
        {
            index = idx;
            cout << "Name\t\tAge\t\tBloodgroup\tCity\t\tStatus" << endl;
            cout << name[index] << "\t\t" << age[index] << "\t\t" << bloodgroup[index] << "\t\t" << city[index] << "\t\t" << status[index] << endl;
            cout << endl;
            cout << "Donor Found...";
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
void viewDonor()
{
    cout << endl;
    cout << "Following Are the Donors: " << endl;
    cout << endl;
    cout << "Name\t\tAge\t\tBloodgroup\tCity\t\tStatus" << endl;
    for (int index = 0; index < 5; index++)
    {
        cout << name[index] << "\t\t" << age[index] << "\t\t" << bloodgroup[index] << "\t\t" << city[index] << "\t\t" << status[index] << endl;
    }
    cout << endl;
    cout << "Press any key for back...";
    getch();
}
