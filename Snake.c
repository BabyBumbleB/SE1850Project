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
    for (int i = 0; i < width; i++)
        {
           for (int j = 0; j < height; j++)
               {
                    grid[i][j] = 0;
               }
        }
        
    //Print map
    for (int i = 0; i < width; i++)
        {
           for (int j = 0; j < height; j++)
               {
                    printf("%d", grid[i][j]);
               }
               printf("\n");
        }
}
