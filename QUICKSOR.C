#include<stdio.h>
#include<conio.h>
void swap(int*a,int*b)
{
 int t=*a;
 *a=*b;
 *b=t;
}

int partition(int arr[],int low,int high)
{
 int pivot=arr[high],i,j,n;
 i=low-1;
 for(j=low;j<=(high-1);j++)
 {
  if(arr[j] <= pivot)
  {
   i++;
   swap(&arr[i],&arr[j]);
  }
 }
  swap(&arr[i+1],&arr[high]);

  return(i+1);
}

void quicksort(int arr[],int low,int high)
{
 if(low < high)
 {
  int pi=partition(arr,low,high);
  //printf("check %d\n",pi);
  quicksort(arr,low,pi-1);

  quicksort(arr,pi+1,high);
 }

}


int main(void)
{
 int arr[]={50,20,60,30,10,40},i;
 int n=sizeof(arr)/sizeof(arr[0]);
 clrscr();
 quicksort(arr,0,n-1);
 printf("sorted array \n");
 for(i=0;i<n;i++)
  printf("%d\t",arr[i]);
 getch();
 return 0;
}