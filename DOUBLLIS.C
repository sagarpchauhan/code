#include<stdio.h>
#include<conio.h>

struct node
{
 int data;
 struct node *next;
 struct node *prev;
};

void push(struct node **head_ref,int data)
{
 struct node *new_node=(struct node*)malloc(sizeof(struct node));
 new_node->data=data;
 new_node->next=*head_ref;
 new_node->prev=NULL;

 if(*head_ref != NULL)
   (*head_ref)->prev=new_node;
 *head_ref=new_node;
}

void append(struct node**head_ref,int data)
{
 struct node *new_node=(struct node*)malloc(sizeof(struct node)),*last=*head_ref;
 new_node->data=data;
 new_node->next=NULL;

 if(*head_ref==NULL)
 {
  new_node->prev=*head_ref;
  *head_ref=new_node;
  return;
 }
 while(last->next!=NULL)
 {
  last=last->next;

 }
 last->next=new_node;
 new_node->prev=last;
}


void printlist(struct node*n)
{
 while(n!=NULL)
 {
  printf("%d\t",n->data);
  n=n->next;
 }
}

void insert(struct node**head_ref,int data,int n)
{
 struct node *new_node=(struct node*)malloc(sizeof(struct node)),*temp=*head_ref;
 new_node->data=data;


 while(temp->data!=n)
 {
  temp=temp->next;
 }
 new_node->next=temp->next;
 temp->next=new_node;
 new_node->prev=temp;
 if(new_node->next!=NULL)
 new_node->next->prev=new_node;
}

void deletenode(struct node **head_ref,int key)
{
  struct node *temp=*head_ref;

  if(temp->data==key)
    {
    temp->next->prev=NULL;
    *head_ref=temp->next;
    free(temp);
    return;
    }
  while(temp->data!=key)
      temp=temp->next;
  temp->prev->next=temp->next;
  if(temp->next!=NULL)
      temp->next->prev=temp->prev;
  free(temp);
}

int main(void)
{
 struct node *head=NULL;
 clrscr();

 push(&head,2);
 push(&head,1);
 append(&head,3);
 insert(&head,4,2);

 printlist(head);
 printf("\n\n");

 deletenode(&head,1);

 printlist(head);
 printf("\n%d",head->prev);

 printf("\nPrevious element of %d is %d:",head->next->data,head->next->prev->data);
 printf("\nNext element of %d is %d:",head->next->data,head->next->next->data);
 getch();
 return 0;
}