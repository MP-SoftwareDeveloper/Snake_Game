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

enum direction{STOP=0,LEFT, RIGHT, UP, DOWN};
direction dir;

void setup()
{
    player.x= widht/2;
    player.y= height/2;

    fruit.x= rand()% (widht-2)+1;
    fruit.y= rand()% (height-2)+1; // this line grantee that fruit.y is always less than the height 

    gameOver= false;
    score=0;
}

void draw()
{
    system("cls");
    //cout<< score << " "; //Number count up test 
    //score++;
    int i,j;
    for(i=0;i<widht;i++) 
        cout<<"*"; //draw first line
    cout<< endl; 
    for(i=0;i<height;i++)
    {        
        for(j=0;j<widht;j++)
        {
            if(j==0 || j==widht-1)
                cout<<"*";
            else if(j==player.x && i==player.y)
            {
                cout<<"O";
            }  
            else if(j==fruit.x && i==fruit.y)  
            {
                 cout<< "X";   
            }
            else
                cout<<" ";
        } 
     cout<< endl;   
    }
 
    for(i=0;i<widht;i++) 
        cout<< "*"; // draw last line
   cout << endl << "Score: " << score;
}

void input()
{
if(kbhit)
{
    switch (getche())
    {
    case 'w':
    case 'W':
        dir= UP;
        break;
    case 's':
    case 'S':
        dir= DOWN;
        break;
    case 'a':
    case 'A':
        dir= LEFT;
        break; 
    case 'd':
    case 'D':
        dir= RIGHT;
        break;            
    
    default:
        dir=STOP;
        break;
    }
}

}

void logic()
{
    switch (dir)
    {
    case LEFT:
        player.x = player.x-1;
        break;
    case RIGHT:
        player.x = player.x+1;
        break; 
    case UP:
        player.y = player.y-1;
        break;
    case DOWN:
        player.y = player.y+1;
        break;           
    
    default:
        break;
    }

    if(player.x > widht)
        player.x = 1;
    else if(player.x<= 0) 
        player.x= widht-1;

    if(player.y >= height)
        player.y = 1;
    else if(player.y<= 0) 
        player.y= height-1;    

    if(player.x==fruit.x && player.y== fruit.y)
    {
        score+=10;

        fruit.x= rand()% (widht-2)+1;
        fruit.y= rand()% (height-2)+1; // this line grantee that fruit.y is always less than the height 
    } 
}

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

        Sleep(50);
    }
    
    
    getch();
	return 0;
}