#include<stdio.h>
#include<conio.h>
int front=-1,rear=-1,elem,s[5];

void enqueue()
{
 printf("\nEnter the element:");
 scanf("%d",&elem);
 if(front==-1 && rear==-1)
 {
  front=front+1;
  rear=rear+1;
  s[rear]=elem;
 }
 else if(front!=-1 && rear<4)
 {
  rear=rear+1;
  s[rear]=elem;
 }
 else
  printf("\nQueue is full:");
  //printf("\nfront%d",front);
  //printf("\nrear%d",rear);
}
void dequeue()
{
 int n=(sizeof(s))/(sizeof(s[0])),i;
 if(front==-1 && rear==-1)
   printf("\nQueue is empty");
 else if(front!=-1 && rear>=0)
 {
  if(front!=rear)
  {
   for(i=0;i<n-1;i++)
   {
    s[i]=s[i+1];
   }
   rear=rear-1;
   n=n-1;
  }
  else
   {
    s[i]=NULL;
    front=front-1;
    rear=rear-1;
   }
 }
}


void display()
{
 int i;
 if(front==-1 && rear==-1)
   printf("\nQueue is empty");
 else
 {
  for(i=0;i<=rear;i++)
  {
   printf("%d\t",s[i]);
  }
 }
}

int main(void)
{
 int choice;
 clrscr();
 while(1)
 {
  printf("\n Enter the operation:\n1.Enqueue.\n2.Dequeue.\n3.Display.\n4.Exit.\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:enqueue();
	  getch();
	  break;
   case 2:dequeue();
	  getch();
	  break;
   case 3:display();
	  getch();
	  break;
   case 4:exit();

   default:printf("\n wrong choice");

  }

 }

 return 0;
}