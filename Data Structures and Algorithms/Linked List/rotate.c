#include<stdio.h>
#include<stdlib.h>
#include"list.h"
main()
{
  printf("Enter a series of numbers(-999 to terminate):");
  node*head;
  int x;
  scanf("%d",&x);
  if(x!=-999)
  {
    head=malloc(sizeof(node));
    head->item=x;
    create_c(head);
  }
  else
  head=NULL;
  print_c(head);

  printf("Enter the degree through which you want to rotate the linked list:");
  int deg;
  scanf("%d",&deg);
  node*ref=head;
  for(int i=0;i<deg;i++)
  {
    ref=ref->next;
  }
  print_c(ref);
}
 

   
