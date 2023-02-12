#include <iostream>

using namespace std;

main()
{
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