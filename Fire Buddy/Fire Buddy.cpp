#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
void cordinates();
void complete();
// Global data
char fireBuddyHead = 234;
char fireBuddyBody = 178;
char fireBuddyHand = 155;
char Buddyhead[4] = {' ', fireBuddyHead, ' ', ' '};
char Buddybody[4] = {'<', fireBuddyBody, '~', fireBuddyHand};
char Buddyfoot[4] = {'/', ' ', '\\', ' '};
int BuddyX = 2;
int BuddyY = 22;
// 2,22
char Enemyhead[5] = {' ', '_', '_', '_', ' '};
char Enemybody[5] = {'/', 'o', ' ', 'o', '\\'};
char Enemyfoot[5] = {'|', ',', ',', ',', '|'};
int enemy1X = 62;
int enemy1Y = 22;
int enemy2X = 14;
int enemy2Y = 14;
string enemy1direction = "down";
string enemy2direction = "left";

char Anthead[5] = {',', ' ', ' ', ' ', ' '};
char Antbody[5] = {'>', 'o', 'o', 'o', ' '};
char Antfoot[5] = {' ', '|', '|', '|', ' '};
int AntX = 32;
int AntY = 6;
int AntBulletX[10];
int AntBulletY[10];
int AntCount = 0;

char Kratoshead[7] = {'.', '-', '.', '-', '\\', '_', '/'};
char Kratosbody[7] = {'(', '_', '(', '_', '(', '*', ')'};
char Kratosfoot[7] = {' ', 'x', ' ', 'x', ' ', 'x', ' '};

int score = 0;

// functions
void gotoxy(int x, int y);
string setcolor(unsigned short color);
char getCharAtxy(short int x, short int y);

void header();

void mainPic();
void loading();
void firstPage();

void option();
void howToPlay();
void instruction();
void credits();
int menu();

void printMaze();

void printBuddy();
void moveBuddyDown();
void moveBuddyUp();
void moveBuddyLeft();
void moveBuddyRight();
void printBuddyHealth();
int Buddyhealth = 100;

void createBullet();
void movebullet();

void printBullet(int x, int y);
void eraseBullet(int x, int y);
void deleteBullet(int index);
int bulletX[100];
int bulletY[100];

int bulletCount = 0;

void printEnemy1();
void printEnemy2();
void printAnt();
void eraseAnt();
void printKratos();
void eraseEnemy1();
void eraseEnemy2();
void moveEnemy1();
void moveEnemy2();
void AntBullet();
void moveAntBullet();
void printAntBullet(int x, int y);
void eraseAntBullet(int x, int y);
void deleteAntBullet(int index);
int Enemy1health = 50;
int Enemy2health = 50;
int Anthealth = 100;
void Printenemyhealth();

void collision();

void addScore();
void printScore();

void gameoverCollsion();
void gameover();
bool game = true;
main()
{
    firstPage();
    int x = menu();
    system("cls");
    printMaze();
    printEnemy1();
    printEnemy2();
    printAnt();
    // printKratos();
    printBuddy();
    bool flag = true;
    while (x == 1 && game)
    {
        printScore();
        printBuddyHealth();
        if (Buddyhealth == 0)
        {
            gameover();
        }
        moveEnemy1();
        moveEnemy2();
        if ((AntX < BuddyX + 15) && (AntY == BuddyY) && flag)
        {
            AntBullet();
        }
        if (Anthealth == 0)
        {
            eraseAnt();
            Anthealth = -1;
            gotoxy(75, 14);
            cout << "Sadara Health: KILL ";
            flag = false;
        }
        moveAntBullet();
        gameoverCollsion();
        movebullet();
        collision();
        Printenemyhealth();
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
            moveBuddyUp();
        }

        if (GetAsyncKeyState(VK_DOWN))
        {
            moveBuddyDown();
        }

        if (GetAsyncKeyState(VK_SPACE))
        {
            createBullet();
        }
        Sleep(50);
    }
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

void printMaze()
{
    setcolor(03);
    cout << "###################################################################### " << endl;
    cout << "##                                                        _____     ## " << endl;
    cout << "##                                                       |  !  |    ## " << endl;
    cout << "##        $                                              |  !  |    ## " << endl;
    cout << "##                                                       |  !  |    ## " << endl;
    cout << "#########################        ##################################### " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "##                                                         $        ## " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "##        ############################################################ " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "##    $                                                       $     ## " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "###############################         ############################## " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "##           ######################################################### " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "##     $                     $                                      ## " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "###########################################                         ## " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "##                                                                  ## " << endl;
    cout << "###################################################################### " << endl;
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
    gotoxy(BuddyX, BuddyY);
    for (int i = 0; i < 4; i++)
    {
        cout << Buddyhead[i];
    }
    gotoxy(BuddyX, BuddyY + 1);
    for (int i = 0; i < 4; i++)
    {
        cout << Buddybody[i];
    }
    gotoxy(BuddyX, BuddyY + 2);
    for (int i = 0; i < 4; i++)
    {
        cout << Buddyfoot[i];
    }
    setcolor(15);
}
void eraseBuddy()
{
    setcolor(12);
    gotoxy(BuddyX, BuddyY);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
    gotoxy(BuddyX, BuddyY + 1);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
    }
    gotoxy(BuddyX, BuddyY + 2);
    for (int i = 0; i < 4; i++)
    {
        cout << " ";
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
        printBuddy();
    }

    if (next == '$' || next1 == '$' || next2 == '$' || next3 == '$')
    {
        score = score + 10;
        eraseBuddy();
        BuddyY++;
        printBuddy();
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
        printBuddy();
    }

    if (next == '$' || next1 == '$' || next2 == '$' || next3 == '$')
    {
        score = score + 10;
        eraseBuddy();
        BuddyY--;
        printBuddy();
    }
}

void moveBuddyLeft()
{
    char next = getCharAtxy(BuddyX - 1, BuddyY);
    char next1 = getCharAtxy(BuddyX - 1, BuddyY + 1);
    char next2 = getCharAtxy(BuddyX - 1, BuddyY + 2);
    if (next == ' ' && next1 == ' ' && next2 == ' ')
    {
        eraseBuddy();
        BuddyX--;
        printBuddy();
    }
    if (next == '$' || next1 == '$' || next2 == '$')
    {
        score = score + 10;
        eraseBuddy();
        BuddyX--;
        printBuddy();
    }
}

void moveBuddyRight()
{
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
    if (next == '|' || next1 == '|' || next2 == '|')
    {
        complete();
    }
}

void printEnemy1()
{
    setcolor(10);
    gotoxy(enemy1X, enemy1Y);
    for (int i = 0; i < 5; i++)
    {
        cout << Enemyhead[i];
    }
    gotoxy(enemy1X, enemy1Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << Enemybody[i];
    }
    gotoxy(enemy1X, enemy1Y + 2);
    for (int i = 0; i < 5; i++)
    {
        cout << Enemyfoot[i];
    }
    setcolor(15);
}

void eraseEnemy1()
{
    setcolor(10);
    gotoxy(enemy1X, enemy1Y);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    gotoxy(enemy1X, enemy1Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    gotoxy(enemy1X, enemy1Y + 2);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    setcolor(15);
}

void moveEnemy1()
{
    if (Enemy1health > 0)
    {
        if (enemy1direction == "up")
        {
            char next = getCharAtxy(enemy1X + 1, enemy1Y - 1);
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
            char next = getCharAtxy(enemy1X + 1, enemy1Y + 3);
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
        gotoxy(75, 12);
        cout << "Botchan Health: KILL ";
    }
}

void printEnemy2()
{
    setcolor(13);
    gotoxy(enemy2X, enemy2Y);
    for (int i = 0; i < 5; i++)
    {
        cout << Enemyhead[i];
    }
    gotoxy(enemy2X, enemy2Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << Enemybody[i];
    }
    gotoxy(enemy2X, enemy2Y + 2);
    for (int i = 0; i < 5; i++)
    {
        cout << Enemyfoot[i];
    }
    setcolor(15);
}

void eraseEnemy2()
{
    setcolor(10);
    gotoxy(enemy2X, enemy2Y);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    gotoxy(enemy2X, enemy2Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    gotoxy(enemy2X, enemy2Y + 2);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
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
        gotoxy(75, 13);
        cout << "Titchi Health: KILL ";
    }
}

void printAnt()
{
    setcolor(06);
    gotoxy(AntX, AntY);
    for (int i = 0; i < 5; i++)
    {
        cout << Anthead[i];
    }
    gotoxy(AntX, AntY + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << Antbody[i];
    }
    gotoxy(AntX, AntY + 2);
    for (int i = 0; i < 5; i++)
    {
        cout << Antfoot[i];
    }
    setcolor(15);
}

void eraseAnt()
{
    setcolor(06);
    gotoxy(AntX, AntY);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    gotoxy(AntX, AntY + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    gotoxy(AntX, AntY + 2);
    for (int i = 0; i < 5; i++)
    {
        cout << " ";
    }
    setcolor(15);
}

void AntBullet()
{
    setcolor(06);
    AntBulletX[AntCount] = AntX - 1;
    AntBulletY[AntCount] = AntY + 1;
    gotoxy(AntBulletX[AntCount], AntBulletY[AntCount]);
    cout << ".";
    AntCount++;
    setcolor(15);
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

void printKratos()
{
    setcolor(15);
    gotoxy(14, 2);
    for (int i = 0; i < 7; i++)
    {
        cout << Kratoshead[i];
    }
    gotoxy(14, 3);
    for (int i = 0; i < 7; i++)
    {
        cout << Kratosbody[i];
    }
    gotoxy(14, 4);
    for (int i = 0; i < 7; i++)
    {
        cout << Kratosfoot[i];
    }
    setcolor(15);
}

void createBullet()
{
    bulletX[bulletCount] = BuddyX + 4;
    bulletY[bulletCount] = BuddyY + 1;
    gotoxy(BuddyX + 4, BuddyY + 1);
    setcolor(12);
    cout << "*";
    bulletCount++;
    setcolor(15);
}

void movebullet()
{
    for (int x = 0; x < bulletCount; x++)
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
}

void deleteBullet(int index)
{
    int x = index;
    while (x < bulletCount)
    {
        bulletX[x] = bulletX[x + 1];
        bulletY[x] = bulletY[x + 1];
        x++;
    }
    bulletCount--;
}

void printBullet(int x, int y)
{
    setcolor(12);
    gotoxy(x, y);
    cout << "*";
    bulletCount++;
    setcolor(15);
}

void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
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
            if (bulletX[x] + 1 == enemy2X && (bulletY[x] == enemy2Y || bulletY[x] == enemy2Y + 1 || bulletY[x] == enemy2Y + 2))
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
        cout << "Botchan Health:  ";
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
        if (AntBulletX[i] == BuddyX + 4)
        {
            Buddyhealth = Buddyhealth - 10;
        }
    }
}

void gameover()
{
    game = false;
    system("cls");
    setcolor(12);
    gotoxy(20, 15);
    cout << "GAME OVER";
    cout << endl;
    cout << endl;
    cout << endl;
    setcolor(15);
}

void complete()
{
    game = false;
    system("cls");
    setcolor(12);
    gotoxy(20, 15);
    cout << "STAGE COMLETE :)";
    cout << endl;
    cout << endl;
    cout << endl;
    setcolor(15);
}

void cordinates()
{

    gotoxy(75, 16);
    cout << BuddyX << " " << BuddyY;
    gotoxy(75, 17);
    cout << AntBulletX[0] << " " << AntBulletY[0];
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