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
int score = 0;
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

    fruitx = rand() % (width - 1) + 1;
    fruity = rand() % (height - 1) + 1;
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
                }else if(j == 0 || j == width - 1){ 
                    grid[i][j] = '|';
                }else if(i == cordY && j == cordX){ 
                    grid[i][j] = 'O';
                }else{
                for(int k = 0; k < snakeLen; k++){
                    if((snakeTailX[k] == j) && (snakeTailY[k] == i)){
                        grid[i][j] = 'o';
                        
                    }

                }


                    
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

        int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = cordX;
    snakeTailY[0] = cordY;
    
    for (int i = 1; i < snakeLen; i++) {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
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
    //refresh()

    if(cordX < 0 || cordX >= width || cordY < 0 || cordY >= height){
        gameOver = 1;
    }
    
for (int i = 0; i < snakeLen; i++) {
        if ((snakeTailX[i] == cordX) && (snakeTailY[i] == cordY))
            gameOver = 1;
    }

if((cordX == fruitx) && (cordY == fruity)){
fruitx = rand() % (width - 1) + 1;
fruity = rand() % (height - 1) + 1;
score += 100;
snakeLen++;
}
    
}

//use array to store the previous data values of the snake's tail, and then we can make a flag to check if the snake is moving only one square at a time by referencing two values in the array that are one index apart, 
    //subtracting them


int main(int argc, char* argv[]){
    setup();
    
    while(!gameOver){ //leave these in this order
        draw();
        input(); 
        logic();
    }
endwin(); //this fixes a bug that didnt let me type in the terminal once the game ended
    return 0;
}
