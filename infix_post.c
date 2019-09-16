#include <stdio.h>
#include<stdlib.h>
#define size 100
void push(char *item,int *top,char stack[size])
{if (*top>=(size-1))
    printf("stack overflow");
    else
 {
    (*top)++;
    stack[*top]=*item;
 }
} 
char pop(int *top,char stack[size])
{
    char item;
    item=stack[*top];
    (*top)--;
    return(item);
}
int is_operator(char *symbol)
{ 
    if (*symbol=='^'|| *symbol=='*'|| *symbol=='/'|| *symbol=='+'|| *symbol=='-')
    return 1;
    else
    return 0;
}
int precedence(char *symbol)
{
    if (*symbol=='^')
    return 3;
    else if (*symbol=='*'||*symbol=='/')
    return 2;
    else if (*symbol=='+'|| *symbol=='-')
    return 1;
    else
    return 0;
}    

int main()
{
char infix[size],postfix[size],stack[size], item,temp;
int i=0,j=0,top=-1;
printf("enter the expression in INFIX notation:");
scanf("%s",infix);
while(infix[i]!='\0')
{
    item=infix[i];
    if(item=='(')
     push(&item,&top,stack);
    else if((item>='A') &&( item<='z') ||( item>='a') && (item<='z'))
    {
      postfix[j]=item;
      j++;
    } 
    else if ((is_operator(&item))==1)
    {
        temp=pop(&top,stack);
        while((is_operator(&temp)==1) && (precedence(&temp)>=precedence(&item)))
        {
         postfix[j]=temp;
         j++;
         temp=pop(&top,stack);
        }    
        push(&temp,&top,stack);
        push(&item,&top,stack);
    }
    else if (item=')')
    {
        temp=pop(&top,stack);
        while(temp!='(')
        {
            postfix[j]=temp;
            j++;
            temp=pop(&top,stack);
        }
    }
    else 
    {
        printf("invalid expression");
        exit(0);
        
    }
    i++;
}
while(top>=-1)
{
    postfix[j]=pop(&top,stack);
    j++;
}
postfix[j]='\0';
printf ("postfix expression:");
puts(postfix);
return 0;
}
