#include<stdio.h>
#include<conio.h>

void printgivenorder(struct node*,int);
struct node
{
 int data;
 struct node *left;
 struct node *right;
};

struct node *newnode(int data)
{
 struct node *node=(struct node*)malloc(sizeof(struct node));
 node->data=data;
 node->left=NULL;
 node->right=NULL;
 return(node);
}

void inorder(struct node *node)
{
 int a[5],i=0;
 if(node==NULL)
   return;

 inorder(node->left);
 printf("%d\t",node->data);
 inorder(node->right);
}


void printlevelorder(struct node *tree)
{
 int i;
  for(i=1;i<=3;i++)
   printgivenorder(tree,i);
}

void preorder(struct node *node)
{
 if(node==NULL)
   return;
 printf("%d\t",node->data);
 preorder(node->left);
 preorder(node->right);
}

void postorder(struct node *node)
{
  if(node==NULL)
   return;
  postorder(node->left);
  postorder(node->right);
  printf("%d\t",node->data);
}

void printgivenorder(struct node *tree,int level)
{
 if(tree==NULL)
 return;

 if(level==1)
   printf("%d\t",tree->data);

 else if(level>1)
 {
  printgivenorder(tree->left,level-1);
  printgivenorder(tree->right,level-1);
 }
}

int main(void)
{
 struct node *root;
 clrscr();
 root=newnode(1);
 root->left=newnode(2);
 root->right=newnode(3);
 root->left->left=newnode(4);
 root->left->right=newnode(5);
 printf("Inorder:\n ");
 inorder(root);
 printf("\nPreorder:\n");
 preorder(root);
 printf("\nPostorder:\n");
 postorder(root);
 printf("\nBFS traversal:\n");
 printlevelorder(root);
 getch();
 return 0;
}


