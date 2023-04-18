#include <iostream>
#include <conio.h>
#include <thread>
using namespace std;
const int width = 40;
const int height = 25;
char screen[height][width];
int x = width / 2;
int y = height / 2;
bool Gameover = false;
int P1X = width - 2; //p - plate
int P1Y = height / 2;
int P2X = 1;
int P2Y = height / 2;
int Lscore = 0;
int Rscore = 0;
int speedx = 1;
int speedy = 1;
int Cvalue;

int RandCoord()
{
    srand(time(0));
    Cvalue = (rand() % 4) + 1;
    return Cvalue;
}
void ResetCoord()
 {
     x = width / 2;
     y = width / 2;
     speedx = 1;
     speedy = 1;
 }
 
void print()
{
   
 for(int h = 0; h < height;h++)
 {
    for(int w = 0; w < width;w++)
    { 
        screen[h][w] = ' ';
        if( w == 0 || w == width - 1)
         screen[h][w] = '#';
        if( h == 0 || h == height - 1)
         screen[h][w] = '#';
        if( w == P1X && h == P1Y)
            screen[h][w] = '|';
        if( w == P1X  && h == P1Y + 1)
            screen[h][w] = '|';
        if( w == P1X && h == P1Y - 1)
            screen[h][w] = '|';
        if( w == P2X && h == P2Y - 1)
            screen[h][w] = '|';
        if( w == P2X && h == P2Y)
            screen[h][w] = '|';
        if( w == P2X && h == P2Y  + 1)
            screen[h][w] = '|';
        if( w == x && h == y)
            screen[h][w] = '@';    
     }
 } 
    for(int h = 0; h < height;h++)
   {
        for(int w = 0;w < width;w++)
            cout << screen[h][w] <<  ' ';

    cout << '\n'; 
   }
   cout << "Score: " << Lscore << '/' << Rscore ;
   cout << endl;
}


void Logic()
{
 P2Y = y;
 if (x == width - 2 )
 {
    Lscore +=1;
    ResetCoord();
 }
 if (x == 2 )
{
    Rscore +=1;
    ResetCoord();
 }
 if (y == 1 )
    speedy = -1;
 if (y == height - 1 )
    speedy = -1;

 

 if (x == P1X - 1  && (y == P1Y - 1 || y == P1Y || y == P1Y + 1)  )
 { 
    speedx = - 1;
    speedy = - 1;
 } 
 if (x == P2X  && (y == P2Y - 1 || y == P2Y || y == P2Y + 1)  )
 {
    speedx = 1;
    speedy = 1;
 }
 if (!Gameover)
 {
    if( Cvalue == 1)
    {
        x += 1 * speedx;
        y += 1 * speedy;
    }
    if( Cvalue == 2)
    {
        x += 1 * speedx;
        y -= 1 * speedy;
    }
    if( Cvalue == 3)
    {
        x -= 1 * speedx;
        y += 1 * speedy;
    }
    if( Cvalue == 4)
    {
        x -= 1 * speedx;
        y -= 1 * speedy;
    }
 }
 
 

}
void Input()
{
	if (kbhit()) // проверяет нажата ли клавиша
		switch (getch())
		{ // просит нажать клавишу
		case 'w':
         if( P1Y != 2 )
			P1Y--;
            else
             break;
			break;
		case 's':
        if(P1Y < height - 3  )
			P1Y++;
			else
             break;
            break;
		case 'x':
			Gameover = true;
			break;
		}
}

int main()
{
while(!Gameover)
{
 system("clear");
 print();
 Logic();
 Input();
 this_thread::sleep_for(chrono::milliseconds(160));
}
}
