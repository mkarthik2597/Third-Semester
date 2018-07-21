#include<stdio.h>
#include<stdlib.h>

struct list
{
 int item;
 struct list* left;
 struct list* right;
};
typedef struct list node;

void createBST(node*);
void inorder(node*);
void minmax(node*);
void search(int, node*);
node* delete(node*, int);

int main()
{
  printf("Enter a list of values(-999 to exit):");
  int x;
  node* head;
  scanf("%d",&x);
  if(x!=-999)
  {
    head=malloc(sizeof(node));
    head->item=x;
    head->left=head->right=NULL;
    createBST(head);
  }
  else
  head=NULL;
  
  if(head!=NULL)
  inorder(head);
  
  minmax(head);
  
  printf("\nEnter a key to be searched in the BST:");
  int key;
  scanf("%d",&key);
  search(key,head);
  
  printf("Enter an item to be deleted:");
  int key;
  scanf("%d",&key);
  
  head=delete(head,key);
  inorder(head);
}

void createBST(node* head)
{
  int x;
  node*temp;
  
  while(scanf("%d",&x),x!=-999)
  {
    temp=malloc(sizeof(node));
    temp->item=x;
    temp->left=temp->right=NULL;
    
    node* curr=head,*prev=NULL;
    while(curr!=NULL)
    {
      prev=curr;
      
      if(x<curr->item)
      curr=curr->left;
      else
      curr=curr->right;
    }
    
    if(x<prev->item)
    prev->left=temp;
    else
    prev->right=temp;
  }
}

void inorder(node* head)
{
  if(head==NULL)
  return;
  
  inorder(head->left);
  printf("%d ",head->item);
  inorder(head->right);
}

void minmax(node* head)
{
  node* temp=head;
  while(temp->left!=NULL)
  temp=temp->left;
  
  printf("\nMinimum value in the list is %d\n",temp->item);
  temp=head;
  
  while(temp->right!=NULL)
  temp=temp->right;
  
  printf("Maximum value in the list is %d\n",temp->item);
}

void search(int key, node* head)
{
  if(head==NULL)
  { 
    printf("Key not found!\n");
    return;
  }
  
  if(head->item==key)
  {
    printf("Key found!\n");
    return;
  }
  
  if(key<head->item)
  search(key, head->left);
  else
  search(key, head->right);
}

node* delete(node* head, int key)
{
  node*prev=NULL, *curr=head;
  while(curr->item!=key)
  {
    prev=curr;
    curr=(key<curr->item)?curr->left:curr->right;
  }
 
  node* link_d;
  
  if(curr->left==NULL)
  link_d=curr->right;
  else if(curr->right==NULL)
  link_d=curr->left;
  else
  {
    node* sux=curr->right;
    while(sux->left!=NULL)
    sux=sux->left;
    
    sux->left=curr->left;
    link_d=curr->right;
  }
  
  if(prev==NULL)
  {
    free(curr);
    return link_d;
  }
  
  if(curr==prev->left)
  prev->left=link_d;
  else
  prev->right=link_d;
  
  free(curr);
  return head;
}
  
  
