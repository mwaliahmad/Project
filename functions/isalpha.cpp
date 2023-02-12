#include <iostream>

using namespace std;
string isAlpha(string input);
main()
{
    string input;
    input = isAlpha(input);
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
            cin >> input;
        }
    }
}
