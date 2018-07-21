#include<stdio.h>
#include<stdlib.h>

struct ll
{
  int item;
  struct ll* left;
  struct ll* right;
};
typedef struct ll node;

typedef struct
{
  node** arr;
  int f;
  int r;
  int count;
}
Q;

void create_tree(node*);
void enQ(Q*,node*);
node* deQ(Q*);
int CheckComplete(node*);
void preorder(node*);

int main()
{
  printf("Enter the root of the tree:");
  node*head=malloc(sizeof(node));
  scanf("%d",&head->item);
  head->left=NULL;
  head->right=NULL;
  
  create_tree(head);
  
  printf("Preorder traversal is:");
  preorder(head);
  
  if(CheckComplete(head))
  printf("\nTree is complete\n");
  else
  printf("\nTree is not complete\n");
}    

void create_tree(node*head)
{
  int x;
  char pos;
  node*temp;
  
  while(1)
  {
    printf("Enter a node:");
    scanf("%d",&x);
    if(x==-999)
    break;
    
    temp=malloc(sizeof(node));
    temp->item=x;
    temp->left=temp->right=NULL;
    
    node*prev=NULL,*curr=head;
    
    while(curr!=NULL)
    {
      prev=curr;
      printf("L or R of %d?",curr->item);
      getchar();
      scanf("%c",&pos);
      if(pos=='L')
      curr=curr->left;
      else
      curr=curr->right;
    }
    if(pos=='L')
    prev->left=temp;
    
    else
    prev->right=temp;
  }
}

void preorder(node* head)
{
  if(head==NULL)
  return;
  
  printf("%d",head->item);
  preorder(head->left);
  preorder(head->right);
}


void enQ(Q* q_ptr, node* head)
{
  q_ptr->r++;
  q_ptr->arr[q_ptr->r]=head;
  q_ptr->count++;
}

node* deQ(Q* q_ptr)
{
  q_ptr->f++;
  q_ptr->count--;
  return q_ptr->arr[q_ptr->f-1];
}
  
int CheckComplete(node* head)
{
  if(head==NULL)
  return 1;
  
  Q q1;
  q1.r=-1;
  q1.f=0;
  q1.count=0;
  q1.arr=malloc(16*sizeof(node*));
  
  enQ(&q1,head);
  int flag=0;
  
  while(q1.count>0)
  {
    head=deQ(&q1);
    
    if(head->left)
    {
      if(flag==1)
      return 0;
      
      enQ(&q1,head->left);
    }
    else
    flag=1;
    
    if(head->right)
    {
      if(flag==1)
      return 0;
      
      enQ(&q1,head->right);
    }
    else
    flag=1;
  }
  
  return 1;
}
