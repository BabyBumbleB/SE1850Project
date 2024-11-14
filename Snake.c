#include <stdio.h>
#include <stdlib.h>

#define width 20 
#define height 20
#define grid[width][height]

int x, y, fruit, gameOver, key, score; //x and y are for the starting coords of the snake
int tailLen = 3; //I always have seen the tail initialized to three in the games, so why not

void setUp(){
    //find starting point
    x = width / 2; 
    y = height / 2;
    gameOver = 0; //initialize gameOver to false, which will later be true
    
}

int main(int argc, char* argv[]){
    //Intalize Grid
    //Empty Space
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
