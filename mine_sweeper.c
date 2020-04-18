#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

void putBombs(int board[SIZE][SIZE], int bombs)
{
  while(bombs)
  {
    int bX = rand() % (SIZE+1);
    int bY = rand() % (SIZE+1);

    if(board[bX][bY] != 8)
    {
      board[bX][bY] = 8;
      bombs--;
    }
  }

}

int main()
{
  srand(time(0));

  int board[SIZE][SIZE] = {
    {0, 0, 0, 0, 0},   // 0
    {0, 0, 0, 0, 0},   // 1
    {0, 0, 8, 0, 0},   // 2
    {0, 0, 0, 0, 0},   // 3
    {0, 0, 0, 0, 0}    // 4
  };


  putBombs(board, 3);
  for(int i = 0; i < SIZE; i++) // printing the clear board
  {
    for(int j = 0; j < SIZE; j++)
      printf("%d ", board[i][j]);
    printf("\n");
  }
  printf("\n\n");

  for(int r = 1; r < SIZE-1; r++) // evaluating the squares around the bombs
    for(int c = 1; c < SIZE-1; c++)
    {
      if(board[r][c] == 8)
      {
        if(board[r-1][c-1]==8){board[r-1][c-1]++;}
        if(board[r-1][c]==8){board[r-1][c]++;}
        if(board[r-1][c+1]==8){board[r-1][c+1]++;}
        if(board[r][c-1]==8){board[r][c-1]++;}
        if(board[r][c+1]!=8){board[r][c+1]++;}
        if(board[r+1][c-1]!=8){board[r+1][c-1]++;}
        if(board[r+1][c]!=8){board[r+1][c]++;}
        if(board[r+1][c+1]!=8){board[r+1][c+1]++;}
      }
    }

    for(int i = 0; i < SIZE; i++) // printing the clear board
    {
      for(int j = 0; j < SIZE; j++)
        printf("%d ", board[i][j]);
      printf("\n");
    }
}
