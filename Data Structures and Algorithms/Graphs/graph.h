


void create_G(node**head, int n)
{
  int i,x;
  for(i=0;i<n;i++)
  {
    printf("Enter nodes adjacent to vertex %d(-999 to exit):",i+1);
    scanf("%d",&x);
    if(x!=-999)
    {
      head[i]=malloc(sizeof(node));
      head[i]->item=x;
      head[i]->next=NULL;
      create_list(head+i);
    }
    else
    head[i]=NULL;
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

/*Function to classify edges*/
void DFS(graph* g_ptr, int vertex)
{
  static int time;
  g_ptr->start_t[vertex-1]=++time;
  g_ptr->visited[vertex-1]=1;
  node*temp=g_ptr->head[vertex-1];
  
  while(temp!=NULL)
  {
    if(g_ptr->visited[temp->item-1]==0)
    {
       printf("(%d,%d) is a tree edge\n",vertex,temp->item);
       g_ptr->parent[temp->item-1]=vertex;
       DFS(g_ptr,temp->item);
    }
    else if(g_ptr->finish_t[temp->item-1]==0)
    printf("(%d,%d) is a back edge\n",vertex,temp->item);
    
    else if(g_ptr->start_t[vertex-1]<g_ptr->start_t[temp->item-1])
    printf("(%d,%d) is a forward edge\n",vertex,temp->item);
    
    else
    printf("(%d,%d) is a cross edge\n",vertex,temp->item);
    
    temp=temp->next;
  }
  g_ptr->finish_t[vertex-1]=++time;
}

