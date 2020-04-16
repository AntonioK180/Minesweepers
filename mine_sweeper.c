#include <stdio.h>

int main()
{
  int board[4][4] = {
    {0, 0, 0, 0},   // 0
    {0, 8, 0, 0},   // 1
    {0, 0, 8, 0},   // 2
    {0, 0, 0, 0}    // 3
  };

  for(int r = 0; r < 4; r++)
    for(int c = 0; c < 4; c++)
    {
      if(board[r][c] == 8)
      {
        if(board[r-1][c-1]!=8){board[r-1][c-1]++;}
        if(board[r-1][c]!=8){board[r-1][c]++;}
        if(board[r-1][c+1]!=8){board[r-1][c+1]++;}
        if(board[r][c-1]!=8){board[r][c-1]++;}
        if(board[r][c+1]!=8){board[r][c+1]++;}
        if(board[r+1][c-1]!=8){board[r+1][c-1]++;}
        if(board[r+1][c]!=8){board[r+1][c]++;}
        if(board[r+1][c+1]!=8){board[r+1][c+1]++;}
      }
    }

    for(int i = 0; i < 4; i++)
    {
      for(int j = 0; j < 4; j++)
        printf("%d ", board[i][j]);
      printf("\n");
    }
}
