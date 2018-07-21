/*Merge sort using linked lists*/
#include<stdio.h>
#include<stdlib.h>
struct ll
{
  int item;
  struct ll* next;
};

typedef struct ll node;
node* FindMiddle(node*,node*);
void divide(node*,node*);
void conquer(node*,node*,node*);
void create(node*, node**);
void print(node*);

int main()
{
  node*head;
  printf("Enter a number(-999 to terminate):");
  int x;
  scanf("%d",&x);
  node*end=NULL;
  if(x!=-999)
  { 
    head=malloc(sizeof(node));
    head->item=x;
    create(head,&end);
  }
  else
  head=NULL;

  printf("\nThe unsorted list is: ");
  print(head);
  
  divide(head,end);

  printf("\nSorted list is:");
  print(head);
  
}

void create(node* head,node** end)
{
  int x;
  while(scanf("%d",&x),x!=-999)
  {
    head->next=malloc(sizeof(node)); 
    head->next->item=x;
    head=head->next;
  }
  
  head->next=NULL;
  *end=head;
}

void print(node* head)
{
  while(head!=NULL)
  {
    printf("%d ",head->item);
    head=head->next;
  }
}

void divide(node*f, node*l)
{
  if(f!=l)
 {
   node*m=FindMiddle(f,l);
   divide(f,m);
   divide(m->next,l);
   conquer(f,m,l);
 }

}

void conquer(node*f, node*l, node*m)
{
  node*p=f,*q=m->next;
  node*temp;
  while(p!=m->next&&q!=NULL)
  {
    if(p->item>q->item)
    {
       temp=p->next; 
       p=malloc(sizeof(node));
       p->item=q->item;
       p->next=temp;

       temp=q->next;
       free(q);
       q=temp;
    }
     
    p=p->next;
  }
}

node* FindMiddle(node* f,node* l)
{
   node*slow,*fast;
   slow=f;
   fast=f;
   /*Experiencing very strange behaiour in this function. If i/p is 8 7 6 5 4 -999, f->item=8 in the first iteration and 5 in all subsequent    iterations. fast->item also takes up some unknown values. What's happening?*/
   while((fast->next!=l) && (fast->next->next!=l))
   {
     printf("%d\n",fast->item);
     getchar();
     fast=fast->next->next;
     slow=slow->next;
   }
  
   return slow;
}
  
