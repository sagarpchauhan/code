#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};

void push(struct node **head_ref,int new_data)
{
 struct node *new_node=(struct node*)malloc(sizeof(struct node)),*temp;
 new_node->data=new_data;
 new_node->next=*head_ref;
 *head_ref=new_node;
}

void printlist(struct node *n)
{
 while(n!=NULL)
 {
  printf("%d\t",n->data);
  n=n->next;
 }
}

void swap_node(struct node **head_ref,int x,int y)
{

 struct node *prevx=NULL,*currx=*head_ref,*prevy=NULL,*curry=*head_ref,*temp;

 if(x==y)
   return;


 while(currx && currx->data != x)
 {
  prevx=currx;
  currx=currx->next;
 }


 while(curry && curry->data != y)
 {
  prevy=curry;
  curry=curry->next;
 }


 if(prevx!=NULL)
     prevx->next=curry;
 else
     *head_ref=curry;

 if(prevy!=NULL)
     prevy->next=currx;
 else
     *head_ref=currx;

 temp=curry->next;
 curry->next=currx->next;
 currx->next=temp;
}

int main(void)
{
 struct node *head=NULL;
 clrscr();

 push(&head,7);
 push(&head,6);
 push(&head,5);
 push(&head,4);
 push(&head,3);
 push(&head,2);
 push(&head,1);

 printlist(head);
 printf("\n\n");

 swap_node(&head,1,4);

 printlist(head);

 getch();
 return 0;
}
