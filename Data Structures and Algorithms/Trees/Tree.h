/*Function to create a tree*/
void create_tree(node*head)
{
  int x;
  char pos;
  node*temp;
  
  while(1)
  {
    printf("Enter a node:");
    scanf("%d",&x);
    if(x==-999)
    break;
    
    temp=malloc(sizeof(node));
    temp->item=x;
    temp->left=temp->right=NULL;
    
    node*prev=NULL,*curr=head;
    
    while(curr!=NULL)
    {
      prev=curr;
      printf("L or R of %d?",curr->item);
      getchar();
      scanf("%c",&pos);
      if(pos=='L')
      curr=curr->left;
      else
      curr=curr->right;
    }
    if(pos=='L')
    prev->left=temp;
    
    else
    prev->right=temp;
  }
}
/*Function to create a BST*/

void createBST(node* head)
{
  int x;
  node*temp;
  
  while(scanf("%d",&x),x!=-999)
  {
    temp=malloc(sizeof(node));
    temp->item=x;
    temp->left=temp->right=NULL;
    
    node* curr=head,*prev=NULL;
    while(curr!=NULL)
    {
      prev=curr;
      
      if(x<curr->item)
      curr=curr->left;
      else
      curr=curr->right;
    }
    
    if(x<prev->item)
    prev->left=temp;
    else
    prev->right=temp;
  }
}

/*Inorder traversal*/
void inorder(node* head)
{
  if(head==NULL)
  return;
  
  inorder(head->left);
  printf("%d",head->item);
  inorder(head->right);
}

/*Preorder traversal*/
void preorder(node* head)
{
  if(head==NULL)
  return;
  
  printf("%d",head->item);
  preorder(head->left);
  preorder(head->right);
}

/*Postorder traversal*/
void preorder(node* head)
{
  if(head==NULL)
  return;
  
  preorder(head->left);
  preorder(head->right);
  printf("%d",head->item);
}

/*Inorder array traversal*/
void inorder(int* tree, int i)
{
  
  if(tree[i]==0)
  return;
  
  inorder(tree, 2*i+1);
  printf("%d",tree[i]);
  inorder(tree, 2*i+2);
}   
/*Function to print all root to leaf paths*/

void PrintTree(Stack* sp, node*head)
{
  if(head->left==NULL && head->right==NULL)
  {
    print(sp);
    return;
  }

  if(head->left!=NULL)
  {
    push(sp,head->left->item);
    PrintTree(sp,head->left);
    pop(sp);
  }
  
  if(head->right!=NULL)
  {
    push(sp,head->right->item);
    PrintTree(sp,hp,head->right);
    pop(sp);
  }
}  

void push(Stack* sp,int item)
{
  sp->k++;
  sp->stack[sp->k]=item;
}

void pop(Stack* sp)
{
  sp->k--;
}

void print(Stack* sp)
{
  int i;
  for(i=0;i<=sp->k;i++)
  printf("%d ",sp->stack[i]);
  
  printf("\n");
}

/*Function to print the longest root to leaf path*/

void PrintTree(Stack* sp,Stack* hp,node*head)
{
  static int k,max;
  k++;
  if(head->left==NULL && head->right==NULL)
  {
    if(k>max)
    {
      max=k;
      store(sp,hp);
    }
    k--;
    return;
  }
  
  if(head->left!=NULL)
  {
    push(sp,head->left->item);
    PrintTree(sp,hp,head->left);
    pop(sp);
  }
  
  if(head->right!=NULL)
  {
    push(sp,head->right->item);
    PrintTree(sp,hp,head->right);
    pop(sp);
  }
}  

void store(Stack* sp, Stack* hp)
{
  if(hp->stack!=NULL)
  free(hp->stack);
  
  hp->k=-1;
  hp->stack=malloc(((sp->k)+1)*sizeof(int));
  
  int i;
  for(i=0;i<=sp->k;i++)
  {
    hp->k++;
    hp->stack[hp->k]=sp->stack[i];
  }
}

/*Function to check if a tree is a full binary tree*/
void postorder(node*head)
{
  if(head==NULL)
  return;
  
  if(head->left!=NULL ^ head->right!=NULL)
  {
    printf("The tree is not full at vertex %d",head->item);
    exit(0);
  }
  
  postorder(head->left);
  postorder(head->right);
}

/*Function to compute height of a tree*/
int tree_height(node* head)
{
  if(head==NULL)
  return 0;
  
  return 1+ max(tree_height(head->left),tree_height(head->right));
}

/*Function to compute tree height*/
int tree_height(node* head)
{
  if(head==NULL)
  return 0;
  
  return 1+ max(tree_height(head->left),tree_height(head->right));
}

int max(int a, int b)
{
  return (a>b)?a:b;
}

/*Function to count leaves in a tree*/
int count_leaves(node* head)
{
  if(head==NULL)
  return 0;
  
  if(head->left==NULL && head->right==NULL)
  return 1;
  
  return count_leaves(head->left)+count_leaves(head->right);
}

/*Function to count internal nodes*/
int count_int(node* head)
{
  if(head==NULL|| (head->left==NULL&&head->right==NULL))
  return 0;
  
  return 1+count_int(head->left)+ count_int(head->right);
}

/*Function to check if a tree is complete. This function employs level order traversal*/
int CheckComplete(node* head)
{
  if(head==NULL)
  return 1;
  
  Q q1;
  q1.r=-1;
  q1.f=0;
  q1.count=0;
  q1.arr=malloc(16*sizeof(node*));
  
  enQ(&q1,head);
  int flag=0;
  
  while(q1.count>0)
  {
    head=deQ(&q1);
    
    if(head->left)
    {
      if(flag==1)
      return 0;
      
      enQ(&q1,head->left);
    }
    else
    flag=1;
    
    if(head->right)
    {
      if(flag==1)
      return 0;
      
      enQ(&q1,head->right);
    }
    else
    flag=1;
  }
  
  return 1;
}


/*Function to check if a tree is a perfect binary tree*/
void postorder(node* head)
{
  static int k=-1;
  
  if(head==NULL)
  return;
  
  k++;
  postorder(head->left);
  postorder(head->right);
  
  arr[k--]++;
}

  int flag=1;
  for(i=0;arr[i]!=0;i++)
  if(arr[i]!=pow(2,i))
  {
    flag=0;
    break;
  }
  
  if(flag)
  printf("\nTree is perfect\n");
  else
  printf("\nTree is not perfect");  

