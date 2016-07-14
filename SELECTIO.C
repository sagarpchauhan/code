#include<stdio.h>
#include<conio.h>

void swap(int *xp,int *yp)
{
 int temp=*xp;
 *xp=*yp;
 *yp=temp;
}


void selcsort(int arr[],int n)
{
 int i,j,min_indx;
 for(i=0;i<=n;i++)
 {
  min_indx=i;

  for(j=i+1;j<=n;j++)
  {
   if(arr[j] < arr[min_indx])
   {
     min_indx=j;


   }
  }
  swap(&arr[i],&arr[min_indx]);
 }

}


int main(void)
{
 int arr[]={50,80,70,20,10,30,60,40,90},i;
 int size=sizeof(arr)/sizeof(arr[0]);
 clrscr();
 selcsort(arr,size-1);
 printf("Sorted array is:\n");
 for(i=0;i<size;i++)
   printf("%d \t",arr[i]);
 getch();
 return 0;

}