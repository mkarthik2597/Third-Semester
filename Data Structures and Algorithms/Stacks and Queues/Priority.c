#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

typedef struct
{
  int item;
  int prty;
} 
queue;

int f,r,count;

void enq(queue**, int,int);
void deq(queue**);
void print(queue**);

main()
{
  queue**arr=malloc(SIZE*sizeof(queue*));
  printf("Queue size is %d",SIZE);
  f=0,r=-1;
  repeat:
  printf("\nEnter\n1 to enqueue\n2 to dequeue:\n");
  int i;
  
  scanf("%d",&i);
  switch(i)
  {
    case 1: printf("Enter element and its priority:");
            int x, prty;
            scanf("%d%d",&x,&prty);
            enq(arr,x,prty);
            print(arr);
            break;
  
    case 2: deq(arr);
            print(arr);
  }
 goto repeat;
}

void enq(queue** arr,int x, int prty)
{
  if(count==SIZE)
  {
    printf("\nQueue OVERFLOW!");
    return;
  }
  int j=r,k=count;
  
  r=(r+1)%SIZE;
  while(k>0&&arr[j]->prty > prty)
  {
    arr[(j+1)%SIZE]=arr[j];
    j=(j+SIZE-1)%SIZE;
    k--;
  }

  j=(j+1)%SIZE;
  arr[j]=malloc(sizeof(queue));
  arr[j]->item=x;
  arr[j]->prty=prty;
  count++;
  
  
}

void deq(queue**arr)
{
  if(count==0)
  printf("Queue is empty!");

  else if(count==1)
  {
    free(arr[f]);
    f=0;
    r=-1;
    count--;
  }
  
  else
  {
    free(arr[f]);
    f=(f+1)%SIZE;
    count--;  
  }
}
  
void print(queue**arr)
{
  int k=count,F=f;
  while(k>0)
  {
    printf("%d ",arr[F]->item);
    F=(F+1)%SIZE;
    k--;
  }
}



    
           
