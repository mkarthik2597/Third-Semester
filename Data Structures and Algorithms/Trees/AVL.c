#include<stdio.h>
#include<stdlib.h>

struct node
{
  int item;
  struct node* left;
  struct node* right;
  int height;
};

typedef struct node node;

void create_node(node **, int);
node* insertBST(node*,node*);
node* rotate_left(node*);
node* rotate_right(node*);
void preorder(node*);
int maxheight(node*,node*);
int getbalance(node*);

main()
{
  printf("Enter a series of nodes(-999 to exit):");
  int x;
  scanf("%d",&x);
  node* head, *newnode;
  if(x!=-999)
  {
    create_node(&head,x);
    while(scanf("%d",&x),x!=-999)
    {
      create_node(&newnode,x);
      head=insertBST(head,newnode);
    }
  }
  else 
  head=NULL;
  
  preorder(head);
  printf("\n");
}

void create_node(node** head_ptr, int x)
{
  node* head=*head_ptr;
  head=malloc(sizeof(node));
  head->item=x;
  head->left=head->right=NULL;
  head->height=1;
  
  *head_ptr=head;
}

node* insertBST(node* head, node* newnode)
{
  if(head==NULL)
  return newnode;
  
  if(newnode->item<head->item)
  head->left=insertBST(head->left,newnode);
  else
  head->right=insertBST(head->right,newnode);
 
  head->height=1+maxheight(head->left,head->right);
  int bf=getbalance(head);
  
  if(bf>1 && newnode->item<head->left->item)
  return rotate_right(head);
  
  if(bf>1 && newnode->item>head->left->item)
  {
    head->left=rotate_left(head->left);
    return rotate_right(head);
  }
  
  if(bf<-1 && newnode->item>head->right->item)
  return rotate_left(head);
  
  if(bf<-1 && newnode->item<head->right->item)
  {
    head->right=rotate_right(head->right);
    return rotate_left(head);
  }
  
  return head;
}

void preorder(node* head)
{
  if(head==NULL)
  return;
  
  printf("%d %d\n",head->item,head->height);
  preorder(head->left);
  preorder(head->right);
}

node* rotate_right(node* pivot)
{
  node* root=pivot->left;
  
  node* lr=pivot->left->right;
  pivot->left->right=pivot;
  pivot->left=lr;
  
  pivot->height=1+maxheight(pivot->left,pivot->right);
  root->height=1+maxheight(root->left,root->right);
  
  return root;
}

node* rotate_left(node* pivot)
{
  node* root=pivot->right;
  
  node* rl=pivot->right->left;
  pivot->right->left=pivot;
  pivot->right=rl;
  
  pivot->height=1+maxheight(pivot->left,pivot->right);
  root->height=1+maxheight(root->left,root->right);
  
  return root;
}
  
int maxheight(node* left, node* right)
{
  if(left==NULL && right==NULL)
  return 0;
  
  if(left==NULL)
  return right->height;
  if(right==NULL)
  return left->height;
  
  if(left->height>right->height)
  return left->height;
  else
  return right->height;
}  

int getbalance(node* head)
{
  if(head->left==NULL)
  return -(head->right->height);
  if(head->right==NULL)
  return (head->left->height);
  
  return (head->left->height)-(head->right->height);
}
