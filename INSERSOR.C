#include<stdio.h>
#include<conio.h>
int main(void)
{
 int temp,i,j,a[]={5,3,4,1,2},n;
 clrscr();
 n=sizeof(a)/sizeof(a[0]);


 for(i=1;i<n;i++)
 {
  temp=a[i];
  j=i-1;
  while((temp<a[j]) && (j>=0))
  {
   a[j+1]=a[j];
   j=j-1;
  }
  a[j+1]=temp;
 }
 printf("Sorted array is:\n");
  for(i=0;i<n;i++)
  printf("%d\t",a[i]);
 getch();
 return 0;
}