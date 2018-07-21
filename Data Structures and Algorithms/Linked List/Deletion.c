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
void delete(node*,int);
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
    int key;
    lbl:printf("Enter number to be deleted:");
    scanf("%d",&key);
    if(key==head->item)
    {
        node*p=head->next;
        free(head);
        head=p;
    }
    else
    ref=find(head,key);
    if(ref==NULL)
    {
        printf("Key not found!");goto lbl;
    }
    delete(ref,key);
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
void delete(node*ref,int key)
{
    node*p=ref->next->next;
    free(ref->next);
    ref->next=p;
}
