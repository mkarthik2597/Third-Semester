#include<stdio.h>
#include<stdlib.h>

#define WHITE 0
#define BLACK 1

struct list
{
  int item;
  int color;
  struct list*next;
};
typedef struct list node;

typedef struct
{
  int* visited;
  int* spanned;
  int* parent;
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
void SetValues(graph*);
void MemAllocate(graph*);
int DetectCycle(graph*,int);
void Kruskal(graph*, edge**, int);
void mark(node*, int);

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
    head[i]=NULL;
    create_list(head+i);
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
    head->color=WHITE;
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
    printf("Enter the 2 vertices\n");
    scanf("%d%d",&edgA[j+1]->v1, &edgA[j+1]->v2);
  }
}

void MemAllocate(graph* g_ptr)
{
  int i;
  int n=g_ptr->n;
  
  g_ptr->spanned=malloc(n*sizeof(int));
  g_ptr->visited=malloc(n*sizeof(int));
  g_ptr->parent=malloc(n*sizeof(int));
  
  for(i=0;i<n;i++)
  g_ptr->spanned[i]=0;
}

void SetValues(graph* g_ptr)
{
  int i; 
  int n=g_ptr->n;
 
  for(i=0;i<n;i++)
  g_ptr->visited[i]=0;
}

void mark(node* head, int v1)
{
  while(head->item!=v1)
  head=head->next;
  
  head->color=BLACK;
}
  
void Kruskal(graph* g_ptr,edge** edgA, int E)
{
  int i;
  int result;
  int v1,v2;
  for(i=0;i<E;i++)
  {
    v1=edgA[i]->v1;
    v2=edgA[i]->v2;
    
    if(g_ptr->spanned[v1-1]==0||g_ptr->spanned[v2-1]==0)
    result=0;
    else
    {
      SetValues(g_ptr);
      result=DetectCycle(g_ptr,v1);
    }
    
    if(result==0)
    {
      edgA[i]->selected=1;
      g_ptr->spanned[v1-1]=1;
      g_ptr->spanned[v2-1]=1;
      
      mark(g_ptr->head[v1-1],v2);
      mark(g_ptr->head[v2-1],v1);
    }
  }  
}      
      
int DetectCycle(graph* g_ptr, int v1)
{
  static int result;
  
  g_ptr->visited[v1-1]=1;
  node*temp=g_ptr->head[v1-1];
  
  while(temp!=NULL)
  {
    if(temp->color!=BLACK)
    {
      temp=temp->next;
      continue;
    }
    if(g_ptr->visited[temp->item-1]==0)
    {
       g_ptr->parent[temp->item-1]=v1;
       DetectCycle(g_ptr,temp->item);
    }
    else if(g_ptr->parent[temp->item-1]!=v1)
    {
      result=1;
      return result;
    }
    
    temp=temp->next;
  }
  return result; 
}
  

      
