#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void printHeader();
int login();
int adminMenu();
int userMenu();

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
            userMenu();
        }
        else if (user == 3)
        {
            cout << endl;

            cout << "Wrong Credentials!! Try again!!";
            Sleep(300);
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
    if (username == "admin" && password == "admin")
    {
        choice = 1;
    }
    else if (username == "user" && password == "user")
    {
        choice = 2;
    }
    else if ((username != "admin" || username != "user") && (password != "admin" || password != "user"))
    {
        choice = 3;
    }
    return choice;
}

int adminMenu()
{
    int choice;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "1. View Details of all Donors... " << endl;
    cout << "2. Add New Donor..." << endl;
    cout << "3. Delete Donor... " << endl;
    cout << "4. Update Donor Details... " << endl;
    cout << "5. Search For Donor... " << endl;
    cout << "6. Log out... " << endl;
    cout << endl;
    cout << "Enter Your Option: ";
    cin >> choice;
    return 0;
}

int userMenu()
{
    int choice;
    cout << endl;
    cout << endl;
    cout << endl;
    cout << "1. View Details of all Donors... " << endl;
    cout << "2. Search For Donor... " << endl;
    cout << "3. Log out... " << endl;
    cout << endl;
    cout << "Enter Your Option: ";
    cin >> choice;
    return 0;
}
