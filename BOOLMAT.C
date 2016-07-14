#include<stdio.h>
#include<conio.h>

void modifym(int a[3][3])
{
 int i=0,j=0,row[3],col[3];

 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   if(a[i][j]==1)
   {
    row[i]=1;
    col[j]=1;
   }
  }
 }

 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   if(row[i]==1 || col[j]==1)
   {
    a[i][j]=1;
   }
  }
 }
}

void printm(int a[3][3])
{
 int i=0,j=0;
 for(i=0;i<3;i++)
 {
  for(j=0;j<3;j++)
  {
   printf("%d\t",a[i][j]);
  }
  printf("\n");
 }
}
int main(void)
{
 int a[3][3]={{0,0,0},{0,0,0},{1,0,0}};
 clrscr();
 printm(a);
 modifym(a);
 printf("\nMatrix after setting the rows and columns are:\n");
 printm(a);
 getch();
 return 0;
}