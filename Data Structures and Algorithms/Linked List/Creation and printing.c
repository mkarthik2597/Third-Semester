#include<stdio.h>
#include<stdlib.h>
struct ll
{
    int item;
    struct ll* next;
};
typedef struct ll node;
void create(node *);
void print(node *);
main()
{
    const node *head;
    head=(node *)malloc(sizeof(node));
    printf("Enter a number(-999 to exit):");
    scanf("%d",&head->item);
    create(head);
    print(head);
}
void create(node*head)
{
    int x;
    head->next=malloc(sizeof(node));
    scanf("%d",&head->next->item);  //Note that the nodes have dynamic storage duration.They are present in the heap till you
                                    //free them.
    if(head->next->item==-999)
    {
        head->next->next=NULL;   //Note that if you want to alter a next pointer of a node, you need to do it through the previous
                                 //next pointer only.
        return;
    }
    else
    create(head->next);
}
void print(node *head)
{
   /*while(head->next!=NULL)
   {
       printf("%d\n",head->item);
       head=head->next;
   }*/
   if(head->next!=NULL)
    {
        printf("%d\n",head->item);
        print(head->next);
    }
    return;
}
