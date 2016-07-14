#include<stdio.h>
#include<conio.h>
#define NA -1

void movend(int m[],int size)
{
 int i=size-1,j;

 for(j=size-1;j>=0;j--)
 {
  if(m[j]!=NA)
  {
   m[i]=m[j];
   i--;
  }
 }
}

void merge(int m[],int n[],int sizem,int sizen)
{
 int i=2,j=0,k=0;


  while(i<sizem && k<sizen)
  {
   if(m[i]<n[k])
   {
    m[j]=m[i];
    i++;
   }
   else
   {
    m[j]=n[k];
    k++;
   }
   j++;
  }


  while(i<sizem)
  {
   m[j]=m[i];
   i++;
   j++;
  }


  while(k<sizen)
  {
   m[j]=n[k];
   k++;
   j++;
  }

}

void print(int a[],int size)
{
 int i;
 for(i=0;i<size;i++)
 {
  printf("%d\t",a[i]);
 }
}
int main(void)
{

 int m[]={1,NA,6,NA,8},n[]={2,7},sizem,sizen;
 clrscr();
 sizem=(sizeof(m))/(sizeof(m[0]));
 sizen=(sizeof(n))/(sizeof(n[0]));
 movend(m,sizem);
 merge(m,n,sizem,sizen);
 print(m,sizem);
 getch();
 return 0;
}