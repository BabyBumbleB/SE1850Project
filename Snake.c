#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>

#define width 20 
#define height 20


int x, y, fruit, gameOver, key, score; //x and y are for the starting coords of the snake
int tailLen = 3; //I always have seen the tail initialized to three in the games, so why not

void plotMap(void);
void setUp(void);


void setUp(){
    //find starting point
    x = width / 2; 
    y = height / 2;
    gameOver = 0; //initialize gameOver to false, which will later be true
    plotMap();
}

void plotMap(){ // README: Fix Map using N Curses? Use Draw function and change the fixed variables to width and height.
    
    char grid[width][height];
    
    for (int i = 0; i < 20; i++) //Row
        {
          for (int j = 0; j < 20; j++) //Col
              {
                    grid[i][j] = '.';
              }
        }
    
    //Intalize Top Border
    for (int i = 0; i < 1; i++) //Row
        {
           for (int j = 0; j < 20; j++) //Col
               {
                    grid[i][j] = '-';
               }
        }
        
    
        
    //Intalize Bottom Border
    for (int i = 19; i < 20; i++)
        {
           for (int j = 0; j < 20; j++)
               {
                    grid[i][j] = '-';
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

int main(int argc, char* argv[]){
    setUp();
}
