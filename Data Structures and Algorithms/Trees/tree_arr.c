#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct
{
 int*stack;
 int k;
}Stack;

void create_tree(int*,int);
void inorder(int*, int);

int main()
{
  printf("Enter the number of nodes in your tree:");
  int n;
  scanf("%d",&n);
  
  int size=pow(2,n)-1; 
  int* tree=malloc(size*sizeof(int));
  
  int i;
  for(i=0;i<size;i++)
  tree[i]=0;
  
  create_tree(tree,n);
  inorder(tree,0);
}  

void create_tree(int* tree, int n)
{
  int k,node,i;
  char pos; 
  printf("Enter the root of the tree:");
  scanf("%d",&tree[0]);

  for(i=1;i<n;i++)
  {
    printf("Enter a node:");
    scanf("%d",&node);
    
    k=0;
    while(1)
    {
      printf("L or R of %d?",tree[k]);
      getchar();
      scanf("%c",&pos); 
      if(pos=='L')
      {
        if(tree[2*k+1]==0)
        {
          tree[2*k+1]=node; 
          break;
        }
        else
        k=2*k+1;
      }

      else
      {
       if(tree[2*k+2]==0)
       {
         tree[2*k+2]=node;
         break;
       }
       else
       k=2*k+2;
      }
    }
  }
}  
    
void inorder(int* tree, int i)
{
  
  if(tree[i]==0)
  return;
  
  inorder(tree, 2*i+1);
  printf("%d",tree[i]);
  inorder(tree, 2*i+2);
}  
    



    
     
  
