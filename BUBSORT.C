#include<stdio.h>
#include<conio.h>
int main(void)
{
 int a[]={5,4,3,2,1,9,8,6,7,10},size,i,j,temp;
 clrscr();
 size=sizeof(a)/sizeof(a[0]);

 for(i=0;i<size-1;i++)
 {
  for(j=0;j<size-i-1;j++)
  {
   if(a[j]>a[j+1])
   {
    temp=a[j];
    a[j]=a[j+1];
    a[j+1]=temp;
   }
  }
 }
 printf("Sorted array is:\n");
 for(i=0;i<size;i++)
   printf("%d\t",a[i]);
 getch();
 return 0;
}