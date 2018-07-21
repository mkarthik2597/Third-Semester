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

typedef struct
{
  int* arr;
  int k;
}
STACK;

void create_G(graph*);
void create_list(node**);
void print_G(graph*);
void print_list(node*);
void SetValues(graph*);
void DFS(graph*,int, STACK*);
void push(STACK*, int);
void pop(STACK*);
void display(STACK*);

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
  
  STACK s1;
  s1.arr=malloc(n*sizeof(node));
  s1.k=-1;
  
  printf("Enter a vertex to perform DFS:");
  int source;
  scanf("%d",&source);
  push(&s1, source);
  DFS(&G,source,&s1);
  
  int i;
  for(i=1;i<=n;i++)
  if(G.visited[i-1]==0)
  DFS(&G,i,&s1);
  
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
      
void push(STACK* s_ptr, int source)
{
  s_ptr->k++;
  s_ptr->arr[s_ptr->k]=source;
}

void pop(STACK* s_ptr)
{
  s_ptr->k--;
}

void DFS(graph* g_ptr, int vertex, STACK* s_ptr)
{
  static time=0;
  node* temp;
  g_ptr->start_t[vertex-1]=++time;
  g_ptr->visited[vertex-1]=1;
  
  while(s_ptr->k!=-1)
  {
    temp=g_ptr->head[s_ptr->arr[s_ptr->k]-1];
    
    while(temp!=NULL)
    {
      if(g_ptr->visited[temp->item-1]==0)
      {
        g_ptr->start_t[temp->item-1]=++time;
        g_ptr->visited[temp->item-1]=1;
        g_ptr->parent[temp->item-1]=s_ptr->arr[s_ptr->k];
        
        push(s_ptr, temp->item);
        temp=g_ptr->head[s_ptr->arr[s_ptr->k]-1];
      }
      
      else
      temp=temp->next;
    }
    
    g_ptr->finish_t[s_ptr->arr[s_ptr->k]-1]=++time;
    pop(s_ptr);
  }
}

void display(STACK* s_ptr)
{
  int i;
  for(i=0;i<=s_ptr->k;i++)
  printf("%d ",s_ptr->arr[i]);
  
  printf("\n");
}

