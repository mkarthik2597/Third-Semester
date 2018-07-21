#include<stdio.h>
#include<stdlib.h>
main()
{
 printf("Enter the number of elements in the array:");
 int size;
 scanf("%d",&size);
 int*ptr=malloc(size*sizeof(int));
 int i;
 printf("Enter the elements:");
 for(i=0;i<size;i++)
 scanf("%d",ptr+i);
 int pass;
 int min;
 
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

for(i=0;i<size;i++)
printf("%d ",ptr[i]);

free(ptr);
}
 
