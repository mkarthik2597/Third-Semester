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
  node** head;
  int n;
}
graph;

void create_G(graph*);
void create_list(node**);
void print_G(graph*);
void print_list(node*);
void SetValues(graph*);
node* DFS(graph*,int);

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
  
  node* TopoList;
 
  int i;
  for(i=1;i<=n;i++)
  if(G.visited[i-1]==0)
  TopoList=DFS(&G,i);
  
  printf("\n\n");
  for(i=0;i<n;i++)
  {
    printf("%d's parent is %d\n",i+1,G.parent[i]);
    printf("Discovery time:%d\n",G.start_t[i]);
    printf("Finish time:%d\n\n",G.finish_t[i]);
  }  
  
  printf("The topologically sorted graph is:\n");
  print_list(TopoList);
  printf("\n\n");
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

  int i; 
  for(i=0;i<g_ptr->n;i++)
  {
    g_ptr->parent[i]=0;
    g_ptr->start_t[i]=0;
    g_ptr->finish_t[i]=0;
    g_ptr->visited[i]=0;
  }
}
      
      
node* DFS(graph* g_ptr, int vertex)
{
  static int time;
  static node* TopoList=NULL;
  
  g_ptr->start_t[vertex-1]=++time;
  g_ptr->visited[vertex-1]=1;
  node*list=g_ptr->head[vertex-1];
  
  while(list!=NULL)
  {
    if(g_ptr->visited[list->item-1]==0)
    {
       g_ptr->parent[list->item-1]=vertex;
       DFS(g_ptr,list->item);
    }
    else if(g_ptr->finish_t[list->item-1]==0)
    {
       printf("(%d,%d) is a back edge.Cannot perform topological sort!\n",vertex,list->item);
       exit(0);
    }
   
   list=list->next;
  }
  
   node* temp=TopoList;
   TopoList=malloc(sizeof(node));
   TopoList->item=vertex;
   TopoList->next=temp;
  
   g_ptr->finish_t[vertex-1]=++time;
   return TopoList;
}
     
      
