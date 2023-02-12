#include <iostream>

using namespace std;
string isBG(string input);
main()
{
    string BG;
    BG = isBG(BG);
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
            cout << "wrong" << endl;
            cin >> input;
        }
    }

    return input;
}