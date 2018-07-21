
struct ll
{
  int item;
  struct ll* next;
};
typedef struct ll node;

void create(node*);
void print(node*);
void delete(node*, int);
int count(node*);

//You need to create one node in the main function before using create
void create(node* head)
{
  int x;
  while(scanf("%d",&x),x!=-999)
  {
    head->next=malloc(sizeof(node)); 
    head->next->item=x;
    head=head->next;
  }
  
  head->next=NULL;
}

void print(node* head)
{
  while(head!=NULL)
  {
    printf("%d ",head->item);
    head=head->next;
  }
}

void delete(node* head, int x)
{
  while(head->next->item!=x)
  head=head->next;

  node* temp=head->next->next;
  free(head->next);
  head->next=temp;
}
  
int count(node* head)
{
  if(head==NULL)
  return 0;
  int x=1;
  while(head->next!=NULL)
  {
    head=head->next;
    x++;
  }
 
  return x;
}

void insert(node*head,int x, int pos)
{
  node* temp;
  
  if(count(head)<pos)
  {
    while(head->next!=NULL)
    head=head->next;
    
    head->next=malloc(sizeof(node));
    head->next->item=x;
    head->next->next=NULL;
  }

  else
  {
    int cnt=1;
    while(cnt<pos-1)
    {
      head=head->next;
      cnt++;
    }
   
    temp=head->next;
    head->next=malloc(sizeof(node));
    head->next->item=x;
    head->next->next=temp;
  }

}

//Subscript c stands for circular linked lists
//You needto take special care of insertion and deletion at the first element.You need to alter the next pointer in the last node as well!

void create_c(node* head)
{
  node* ref=head;
  int x;
  while(scanf("%d",&x),x!=-999)
  {
    head->next=malloc(sizeof(node));
    head->next->item=x;
    head=head->next;
  }

  head->next=ref;
}

void print_c(node* head)
{
  node* ref=head;
  do
  {
    printf("%d ",head->item);
    head=head->next;
  }
  while(head!=ref);
}

int count_c(node* head)
{
  node*ref=head;

  if(head==NULL)
  return 0;
  int x=1;
  while(head->next!=ref)
  {
    head=head->next;
    x++;
  }

  return x;
}

void insert_c (node*head,int x, int pos)
{
  node* temp;
  node*ref=head;
    
 if(pos==1)
 {
   node*temp=head;
   head=malloc(sizeof(node));
   head->item=x;
   head->next=temp;

   node*ref=head;
   head=head->next;
   while(head->next!=temp)
   head=head->next;
   head->next=ref;
 }
                   

 else if(count_c(head)<pos)
  {
    while(head->next!=ref)
    head=head->next;

    head->next=malloc(sizeof(node));
    head->next->item=x;
    head->next->next=ref;
  }

  else
  {
    int cnt=1;
    while(cnt<pos-1)
    {
      head=head->next;
      cnt++;
    }

    temp=head->next;
    head->next=malloc(sizeof(node));
    head->next->item=x;
    head->next->next=temp;
  }
}

//Include this code for deletion of the first node in a circular linked list in the main function

/*        if(head->item==x)
          {
            if(count_c(head)!=1)
            { node*temp=head->next;
              node*temp2=head;
              free(head);
              head=temp;

              node*ref=head;
              while(ref->next!=temp2)
              ref=ref->next;
              ref->next=head;

              print_c(head);
           }
          else
           {
            free(head);
            head=NULL;
           }
        }
*/

//For a doubly linked list, define a new node* called prev

void create_d(node* head)
{
  int x;
  while(scanf("%d",&x),x!=-999)
  {
    head->next=malloc(sizeof(node)); 
    head->next->item=x;
    head->next->prev=head;
    head=head->next;
  }
  
  head->next=NULL;
}



