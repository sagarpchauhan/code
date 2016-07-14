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

void revlist(struct node **head_ref)
{
 struct node *prev=NULL,*next,*curr=*head_ref;
 while(curr!=NULL)
 {
  next=curr->next;
  curr->next=prev;
  prev=curr;
  curr=next;
 }
 *head_ref=prev;
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

 revlist(&head);

 printlist(head);

 getch();
 return 0;
}
