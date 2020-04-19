#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 5

void zero(int board[SIZE][SIZE])
{
  for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < SIZE; j++)
      board[i][j] = 0;
}

void putBombs(int board[SIZE][SIZE], int bombs)
{
  while(bombs)
  {
    int bX = rand() % SIZE;
    int bY = rand() % SIZE;

    if(board[bX][bY] != 8)
    {
      board[bX][bY] = 8;
      bombs--;
    }
  }
}

void evaluateCells(int board[SIZE][SIZE])
{
  for(int r = 0; r < SIZE; r++) // evaluating the squares around the bombs
  {
      for(int c = 0; c < SIZE; c++)
    {
      if(board[r][c] == 8)
      {
        if(board[r-1][c-1]!=8 && r-1 >= 0 && c-1 >= 0){board[r-1][c-1]++;}
        if(board[r-1][c]!=8 && r-1 >= 0){board[r-1][c]++;}
        if(board[r-1][c+1]!=8 && r-1 >= 0 && c+1 < SIZE){board[r-1][c+1]++;}
        if(board[r][c-1]!=8 && c-1 >= 0){board[r][c-1]++;}
        if(board[r][c+1]!=8 && c+1 < SIZE){board[r][c+1]++;}
        if(board[r+1][c-1]!=8 && r+1 < SIZE && c-1 >= 0){board[r+1][c-1]++;}
        if(board[r+1][c]!=8 && r+1 < SIZE){board[r+1][c]++;}
        if(board[r+1][c+1]!=8 && r+1 < SIZE && c+1 < SIZE){board[r+1][c+1]++;}
      }
    }
  }
}

void printBoard(int board[SIZE][SIZE])
{
  for(int i = 0; i < SIZE; i++)
  {
    for(int j = 0; j < SIZE; j++)
      printf("%d ", board[i][j]);
    printf("\n");
  }
}

void printDuska(char duska[SIZE][SIZE])
{
  for(int i = 0; i < SIZE; i++)
    {
      for(int j = 0; j < SIZE; j++)
        printf("%c ", duska[i][j]);
      printf("\n");
    }
}

int main()
{
  srand(time(0));

  int board[SIZE][SIZE];
  char duska[SIZE][SIZE];
  for(int i = 0; i < SIZE; i++)
    for(int j = 0; j < SIZE; j++)
      duska[i][j] = 'G';
  zero(board);

  putBombs(board, 3);
  evaluateCells(board);

  int x;
  int y;

  while(1)
  {
    printDuska(duska);

    printf("Enter an X [0;%d]: ", SIZE-1);
    scanf("%d", &x);
    printf("Enter a Y [0;%d]: ", SIZE-1);
    scanf("%d", &y);

    if(board[y][x] == 8)
    {
      printf("Game Over!\n");
      break;
    }

    duska[y][x] = board[x][y]+48;
  }

}
