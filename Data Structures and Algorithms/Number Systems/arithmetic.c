#include<stdio.h>
#include<string.h>

void convert(char*, int);
void strrev(char *);
void addition(char*, char*, int);
void multiplication(char*, char*, int);
void subtraction(char*, char*, int);
void print(char*str);
int decimal(char*, int);

int main()
{
  printf("Enter two strings to perform arithmetic operations on them:");
  char str1[30],str2[30];
  scanf("%s%s",str1,str2);
  printf("Enter the base of the numbers:");
  int base;
  scanf("%d",&base);
  if(base>10)
  {
    convert(str1,base);
    convert(str2,base);
  }
  strrev(str1);
  strrev(str2);
  
  printf("Enter\n1 for addition\n2 for subtraction\n3 for multiplication and\n4 for division\n");
  int i;
  scanf("%d",&i);
  switch(i)
  {
    case 1:addition(str1,str2,base);break;
    case 2:subtraction(str1,str2,base);break;
    case 3:multiplication(str1,str2,base);break;
    //case 4:division(str1,str2);break;*/
  } 
}

void strrev(char* str)
{
  int i,length=strlen(str),temp;
  for(i=0;i<length/2;i++)
  temp=str[i],str[i]=str[length-i-1],str[length-i-1]=temp;
}

void convert(char* str, int base)
{
  int i;
  for(i=0;str[i]!=0;i++)
  if(str[i]>=65)
  str[i]-=7;
}

void print(char*str)
{
  int i;
  for(i=0;str[i]!=0;i++)
  {
    if(str[i]>=58)
    putchar(str[i]+7);
    else
    putchar(str[i]);
  }
 printf("\n");
}
 
int decimal(char* str, int base)
{
  int i,inx=1,sum=0;
  while(str[i]!=0)
  {
    sum+=(str[i]-'0')*inx;
    inx*=base;
    i++;
  }
 return sum;
}

void addition(char* str1, char* str2, int base)
{
  char add[30];
  int carry=0,sum,i=0;
  
 while(str1[i]!=0 && str2[i]!=0)
  {
    sum=str1[i]+str2[i]+carry-2*'0';
    carry=sum/base;
    add[i]=sum%base+'0';
    i++;
  }
  
  while(str1[i]!=0)
  {
    sum=str1[i]+carry-'0';
    add[i]=sum%base+'0';
    carry=sum/base;
    i++;
  }
  
 while(str2[i]!=0)
 {
   sum=str2[i]+carry-'0';
   add[i]=sum%base+'0';
   carry=sum/base;
   i++;
 } 

 while(carry)
{
  add[i]=carry%10+'0';
  carry/=10;
  i++;
}

add[i]=0;
strrev(add);

if(base>10)
print(add);
else
puts(add);
}

void multiplication(char* str1, char* str2,int base)
{
  char product[30];
  int d_val=decimal(str2,base);
  
  int i=0,carry=0,prod=0;
  while(str1[i]!=0)
  {
    prod=(str1[i]-'0')*d_val+carry;
    product[i]=prod%base+'0';
    carry=prod/base;
    i++;
  }
 
 while(carry)
 {
   product[i]=carry%10+'0';
   carry/=10;
   i++;
 }
 
 product[i]=0;
 strrev(product);
 
 if(base>10)
 print(product);
 else
 puts(product);

}

void subtraction(char* str1, char* str2,int base)
{
  int flag;
  if(decimal(str1,base)<decimal(str2,base))
  {
    flag=1;char*temp;
    temp=str1,str1=str2,str2=temp;
  }
   
  char diff[30];
  int i,k;
  for(i=0;str1[i]!=0;i++)
  {
    if(str1[i]>=str2[i])
    diff[i]=str1[i]-str2[i]+'0';
    
    else
    {
      diff[i]=str1[i]-str2[i]+base+'0';
      
      if(str1[i-1]!=48)
      str1[i-1]--;
      else
     {
       k=i-1;
       while(str1[k]==48)
       {
         str1[k]+=base-1;
         k++;
       }
      str1[k]--;
     }
    }
  }     
      
  diff[i]=0;
  strrev(diff);
   
 if(flag)
 printf("-");
  
 if(base>10)
 print(diff);
 else
 puts(diff);
}
  
