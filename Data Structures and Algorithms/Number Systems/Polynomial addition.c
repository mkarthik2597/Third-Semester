#include<stdio.h>
#include<stdlib.h>

struct ll
{
  int item;
  struct ll* next;
};
typedef struct ll node;

void create(node*, int);
void print(node*);
void add(node*, node*,int,int);

main()
{
  

  retry:
  printf("Enter the degree of the first polynomial:");
  int deg1; 
  scanf("%d",&deg1);
  if(deg1<0)
  {
    printf("\nRetry!");
    goto retry;
  }
  
  node*p1=malloc(sizeof(node));
  printf("\nEnter your co-efficients starting with coefficient of term with degree %d(%d in total):",deg1,deg1+1);
 
  scanf("%d",&p1->item);
  if(deg1==0)
  p1->next=NULL;
  else 
  create(p1,deg1);
  
  retry2:
  printf("Enter the degree of the second polynomial:");
  int deg2; 
  scanf("%d",&deg2);
  
  if(deg2<0)
  {
    printf("\nRetry!");
    goto retry2;
  }
  node*p2=malloc(sizeof(node));
  printf("\nEnter your co-efficients starting with coefficient of term with degree%d(%d in total):",deg2,deg2+1);
  scanf("%d",&p2->item);
  if(deg2==0)
  p2->next=NULL;
  else create(p2,deg2);

  add(p1,p2,deg1,deg2);

}

void create(node*head, int deg)
{
  while(deg>0)
  {
    head->next=malloc(sizeof(node));
    scanf("%d",&head->next->item);
    deg--;
    head=head->next;
  }
  
  head->next=NULL;
}

void print(node* head)
{
  while(head!=NULL)
  {
    printf("%d ",head->item);
    head=head->next;
  }
}

void add(node*p1, node*p2, int deg1, int deg2)
{
  int save1,save2;
  save1=deg1; 
  save2=deg2;

  node* p4=malloc(sizeof(node));
  node* p3=p4;
 
  if(deg1>deg2)
  {
    p4->item=p1->item;
    p1=p1->next; 
    deg1--;
  
    while(deg1>deg2)
    {
      p4->next=malloc(sizeof(node));
      p4->next->item=p1->item;
      p1=p1->next;
      p4=p4->next;
      deg1--;
    }
   
  }
   
 else if(deg2>deg1)
  {
    p4->item=p2->item;
    p2=p2->next;
    deg2--; 
    
    while(deg2>deg1)
    {
      p4->next=malloc(sizeof(node));
      p4->next->item=p2->item;
      p2=p2->next;
      p4=p4->next;
      deg2--; 
    }
    
  }

 else
 {
   p4->item=p1->item+p2->item;
   p1=p1->next;
   p2=p2->next;
 }  

 while(p1)
 {
   p4->next=malloc(sizeof(node));
   p4->next->item=p1->item+p2->item;
   p1=p1->next;
   p2=p2->next;
   p4=p4->next;
 }

 p4->next=NULL;
 printf("\nThe polynomial sum is of degree %d and its coefficients are:\n",(save1>=save2?save1:save2));
 print(p3);
 printf("\n");

}


  
  
  
    
