#include<stdio.h>
#include<conio.h>
int top=-1;

struct node
{
 int data;
 struct node *next;
};

void push(struct node **href,int data)
{
 struct node *newnode=(struct node*)malloc(sizeof(struct node)),*prev=*href;

 newnode->data=data;
 newnode->next=NULL;
 top=top+1;
 if(*href==NULL)
 {
  *href=newnode;
 }
 else
 {
  while(prev->next!=NULL)
   prev=prev->next;
  prev->next=newnode;

 }

}

void pop(struct node **href)
{
 struct node *temp=*href,*prev=NULL;
 int n=0;
 while(n!=top)
   {
   prev=temp;
   temp=temp->next;
   n++;
   }
 prev->next=NULL;
 printf("\npopped element:%d",temp->data);
 top=top-1;
 free(temp);
}

void display(struct node *n)
{
 printf("\n");
 while(n!=NULL)
 {
  printf("%d\t",n->data);
  n=n->next;
 }

}


int main(void)
{
 struct node *head=NULL;
 clrscr();
 push(&head,10);
 push(&head,20);
 push(&head,30);
 display(head);

 pop(&head);
 pop(&head);
 display(head);

 getch();
 return 0;
}