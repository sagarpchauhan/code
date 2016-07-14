#include<stdio.h>
#include<conio.h>

int pivot(int arr[])
{
 int i=0;
 while(arr[i]<arr[i+1])
 {
  i++;
 }
 return(i);
}

int bin(int arr[],int l,int h,int k)
{
 int m;
 if(l<=h)
 {
  m=(l+h)/2;
  if(arr[m]==k)
    return m;
  else if(arr[m]<k)
    bin(arr,m+1,h,k);
  else
    bin(arr,l,m-1,k);
 }
 else
    return 0;
}

int main(void)
{
 int arr[]={3,4,5,6,7,1,2},p,key,pos;
 int size=(sizeof(arr))/(sizeof(arr[0]));
 clrscr();
 p=pivot(arr);
 printf("\n pivot location:%d",p);
 printf("\nEnter the key to be searched:");
 scanf("%d",&key);
 if(key==arr[p])
    pos=p;
 else if(key<arr[0])
    pos=bin(arr,p+1,size-1,key);
 else
    pos=bin(arr,0,p-1,key);
 printf("\n\n%d found at %d location:",key,pos);
 getch();
 return 0;
}