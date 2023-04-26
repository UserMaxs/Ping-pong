#include <iostream>
#include <conio.h>
#include <thread>
#include <stdlib.h>
#include <ctime>
using namespace std;

const int width = 40;
const int height = 26;
char screen[height][width];
float x = width / 2;
float y = height / 2;
bool Gameover = false;
int P1X = width - 2; //p - plate
int P1Y = height / 2;
int P2X = 1;
int P2Y = height / 2;
int Lscore = 0;
int Rscore = 0;
double speedx = 1;
double speedy = 1;
int Cvalue = 1;

void ResetCoord_speed()
 {
     speedx = 1;
     speedy = 1;
     x = width / 2;
     y = height / 2;
 }

void RandCoord()
{ 
    srand(time(0));
    Cvalue = rand() % 4;
    if (Cvalue == 1)
    {
            speedx *= 1;
            speedy *= 1;
    }
        if (Cvalue == 2)
    {
            speedx *= 1;
            speedy *= -1; 
    }
        if (Cvalue == 3)
    {
            speedx *= -1;
            speedy *= 1; 
    }
         if (Cvalue == 4)
    {
            speedx *= -1;
            speedy *= -1;
    }   

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
     }
     screen[int(y)][int (x)] = '@';
 } 
    for(int h = 0; h < height;h++)
   {
        for(int w = 0;w < width;w++)
            cout << screen[h][w] <<  ' ';

    cout << '\n'; 
   }
   cout << "Score: " << Lscore << '/' << Rscore ;
   cout << endl;
this_thread::sleep_for(chrono::milliseconds(100));
}



void Logic()
{
    if (!Gameover)
     {
     x += 1 * speedx;
     y += 1 * speedy;
     
     } 
 P2Y = y;
 if (x == width - 2 )
 {
    Lscore +=1;
    ResetCoord_speed();
    RandCoord();
 }
 if (x == 1 )
{
    Rscore +=1;
    ResetCoord_speed();
    RandCoord();
 }
 if (y == 1 )
    speedy *=  -1 ;
 if (y == height - 1 )
    speedy *= -1;

 

 if (x == P1X - 1  && (y == P1Y - 1 || y == P1Y || y == P1Y + 1)  )
 { 
    speedx = - 1 * (speedx + 0,1);
   if (speedy > 0)
    speedy =  1 * (speedy + 0,1);
   if ( speedy < 0)
    speedy = speedy - 0,1;   
 } 
 if (x == P2X + 1  && ((y == P2Y - 1) || (y == P2Y) || (y == P2Y + 1) ) )
  {
     speedx =  (speedx - 0,1);
    if ( speedy > 0)
       speedy = speedx + 0,1;
    if ( speedy < 0)
      speedy = -1 * (speedx - 0,1);
  }
  this_thread::sleep_for(chrono::milliseconds(50));

 }
  
void Input()
{
	if (kbhit()) // проверяет нажата ли клавиша
		switch (getch())
		{ // просит нажать клавишу
		case 'w':
         if( P1Y != 2  )
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
this_thread::sleep_for(chrono::milliseconds(0));

  
}

int main()
{
while(!Gameover)
{
 system("clear");
 print();
 Input();
 Logic();

}
} 
