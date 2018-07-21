#include<stdio.h>
#include<stdlib.h>
main()
{
 printf("Enter the number of elements in the array:");
 int size;
 scanf("%d",&size);
 int* ptr=malloc(size*sizeof(int));
 int pass,i;
 printf("Enter the elements of the array:");
 for(i=0;i<size;i++)
 scanf("%d",ptr+i);
 
 int flag;
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
 
 for(i=0;i<size;i++)
 printf("%d ",ptr[i]);

 free(ptr);
}
