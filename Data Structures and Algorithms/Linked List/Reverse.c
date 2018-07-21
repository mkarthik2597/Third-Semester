#include<stdio.h>
#include<stdlib.h>
#include<list.h>
node* reverse(node*);
main()
{
    node*head=malloc(sizeof(node)),*ref;
    printf("Enter a number(-999 to exit):");
    scanf("%d",&head->item);
    if(head->item==-999)
    head->next=NULL;
    else
    create(head);
    ref=reverse(head);
    head->next=malloc(sizeof(node));
    head->next->item=-999;
    head->next->next=NULL;
    head=ref;
    print(head);
}
node*reverse(node*head)
{
    static node*ref;
    if(head->next->next!=NULL)
    {
        reverse(head->next);
        head->next->next=head;
    }
    else
    {
        ref=head;
        free(head->next);
    }
    return ref;
}
