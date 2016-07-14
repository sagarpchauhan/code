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


void storearray(struct node *node,int *arr[],int *i)
{
 if(node==NULL)
   return;

 storearray(node->left,arr,i);
 arr[*i]=node->data;
 (*i)++;
 storearray(node->right,arr,i);
}

int countnode(struct node *root)
{
 if(root==NULL)
  return 0;

 return countnode(root->left)+countnode(root->right)+1;
}

void arrtobst(struct node *root,int *arr[],int*i)
{
 if(root==NULL)
  return;

 arrtobst(root->left,arr,i);
 root->data=arr[*i];
 (*i)++;
 arrtobst(root->right,arr,i);
}

int search(struct node*arr[],int key)
{
 int i=0;
 while(arr[i]!=key)
  i++;
 return i;
}

int main(void)
{
 int *arr[7],i=0,n,j,temp,key,f;
 struct node *root=NULL;
 clrscr();

 root=newnode(10);
 root->left=newnode(30);
 root->right=newnode(15);
 root->left->left=newnode(20);
 root->right->right=newnode(5);
 inorder(root);
 printf("\n");
 n=countnode(root);
 printf("number of nodes=%d",n);

 printf("\nStoring nodes to array:\n");
 storearray(root,arr,&i);
 for(i=0;i<n;i++)
  printf( "%d\t",arr[i]);

 for(i=0;i<n-1;i++)
 {
  for(j=0;j<n-1-i;j++)
  {
   if(arr[j]>arr[j+1])
   {
    temp=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=temp;
   }
  }
 }
 printf("\narray in sorted order:\n");
 for(i=0;i<n;i++)
  printf( "%d\t",arr[i]);

 i=0;
 printf("\nArray to tree:\n");
 arrtobst(root,arr,&i);
 inorder(root);

 printf("\nenter the key to be searched in array:\n");
 scanf("%d",&key);

 f=search(arr,key);
 printf("\n arr elem found at %d",f+1);
 getch();
 return 0;
}
