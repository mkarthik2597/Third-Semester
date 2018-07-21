#include<stdio.h>

void create_heap(int*,int);
void print_heap(int*,int);
void sort_heap(int*, int);
void adjust_heap(int*,int);

int main()
{
  printf("Enter the number of nodes:");
  int n;
  scanf("%d",&n);
  int arr[n];
  
  create_heap(arr,n);
  print_heap(arr,n);
  
  sort_heap(arr,n);
  print_heap(arr,n);
}

void create_heap(int* arr, int n)
{
  int i;
  int parent,child,node;
  printf("Enter the nodes:");
  for(i=0;i<n;i++)
  { 
    scanf("%d",&node);
    child=i;
    parent=(i-1)/2;
    
    while(child>0 && arr[parent]>node)
    {
      arr[child]=arr[parent];
      child=parent;
      parent=(child-1)/2;
    }
    
    arr[child]=node;
  }
}

void print_heap(int*arr, int n)
{
  int i;
  for(i=0;i<n;i++)
  printf("%d ",arr[i]);
  
  printf("\n");
}

void sort_heap(int* arr, int n)
{
  int j,temp;
  for(j=n-1;j>0;j--)
  {
    temp=arr[j];
    arr[j]=arr[0];
    arr[0]=temp;
    
    adjust_heap(arr,j);
  }
}
 
void adjust_heap(int* arr, int n)
{
  int parent=0,node=arr[parent],i=2*parent+1;
  
  while(i<n)
  { 
    if(i+1<n)
    {
      if(arr[i+1]<arr[i])
      i++;
    }
    
    if(node>arr[i])
    {
      arr[parent]=arr[i];
      parent=i;
      i=2*parent+1;
    }
    else
    break;
  }
  arr[parent]=node;
}
