#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct list
{
  int item;
  int weight;
  struct list*next;
};
typedef struct list node;

typedef struct
{
  node** head;
  int n;
}
graph;

typedef struct
{
  int vertex;
  int key;
}
heapnode;

typedef struct
{
  heapnode* tree;
  int n;
  int* position;
  int* parent;
}
heap;

void create_G(graph*);
void create_list(node**);
void print_G(graph*);
void print_list(node*); 
void create_heap(heap*);
void decrease_key(heap*,int);
void Prims(graph*,heap*);
void adjustheap(heap*);
int CheckHeap(heap*,int);


int main()
{
  printf("Enter the number of vertices in your graph:");
  int n;
  scanf("%d",&n);
  graph G;
  G.head=malloc(n*sizeof(node*));
  G.n=n;
  
  create_G(&G);
  
  int i;
  print_G(&G);
  
  heap H1;
  H1.n=n;
  create_heap(&H1);
  
  printf("Enter a vertex of your choice for the MST root:");
  int root;
  scanf("%d",&root);
  H1.tree[root].key=0;
  decrease_key(&H1,root);

  Prims(&G,&H1);
  
  for(i=0;i<n;i++)
  {
    if(H1.parent[i]!=i)
    printf("(%d,%d)\n",i,H1.parent[i]);
  }
}

void create_G(graph* g_ptr)
{
  int i,x;
  int weight;
  for(i=0;i<g_ptr->n;i++)
  {
    printf("Enter elements adjacent to vertex %d and weight of the edge(-999 to exit):",i);
    scanf("%d",&x);
    if(x!=-999)
    {
      scanf("%d",&weight);
      g_ptr->head[i]=malloc(sizeof(node));
      g_ptr->head[i]->item=x;
      g_ptr->head[i]->weight=weight;
      g_ptr->head[i]->next=NULL;
      create_list(g_ptr->head+i);
    }
    else
    g_ptr->head[i]=NULL;
  }
}

void create_list(node** head_ptr)
{
  int x,weight; 
  node*head=*head_ptr;
  node*temp;
  while(scanf("%d",&x),x!=-999)
  {
    scanf("%d",&weight);
    temp=head;
    head=malloc(sizeof(node));
    head->item=x;
    head->weight=weight;
    head->next=temp;
  }
  *head_ptr=head;
}

void print_G(graph* g_ptr)
{
  int i;
  for(i=0;i<g_ptr->n;i++)
  {
    printf("%d->",i);
    print_list(g_ptr->head[i]);
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

void create_heap(heap* h_ptr)
{
  int n=h_ptr->n;
  h_ptr->tree=malloc(n*sizeof(heapnode));
  h_ptr->position=malloc(n*sizeof(int));
  h_ptr->parent=malloc(n*sizeof(int));
  
  int i;
  for(i=0;i<n;i++)
  {
    h_ptr->tree[i].vertex=i;
    h_ptr->tree[i].key=INT_MAX;
    h_ptr->position[i]=i;
    h_ptr->parent[i]=i;
  }
}

void decrease_key(heap* h_ptr, int source)
{
  int pos=h_ptr->position[source];       /*Think of position[] as a function. Tree[position] will give you the heapnode*/
  heapnode tempnode=h_ptr->tree[pos];
  int child=pos;
  int parent=(child-1)/2;
  
  while(child>0 && h_ptr->tree[parent].key>tempnode.key)
  {
     h_ptr->position[h_ptr->tree[parent].vertex]=child;
     h_ptr->tree[child]=h_ptr->tree[parent];
     child=parent;
     parent=(child-1)/2;
  }
  
  h_ptr->position[source]=child;
  h_ptr->tree[child]=tempnode;
}

void adjustheap(heap* h_ptr)
{
  int parent=0, child=2*parent+1;
  heapnode tempnode=h_ptr->tree[0];
  
  while(child<h_ptr->n)
  {
    if(child+1<h_ptr->n)
    {
      if(h_ptr->tree[child+1].key<h_ptr->tree[child].key)
      child++;
    }
    
    if(h_ptr->tree[child].key<tempnode.key)
    {
      h_ptr->position[h_ptr->tree[child].vertex]=parent;
      h_ptr->tree[parent]=h_ptr->tree[child];
      parent=child;
      child=2*parent+1;
    }
    else
    break;
  }
  
   h_ptr->position[tempnode.vertex]=parent;
   h_ptr->tree[parent]=tempnode;
} 

void Prims(graph* g_ptr, heap* h_ptr)
{
  heapnode min_node;
  int temp_pos;
  while(h_ptr->n>0)
  {
    min_node=h_ptr->tree[0];

    h_ptr->tree[0]=h_ptr->tree[h_ptr->n-1];
    h_ptr->position[h_ptr->tree[h_ptr->n-1].vertex]=0;
    h_ptr->position[min_node.vertex]=h_ptr->n-1;
    h_ptr->n--;
    adjustheap(h_ptr);
    
    node*temp= g_ptr->head[min_node.vertex];
    while(temp!=NULL)
    {
      temp_pos=h_ptr->position[temp->item];
      if(CheckHeap(h_ptr,temp->item)&&h_ptr->tree[temp_pos].key>temp->weight)
      {
        h_ptr->tree[temp_pos].key=temp->weight;
        decrease_key(h_ptr,temp->item);
        h_ptr->parent[temp->item]=min_node.vertex;
      }
      temp=temp->next;
    }
  }
}

int CheckHeap(heap* h_ptr, int item)
{
  if(h_ptr->position[item]>=h_ptr->n)
  return 0;
  else
  return 1;
}

    
