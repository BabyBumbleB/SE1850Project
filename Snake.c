#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h> //remember to do -lncurses when compiling or running, i forgor which one :skull:

#define width 20
#define height 20

int x, y, fruitx, fruity, gameOver;
int snakeTailX[100], snakeTailY[100];
int snakeLen, snakeLenx, snakeLeny;

void setup()
{ 
    //find starting point and initialize snakes starting length to three, so that it's not just a head

    snakeLen = 3;
    x = width / 2; 
    y = height / 2;
    
    gameOver = 0; //initialize gameOver to false, which will later be true
}

void draw(){ // Runs per frame README: Fix Map using N Curses? Use Draw function and change the fixed variables to width and height.
    char grid[width][height];
    for (int i = 0; i < width; i++) // Row
        {
            for (int j = 0; j < height; j++) // Col
            {
                grid[i][j] = '.'; // No Idea why this works
                
                if(i == 0 || i == width - 1){ // Top Border or Bottom Border
                    grid[i][j] = '-';
                }

                if(j == 0 || j == width - 1){ // Left Border or right border
                    grid[i][j] = '|';
                }

                if(i == x && j == y){ // Spawn point middle
                    grid[x][y] = 'O';
                }
            }
        }
 
    for (int i = 0; i < 20; i++)
        {
           for (int j = 0; j < 20; j++)
               {
                    printf(" %c ", grid[i][j]);
               }
               printf("\n");
        }
}

void input()
{
    char getKey = scanf(" %c ");

    switch(getKey)
    {
        case 'w':   
            //w
            break;
        case 'a':
            //a
            break;
        case 's':
            //s
            break;
        case 'd':
            //d
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
    
    for (int i = 1; i < snakeTailLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
}


    
//use array to store the previous data values of the snake's tail, and then we can make a flag to check if the snake is moving only one square at a time by referencing two values in the array that are one index apart, 
    //subtracting them
}
//include a score system, maybe add 10 points for each fruit.
int main(int argc, char* argv[]){
    setup();
    draw();
    logic();
}
