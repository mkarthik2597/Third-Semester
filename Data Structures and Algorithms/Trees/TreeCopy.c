#include<stdio.h>
#include<stdlib.h>

struct ll
{
  int item;
  struct ll* left;
  struct ll* right;
};
typedef struct ll node;

void inorder_copy(node*,node*);
void create(node*);
void inorder_print(node*);

main()
{
  printf("Enter the root of the tree:");
  node*head1,*head2;
  int x;
  scanf("%d",&x);
  if(x!=-999)
  {
    head1=malloc(sizeof(node));
    head1->item=x;
    head1->left=head1->right=NULL;
    
    create(head1);
  }
  else
  head1=head2=NULL;
  
  head2=malloc(sizeof(node));
  head2->left=head2->right=NULL;
  inorder_copy(head1,head2);
  inorder_print(head1);
  inorder_print(head2);
}

void create(node* head1)
{
  int i,x;
  char pos;
  node*temp;
  
  while(1)
  {
    printf("Enter a node(-999 to terminate):");
    scanf("%d",&x);
    if(x==-999)
    break;
    
    temp=malloc(sizeof(node));
    temp->item=x;
    temp->left=temp->right=NULL;
    
    node*prev=NULL,*curr=head1;
    
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

void inorder_copy(node* head1, node* head2)
{
  if(head1->left!=NULL)
  {
    head2->left=malloc(sizeof(node));
    head2->left->left=head2->left->right=NULL;
    inorder_copy(head1->left,head2->left);
  }
  
  head2->item=head1->item;
  
  if(head1->right!=NULL)
  {
    head2->right=malloc(sizeof(node));
    head2->right->left=head2->right->right=NULL;
    inorder_copy(head1->right,head2->right);
  }
}

void inorder_print(node* head)
{
  if(head==NULL)
  return;
  
  inorder_print(head->left);
  printf("%d ",head->item);
  inorder_print(head->right);
}
