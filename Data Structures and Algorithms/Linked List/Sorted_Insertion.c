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
void insert(node*,int);
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
    printf("Enter new item\n");
    int no;
    scanf("%d",&no);
    if(no<=head->item)
    {
        node*p=head;
        head=(node*)malloc(sizeof(node));
        head->next=p;
        head->item=no;
    }
    else
    ref=find(head,no);
    if(ref==NULL)
    {

    }
    insert(ref,no);
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
    if(head->next->item>=key)
    return head;
    else if(head->next->next==NULL)
    return head;
    else
    find(head->next,key);
}
void insert(node*ref,int no)
{
    node*p=ref->next;
    ref->next=(node*)malloc(sizeof(node));
    ref->next->next=p;
    ref->next->item=no;
}
