//#include "stdafx.h"

#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> // Sleep(ms  )

using namespace std;

int score;
int const widht = 20, height = 20;
bool gameOver;

struct point
{
	int x, y;
};

point player, fruit;


void setup()
{
    player.x= widht/2;
    player.y= height/2;

    fruit.x= rand()% widht;
    fruit.y= rand()% height; // this line grantee that fruit.y is always less than the height 

    gameOver= false;
    score=0;
}

void draw()
{
    system("cls");
    cout<< score << " ";
    score++;

}

void input()
{}

void logic()
{}

int main()
{


    srand(time(NULL));
	cout << "Snake Game by MP:....";

    setup();

    while (!gameOver)
    {
        draw();
        logic();
        input();

        Sleep(200);
    }
    
    
    getch();
	return 0;
}