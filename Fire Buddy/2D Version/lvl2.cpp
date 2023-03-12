#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

main()
{
    

    void loadMap(char map[38][131]) {
    int x = 0, y = 0;
    char temp;
    fstream mapHandle;
    mapHandle.open("squareMap.txt", ios::in);
    while (!mapHandle.eof()) {
        mapHandle >> noskipws >> temp;
        if (temp == '\n') {
            y++;
            x = 0;
        } else {
            map[y][x] = temp;
            x++;
        }
    }
    mapHandle.close();
}
}