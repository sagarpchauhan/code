#include<stdio.h>
#include<conio.h>

int sumcheck(int arr[],int s,int n)
{
 int l,r;
 l=0;
 r=n-1;
 while(l<r)
 {
 if(arr[l]+arr[r]==s)
   return 1;
 else if(arr[l]+arr[r]>s)
   r--;
 else
   l++;
 }
 return 0;
}

void swap(int *xp,int *yp)
{
 int temp=*xp;
 *xp=*yp;
 *yp=temp;
}


void quicksort(int arr[],int l,int h)
{
 int p1;
 if(l<h)
 {
  p1=partition(arr,l,h);
  quicksort(arr,l,p1-1);
  quicksort(arr,p1+1,h);
 }
}

int partition(int arr[],int l,int h)
{
 int pv,i,j;
 pv=arr[h];
 i=l-1;
 for(j=l;j<=(h-1);j++)
 {
  if(arr[j]<pv)
  {
   i++;
   swap(&arr[i],&arr[j]);
  }
 }
   swap(&arr[i+1],&arr[h]);
   return(i+1);

}

int main(void)
{
 int arr[]={1,5,6,8,2},n,i,s=10;
 n=(sizeof(arr))/(sizeof(arr[0]));
 clrscr();
 quicksort(arr,0,n-1);
 for(i=0;i<n;i++)
 {
  printf("%d\t",arr[i]);
 }
 printf("\n");
 if(sumcheck(arr,s,n))
  {
   printf("Pairs found");
  }
  else
    printf("pairs not found");
 getch();
 return 0;
}
