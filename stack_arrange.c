#include<stdio.h>
#include<conio.h>
#define size 50


void display(int *n,int stack[size])
{int i,j,ele1,ele2;
    for(i=*n-1;i>0;i--)
 {
    for(j=*n-1;j>(*n-1-i);j--)
   {
    ele1=stack[j];
    ele2=stack[j-1];
    if(ele1<ele2)
    {stack[j]=ele2;
    stack[j-1]=ele1; 
    }

   }

 }
 if (*n==-1)
 printf("stack is empty");
 else
{ printf("the stack after arranging is:");
 for(i=*n-1;i>=0;i--)
 {printf("%d",stack[i]);
 printf("\n");
 }
}
}


void push(int *top,int stack[size])
{
    if (*top==size-1)
    printf ("stack is full");
    
    else if(*top==-1)
    {
        *top=0;
        printf("enter the element to be inserted:");
        scanf ("%d",&stack[*top]);
        (*top)++;
    }
    else
    {
        printf("enter the element to be inserted:");
        scanf ("%d",&stack[*top]);
        (*top)++;
    }
}



void main()
{
  int n, top=-1,stack[size];
  do
   {
      printf("1.insert \n  2.display \n 3.exit\n");
  scanf("%d",&n);
  switch(n)
  {case 1:push(&top,stack);
          break;
    case 2: display(&top,stack);
         break;
    case 3 :break;
    default: printf ("enter correct option");
  }
   }while(n!=3);
printf("Thank you ");
 getch();
}
