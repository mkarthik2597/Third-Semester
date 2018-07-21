#include<stdio.h>
#include<stdlib.h>
main()
{
 printf("Enter the number of elements in your array:");
 int size;
 scanf("%d",&size);
 int* ptr=malloc(size*sizeof(int));
 int i;
 printf("Enter the elements of the array:");
 for(i=0;i<size;i++)
 scanf("%d",ptr+i);
 
int key;
printf("Enter the element that you want to search:");
scanf("%d",&key);
int flag=0;

for(i=0;i<size;i++)
{
 if(ptr[i]==key)
 {
   printf("%d ",i+1);
   flag=1;
 }
}

if(flag==0)
printf("Key not found!\n");

free(ptr);
} 

