#include<stdio.h>
#include<stdlib.h>
main()
{
 printf("Enter the number of elements in the array:");
 int size;
 scanf("%d",&size);
 int* ptr=malloc(size*sizeof(int));
 int i;
 printf("Enter the elements:");
 for(i=0;i<size;i++)
 scanf("%d",ptr+i);

 int pass,j,k;
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

for(i=0;i<size;i++)
printf("%d ",ptr[i]);
free(ptr);

}
 
