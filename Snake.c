#include <stdio.h> //gcc snake.c -o snake -lncurses 
#include <stdlib.h>
#include <ncurses.h> //remember to do -lncurses when compiling 
#include <curses.h>
#include <unistd.h>

int cordX, cordY, fruitx, fruity, gameOver;
int snakeTailX[100], snakeTailY[100];
int snakeLen, snakeLenx, snakeLeny;
int width = 20;
int height = 20;
int score = 0;
int keyPressed;
int storeKey;

void setup()
{     
    initscr();
    noecho(); 
    keypad(stdscr, TRUE);

    snakeLen = 3;
    cordX = width / 2; //starting coords of snake head
    cordY = height / 2;
    gameOver = 0; 

    fruitx = rand() % (width - 1) + 1; //this makes sure the fruit can only spawn withinn the 2d array
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
                    grid[i][j] = '-'; // Top and Bottom Grid
                }else if(j == 0 || j == width - 1){ 
                    grid[i][j] = '|'; // Side walls of Grid
                }else if(i == cordY && j == cordX){ 
                    grid[i][j] = 'O'; // Snake head
                }else if(i == fruity && j == fruitx){ 
                    grid[i][j] = '*';
                }else{
                    for(int k = 0; k < snakeLen; k++){
                        if((snakeTailX[k] == j) && (snakeTailY[k] == i)){
                            grid[i][j] = 'o'; // Snake body
                            
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
    mvprintw(height, 0, "Score : %d", score);
    mvprintw(height + 1, 0, "Created by Haden and Ben");
}

void input()
{
    keyPressed = getch();    
    switch(keyPressed) //getting input from user and storing it
    {
        case 'w': if(storeKey != 3) { storeKey = 1; } break;
        case 'a': if(storeKey != 4) { storeKey = 2; } break;
        case 's': if(storeKey != 1) { storeKey = 3; } break;
        case 'd': if(storeKey != 2) { storeKey = 4; } break;
        default: break;
    }
    switch(keyPressed)
    {
        case KEY_UP: if(storeKey != 3) { storeKey = 1; } break;
        case KEY_LEFT: if(storeKey != 4) { storeKey = 2; } break;
        case KEY_DOWN: if(storeKey != 1) { storeKey = 3; } break;
        case KEY_RIGHT: if(storeKey != 2) { storeKey = 4; } break;
        default: break;
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
    
    
    switch(storeKey) //actually making the snake move based off of user input
    {
        case 1: cordY--; break;
        case 2: cordX--; break;
        case 3: cordY++; break;
        case 4: cordX++; break;
        default: break;
    } 
    

    if(cordX < 1 || cordX >= (width - 1) || cordY < 1 || cordY >= (height - 1)){
        gameOver = 1; //if snake leaves the parameters, gameover. 
    }
    
    for (int i = 0; i < snakeLen; i++) {
        if ((snakeTailX[i] == cordX) && (snakeTailY[i] == cordY))
            gameOver = 1; //if the snake collides with its body, gameover
    }

    if((cordX == fruitx) && (cordY == fruity)){
        fruitx = rand() % (width - 1) + 1; //randomizing the location spawns of the fruit
        fruity = rand() % (height - 1) + 1;
        score += 100; //just random score incrementation based on when it touched a fruit
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
        halfdelay(1);
    }
    if(gameOver == 1){
    printf("\nGame over! The final score was %d points\n", score);
    }
    endwin(); //this fixes a bug that didnt let me type in the terminal once the game ended
    return 0;
}
