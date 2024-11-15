#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define width 20
#define height 20

int x = 0, y = 0, fruit; 
int gameOver;

int snakeLen;






void setup(){ // Intailzize
    //find starting point
    
    snakeLen = 1;
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

                if(i == i && j == 0 || j == width - 1){ // Left Border or right border
                    grid[i][j] = '|';
                }

                if(i == x && j == y){ // Spawn point middle
                    grid[x][y] = 'O';
                }




                
            }
        }

   
        
        
    
        
    
        
    //Print map
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
    }
}

void logic()
{
    
}

int main(int argc, char* argv[]){
    setup();
    draw();
}
