#include<stdio.h>
#include<stdlib.h>

struct list
{
  int item;
  struct list*next;
};
typedef struct list node;

typedef struct
{
  int* parent;
  int* TreeSize;
  node** head;
  int n;
}
graph;

typedef struct
{
  int v1;
  int v2;
  int weight;
  int selected;
}
edge;

void create_G(graph*);
void create_list(node**);
void create_edge_list(edge**,int);
void print_G(graph*);
void print_list(node*); 
void MemAllocate(graph*);
void Kruskal(graph*, edge**, int);
void Union(graph*,int,int);
int find(graph*,int);


int main()
{
  printf("Enter the number of vertices in your graph:");
  int n;
  scanf("%d",&n);
  graph G;
  G.head=malloc(n*sizeof(node*));
  G.n=n;
  
  create_G(&G);
  print_G(&G);
  
  int E;
  printf("Enter the number of edges in your graph:");
  scanf("%d",&E);
  
  edge* edgA[E];
  create_edge_list(edgA,E);
  MemAllocate(&G);
  Kruskal(&G,edgA,E);
  
  int i;
  for(i=0;i<E;i++)
  if(edgA[i]->selected==1)
  printf("(%d,%d)\n",edgA[i]->v1,edgA[i]->v2);
}

void create_G(graph* g_ptr)
{
  int i,x;
  for(i=0;i<g_ptr->n;i++)
  {
    printf("Enter elements adjacent to vertex %d(-999 to exit):",i+1);
    scanf("%d",&x);
    if(x!=-999)
    {
      g_ptr->head[i]=malloc(sizeof(node));
      g_ptr->head[i]->item=x;
      g_ptr->head[i]->next=NULL;
      create_list(g_ptr->head+i);
    }
    else
    g_ptr->head[i]=NULL;
  }
}

void create_list(node** head_ptr)
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

void print_G(graph* g_ptr)
{
  int i;
  for(i=0;i<g_ptr->n;i++)
  {
    printf("%d->",i+1);
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

void create_edge_list(edge** edgA, int E)
{ 
  int i,j;
  int w;
  for(i=0;i<E;i++)
  {
    printf("Enter the weight of the new edge:");
    scanf("%d",&w);
    
    j=i-1;
    while(j>=0 && edgA[j]->weight > w)
    {
      edgA[j+1]=edgA[j];
      j--;
    }
    edgA[j+1]=malloc(sizeof(edge));
    edgA[j+1]->weight=w;
    edgA[j+1]->selected=0;
    printf("Enter the 2 vertices\n");
    scanf("%d%d",&edgA[j+1]->v1, &edgA[j+1]->v2);
  }
}

void MemAllocate(graph* g_ptr)
{
  int i;
  int n=g_ptr->n;
  
  g_ptr->parent=malloc(n*sizeof(int));
  g_ptr->TreeSize=malloc(n*sizeof(int));
  
  for(i=0;i<n;i++)
  {
    g_ptr->parent[i]=i+1;
    g_ptr->TreeSize[i]=1;
  }
}

void Kruskal(graph* g_ptr,edge** edgA, int E)
{
   int i,v1_parent,v2_parent;
   for(i=0;i<g_ptr->n-1;i++)
   {
      v1_parent=find(g_ptr,edgA[i]->v1);
      v2_parent=find(g_ptr,edgA[i]->v2);
      
      if(v1_parent!=v2_parent)
      {
        edgA[i]->selected=1;
        Union(g_ptr,v1_parent,v2_parent);
      }
   }
}      
      
void Union(graph* g_ptr, int v1, int v2)
{
  if(g_ptr->TreeSize[v1-1] > g_ptr->TreeSize[v2-1])
  {
    g_ptr->parent[v2-1]=v1;
    g_ptr->TreeSize[v1-1]+=g_ptr->TreeSize[v2-1];
  }
  else
  {
    g_ptr->parent[v1-1]=v2;
    g_ptr->TreeSize[v2-1]+=g_ptr->TreeSize[v1-1];
  }
}


int find(graph* g_ptr, int v)
{
  if(g_ptr->parent[v-1]==v)
  return v;
  
  return find(g_ptr,g_ptr->parent[v-1]);
}

      
