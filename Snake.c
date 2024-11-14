#include <stdio.h>
#include <stdlib.h>

#define width 20 
#define height 20
#define grid[width][height]

int x, y, fruit, gameOver, key, score; //x and y are for the starting coords of the snake
int tailLen = 3; //I always have seen the tail initialized to three so why not

void setUp(){
    
}

int main(int argc, char* argv[]){
    for(int i = 0; i < width; i++)
        {
           for (j = 0; j < height; j++)
               {
                    printf("%d\n". grid[i][j]);
               }
        }
}
