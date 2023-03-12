#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

// Global data

// Buddy in 2D arrays
char Buddy[3][4];
char BuddyLeft[3][4];
// Buddy coordinates
int BuddyX = 50;
int BuddyY = 2;
// 3,22

int Buddyhealth = 100; // buddy health,jump and direction variable
string printDirection = "right";
bool isJump = false;
int jumpTick = 0;

// princess in 2D arrays
char princess[3][3];
int princessX = 28;
int princessY = 1;
int jailX = 26;
int jailY = 4;

// enemy in 2D arrays
char Enemy[3][5];
// Enemies coordinates
int enemy1X = 62;
int enemy1Y = 22;
int enemy2X = 14;
int enemy2Y = 14;
string enemy1direction = "down";
string enemy2direction = "left";

// Ant in 2D arrays
char Ant[3][5];;
// Ant coordinates
int AntX = 32;
int AntY = 6;
int AntBulletX[10];
int AntBulletY[10];
int AntCount = 0;

// Kratos in 2D arrays
char Kratos[3][7];
int KratosX = 62;
int KratosY = 22;

int score = 0; // score

// functions
void cordinates(); // helping functions
void complete();
void gotoxy(int x, int y);
string setcolor(unsigned short color);
char getCharAtxy(short int x, short int y);
void ShowConsoleCursor(bool showFlag);

void header(); // first page functions and sub-functions
void mainPic();
void loading();
void firstPage();

void option(); // second page functions and sub-functions
void howToPlay();
void instruction();
void credits();
int menu();

void printMaze1(char Maze1[26][70]); // maze functions
void printMaze2(char Maze2[26][71]);

void printBuddy(); // buddy control, print functions
void printBuddyLeft();
void teleportBuddy();
void eraseBuddy();
void moveBuddyDown();
void moveBuddyUp();
void moveBuddyLeft();
void moveBuddyRight();
void printBuddyHealth();
void controlBuddy();
bool canJump();

void printPrincess();
void erasePrincess();
void movePrincessDown();
void jailOpen();

void createBullet(); // buddy bullets functions, arrays and array counter
void movebullet();
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void deleteBullet(int index);
int bulletX[100];
int bulletY[100];
char bulletDirection[100];
int bulletCount = 0;

void printEnemy1(); // horzontal enemy functions and health variable
void eraseEnemy1();
void moveEnemy1();
int Enemy1health = 50;

void printEnemy2(); // vertical enemy functions and health variable
void eraseEnemy2();
void moveEnemy2();
int Enemy2health = 50;

void printAnt(); // Ant and its bullet functions and health variable
void eraseAnt();
void AntBullet();
void moveAntBullet();
void printAntBullet(int x, int y);
void eraseAntBullet(int x, int y);
void deleteAntBullet(int index);
int Anthealth = 100;

void printkratos(); // kratos functions and health variable
void erasekratos();
void movekratos();
int kratosHealth = 200;

void Printenemyhealth(); // printing enemies health

void collision(); // bullet collision function

void addScore(); // score print and increment function
void printScore();

void gameoverCollsion(); // check gameover function
void gameover();         // print gameover function

bool game = true; // flags for game
bool AntFlag = true;

int mainTick = 0;
bool second = false;

void loadMaze1(char Maze1[26][70]);
void loadMaze2(char Maze2[26][71]);
void loadBuddy();
void loadBuddyLeft();
void loadPrincess();
void loadEnemy();
void loadAnt();
void loadKratos();

main()
{
    char Maze1[26][70];
    char Maze2[26][71];

    loadMaze1(Maze1);
    loadMaze2(Maze2);
    loadBuddy();
    loadBuddyLeft();
    loadPrincess();
    loadEnemy();
    loadAnt();
    loadKratos();
    ShowConsoleCursor(false);
    // firstPage();
    // int x = menu();
    system("cls");
    printMaze1(Maze1);

    printEnemy1();
    printEnemy2();
    printAnt();

    printBuddy();
    // x == 1 &&
    while (game)
    {
        printScore();
        printBuddyHealth();

        gameover();

        moveEnemy1();
        moveEnemy2();

        AntBullet();

        moveAntBullet();
        gameoverCollsion();
        movebullet();
        collision();
        Printenemyhealth();
        controlBuddy();
        Sleep(50);
        // cordinates();
    }
    system("cls");
    printMaze2(Maze2);
    BuddyX = 3;
    BuddyY = 22;
    printBuddy();
    printkratos();
    printPrincess();

    while (second)
    {
        movePrincessDown();
        printScore();
        movekratos();

        printBuddyHealth();
        gameover();
        gameoverCollsion();
        movebullet();
        collision();
        Printenemyhealth();
        controlBuddy();
        teleportBuddy();

        if (kratosHealth == -1)
        {
            jailOpen();
        }

        Sleep(50);
    }
    system("cls");
}

void header()
{
    setcolor(10);
    cout << " _______  __  .______       _______    .______    __    __   _______   _______  ____    ____ " << endl;
    cout << "|   ____||  | |   _  \\     |   ____|   |   _  \\  |  |  |  | |       \\ |       \\ \\   \\  /   / " << endl;
    cout << "|  |__   |  | |  |_)  |    |  |__      |  |_)  | |  |  |  | |  .--.  ||  .--.  | \\   \\/   /  " << endl;
    cout << "|   __|  |  | |      /     |   __|     |   _  <  |  |  |  | |  |  |  ||  |  |  |  \\_    _/   " << endl;
    cout << "|  |     |  | |  |\\  \\----.|  |____    |  |_)  | |  `--'  | |  '--'  ||  '--'  |    |  |     " << endl;
    cout << "|__|     |__| | _| `._____||_______|   |______/   \\______/  |_______/ |_______/     |__|     " << endl;
    cout << endl;
    setcolor(15);
}

void mainPic()
{
    setcolor(12);
    cout << "                                      ::                                                  " << endl;
    cout << "                                    :::::                                                 " << endl;
    cout << "                                   :::::::::.   .::                                       " << endl;
    cout << "                                    ::::::::-: .:::.                                      " << endl;
    cout << "                                 .   ::::::::::::::   .                                   " << endl;
    cout << "                                 ::..:::::::::::::::. :-                                  " << endl;
    cout << "                                 -:::::::........:::::::                                  " << endl;
    cout << "                                 .::::..         ...:::.                                  " << endl;
    cout << "                                   :..  :        :. ..:  -                                " << endl;
    cout << "                                -..:.  *@@-     +@@+ ..::.                                " << endl;
    cout << "                                .:..  -@@@@#***#@@@@* ..-..                               " << endl;
    cout << "                                 :..  +@@@@@@@@@@@@@@-..::-                               " << endl;
    cout << "                                  .:  *@+=%@@@@@%=:@@- .:.                                " << endl;
    cout << "                                   .  -@@  -@@@@. :@@  -                                  " << endl;
    cout << "                                   -   -+%**@@@@+*#+  .:                                  " << endl;
    cout << "                                 .@*    +@@@@@@@@@@:  .@*                                 " << endl;
    cout << "                                 #@%:    : *@@@@= -   =@@.                                " << endl;
    cout << "                                -@@@@*.     ***+     +@@@+                                " << endl;
    cout << "                           .=++:+@@@@@@*- -+@@@@#..*@@@@@==%@@#*+:.                       " << endl;
    cout << "                       .=%@@@@@@*-#@@@@@@@+--=-. *@@@@@#-+@@@@@@@@@@*-.                   " << endl;
    cout << "                    :+%@@@@@@@@@@::-@@@@@@@@@@@@@@@@@@+:*@@@@@@@@@@@@@@+                  " << endl;
    cout << "                   %@@@@@@@@@@*::*##=:-%@@@@@@@@@*.:-%@@@@@@@@@@@@@@@@@@@-                " << endl;
    cout << "                 *@@@@@@@@@%*::+%@@@@@#=:*@@@@@@*::*@@@@@@@@@@@@@@@@@@@@@#                " << endl;
    cout << "                :@@@@@@%#+-::=%@@@@@@@@@@#++++***+:%@@@@@@@@@@@@@@@@@@@@@@:               " << endl;
    cout << "                +:=-+#@@@@#-@@@@@@@@@@@@@@@@-::-@@@*:*@@@@@#+:-:::::*@@@@@@               " << endl;
    cout << "               @@@@@@@@@@@#.@@@@@@@@@@@@@@@@@:+%@@@@@@@@@@@@@@.@@@@@@@#++*=               " << endl;
    cout << "              #@@@@@@@@@@@  +@@@@@@@@@@@@@@@:  :@@@#:%@@@@@@@= :@@@@@@@@@@@@              " << endl;
    cout << "              @@@@@@@@@@@#   #@@@@@@@@@@@@@@@@@@@@%-@@@@@@@@@   #@@@@@@@@@@@-             " << endl;
    cout << "             :@@@@@@@@@@@:    *@#****+*#*#@@@@@@#*=%@@@@@@@@:   :@@@@@@@@@@@*             " << endl;
    cout << "             :@@@@@@@@@@@      +@@@@@@@@@#::-=+*#%@@@@@@@@@%     #@@@@@@@@@@*             " << endl;
    cout << "            .-:*@@@@@@@@=      *@@@@@@@@@@:+@@@@@@@@@@@@@@@=     .@@@@@@@@%=-             " << endl;
    cout << endl;
    setcolor(15);
}

void printMaze1(char Maze1[26][70])
{
    setcolor(03);
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            cout << Maze1[i][j];
        }
        // Sleep(50);
        cout << endl;
    }
    setcolor(15);
}

void printMaze2(char Maze2[26][71])
{
    setcolor(03);
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 71; j++)
        {
            cout << Maze2[i][j];
        }
        cout << endl;
    }
    setcolor(15);
}

void loading()
{
    int x = 0;
    char loading = 219;
    for (int i = 0; i <= 10; i++)
    {
        gotoxy(35 + x, 39);
        Sleep(300);
        cout << loading << loading;
        x = x + 2;
        gotoxy(60, 39);
        cout << i << "0%";
    }
    gotoxy(40, 40);
    cout << "COMPLETE ";
    Sleep(200);
    cout << "!";
    Sleep(200);
    cout << "!";
    Sleep(500);
}

void firstPage()
{
    system("cls");
    header();
    mainPic();
    loading();
}

int menu()
{
    int choice = 0;
    while (choice != 3)
    {

        system("cls");
        header();

        setcolor(12);
        gotoxy(40, 10);
        cout << "Menu";
        gotoxy(26, 11);
        cout << "___________________________________";

        setcolor(15);
        gotoxy(38, 13);
        cout << "1. Start";
        gotoxy(38, 14);
        cout << "2. Option";
        gotoxy(38, 15);
        cout << "3. Exit";
        gotoxy(38, 17);
        cout << "Enter Option: ";
        cin >> choice;

        if (choice == 1)
        {
            return choice;
        }

        if (choice == 2)
        {
            option();
        }
    }
    if (choice == 3)
    {
        system("cls");
    }
    return 0;
}

void option()
{
    int choice = 0;

    while (choice != 4)
    {
        system("cls");
        header();
        setcolor(12);
        gotoxy(35, 10);
        cout << "Menu > Option";
        gotoxy(26, 11);
        cout << "___________________________________";
        setcolor(15);
        gotoxy(35, 13);
        cout << "1. How to Play";
        gotoxy(35, 14);
        cout << "2. Instruction";
        gotoxy(35, 15);
        cout << "3. Credits";
        gotoxy(35, 16);
        cout << "4. Back";
        gotoxy(35, 18);
        cout << "Enter Option: ";
        cin >> choice;

        if (choice == 1)
        {
            howToPlay();
        }

        if (choice == 2)
        {
            instruction();
        }

        if (choice == 3)
        {
            credits();
        }
    }
}

void howToPlay()
{
    system("cls");
    header();
    setcolor(12);
    gotoxy(35, 10);
    cout << "Menu > Option > How to Play";
    gotoxy(32, 11);
    cout << "___________________________________";
    setcolor(15);
    gotoxy(30, 13);
    cout << "Keys\t\t\t\t Functions";
    gotoxy(30, 15);
    cout << "Up arrow\t\t\t\t Move Character Upward";
    gotoxy(30, 16);
    cout << "Down arrow\t\t\t Move Character Downward";
    gotoxy(30, 17);
    cout << "Left arrow\t\t\t Move Character Leftward";
    gotoxy(30, 18);
    cout << "Right arrow\t\t\t Move Character Rightward";
    gotoxy(30, 19);
    cout << "Space\t\t\t\t Character Fire";
    gotoxy(35, 21);
    cout << "Press any key for back...";
    getch();
}

void instruction()
{
    system("cls");
    header();
    setcolor(12);
    gotoxy(35, 10);
    cout << "Menu > Option > Instruction";
    gotoxy(31, 11);
    cout << "___________________________________";
    setcolor(15);
    gotoxy(25, 13);
    cout << "You can press arrow keys for movement and space key for shooting";
    gotoxy(25, 15);
    cout << "Your score will increase by firing on enemies and eating score booster ";
    gotoxy(25, 17);
    cout << "Your health will decrease by colliding with enemies and by fire of enemies.";
    gotoxy(25, 19);
    cout << "Your level will pass by touching with gate after killing all enemies";
    gotoxy(35, 22);
    cout << "Press any key for back...";
    getch();
}

void credits()
{
    system("cls");
    header();
    setcolor(12);
    gotoxy(35, 10);
    cout << "Menu > Option > Credits";
    gotoxy(31, 11);
    cout << "___________________________________";
    setcolor(15);
    gotoxy(25, 13);
    cout << "Game Design By WALI AHMAD";
    gotoxy(25, 15);
    cout << "Enemies Art BY WALI AHMAD";
    gotoxy(25, 17);
    cout << "Character Art By ANAS MUSTAFA";
    gotoxy(25, 19);
    cout << "Special Thanks to ABDUL SABUR and ABDUL REHMAN";
    gotoxy(35, 22);
    cout << "Press any key for back...";
    getch();
}

void printBuddy()
{
    setcolor(12);
    int PrintBX = BuddyX;
    int PrintBY = BuddyY;
    for (int i = 0; i < 3; i++)
    {
        gotoxy(PrintBX, PrintBY);
        for (int j = 0; j < 4; j++)
        {
            cout << Buddy[i][j];
        }
        cout << endl;
        PrintBY++;
    }
    setcolor(15);
}

void printBuddyLeft()
{
    setcolor(12);
    int PrintBX = BuddyX;
    int PrintBY = BuddyY;
    for (int i = 0; i < 3; i++)
    {
        gotoxy(PrintBX, PrintBY);
        for (int j = 0; j < 4; j++)
        {
            cout << BuddyLeft[i][j];
        }
        cout << endl;
        PrintBY++;
    }
    setcolor(15);
}

void teleportBuddy()
{
    char wall = 219;
    char nextleft = getCharAtxy(BuddyX - 1, BuddyY);
    char nextleft1 = getCharAtxy(BuddyX - 1, BuddyY + 1);
    char nextleft2 = getCharAtxy(BuddyX - 1, BuddyY + 2);
    if (nextleft == wall && nextleft1 == wall && nextleft2 == wall)
    {
        eraseBuddy();
        BuddyX = 64;
        printBuddyLeft();
    }

    char nextright = getCharAtxy(BuddyX + 4, BuddyY);
    char nextright1 = getCharAtxy(BuddyX + 4, BuddyY + 1);
    char nextright2 = getCharAtxy(BuddyX + 4, BuddyY + 2);
    if (nextright == wall && nextright1 == wall && nextright2 == wall)
    {
        eraseBuddy();
        BuddyX = 3;
        printBuddy();
    }
}

void eraseBuddy()
{
    setcolor(12);
    int EraseBX = BuddyX;
    int EraseBY = BuddyY;
    for (int i = 0; i < 3; i++)
    {
        gotoxy(EraseBX, EraseBY);
        for (int j = 0; j < 4; j++)
        {
            cout << ' ';
        }
        cout << endl;
        EraseBY++;
    }
    setcolor(15);
}

void moveBuddyDown()
{
    char next = getCharAtxy(BuddyX, BuddyY + 3);
    char next1 = getCharAtxy(BuddyX + 1, BuddyY + 3);
    char next2 = getCharAtxy(BuddyX + 2, BuddyY + 3);
    char next3 = getCharAtxy(BuddyX + 3, BuddyY + 3);
    if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ')
    {
        eraseBuddy();
        BuddyY++;
        if (printDirection == "right")
        {
            printBuddy();
        }
        else
        {
            printBuddyLeft();
        }
    }

    else if (next == '$' || next1 == '$' || next2 == '$' || next3 == '$')
    {
        score = score + 10;
        eraseBuddy();
        BuddyY++;
        if (printDirection == "right")
        {
            printBuddy();
        }
        else
        {
            printBuddyLeft();
        }
    }
}

void moveBuddyUp()
{
    char next = getCharAtxy(BuddyX, BuddyY - 1);
    char next1 = getCharAtxy(BuddyX + 1, BuddyY - 1);
    char next2 = getCharAtxy(BuddyX + 2, BuddyY - 1);
    char next3 = getCharAtxy(BuddyX + 3, BuddyY - 1);
    if (next == ' ' && next1 == ' ' && next2 == ' ' && next3 == ' ')
    {
        eraseBuddy();
        BuddyY--;
        if (printDirection == "right")
        {
            printBuddy();
        }
        else
        {
            printBuddyLeft();
        }
    }

    if (next == '$' || next1 == '$' || next2 == '$' || next3 == '$')
    {
        score = score + 10;
        eraseBuddy();
        BuddyY--;
        if (printDirection == "right")
        {
            printBuddy();
        }
        else
        {
            printBuddyLeft();
        }
    }
}

void moveBuddyLeft()
{
    printDirection = "left";
    char next = getCharAtxy(BuddyX - 1, BuddyY);
    char next1 = getCharAtxy(BuddyX - 1, BuddyY + 1);
    char next2 = getCharAtxy(BuddyX - 1, BuddyY + 2);
    if (next == ' ' && next1 == ' ' && next2 == ' ')
    {
        eraseBuddy();
        BuddyX--;
        printBuddyLeft();
    }
    if (next == '$' || next1 == '$' || next2 == '$')
    {
        score = score + 10;
        eraseBuddy();
        BuddyX--;
        printBuddyLeft();
    }
    if ((BuddyX - 1 == princessX + 2) && (BuddyY == princessY))
    {
        complete();
        eraseBuddy();
        erasePrincess();
    }
}

void moveBuddyRight()
{
    printDirection = "right";
    char next = getCharAtxy(BuddyX + 4, BuddyY);
    char next1 = getCharAtxy(BuddyX + 4, BuddyY + 1);
    char next2 = getCharAtxy(BuddyX + 4, BuddyY + 2);
    if (next == ' ' && next1 == ' ' && next2 == ' ')
    {
        eraseBuddy();
        BuddyX++;
        printBuddy();
    }
    if (next == '$' || next1 == '$' || next2 == '$')
    {
        score = score + 10;
        eraseBuddy();
        BuddyX++;
        printBuddy();
    }
    // && Enemy1health == -1 && Enemy2health == -1 && Anthealth == -1
    if ((next == '|' || next1 == '|' || next2 == '|'))
    {
        complete();
        eraseBuddy();
    }
    if ((BuddyX + 3 == princessX - 1) && (BuddyY == princessY))
    {
        complete();
        eraseBuddy();
        erasePrincess();
    }
}

void controlBuddy()
{
    if (GetAsyncKeyState(VK_LEFT))
    {
        moveBuddyLeft();
    }

    if (GetAsyncKeyState(VK_RIGHT))
    {
        moveBuddyRight();
    }

    if (GetAsyncKeyState(VK_UP))
    {
        if (canJump())
        {
            isJump = true;
        }
    }
    if (isJump)
    {
        moveBuddyUp();
        jumpTick += 1;
        if (jumpTick == 4)
        {
            isJump = false;
            jumpTick = 0;
        }
    }
    else
    {
        moveBuddyDown();
    }

    if (GetAsyncKeyState(VK_SPACE))
    {
        createBullet();
    }
}

bool canJump()
{
    char below1 = getCharAtxy(BuddyX, BuddyY + 3);
    char below2 = getCharAtxy(BuddyX + 1, BuddyY + 3);
    char below3 = getCharAtxy(BuddyX + 2, BuddyY + 3);
    char below4 = getCharAtxy(BuddyX + 3, BuddyY + 3);
    if ((below1 == '#' || below2 == '#' || below3 == '#' || below4 == '#'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void printEnemy1()
{
    setcolor(10);
    int EnemyP1X = enemy1X;
    int EnemyP1Y = enemy1Y;
    for (int i = 0; i < 3; i++)
    {
        gotoxy(EnemyP1X, EnemyP1Y);
        for (int j = 0; j < 5; j++)
        {
            cout << Enemy[i][j];
        }
        cout << endl;
        EnemyP1Y++;
    }
    setcolor(15);
}

void eraseEnemy1()
{
    setcolor(10);
    int EnemyP1X = enemy1X;
    int EnemyP1Y = enemy1Y;
    for (int i = 0; i < 3; i++)
    {
        gotoxy(EnemyP1X, EnemyP1Y);
        for (int j = 0; j < 5; j++)
        {
            cout << ' ';
        }
        cout << endl;
        EnemyP1Y++;
    }
    setcolor(15);
}

void moveEnemy1()
{
    if (Enemy1health > 0)
    {
        if (enemy1direction == "up")
        {
            char next = getCharAtxy(enemy1X, enemy1Y - 1);
            if (next == ' ')
            {
                eraseEnemy1();
                enemy1Y--;
                printEnemy1();
            }
            if (next == '#')
            {
                enemy1direction = "down";
            }
        }
        if (enemy1direction == "down")
        {
            char next = getCharAtxy(enemy1X, enemy1Y + 3);
            if (next == ' ')
            {
                eraseEnemy1();
                enemy1Y++;
                printEnemy1();
            }
            if (next == '#')
            {
                enemy1direction = "up";
            }
        }
    }
    if (Enemy1health == 0)
    {
        eraseEnemy1();
        Enemy1health = -1;
        enemy1X = 0;
        enemy1Y = 0;
        gotoxy(75, 12);
        cout << "Botchan Health: KILL ";
    }
}

void printEnemy2()
{
    setcolor(13);
    int EnemyP2X = enemy2X;
    int EnemyP2Y = enemy2Y;

    for (int i = 0; i < 3; i++)
    {
        gotoxy(EnemyP2X, EnemyP2Y);
        for (int j = 0; j < 5; j++)
        {
            cout << Enemy[i][j];
        }
        cout << endl;
        EnemyP2Y++;
    }
    setcolor(15);
}

void eraseEnemy2()
{
    setcolor(10);
    int EnemyP2X = enemy2X;
    int EnemyP2Y = enemy2Y;
    for (int i = 0; i < 3; i++)
    {
        gotoxy(EnemyP2X, EnemyP2Y);
        for (int j = 0; j < 5; j++)
        {
            cout << ' ';
        }
        cout << endl;
        EnemyP2Y++;
    }
    setcolor(15);
}

void moveEnemy2()
{

    if (Enemy2health > 0)
    {
        if (enemy2direction == "left")
        {
            char next = getCharAtxy(enemy2X - 1, enemy2Y + 1);
            if (next == ' ')
            {
                eraseEnemy2();
                enemy2X--;
                printEnemy2();
            }
            if (next == '#')
            {
                enemy2direction = "right";
            }
        }

        if (enemy2direction == "right")
        {
            char next = getCharAtxy(enemy2X + 5, enemy2Y + 1);
            if (next == ' ')
            {
                eraseEnemy2();
                enemy2X++;
                printEnemy2();
            }
            if (next == '#')
            {
                enemy2direction = "left";
            }
        }
    }
    if (Enemy2health == 0)
    {
        eraseEnemy2();
        Enemy2health = -1;
        enemy2X = 0;
        enemy2Y = 0;
        gotoxy(75, 13);
        cout << "Titchi Health: KILL ";
    }
}

void printAnt()
{
    setcolor(06);
    int AntPX = AntX;
    int AntPY = AntY;

    for (int i = 0; i < 3; i++)
    {
        gotoxy(AntPX, AntPY);
        for (int j = 0; j < 5; j++)
        {
            cout << Ant[i][j];
        }
        cout << endl;
        AntPY++;
    }
    setcolor(15);
}

void eraseAnt()
{
    setcolor(06);
    int AntPX = AntX;
    int AntPY = AntY;

    for (int i = 0; i < 3; i++)
    {
        gotoxy(AntPX, AntPY);
        for (int j = 0; j < 5; j++)
        {
            cout << ' ';
        }
        cout << endl;
        AntPY++;
    }
    setcolor(15);
}

void AntBullet()
{
    if ((AntX < BuddyX + 20) && (AntY == BuddyY) && AntFlag)
    {
        setcolor(06);
        AntBulletX[AntCount] = AntX - 1;
        AntBulletY[AntCount] = AntY + 1;
        gotoxy(AntBulletX[AntCount], AntBulletY[AntCount]);
        cout << ".";
        AntCount++;
        setcolor(15);
    }

    if (Anthealth == 0)
    {
        eraseAnt();
        Anthealth = -1;
        AntX = 0;
        AntY = 0;
        gotoxy(75, 14);
        cout << "Sadara Health: KILL ";
        AntFlag = false;
    }
}

void moveAntBullet()
{
    for (int x = 0; x < AntCount; x++)
    {
        char next = getCharAtxy(AntBulletX[x] - 1, AntBulletY[x]);
        if (next != ' ')
        {
            eraseAntBullet(AntBulletX[x], AntBulletY[x]);
            deleteAntBullet(x);
        }
        else
        {
            eraseAntBullet(AntBulletX[x], AntBulletY[x]);
            AntBulletX[x]--;
            printAntBullet(AntBulletX[x], AntBulletY[x]);
        }
    }
}

void printAntBullet(int x, int y)
{
    setcolor(06);
    gotoxy(x, y);
    cout << ".";
    setcolor(15);
}

void eraseAntBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void deleteAntBullet(int index)
{
    int x = index;
    while (x < AntCount)
    {
        AntBulletX[x] = AntBulletX[x + 1];
        AntBulletY[x] = AntBulletY[x + 1];
        x++;
    }
    AntCount--;
}

void printPrincess()
{
    int princessPX = princessX;
    int princessPY = princessY;
    setcolor(02);
    for (int i = 0; i < 3; i++)
    {
        gotoxy(princessPX, princessPY);
        for (int j = 0; j < 3; j++)
        {
            cout << princess[i][j];
        }
        cout << endl;
        princessPY++;
    }
    setcolor(15);
}

void erasePrincess()
{
    int princessPX = princessX;
    int princessPY = princessY;
    for (int i = 0; i < 3; i++)
    {
        gotoxy(princessPX, princessPY);
        for (int j = 0; j < 3; j++)
        {
            cout << ' ';
        }
        cout << endl;
        princessPY++;
    }
}

void movePrincessDown()
{
    char next = getCharAtxy(princessX, princessY + 3);
    char next1 = getCharAtxy(princessX + 1, princessY + 3);
    char next2 = getCharAtxy(princessX + 2, princessY + 3);
    if (next == ' ' && next1 == ' ' && next2 == ' ')
    {
        erasePrincess();
        princessY++;
        printPrincess();
    }
}

void jailOpen()
{
    int jailPX = jailX;
    int jailPY = jailY;
    while (jailPX < 34)
    {
        gotoxy(jailPX, jailPY);
        cout << ' ';
        jailPX++;
    }
}

void createBullet()
{
    if (printDirection == "right")
    {
        Beep(2000, 5);
        char next = getCharAtxy(BuddyX + 4, BuddyY + 1);
        if (next == ' ')
        {
            bulletX[bulletCount] = BuddyX + 4;
            bulletY[bulletCount] = BuddyY + 1;
            bulletDirection[bulletCount] = 'R';
            gotoxy(BuddyX + 4, BuddyY + 1);
            setcolor(12);
            cout << "*";
            bulletCount++;
            setcolor(15);
        }
    }

    if (printDirection == "left")
    {
        Beep(2000, 5);
        char next = getCharAtxy(BuddyX - 1, BuddyY + 1);
        if (next == ' ')
        {
            bulletX[bulletCount] = BuddyX - 1;
            bulletY[bulletCount] = BuddyY + 1;
            bulletDirection[bulletCount] = 'L';
            gotoxy(BuddyX - 1, BuddyY + 1);
            setcolor(12);
            cout << "*";
            bulletCount++;
            setcolor(15);
        }
    }
}

void movebullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (bulletDirection[x] == 'R')
        {
            char next = getCharAtxy(bulletX[x] + 1, bulletY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                deleteBullet(x);
            }
            else
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x]++;
                printBullet(bulletX[x], bulletY[x]);
            }
        }

        if (bulletDirection[x] == 'L')
        {
            char next = getCharAtxy(bulletX[x] - 1, bulletY[x]);
            if (next != ' ')
            {
                eraseBullet(bulletX[x], bulletY[x]);
                deleteBullet(x);
            }
            else
            {
                eraseBullet(bulletX[x], bulletY[x]);
                bulletX[x]--;
                printBullet(bulletX[x], bulletY[x]);
            }
        }
    }
}

void deleteBullet(int index)
{
    int x = index;
    while (x < bulletCount)
    {
        bulletX[x] = bulletX[x + 1];
        bulletY[x] = bulletY[x + 1];
        bulletDirection[x] = bulletDirection[x + 1];
        x++;
    }
    bulletCount--;
}

void printBullet(int x, int y)
{
    setcolor(12);
    gotoxy(x, y);
    cout << "*";
    setcolor(15);
}

void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void printkratos()
{
    int KratosPX = KratosX;
    int KratosPY = KratosY;
    for (int i = 0; i < 3; i++)
    {
        gotoxy(KratosPX, KratosPY);
        for (int j = 0; j < 7; j++)
        {
            cout << Kratos[i][j];
        }
        cout << endl;
        KratosPY++;
    }
}
void erasekratos()
{
    int KratosPX = KratosX;
    int KratosPY = KratosY;
    for (int i = 0; i < 3; i++)
    {
        gotoxy(KratosPX, KratosPY);
        for (int j = 0; j < 7; j++)
        {
            cout << ' ';
        }
        cout << endl;
        KratosPY++;
    }
}
void movekratos()
{
    char wall = 219;
    if (kratosHealth > 0)
    {

        bool canMove = true;
        int xDiff = BuddyX - KratosX;
        // int yDiff = BuddyY - KratosY;
        int xOffset = 0;
        int yOffset = 0;
        erasekratos();
        // if (abs(xDiff) > abs(yDiff))
        // {
        if (xDiff < 0)
        {
            xOffset = -1;
        }
        else
        {
            xOffset = 1;
        }
        // }
        // else
        // {
        //     if (yDiff < 0)
        //     {
        //         yOffset = -1;
        //     }
        //     else
        //     {
        //         yOffset = 1;
        //     }
        // }

        char next;
        for (int i = 0; i < 7; i++)
        {
            next = getCharAtxy(KratosX + xOffset + i, KratosY + yOffset);
            // for (int j = 0; j < 3; j++)
            // {
            if (next == '#' && next == wall)
            {
                canMove = false;
                break;
            }
            // }
        }
        if (canMove)
        {
            KratosX += xOffset;
            // KratosY += yOffset;
        }
        printkratos();
    }
    if (kratosHealth == 0)
    {
        erasekratos();
        kratosHealth = -1;
        KratosX = 0;
        KratosY = 0;
        gotoxy(75, 15);
        cout << "Kratos Health: KILL ";
    }
}

void collision()
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (Enemy1health > 0)
        {
            if (bulletX[x] + 1 == enemy1X && (bulletY[x] == enemy1Y || bulletY[x] == enemy1Y + 1 || bulletY[x] == enemy1Y + 2))
            {
                eraseBullet(bulletX[x], bulletY[x]);
                Enemy1health = Enemy1health - 5;
                addScore();
                deleteBullet(x);
            }
        }

        if (Enemy2health > 0)
        {
            if ((bulletX[x] - 1 == enemy2X + 5 || bulletX[x] + 1 == enemy2X) && (bulletY[x] == enemy2Y || bulletY[x] == enemy2Y + 1 || bulletY[x] == enemy2Y + 2))
            {
                eraseBullet(bulletX[x], bulletY[x]);
                Enemy2health = Enemy2health - 5;
                addScore();
                deleteBullet(x);
            }
        }

        if (Anthealth > 0)
        {
            if (bulletX[x] + 1 == AntX && (bulletY[x] == AntY || bulletY[x] == AntY + 1 || bulletY[x] == AntY + 2))
            {
                eraseBullet(bulletX[x], bulletY[x]);
                Anthealth = Anthealth - 5;
                addScore();
                deleteBullet(x);
            }
        }

        if (kratosHealth > 0)
        {
            if ((bulletX[x] - 1 == KratosX + 7 || bulletX[x] + 1 == KratosX) && (bulletY[x] == KratosY || bulletY[x] == KratosY + 1 || bulletY[x] == KratosY + 2))
            {
                eraseBullet(bulletX[x], bulletY[x]);
                kratosHealth = kratosHealth - 5;
                addScore();
                deleteBullet(x);
            }
        }
    }
}

void printScore()
{
    gotoxy(75, 8);
    cout << "Score: " << score;
}

void addScore()
{
    score++;
}

void printBuddyHealth()
{
    gotoxy(75, 10);
    cout << "Your Health:    ";
    gotoxy(75, 10);
    cout << "Your Health: " << Buddyhealth;
}

void Printenemyhealth()
{
    if (Enemy1health > 0)
    {
        gotoxy(75, 12);
        cout << "Botchan Health:   ";
        gotoxy(75, 12);
        cout << "Botchan Health: " << Enemy1health;
    }
    if (Enemy2health > 0)
    {
        gotoxy(75, 13);
        cout << "Titchi Health:   ";
        gotoxy(75, 13);
        cout << "Titchi Health: " << Enemy2health;
    }

    if (Anthealth > 0)
    {
        gotoxy(75, 14);
        cout << "Sadara Health:    ";
        gotoxy(75, 14);
        cout << "Sadara Health: " << Anthealth;
    }

    if (kratosHealth > 0)
    {
        gotoxy(75, 15);
        cout << "Kratos Health:    ";
        gotoxy(75, 15);
        cout << "Kratos Health: " << kratosHealth;
    }
}

void gameoverCollsion()
{
    // enemy1
    if (Enemy1health > 0)
    {
        if (BuddyX + 3 == enemy1X - 1 && BuddyY == enemy1Y) // right
        {
            Buddyhealth = 0;
        }
        if ((BuddyX == enemy1X + 1 && BuddyY - 1 == enemy1Y + 2) || (BuddyX == enemy1X - 1 && BuddyY - 1 == enemy1Y + 2) || (BuddyX == enemy1X - 2 && BuddyY - 1 == enemy1Y + 2) || (BuddyX == enemy1X - 3 && BuddyY - 1 == enemy1Y + 2) || (BuddyX + 1 == enemy1X && BuddyY - 1 == enemy1Y + 2) || (BuddyX + 2 == enemy1X && BuddyY - 1 == enemy1Y + 2) || (BuddyX + 3 == enemy1X && BuddyY - 1 == enemy1Y + 2)) // up
        {
            Buddyhealth = 0;
        }
        if ((BuddyX == enemy1X + 1 && BuddyY + 2 == enemy1Y - 1) || (BuddyX == enemy1X - 1 && BuddyY + 2 == enemy1Y - 1) || (BuddyX == enemy1X - 2 && BuddyY + 2 == enemy1Y - 1) || (BuddyX == enemy1X - 3 && BuddyY + 2 == enemy1Y - 1) || (BuddyX + 1 == enemy1X && BuddyY + 2 == enemy1Y - 1) || (BuddyX + 2 == enemy1X && BuddyY + 2 == enemy1Y - 1) || (BuddyX + 3 == enemy1X && BuddyY + 2 == enemy1Y - 1)) // down
        {
            Buddyhealth = 0;
        }
    }

    if (Enemy2health > 0)
    {
        // enemy2
        if (BuddyX + 3 == enemy2X - 1 && BuddyY == enemy2Y) // right
        {
            Buddyhealth = 0;
        }
        if (BuddyX - 1 == enemy2X + 5 && BuddyY == enemy2Y) // left
        {
            Buddyhealth = 0;
        }
        if (BuddyX == enemy2X && BuddyY - 1 == enemy2Y + 2) // up
        {
            Buddyhealth = 0;
        }
        if (BuddyX == enemy2X && BuddyY + 2 == enemy2Y) // down
        {
            Buddyhealth = 0;
        }
    }
    // ant
    for (int i = 0; i < AntCount; i++)
    {
        if (AntBulletX[i] == BuddyX + 4 && (AntBulletY[i] == BuddyY || AntBulletY[i] == BuddyY + 1 || AntBulletY[i] == BuddyY + 2))
        {
            Buddyhealth = Buddyhealth - 10;
        }
    }

    // kratos
    if (kratosHealth > 0)
    {
        // kratos
        if (BuddyX + 3 == KratosX - 1 && BuddyY == KratosY) // right
        {
            Buddyhealth = 0;
        }
        if (BuddyX - 1 == KratosX + 7 && BuddyY == KratosY) // left
        {
            Buddyhealth = 0;
        }
        if (BuddyX == KratosX && (BuddyY + 3 == KratosY || BuddyY + 3 == KratosY + 1 || BuddyY + 3 == KratosY + 2 || BuddyY + 3 == KratosY + 3 || BuddyY + 3 == KratosY + 4 || BuddyY + 3 == KratosY + 5 || BuddyY + 3 == KratosY + 6 || BuddyY + 3 == KratosY + 7)) // down
        {
            Buddyhealth = 0;
        }
    }
}

void gameover()
{
    if (Buddyhealth == 0)
    {
        game = false;
        second = false;
        system("cls");
        setcolor(12);
        gotoxy(20, 15);
        cout << "GAME OVER";
        cout << endl;
        cout << endl;
        cout << endl;
        setcolor(15);
    }
}

void complete()
{
    game = false;
    second = false;
    system("cls");
    setcolor(12);
    gotoxy(20, 15);
    cout << "STAGE COMLETE :)";
    cout << endl;
    cout << endl;
    cout << endl;
    setcolor(15);
    second = true;
}

void cordinates()
{

    gotoxy(75, 16);
    cout << BuddyX << " " << BuddyY;
    gotoxy(75, 17);
    cout << AntBulletX[0] << " " << AntBulletY[0];
}

void loadMaze1(char Maze1[26][70])
{
    fstream MazeOne;
    MazeOne.open("Maze1.txt", ios::in);
    string line;
    int row = 0;
    while (getline(MazeOne, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            Maze1[row][i] = line[i];
        }
        row++;
    }
    MazeOne.close();
}
void loadMaze2(char Maze2[26][71])
{
    fstream MazeTwo;
    MazeTwo.open("Maze2.txt", ios::in);
    string line;
    int row = 0;
    char wall = 219;
    while (getline(MazeTwo, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == 'W')
            {
                Maze2[row][i] = wall;
            }
            else
            {
                Maze2[row][i] = line[i];
            }
        }
        row++;
    }
    MazeTwo.close();
}
void loadBuddy()
{
    char fireBuddyHead = 234;
    char fireBuddyBody = 178;
    char fireBuddyHand = 155;
    fstream rightBuddyFile;
    rightBuddyFile.open("BuddyRight.txt", ios::in);
    string line;
    int row = 0;
    while (getline(rightBuddyFile, line))
    {
        for (int i = 0; i < 4; i++)
        {
            if (line[i] == 'H')
            {
                Buddy[row][i] = fireBuddyHead;
            }
            else if (line[i] == 'B')
            {
                Buddy[row][i] = fireBuddyBody;
            }
            else if (line[i] == 'L')
            {
                Buddy[row][i] = fireBuddyHand;
            }
            else
            {
                Buddy[row][i] = line[i];
            }
        }
        row++;
    }
    rightBuddyFile.close();
}

void loadBuddyLeft()
{
    char fireBuddyHead = 234;
    char fireBuddyBody = 178;
    char fireBuddyHand = 155;
    fstream leftBuddyFile;
    leftBuddyFile.open("BuddyLeft.txt", ios::in);
    string line;
    int row = 0;
    while (getline(leftBuddyFile, line))
    {
        for (int i = 0; i < 4; i++)
        {
            if (line[i] == 'H')
            {
                BuddyLeft[row][i] = fireBuddyHead;
            }
            else if (line[i] == 'B')
            {
                BuddyLeft[row][i] = fireBuddyBody;
            }
            else if (line[i] == 'L')
            {
                BuddyLeft[row][i] = fireBuddyHand;
            }
            else
            {
                BuddyLeft[row][i] = line[i];
            }
        }
        row++;
    }
    leftBuddyFile.close();
}

void loadPrincess()
{
    char head = 148;
    char center = 219;
    char rightHand = 191;
    char leftHand = 218;
    char legs = 19;
    fstream PrincessFile;
    PrincessFile.open("Princess.txt", ios::in);
    string line;
    int row = 0;
    while (getline(PrincessFile, line))
    {
        for (int i = 0; i < 3; i++)
        {
            if (line[i] == 'H')
            {
                princess[row][i] = head;
            }
            else if (line[i] == 'B')
            {
                princess[row][i] = center;
            }
            else if (line[i] == 'L')
            {
                princess[row][i] = legs;
            }
            else if (line[i] == 'r')
            {
                princess[row][i] = rightHand;
            }
            else if (line[i] == 'l')
            {
                princess[row][i] = leftHand;
            }
            else
            {
                princess[row][i] = line[i];
            }
        }
        row++;
    }
    PrincessFile.close();
}

void loadEnemy()
{
    fstream EnemyFile;
    EnemyFile.open("Enemy.txt", ios::in);
    string line;
    int row = 0;
    while (getline(EnemyFile, line))
    {
        for (int i = 0; i < 5; i++)
        {
            Enemy[row][i] = line[i];
        }
        row++;
    }
    EnemyFile.close();
}

void loadAnt()
{
    fstream AntFile;
    AntFile.open("Ant.txt", ios::in);
    string line;
    int row = 0;
    while (getline(AntFile, line))
    {
        for (int i = 0; i < 5; i++)
        {
            Ant[row][i] = line[i];
        }
        row++;
    }
    AntFile.close();
}
void loadKratos()
{
    fstream KratosFile;
    KratosFile.open("Kratos.txt", ios::in);
    string line;
    int row = 0;
    while (getline(KratosFile, line))
    {
        for (int i = 0; i < 7; i++)
        {
            Kratos[row][i] = line[i];
        }
        row++;
    }
    KratosFile.close();
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

string setcolor(unsigned short color)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon, color);
    return "";
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufsize;
    coordBufsize.X = 1;
    coordBufsize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}