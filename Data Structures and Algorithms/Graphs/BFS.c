#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct list
{
  int item;
  struct list*next;
};
typedef struct list node;

typedef struct
{
  int *arr;
  int f;
  int r;
  int count;
}Q;


typedef struct
{
  int *parent;
  int *distance;
  node** G;
  int n;
}
Graph_Att;

void SetValues(Graph_Att *,int);
void BFS(Graph_Att* g1_ptr, int source);
void enq(Q*,int);
int deq(Q*);
void create_G(node**,int);  
void create_list(node**);
void print_G(node**,int);
void print_list(node*);


int main()
{
  printf("Enter the number of vertices in your graph:");
  int n;
  scanf("%d",&n);
  node* head[n];
  
  create_G(head,n);
  print_G(head,n);

  Graph_Att G1;
  G1.n=n;
  G1.G=head;
  SetValues(&G1,n);
  
  printf("Choose a vertex to perform BFS:");
  int source;
  scanf("%d",&source);

  BFS(&G1,source);
  
  int i;
  for(i=0;i<G1.n;i++)
  {
   printf("%d is at a distance of %d from %d.",i+1,G1.distance[i],source);
   printf("%d's parent in the BF tree is %d\n",i+1,G1.parent[i]);
  }
}



void SetValues(Graph_Att *G1_ptr,int n)
{
  G1_ptr->parent=malloc(n*sizeof(int));
  G1_ptr->distance=malloc(n*sizeof(int));

  int i; 
  for(i=0;i<G1_ptr->n;i++)
  {
    G1_ptr->parent[i]=0;
    G1_ptr->distance[i]=INT_MAX;
  }
}

void BFS(Graph_Att* g1_ptr, int source)
{
  Q q1;
  q1.f=0;
  q1.r=-1;
  q1.arr=malloc(g1_ptr->n*sizeof(int));
  q1.count=g1_ptr->n;

 
  int tr_vx=0;
  int u;
  node* head_temp;

  enq(&q1,source); 
  tr_vx++;
  g1_ptr->distance[source-1]=0;

  while(tr_vx<g1_ptr->n)
  {
    u=deq(&q1);
    head_temp=g1_ptr->G[u-1];
    while(head_temp!=NULL)
    {
      if(g1_ptr->distance[head_temp->item-1]==INT_MAX)
      {
        g1_ptr->distance[head_temp->item-1]=g1_ptr->distance[u-1]+1;
        g1_ptr->parent[head_temp->item-1]=u;
        enq(&q1,head_temp->item);
        tr_vx++;
      }
      head_temp=head_temp->next;
    }
  }
}

void create_G(node**head, int n)
{
  int i,x;
  for(i=0;i<n;i++)
  {
    printf("Enter nodes adjacent to vertex %d(-999 to exit):",i+1);
    head[i]=NULL;
    create_list(head+i);
  }
}

void create_list(node**head_ptr)
{
  int x; 
  node*head=*head_ptr;
  node*temp;
  
  while(scanf("%d",&x),x!=-999)
  {
    temp=head;
    head=malloc(sizeof(node));
    head->item=x;
    head->next=temp;
  }
  *head_ptr=head;
}

void print_G(node**head, int n)
{
  int i;
  for(i=0;i<n;i++)
  {
    printf("%d->",i+1);
    print_list(head[i]);
    printf("\n");
  }
}

void print_list(node*head)
{
  while(head!=NULL)
  {
    printf("%d ",head->item);
    head=head->next;
  }
}

void enq(Q* q1_ptr, int item)
{
  q1_ptr->r=(q1_ptr->r+1)%q1_ptr->count;
  q1_ptr->arr[q1_ptr->r]=item;
}

int deq(Q* q1_ptr)
{
  int x=q1_ptr->arr[q1_ptr->f];
  q1_ptr->f=(q1_ptr->f+1)%q1_ptr->count;
  return x;
}



