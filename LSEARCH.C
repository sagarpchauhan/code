#include<stdio.h>
#include<conio.h>

int main(void)
{
 int arr[50],i,search,num;
 clrscr();
 printf("Enter the number of elements:");
 scanf("%d",&num);
 printf("\nEnter %d elements of array:",num);
 for(i=0;i<num;i++)
 {
  scanf("%d",&arr[i]);
 }
 printf("\nEnter the num to search");
 scanf("%d",&search);
 for(i=0;i<num;i++)
 {
   if(arr[i]==search)
   {
    printf("Array element %d found at %d location",search,i+1);
    break;

   }

 }
  if(i==num)
    printf("Array element not found");
 getch();
 return 0;
}