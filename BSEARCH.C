#include<stdio.h>
#include<conio.h>
int bin(int a[],int low,int high);
int key;
int main(void)
{
 int a[50],search,num,i,loc;
 clrscr();
 printf("Enter the number of array elements");
 scanf("%d",&num);
 printf("Enter %d elements",num);
 for(i=0;i<num;i++)
   scanf("%d",&a[i]);
 printf("Enter the key to be searched");
 scanf("%d",&key);
 loc=bin(a,0,num);
 printf("%d is found at %d location",key,loc+1);
 getch();
 return 0;
}

int bin(int a[],int low,int high)
{
 int mid;
 if(low < high)
 {
   mid=(low+high)/2;
   if(key>a[mid])
   {
    low=mid+1;
    bin(a,low,high);
   }
   else if(key < a[mid])
   {
    high=mid-1;
    bin(a,low,high);
   }
   else if(key==a[mid])
      return (mid);
   else
      return 0;

 }
}