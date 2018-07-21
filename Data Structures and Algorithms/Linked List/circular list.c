#include<stdio.h>
#include<stdlib.h>
#include<list.h>
node*create_c(node*);
void print_c(node*,node*);
main()
{
    node*head=malloc(sizeof(node)),*ref;
    printf("Enter a number(-999 to exit:)");
    scanf("%d",&head->item);
    if(head->item==-999)
    head->next=NULL;
    else
    {
        ref=create_c(head);
        ref->next=head;
    }
    print_c(head,head);
}
node* create_c(node*head)
{
    head->next=malloc(sizeof(node));
    scanf("%d",&head->next->item);
    if(head->next->item!=-999)
    create_c(head->next);
    else
    {
        free(head->next);
        return head;
    }
}
void print_c(node*ref,node*head)
{
    if(head->next!=ref)
    {
        printf("%d\n",head->item);
        print_c(ref,head->next);
    }
    else
    {
        printf("%d",head->item);
        return;
    }
}
