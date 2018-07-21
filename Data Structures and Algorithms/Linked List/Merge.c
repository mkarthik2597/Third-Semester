#include<stdio.h>
#include<stdlib.h>
#include"list.h"

void insert_(node*, int);
main()
{
  printf("Enter the first sorted list(-999 to exit):");
  node*head1;
  int x;
  scanf("%d",&x);
  if(x==-999)
  head1=NULL;
  else
  {
    head1=malloc(sizeof(node));
    head1->item=x;
    create(head1);
  }

  printf("Enter the second sorted list(-999 to exit):");
  node*head2;
  scanf("%d",&x);
  if(x==-999)
  head2=NULL;
  else
  {
    head2=malloc(sizeof(node));
    head2->item=x;
    create(head2);
  }
  
 node*head_1,*head_2,*temp;
 head_2=head2;
 
 if(head_2->item<head1->item)
 {
   temp=head1;
   head1=malloc(sizeof(node));
   head1->item=head_2->item;
   head1->next=temp;
   head_2=head_2->next;
 }
 
 head_1=head1;
 
 while(head_1->next && head_2)
 {
   if(head_2->item<=head_1->next->item) 
   { 
     insert_(head_1,head_2->item);
     head_2=head_2->next;
     head_1=head_1->next;
     
   }
   else
   head_1=head_1->next;
 }
 
 while(head_2)
 {
   insert_(head_1,head_2->item);
   head_1=head_1->next;
   head_2=head_2->next;
 }  
 
 print(head1);

}

void insert_(node*head,int x)
{
  node*temp=head->next;
  head->next=malloc(sizeof(node));
  head->next->item=x;
  head->next->next=temp;
}  

