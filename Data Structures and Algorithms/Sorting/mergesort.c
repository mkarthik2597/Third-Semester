#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void divide(int*,int,int);
void conquer(int*, int, int, int);

int main()
{
  printf("Enter the size of the array:");
  int size;
  scanf("%d",&size);
  int* arr=malloc(size*sizeof(int));
  printf("\nEnter the array elements:");
  int i;
  for(i=0;i<size;i++)
  scanf("%d",arr+i);

  int s=0,t=size-1;
  divide(arr,s,t);

  for(i=0;i<size;i++)
  printf("%d ",arr[i]);
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
  int size1=m-s+1;
  int size2=t-m;
  int temp1[size1+1];
  int temp2[size2+1];
  
  temp1[size1]=INT_MAX;
  temp2[size2]=INT_MAX;
  int i;
  
  for(i=0;i<size1;i++)
  temp1[i]=arr[s+i];  /*Not arr[i]*/
  
  for(i=0;i<size2;i++)
  temp2[i]=arr[m+1+i];
  
  int k=s,j=0,count=0;
  i=0;

  for(count=0;count<size1+size2;count++)
  {
    if(temp1[i]<temp2[j])
    arr[k++]=temp1[i++];

    else
    arr[k++]=temp2[j++];
  }
}
