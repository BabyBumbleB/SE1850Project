#include <stdio.h> // gcc snake.c -o snake -lncurses
#include <stdlib.h>
#include <ncurses.h> //remember to do -lncurses when compiling or running, i forgor which one :skull:
#include <curses.h>

//#define getmaxyx(win,y,x)	(y = getmaxy(win), x = getmaxx(win))

int cordX, cordY, fruitx, fruity, gameOver;
int snakeTailX[100], snakeTailY[100];
int snakeLen, snakeLenx, snakeLeny;
int width = 20;
int height = 20;

char keyPressed;
char storeKey;

void setup()
{     
    initscr();
    noecho(); 
    
    //getmaxyx(stdscr, height, width);

    snakeLen = 3;
    cordX = width / 2; 
    cordY = height / 2;
    gameOver = 0; 
}

void draw(){ 

    char grid[height][width];
    
    for (int i = 0; i < height; i++) // Row
        {
            for (int j = 0; j < width; j++) // Col
            {
                grid[i][j] = '.'; 
                
                if(i == 0 || i == height - 1){ 
                    grid[i][j] = '-';
                }

                if(j == 0 || j == width - 1){ 
                    grid[i][j] = '|';
                }

                if(i == cordY && j == cordX){ 
                    grid[i][j] = 'O';
                }
            }
        }
 
    for (int i = 0; i < height; i++)
        {
           for (int j = 0; j < width; j++)
               {
                    mvaddch(i, j, grid[i][j]);
               }
        }
}

void input()
{
    keyPressed = getch();
    switch(keyPressed)
    {
        case 'w':   
            storeKey = 'w';
            break;
        case 'a':
            storeKey = 'a';
            break;
        case 's':
            storeKey = 's';
            break;
        case 'd':
            storeKey = 'd';
            break;
        default: 
            break;
    }
}

void logic()
{
    switch(storeKey)
    {
        case 'w':   
            cordY--;
            break;
        case 'a':
            cordX--;
            break;
        case 's':
            cordY++;
            break;
        case 'd':
            cordX++;
            break;
        default: 
            break; 
    }
    
    
    // int prevX = snakeTailX[0];
    // int prevY = snakeTailY[0];
    // int prev2X, prev2Y;
    // snakeTailX[0] = cordX;
    // snakeTailY[0] = cordY;
    
    // for (int i = 1; i < snakeLen; i++) {
    //     prev2X = snakeTailX[i];
    //     prev2Y = snakeTailY[i];
    //     snakeTailX[i] = prevX;
    //     snakeTailY[i] = prevY;
    //     prevX = prev2X;
    //     prevY = prev2Y;
    // }
}

//use array to store the previous data values of the snake's tail, and then we can make a flag to check if the snake is moving only one square at a time by referencing two values in the array that are one index apart, 
    //subtracting them

//include a score system, maybe add 10 points for each fruit.
int main(int argc, char* argv[]){
    setup();
    
    while(!gameOver){
        logic();
        input(); 
        draw();
    }

    
}
