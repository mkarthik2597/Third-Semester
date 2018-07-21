#include<stdio.h>
#include<stdlib.h>
struct ll
{
  int item;
  struct ll*next;
};
typedef struct ll node;
void create(node*);
void display(node*);

main()
{
  printf("Enter a list of numbers(-999 to terminate):");
  int x;
  node*head;
  scanf("%d",&x);
  if(x!=-999)
  {
    head=malloc(sizeof(node));
    head->item=x;
    scanf("%d",&x);
    if(x!=-999)
    {
      head->next=malloc(sizeof(node));
      head->next->item=x;
      create(head);
    }
    else
    head->next=NULL;
  }
  else
  head=NULL;
  print(head);
}

void create(node*head)
{
  node*temp=head->next;
  node*ref=temp;
  int x;
  while(scanf("%d",&x),x!=-999)
  {
    ref->next=malloc(sizeof(node));
    ref->next->item=x;
    ref=ref->next;
    temp->next=(unsigned int)head^(unsigned int)ref;
    head=temp;
    temp=ref;
  }
  temp->next=head;
}

void print(node*head)
{
  printf("%d ",head->item);
  node*ref=head;
  node*temp;
  head=head->next;
  while(head->next!=ref)
  {
    printf("%d ",head->item);
    temp=head;
    head=(unsigned int)(head->next)^(unsigned int)ref;
    ref=temp;
  }
  printf("%d\n",head->item);
}
