#include<stdio.h>
#include<stdlib.h>
#include<time.h>
main()
{
  int*arr=malloc(sizeof(int)*1000);
  int i; 
  for(i=0;i<1000;i++)
  arr[i]=rand()%100+1;

  clock_t start,end;

  int size=1000,pass;
  int temp;
 
  start=clock();
  
  for(pass=0;pass<size-1;pass++)
  for(i=0;i<size-pass-1;i++)
  if(arr[i]>arr[i+1])
  temp=arr[i],arr[i]=arr[i+1],arr[i+1]=temp;

  end=clock();
  double total=(double)(end-start)/CLOCKS_PER_SEC;

  printf("Time=%f",total);
}


