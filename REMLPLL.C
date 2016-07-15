#include<stdio.h>
#include<conio.h>

struct node
{
 int data;
 struct node *next;
};

void push(struct node **head_ref,int data)
{
 struct node *newnode=(struct node *)malloc(sizeof(struct node));
 newnode->data=data;
 newnode->next=*head_ref;
 *head_ref=newnode;
}
void printnodes(struct node *n)
{
 while(n!=NULL)
 {
   printf("%d\t",n->data);
   n=n->next;
 }
}
struct node * detectloop(struct node **head_ref)
{
 struct node *s=*head_ref,*p=*head_ref;
 s=s->next;
 p=p->next->next;
 while(s!=p)
 {
  s=s->next;
  p=p->next->next;
 }
 if(s==p)
  return s;
 else
  return 0;
}

int countnode(struct node **pos)
{
 struct node *s=*pos,*p=*pos;
 int count=0;
 p=p->next;
 count++;
 while(s!=p)
 {
  p=p->next;
  count++;
 }
 if(s==p)
  return count;
 else
  return 0;
}

struct node * firstloopnode(struct node **head_ref,int n)
{
 struct node *s=*head_ref,*p=*head_ref;
 while(n!=0)
 {
  p=p->next;
  n--;
 }
 while(s!=p)
 {
  s=s->next;
  p=p->next;
 }
 if(s==p)
  return s;
 else
  return 0;
}

void removeloop(struct node **start)
{
 struct node *s=*start,*p=*start;
 while(p->next!=s)
 {
  p=p->next;
 }
 p->next=NULL;
}

int main(void)
{
 struct node *head=NULL,*pos,*start;
 int n;
 clrscr();

 push(&head,8);
 push(&head,7);
 push(&head,6);
 push(&head,5);
 push(&head,4);
 push(&head,3);
 push(&head,2);
 push(&head,1);
 printnodes(head);

 head->next->next->next->next->next->next->next->next=head->next->next->next;
 printf("\n\nAfter looping node 8 to node 4.");
 pos=detectloop(&head);
 printf("\n\nLoop detected at node:%d",pos->data);
 n=countnode(&pos);
 printf("\n\nNumber of loop nodes:%d",n);

 start=firstloopnode(&head,n);
 printf("\n\nFirst loop node:%d",start->data);

 removeloop(&start);
 printf("\n\nAfter removing the loop.\n");
 printnodes(head);

 getch();
 return 0;
}