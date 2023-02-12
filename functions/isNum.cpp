#include <iostream>

using namespace std;
string isNum(string input);
main()
{
    string input;
    input = isNum(input);
}

string isNum(string input)
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
            return input;
        }
        else
        {
            cin.clear();
            cin.ignore();
            cout << "Wrong Charater..." << endl;
            cin >> input;
        }
    }
}