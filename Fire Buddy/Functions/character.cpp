#include <iostream>
#include <windows.h>
using namespace std;
char fireBuddyHead = 234;
char fireBuddyBody = 178;
char fireBuddyHand = 155;
char head[5] = {' ', ' ', fireBuddyHead, ' ', ' '};
char body[5] = {' ', '<', fireBuddyBody, '~', fireBuddyHand};
char foot[5] = {' ', '/', ' ', '\\', ' '};
void printBuddy();
void gotoxy(int x, int y);
main()
{
    system("cls");
    cout << " ___" << endl;
    cout << "/o o\\" << endl;
    cout << "|,,,|" << endl;

    cout << endl;

    cout << "    ," << endl;
    cout << "ooo<" << endl;
    cout << "|||" << endl;

    cout << endl;

    cout << "\\_/-.--." << endl;
    cout << "(')__)__)" << endl;
    cout << " ^  ^  ^ " << endl;
    printBuddy();
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void printBuddy()
{
    gotoxy(20, 10);
    for (int i = 0; i < 5; i++)
    {
        cout << head[i];
    }
    gotoxy(20, 11);
    for (int i = 0; i < 5; i++)
    {
        cout << body[i];
    }
    gotoxy(20, 12);
    for (int i = 0; i < 5; i++)
    {
        cout << foot[i];
    }
}
