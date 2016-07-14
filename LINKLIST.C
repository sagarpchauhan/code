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
 struct node *new_node=(struct node*)malloc(sizeof(struct node));
 new_node->data=new_data;
 new_node->next=*head_ref;
 *head_ref=new_node;
}

void append(struct node **head_ref,int new_data)
{
 struct node *new_node=(struct node*)malloc(sizeof(struct node));
 struct node *last=*head_ref;
 new_node->data=new_data;
 new_node->next=NULL;
 if(*head_ref==NULL)
 {
  *head_ref=new_node;
  return;
 }
 while(last->next!=NULL)
 {
  last=last->next;
 }
 last->next=new_node;

}

void printlist(struct node *n)
{
 while(n!=NULL)
 {
  printf("%d\t",n->data);
  n=n->next;
 }
}


void insert_after(struct node **head_ref,int new_data,int n)
{

 struct node *prev=*head_ref,*new_node=(struct node*)malloc(sizeof(struct node));
 new_node->data=new_data;

 while(prev->data!=n)
 {
  prev=prev->next;
 }
 if(prev->next==NULL)
 {
  prev->next=new_node;
  new_node->next=NULL;
 }
 else
 {
 new_node->next=prev->next;
 prev->next=new_node;
 }
}

void del_node(struct node **head_ref,int key)
{
 struct node *temp=*head_ref,*prev;

 if(temp->data==key)
 {
  *head_ref=temp->next;
  free(temp);
  return;
 }

 while(temp->data!=key)
 {
  prev=temp;
  temp=temp->next;
 }

 if(temp==NULL)
 {
  return;
 }
 prev->next=temp->next;
 free(temp);
}

void del_pos(struct node **head_ref,int pos)
{
 struct node *temp=*head_ref,*prev=NULL;
 int i;

 if(pos==0)
 {
  *head_ref=temp->next;
  free(temp);
  return;
 }

 for(i=0;i<pos-1;i++)
 {
   prev=temp;
   temp=temp->next;
 }


 prev->next=temp->next;
 free(temp);
}


int main(void)
{
 int n,d,p;
 struct node *head,*second,*third;
 clrscr();
 head=(struct node*)malloc(sizeof(struct node));
 second=(struct node*)malloc(sizeof(struct node));
 third=(struct node*)malloc(sizeof(struct node));

 head->data=1;
 head->next=second;

 second->data=2;
 second->next=third;

 third->data=3;
 third->next=NULL;


 printf("Already created linked list:\n");
 printlist(head);


 push(&head,4);
 printf("\n\nAfter inserting new node to first position:\n");
 printlist(head);


 append(&head,5);
 printf("\n\nAfter appending new node:\n");
 printlist(head);

 printf("\n\nEnter the data after which you want to insert new node\n");
 scanf("%d",&n);
 insert_after(&head,6,n);
 printlist(head);

 printf("\n\nEnter the data that you want to delete\n");
 scanf("%d",&d);
 del_node(&head,d);
 printlist(head);

 printf("\n\nEnter the position where you want to delete\n");
 scanf("%d",&p);
 del_pos(&head,p);
 printlist(head);

 getch();
 return 0;
}