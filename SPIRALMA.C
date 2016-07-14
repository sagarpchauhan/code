#include<stdio.h>
#include<conio.h>
#define r 3
#define c 4

void sprint(int a[r][c])
{
 int rs=0,cs=0,re=r-1,ce=c-1,i;


 for(i=0;i<=ce;i++)
   {
   printf("%d\t",a[rs][i]);
   }
 rs++;


 for(i=rs;i<=re;i++)
 {
  printf("%d\t",a[i][ce]);
 }
 ce--;


 for(i=ce;i>=cs;i--)
   printf("%d\t",a[re][i]);
 re--;

 for(i=cs;i<=ce;i++)
   printf("%d\t",a[re][i]);
}


int main(void)
{
 int i,j,a[r][c];
 clrscr();
 printf("Enter the matrix elements:\n");

 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }

  printf("\n\n The entered matrix is:\n");

  for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%d\t",a[i][j]);
  }
  printf("\n");
 }
 printf("\n\n");
 printf("\n Matrix printed in spiral form is:\n");
 sprint(a);
 getch();
 return 0;

}