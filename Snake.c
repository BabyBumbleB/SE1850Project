#include <stdio.h> // gcc snake.c -o snake -lncurses
#include <stdlib.h>
#include <ncurses.h> //remember to do -lncurses when compiling or running, i forgor which one :skull:



#define width 20
#define height 20


int x, y, fruitx, fruity, gameOver;
int snakeTailX[100], snakeTailY[100];
int snakeLen, snakeLenx, snakeLeny;

char keyPressed;

void setup()
{     
    initscr();
    noecho();
    snakeLen = 3;
    x = width / 2; 
    y = height / 2;
    gameOver = 0; 
}

void draw(){ 
    
    char grid[width][height];
    
    for (int i = 0; i < width; i++) // Row
        {
            for (int j = 0; j < height; j++) // Col
            {
                grid[i][j] = '.'; 
                
                if(i == 0 || i == width - 1){ 
                    grid[i][j] = '-';
                }

                if(j == 0 || j == height - 1){ 
                    grid[i][j] = '|';
                }

                if(i == x && j == y){ 
                    grid[i][j] = 'O'; //
                }
            }
        }
 
    for (int i = 0; i < width; i++)
        {
           for (int j = 0; j < height; j++)
               {
                    mvaddch(i, j, grid[i][j]);
                    refresh();
               }
        }
}

void input()
{
    keyPressed = getch();
    switch(keyPressed)
    {
        case 'w':   
            
            break;
        case 'a':
            
            break;
        case 's':
            
            break;
        case 'd':
            
            break;
        default: 
            break;
    }
}

void logic() //this function is mainly meant to store the current location of the snake's head and tail in the corresponding arrays, and then update their locations 
{
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;
    
    for (int i = 1; i < snakeLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
}


    
//use array to store the previous data values of the snake's tail, and then we can make a flag to check if the snake is moving only one square at a time by referencing two values in the array that are one index apart, 
    //subtracting them

//include a score system, maybe add 10 points for each fruit.
int main(int argc, char* argv[]){
    setup();
    
    while(!gameOver){
        //logic();
        input(); 
        draw();
    }
}
