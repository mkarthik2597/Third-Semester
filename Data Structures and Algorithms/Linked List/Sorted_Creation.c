#include<stdio.h>
#include<stdlib.h>
struct ll
{
    int item;
    struct ll* next;
};
typedef struct ll node;
void print(node *);
node*find(node*,int);
void insert(node*,int);
main()
{
    node *head,*ref;
    head=(node *)malloc(sizeof(node));
    printf("Enter a number:\n");
    scanf("%d",&head->item);
    if(head->item==-999)
    head->next=NULL;
    else
    {
        head->next=(node*)malloc(sizeof(node));
        head->next->item=-999;
        head->next->next=NULL;
    }
    printf("Enter new item(-999 to exit):\n");
    int no;
    rept:scanf("%d",&no);
    if(no==-999)
    goto lbl;
    if(no<=head->item)
    {
        node*p=head;
        head=(node*)malloc(sizeof(node));
        head->next=p;
        head->item=no;
    }
    else
    ref=find(head,no);
    insert(ref,no);
    goto rept;
    lbl:print(head);
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


