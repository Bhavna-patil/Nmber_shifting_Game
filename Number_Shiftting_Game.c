#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<windows.h>
void rule(void);
void randarray(int(*)[4]);
void showmatrix(int(*)[4]);
void randarray(int arr[][4])
{
  int i,j,n=15,num[n],lastindex,index;
  for(i=0;i<15;i++)
  num[i]=i+1;
  srand(time(NULL));
  lastindex=n-1;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    {
      if(lastindex>=0)
      {
        index=rand()%(lastindex+1);
        arr[i][j]=num[index];
        num[index]=num[lastindex--];
      }
    }
  }
  arr[i-1][j-1]=0;
}
void showmatrix(int arr[][4])
{
  int i,j;
  printf("--------------------\n");
  for(i=0;i<4;i++)
  {
    printf("|");
    for(j=0;j<4;j++)
    {
      if(arr[i][j]!=0)
      printf("%2d | ",arr[i][j]);
      else
      printf("   | ");
    }
    printf("\n");
  }
  printf("--------------------\n");
}

int winner(int arr[][4])
{
   int i,j,k=1;
   for(i=0;i<4;i++)
   {
    for(j=0;j<4;j++,k++)
     if(arr[i][j]!=k && k!=16)
     break;
     if(j<4)
     break;
   }

   if(j<4)
   return 0;
   return 1;
}

void swap(int *x,int *y)
{
  *x=*x+*y;
  *y=*x-*y;
  *x=*x-*y;
  printf("");
}

int shiftup(int arr[][4])
{
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    if(arr[i][j]==0)
    break;
    if(j<4)
    break;
  }
  if(i==3)
  return 0;

  swap(&arr[i][j],&arr[i+1][j]);
  return 1;
}

int shiftdown(int arr[][4])
{
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
     if(arr[i][j]==0)
     break;
     if(j<4)
     break;
  }
  if(i==0)
  return 0;
  swap(&arr[i][j],&arr[i-1][j]);
  return 1;
}
int shiftright(int arr[][4])
{
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    if(arr[i][j]==0)
    break;
    if(j<4)
    break;
  }
  if(j==0)
  return 0;
  swap(&arr[i][j],&arr[i][j-1]);
  return 1;
}
int shiftleft(int arr[][4])
{
  int i,j;
  for(i=0;i<4;i++)
  {
    for(j=0;j<4;j++)
    if(arr[i][j]==0)
    break;
    if(j<4)
    break;
  }
  if(j==3)
  return 0;
  swap(&arr[i][j],&arr[i][j+1]);
  return 1;
}
void rule(void)
{
   char k=1;
   int i,j;
     printf("                .......................NUMBER SHIFFTING GAME............................      ");
     printf("\n\n   RULES OF THIS GAME:=");
     printf("\n1. You Can Shift Only a Singal Number At a Time BY ARROW key\n");
     printf("                Move Up     : By UP arrow key\n");
     printf("                Move Down   : By DOWN arrow key\n");
     printf("                Move Left   : By LEFT arrow key\n");
     printf("                Move Right  : By RIGHT arrow key\n");
     printf("\n2.You can move number at empty position\n");
     printf("\n3.For each valid move : your total number of moves will decreases by 1\n");
     printf("\n4.Winning situation : Number in 4*4 matrixis should be in order from 1 to 15\n");
     printf("\n                    WINNING SITUATION            \n");
     printf("-----------------\n");
    for(i=0;i<4;i++)
    {
     
       printf("| ");
       for(j=0;j<4;j++)
       {
        if(i==3&&j==3)
        {
          printf("%c",0);
          printf(" |");
        }
        else
        {  printf("%d",k);
          if(k<10)
          printf(" | ");
          else
          printf("| ");
        }
        k++;
       }
       printf("\n");
    } 
     printf("-----------------\n");
   printf("5. You can exit game any time by pressing any key 'e' or 'E'\n");
   printf("\n        ...........Best of & Try two Win in minimum moves..........\n ");
   printf("Enter any key to start Game........\n");
   k=getch();
}

int main()
{
  char s[20],key,check;
  int maxtry=300,arr[4][4];
  printf("User name:= ");
  scanf("%s",s);
  system("cls");
  while(1)
  {
    randarray(arr);
    rule();
    while(!winner(arr))
    {
      system("cls");
      if(!maxtry)
      break;
      printf("\n\n player name: %s....Remaining Moves:= %d\n\n",s,maxtry);
      showmatrix(arr);
      key=getch();
      switch(key)
      {
        case 101:
        case 69:printf("       Thanks For Playing      \n");
         printf("Exit Game!!!!");
        exit(0);
        case 72:
                if(shiftup(arr))
                maxtry--;
                break;
        case 80:
                if(shiftdown(arr))
                maxtry--;
                break; 
        case 77:
                if(shiftright(arr))
                maxtry--;
                break;   
        case 75:
                if(shiftleft(arr))
                maxtry--;
                break;                    
        default :printf("\n\nNot Allowed\n");
      }
    }
    if(!maxtry)
    printf("\n******you loss*******\n");
    else
    printf("\n.........Congratulations %s u win this game............\n");
    fflush(stdin);
    printf("\n.......Enter y to play again....");
    scanf("%c",&check);
    if(check!='y'&&check!='Y')
    break;
    maxtry=3;
  }
  return 0;
}