#include<stdio.h>
#include<conio.h>


int main(void)
{
 int a[]={1,3,8,2,6,5,7},x1=a[0],x2,i,b[]={1,2,3,4,5,6,7,8};
 clrscr();

 for(i=1;i<7;i++)
    {
    x1=x1^a[i];
    }
 x2=b[0];
 printf("\n");

 for(i=1;i<8;i++)
 {
  x2=x2^b[i];
 }
 printf("\n missing element:%d",(x2^x1));

 getch();
 return 0;
}


