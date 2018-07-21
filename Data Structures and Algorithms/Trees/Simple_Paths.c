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
  int* start_t;
  int* finish_t;
  int* visited;
  int* CountPaths;
  node** head;
  int n;
}
graph;

void create_G(graph*);
void create_list(node**);
void print_G(graph*);
void print_list(node*);
void SetValues(graph*);
void DFS(graph*,int);

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
  SetValues(&G);
  
  printf("Enter source vertex:");
  int source;
  scanf("%d",&source);
  printf("Enter destination vertex:");
  int dest;
  scanf("%d",&dest);
  DFS(&G,source,dest);
  
  int i;
  for(i=1;i<=n;i++)
  if(G.visited[i-1]==0)
  DFS(&G,i);
  
  printf("\n\n");
  for(i=0;i<n;i++)
  {
    printf("%d's parent is %d\n",i+1,G.parent[i]);
    printf("Discovery time:%d\n",G.start_t[i]);
    printf("Finish time:%d\n\n",G.finish_t[i]);
  }  
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


void SetValues(graph* g_ptr)
{
  int n=g_ptr->n;
  g_ptr->parent=malloc(n*sizeof(int));
  g_ptr->start_t=malloc(n*sizeof(int));
  g_ptr->finish_t=malloc(n*sizeof(int));
  g_ptr->visited=malloc(n*sizeof(int));
  g_ptr->CountPaths=malloc(n*sizeof(int));

  int i; 
  for(i=0;i<g_ptr->n;i++)
  {
    g_ptr->parent[i]=0;
    g_ptr->start_t[i]=0;
    g_ptr->finish_t[i]=0;
    g_ptr->visited[i]=0;
    g_ptr->CountPaths[i]=0;
  }
}
      
      
void DFS(graph* g_ptr, int vertex, int dest)
{
  static int time;
  g_ptr->start_t[vertex-1]=++time;
  g_ptr->visited[vertex-1]=1;
  node*temp=g_ptr->head[vertex-1];
  
  while(temp->item!=dest && temp!=NULL)
  {
    if(g_ptr->visited[temp->item-1]==0)
    {
       g_ptr->parent[temp->item-1]=vertex;
       DFS(g_ptr,temp->item,dest);
    }
    
    temp=temp->next;
  }
  g_ptr->finish_t[vertex-1]=++time;
}
     
      
