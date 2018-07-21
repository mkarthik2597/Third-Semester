#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct list
{
  int item;
  struct list* left;
  struct list* right;
};
typedef struct list node;

int operand(char);
void postorder(node*);
void preorder(node*);
void inorder(node*);

main()
{
  printf("Enter a postfix expression:");
  char postfix[30];
  scanf("%s",postfix);
  int len=strlen(postfix);
  node** stack=malloc(len*sizeof(node*));
 
  int i,k=-1;
  node*temp;
  for(i=0;i<len;i++)
  {
    if(operand(postfix[i]))
    {
      stack[++k]=malloc(sizeof(node));
      stack[k]->item=postfix[i];
      stack[k]->left=stack[k]->right=NULL;
    }
    
    else
    {
      temp=malloc(sizeof(node));
      temp->item=postfix[i];
      temp->left=stack[k-1];
      temp->right=stack[k];
      stack[--k]=temp;
    }
  }
  printf("Postfix expression:");
  postorder(stack[k]);
  printf("\nPrefix expression:");
  preorder(stack[k]);
  printf("\nInfix expression:\n");
  inorder(stack[k]);
}

int operand(char ch)
{
  switch(ch)
  {
    case '+':
    case '-':
    case '*':
    case '/':
    
    return 0;
  }
  return 1;
} 
 
void postorder(node* head)
{
  if(head->left!=NULL)
  postorder(head->left);
  
  if(head->right!=NULL)
  postorder(head->right);
  
  printf("%c",head->item);
} 

void preorder(node* head)
{
  printf("%c",head->item);
  
  if(head->left!=NULL)
  preorder(head->left);
  
  if(head->right!=NULL)
  preorder(head->right);
  
} 

void inorder(node* head)
{
  if(head->left!=NULL)
  inorder(head->left);
  
  printf("(%c)",head->item);
  
  if(head->right!=NULL)
  inorder(head->right);
  
} 

