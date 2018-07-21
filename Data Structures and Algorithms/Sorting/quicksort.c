#include<stdio.h>
#include<stdlib.h>

void quicksort(int*,int,int);
int partition(int*,int,int);
void swap(int*, int*);

main()
{
  printf("Enter the size of the array:");
  int size;
  scanf("%d",&size);
  int* arr=malloc(size*sizeof(int));
  printf("Enter the array elements:");
  int i;
  for(i=0;i<size;i++)
  scanf("%d",arr+i);
  
  quicksort(arr,0,size-1);
  
  for(i=0;i<size;i++)
  printf("%d ",arr[i]);
}
 
void quicksort(int*arr, int l,int h)
{
  if(l<h)                           //Not less than or equal to.Makes no sense to sort an element already in place.
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

 swap(arr+j,arr+i+1);                  //The function return the position of the pivot.Then the quicksort function sends the two halves
 return i+1;                           //individually
}

void swap(int* a,int* b)
{
  int temp;
  temp=*a,*a=*b,*b=temp;
}
