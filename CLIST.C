#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
};

void append(struct node **head_ref,int new_data)
{
 struct node *new_node=(struct node*)malloc(sizeof(struct node));
 struct node *last=*head_ref;
 new_node->data=new_data;

 if(*head_ref==NULL)
 {
  *head_ref=new_node;
  new_node->next=*head_ref;
  return;
 }
 while(last->next!=*head_ref)
 {
  last=last->next;
 }
 last->next=new_node;
 new_node->next=*head_ref;

}

void printlist(struct node *n)
{
 struct node *temp=n;

 if(n!=NULL)
 {
 do{
  printf("%d\t",temp->data);
  temp=temp->next;
  }
  while(temp!=n);
 }
}

int main(void)
{
 struct node *head=NULL;
 clrscr();

 append(&head,5);
 append(&head,6);
 append(&head,7);
 append(&head,8);
 printlist(head);
 getch();
 return 0;

}
