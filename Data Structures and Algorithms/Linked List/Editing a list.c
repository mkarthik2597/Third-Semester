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
node*find(node*,int);
void edit(node*);
main()
{
    node *head,*ref;
    head=(node *)malloc(sizeof(node));
    printf("Enter a number:(-999 to exit)\n");
    scanf("%d",&head->item);
    if(head->item==-999)
    head->next=NULL;
    else
    create(head);
    printf("Enter the item key which has to be edited:");
    int key;
    scanf("%d",&key);
    if(head->item==key)
    ref=head;
    else
    ref=find(head,key);
    edit(ref->next);
    print(head);
}
void create(node*head)
{
    int x;
    head->next=malloc(sizeof(node));
    scanf("%d",&head->next->item);
    if(head->next->item==-999)
    {
        head->next->next=NULL;
        return;
    }
    else
    create(head->next);
}
void print(node *head)
{
    if(head->next!=NULL)
    {
        printf("%d\n",head->item);
        print(head->next);
    }
    return;
}
node*find(node*head,int key)
{
    if(head->next->item==key)
    return head;
    else if(head->next->next==NULL)
    return NULL;
    else
    find(head->next,key);
}
void edit(node*ref)
{
    int x;
    printf("Enter new number:");
    scanf("%d",&x);
    ref->item=x;
}
