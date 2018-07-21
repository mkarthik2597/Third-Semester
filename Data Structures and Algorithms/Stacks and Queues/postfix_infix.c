#include<stdio.h>
#include<string.h>
int operand(char);
main()
{
  char postfix[30];
  printf("Enter a postfix expression:");
  scanf("%s",postfix);
  char temp[30]={};
  char stack[30][30]={};
  int k=-1,j;
  int i,len=strlen(postfix);
  for(i=0;i<len;i++)
  {
    if(operand(postfix[i]))
    {
       k++;
       stack[k][0]=postfix[i];
       stack[k][1]=0;
    }
    else
    {
      temp[0]='(';
      strcpy(temp+1,stack[k-1]);
      temp[strlen(temp)]=postfix[i];
      strcat(temp,stack[k]);
      temp[strlen(temp)]=')';
      temp[strlen(temp)]=0;
      
      k--;
      strcpy(stack[k],temp);
      
      for(j=0;temp[j]!=0;j++)
      temp[j]=0;
    }
  }

  puts(stack[k]);
}

int operand(char ch)
{
  switch(ch)
  {
    case '+':
    case '-':
    case '*':
    case '/':
    return 0;
  }
   
  return 1;
}
   
