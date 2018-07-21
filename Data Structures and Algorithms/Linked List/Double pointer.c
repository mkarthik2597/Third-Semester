#include<stdio.h>
#include<stdlib.h>
#include "list.h"

main()
{
  printf("Enter a series of elements(-999 to exit):");
  int x;
  scanf("%d",&x);
  node* head;
  if(x==-999)
  head=NULL;
  else
  {
    head=malloc(sizeof(node));  
    head->item=x;
    create(head);
  }
  
  print(head);
  
  //Code to find out middle element
  node *singl,*doubl;
  singl=doubl=head;
  
  while(doubl->next!=NULL && doubl->next->next!=NULL)
  {
    singl=singl->next;
    doubl=doubl->next->next;
  }
  
  if(doubl->next==NULL)
  printf("\nMiddle element is %d",singl->item);
  else
  printf("\nMiddle element is %d",singl->next->item);

  //Code to find kth element from the end 

  printf("Enter the position of the element from the end:");
  int k;
  scanf("%d",&k);
  int cnt=1;
  singl=doubl=head;
  
  while(cnt<k)
  {
    doubl=doubl->next;
    cnt++;
  }
  
  while(doubl->next!=NULL)
  {
    singl=singl->next;
    doubl=doubl->next;
  }

  printf("\n%d",singl->item);
}



