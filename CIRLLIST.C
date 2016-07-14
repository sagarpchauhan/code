#include<stdio.h>
#include<conio.h>

struct node
{
 int data;
 struct node *next;
};

void push(struct node **head_ref,int dat)
{
 struct node *new_node=(struct node *)malloc(sizeof(struct node)),*temp;
 temp=*head_ref;
 new_node->data=dat;
 new_node->next=*head_ref;

 if(*head_ref!=NULL)
 {
  while(temp->next !=*head_ref)
    temp=temp->next;
  temp->next=new_node;
 }
 else
  new_node->next=new_node;
 *head_ref=new_node;
}


void printlist(struct node *n)
{
 struct node *temp=n;
 if(n!=NULL)
 {
  do
  {
    printf("%d\t",temp->data);
    temp=temp->next;
  }
  while(temp!=n);
 }

}

struct node *lastelem(struct node *href)
{
 struct node* temp=href->next;
 while(temp->next->data!=href->data)
 {
  temp=temp->next;
 }
 return temp;
}

int main(void)
{
 struct node *head=NULL,*temp;

 clrscr();
 push(&head,1);
 push(&head,2);
 push(&head,3);
 push(&head,4);
 push(&head,5);
 push(&head,6);
 printlist(head);
 temp=lastelem(head);
 printf("\n Next of last elem(%d) is %d",temp->data,temp->next->data);
 getch();
 return 0;
}