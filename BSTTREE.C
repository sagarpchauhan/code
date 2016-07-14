#include<stdio.h>
#include<conio.h>

struct node
{
 int data;
 struct node *left,*right;
};

struct node *newnode(int data)
{
 struct node *node=(struct node *)malloc(sizeof(struct node));
 node->data=data;
 node->left=NULL;
 node->right=NULL;
 return(node);
}

struct node *insert(struct node *node,int data)
{
 if(node==NULL)
   return newnode(data);

 if(data<node->data)
   node->left= insert(node->left,data);

 else if(data>node->data)
   node->right=insert(node->right,data);

 return node;
}

void inorder(struct node*root)
{
 if(root==NULL)
 return;

 inorder(root->left);
 printf("%d\t",root->data);
 inorder(root->right);

}

struct node *minval(struct node *node)
{
 struct node *current=node;
 while(current->left!=NULL)
    current=current->left;
 return current;
}

struct node *deletenode(struct node *root,int data)
{
 struct node *temp=NULL;
 if(root==NULL)
   return root;

 if(data<root->data)
   root->left=deletenode(root->left,data);

 else if(data>root->data)
   root->right=deletenode(root->right,data);

 else
 {
  if(root->left==NULL)
  {
   temp=root->right;
   free(root);
   return temp;
  }
  else if(root->right==NULL)
  {
   temp=root->left;
   free(root);
   return temp;
  }
  else
  {
   temp=minval(root->right);
   root->data=temp->data;
   root->right=deletenode(root->right,temp->data);
  }
 }
 return root;
}


int main(void)
{
 struct node *root=NULL;
 clrscr();
 root=insert(root,50);
 insert(root,30);
 insert(root,20);
 insert(root,40);
 insert(root,70);
 insert(root,60);
 insert(root,80);
 printf("\nInorder traversal if BST tree is:\n");
 inorder(root);
 printf("\nAfter deleting node 20:\n");
 deletenode(root,20);
 inorder(root);
 printf("\nAfter deleting node 30:\n");
 deletenode(root,30);
 inorder(root);
 printf("\nAfter deleting node 50:\n");
 deletenode(root,50);
 inorder(root);

 getch();
 return 0;
}
