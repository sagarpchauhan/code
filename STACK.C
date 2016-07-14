#include<stdio.h>
#include<conio.h>

int top=-1,stack[5],choice,elem;

void push()
{
 if(top<4)
 {
  printf("\n Enter the element to be pushed:");
  scanf("%d",&elem);
  top=top+1;

  stack[top]=elem;
 }
 else
  printf("\nStack is full");
 printf("\ntop=%d",top);
}

void pop()
{
 if(top>=0)
   {
    elem=stack[top];
    top=top-1;
    printf("\npoped element is %d",elem);
   }
 else
   printf("\nStack is empty");
}

void display()
{
 int i;
 printf("\n");
 if(top<0)
  printf("stack is empty");
 else
 {
  for(i=0;i<=top;i++)
  {
   printf("\t%d",stack[i]);
  }
 }
}
int main(void)
{
 while(1)
 {
  clrscr();
  printf("Enter the operation that you want to perform:\n1.insert \n2.delete \n3.display \n4.exit\n");
  scanf("%d",&choice);
  switch(choice)
  {
   case 1:push();
	  getch();
	  break;
   case 2:pop();
	  getch();
	  break;
   case 3:display();
	  getch();
	  break;
   case 4:exit();

   default:printf("\nYou have entered wrong choice:");
	   getch();
  }


 }


 return 0;
}