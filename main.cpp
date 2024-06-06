//  https://www.youtube.com/watch?v=PSoLD9mVXTA
//Code Source >>>>  https://www.youtube.com/watch?v=px3VIvC4pUA&list=PLkiD2wMfuiHcw--LDS8h2wv5rlcDX6cON 
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
point tail[400];
int n_tail;
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

    n_tail=0;
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
            {
                bool flag=0;
                for(int k=0; k<n_tail;k++)
                if(j==tail[k].x && i==tail[k].y){
                    cout<< "o";
                    flag=true;
                }

                if( flag ==false)
                 cout<<" ";
            }
                
        } 
     cout<< endl;   
    }
 
    for(i=0;i<widht;i++) 
        cout<< "*"; // draw last line
   cout << endl << "Score: " << score;
}

void input()
{
if(_kbhit)
{
    switch (_getche())
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
    case 'x':
    case 'X':
        gameOver= true;
        break; 
    default:
       // dir=STOP;
        break;
    }
}

}

void logic()
{
    for(int i=n_tail; i>=1; i--)
    {
        tail[i].x=tail[i-1].x;
        tail[i].y=tail[i-1].y;
    }

    tail[0].x=player.x;
    tail[0].y=player.y;

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

        n_tail++;
    } 
}

int main()
{
    srand(time(NULL));
	cout << "Snake Game by MP:....";

    setup();
    CONSOLE_CURSOR_INFO ci;

    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    ci.bVisible=false;
    ci.dwSize=10;

    SetConsoleCursorInfo(output , &ci);

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