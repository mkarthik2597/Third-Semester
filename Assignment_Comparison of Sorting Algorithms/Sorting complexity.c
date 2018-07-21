#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble(int*, int);
void generate(int*,int);
void insertion(int*,int);
void selection(int*,int);
void merge(int*,int);
void divide(int*,int,int);
void conquer(int*,int,int,int);
void quicksort(int*,int,int);
int partition(int*,int,int);
void swap(int*, int*);
void print_heap(int*,int);
void heapsort(int*,int);
void sort_heap(int*, int);
void adjust_heap(int*,int);

int main()
{
  printf("Enter input array size:");
  int n;
  scanf("%d",&n);
  int*arr=malloc(n*sizeof(int));
 
  generate(arr,n);
  bubble(arr,n);

  generate(arr,n); 
  insertion(arr,n);
  
  generate(arr,n);
  selection(arr,n);

  generate(arr,n);
  merge(arr,n);
  
  generate(arr,n);
  
  clock_t start,end;
  start=clock();
  
  quicksort(arr,0,n-1);
  
  end=clock();
  double total=(double)(end-start)/CLOCKS_PER_SEC;
  printf("Time for quicksort=%fs\n",total); 
  
  generate(arr,n);
  heapsort(arr,n);
  
  free(arr);
  
}


void generate(int* arr, int n)
{
  srand(1);
  int i;
  for(i=0;i<n;i++)
  arr[i]=rand();
}

void bubble(int*ptr, int size)
{
  int flag,pass,i;
  clock_t start,end;
  start=clock();

  for(pass=0;pass<size-1;pass++)
  {
   flag=0;
   for(i=0;i<size-pass-1;i++)
   if(ptr[i]>ptr[i+1])
   {
    int temp;
    temp=ptr[i],ptr[i]=ptr[i+1],ptr[i+1]=temp;
    flag=1;
   }
   if(flag==0)
   break;
  }

  end=clock();
  double total=(double)(end-start)/CLOCKS_PER_SEC;

  printf("Time for bubble sort=%fs\n",total);
}

void insertion(int* ptr, int size)
{
  int pass,j,k;
  clock_t start,end;
  start=clock();

  for(pass=1;pass<size;pass++)
  {
    j=pass-1;
    k=ptr[pass];
    while(k<ptr[j]&&j>=0)
    {
      ptr[j+1]=ptr[j];
      j--;
    }
   ptr[j+1]=k;
  }
  
  end=clock();
  double total=(double)(end-start)/CLOCKS_PER_SEC;

  printf("Time for insertion sort=%fs\n",total);
}

void selection(int*ptr, int size)
{
  int pass,min,i;
 
  clock_t start,end;
  start=clock();
 
  for(pass=0;pass<size-1;pass++)
  {
   min=pass;
   for(i=pass+1;i<size;i++)
   if(ptr[i]<ptr[min])
   min=i;

   if(min!=pass)
   {
     int temp;
     temp=ptr[min],ptr[min]=ptr[pass],ptr[pass]=temp;
   }
  }
 
  end=clock();
  double total=(double)(end-start)/CLOCKS_PER_SEC;

  printf("Time for selection sort=%fs\n",total);
}

void merge(int*arr, int size)
{
  int s=0,t=size-1;
  clock_t start,end;
  start=clock();
 
  divide(arr,s,t);
  end=clock();
  double total=(double)(end-start)/CLOCKS_PER_SEC;
  printf("Time for merge sort=%fs\n",total);
}


void divide(int* arr,int s,int t)
{
  if(s<t)
 {  
  int m=(s+t)/2;
  divide(arr,s,m);
  divide(arr,m+1,t);
  conquer(arr,s,m,t);
 }

}

void conquer(int* arr,int s,int m, int t)
{
  int temp1[m-s+1];
  int temp2[t-m];
  int i;
  
  for(i=0;i<=m-s;i++)
  temp1[i]=arr[s+i];
  
  for(i=0;i<=t-m-1;i++)
  temp2[i]=arr[m+1+i];
  
  int k=s,j=0;
  i=0;

   while(i<=m-s&&j<=t-m-1)
  { 
    if(temp1[i]<temp2[j])
    arr[k++]=temp1[i++];
    
    else
    arr[k++]=temp2[j++];
  }  
  
  while(i>m-s&&k<t+1)
  arr[k++]=temp2[j++];
  
  while(j>t-m-1&&k<t+1)
  arr[k++]=temp1[i++];
}

void quicksort(int*arr, int l,int h)
{
 
  
  if(l<h)                          
 { 
  int i;
  i=partition(arr,l,h); 

  quicksort(arr,l,i-1);
  quicksort(arr,i+1,h);
 }
  

}


int partition(int*arr, int l,int h)  
{                                      
  int pivot=arr[h];                  
  int i,j;
  j=l;
  i=l-1;
  
  while(j<h)
 { 
   if(arr[j]<pivot)
    {
      i++;
      swap(arr+j,arr+i);
    }
  
  j++;
 }

 swap(arr+j,arr+i+1);                  
 return i+1;                         
}

void swap(int* a,int* b)
{
  int temp;
  temp=*a,*a=*b,*b=temp;
}


void heapsort(int* arr, int n)
{
  clock_t start,end;
  start=clock();

  int i;
  int parent,child,node;
 
  for(i=0;i<n;i++)
  { 
    node=arr[i];
    child=i;
    parent=(i-1)/2;
    
    while(child>0 && arr[parent]<node)
    {
      arr[child]=arr[parent];
      child=parent;
      parent=(child-1)/2;
    }
    
    arr[child]=node;
  }
  
  sort_heap(arr,n);

  end=clock();
  double total=(double)(end-start)/CLOCKS_PER_SEC;
  printf("Time for heapsort=%fs\n",total); 
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
      if(arr[i+1]>arr[i])
      i++;
    }
    
    if(node<arr[i])
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

void print_heap(int*arr, int n)
{
  int i;
  for(i=0;i<n;i++)
  printf("%d ",arr[i]);
  
  printf("\n");
}

