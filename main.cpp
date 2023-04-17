#include <iostream>
#include <conio.h>
#include <thread>
using namespace std;
const int width = 30;
const int height = 20;
char screen[height][width];
int x = width / 2;
int y = height / 2;
bool Gameover = false;
int P1X = width - 2; //p - plate
int P1Y = height / 2;



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
     }
 } 
    for(int h = 0; h < height;h++)
   {
        for(int w = 0;w < width;w++)
            cout << screen[h][w] <<  ' ';

    cout << '\n'; 
   }
   cout << "Score: ";
   cout << endl;
}


void Logic()
{
 
}

void Input()
{
	if (kbhit()) // проверяет нажата ли клавиша
		switch (getch())
		{ // просит нажать клавишу
		case 'w':
         if( P1Y != 0 )
			P1Y--;
            else
			 break;
		case 's':
        if(P1Y < height - 2  )
			P1Y++;
			else
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
 this_thread::sleep_for(chrono::milliseconds(50));
}
}
