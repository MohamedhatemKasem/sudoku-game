#include<stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}
int grid[9][9]=
{
    {0, 0, 5, 3, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 0, 0, 0, 2, 0},
    {0, 7, 0, 0, 1, 0, 5, 0, 0},
    {4, 0, 0, 0, 0, 5, 3, 0, 0},
    {0, 1, 0, 0, 7, 0, 0, 0, 6},
    {0, 0, 3, 2, 0, 0, 0, 8, 0},
    {0, 6, 0, 5, 0, 0, 0, 0, 9},
    {0, 0, 4, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 9, 7, 0, 0}
};
int grid_copy [9][9]=
{
    {0, 0, 5, 3, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 0, 0, 0, 2, 0},
    {0, 7, 0, 0, 1, 0, 5, 0, 0},
    {4, 0, 0, 0, 0, 5, 3, 0, 0},
    {0, 1, 0, 0, 7, 0, 0, 0, 6},
    {0, 0, 3, 2, 0, 0, 0, 8, 0},
    {0, 6, 0, 5, 0, 0, 0, 0, 9},
    {0, 0, 4, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 9, 7, 0, 0}
};
int check(int x,int y,int n)
{
    int i,j=0;
    if(n>9||n<1)
    {
         SetColor(4);
        printf("in valid number \n");
           SetColor(15);
        return 0;
    }
    else if (x>8||y>8||x<0||y<0)
    {
        SetColor(4);
        printf("in valid  position\n");
        SetColor(15);
        return 0;
    }
    if (grid_copy [x][y]!=0)
    {
        SetColor(4);
        printf("in valid  position\n");
        SetColor(15);
        return 0;
    }
    for(j=0; j<9; j++)
    {
        if(n==grid[x][j])
        {
            SetColor(4);
            printf(" invalid duplicate in same row  column  number %d \n",j);
            SetColor(15);
            return 0;
        }
    }
    for(j=0; j<9; j++)
    {
        if(n==grid[j][y])
        {
            SetColor(4);
            printf(" invalid duplicate in same column  row  number %d \n",j);
            SetColor(15);
            return 0;
        }
    }
SetColor(2);
printf(" valid position and number\n");
SetColor(15);
return 1;
}
void arr_2dprint(int (*p)[9],int r,int c)
{
    int i,j;
    int(*p2)[9]=grid_copy;
    for(i=1; i<=r; i++)
    {
        if(i%3==1)
        {
            printf("  -----------------------------------\n");
        }
        for (j=1; j<=c; j++)
        {
            if(p2[i-1][j-1]==0&&p[i-1][j-1]!=0)
            {
             SetColor(3);
            }
            else if(p[i-1][j-1]!=0)
            {
             SetColor(2);
            }
            else
            {
                SetColor(15);
            }

            printf("%4d",p[i-1][j-1]);
        }
        SetColor(15);
        printf("\n");
    }
    printf("  -----------------------------------\n");
}
void insert_(void)
{
    int r,c,number;
    while(1)
    {

        printf("insert the number");
        fflush(stdin);
        scanf("%d",&number);
        printf("insert the row");
        scanf("%d",&r);
        printf("insert the coloum");
        scanf("%d",&c);
        if(check(r,c,number))
        {
            grid[r][c]=number;
            arr_2dprint(grid,9,9);
        }
    }
}
void app_start(void)
{
    printf("welcome to  sudoko game you must fill the white colors the green  colors  Not adjustable");
    arr_2dprint(grid,9,9);
    insert_();

}
