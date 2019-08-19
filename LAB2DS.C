#include<conio.h>
#include<stdio.h>
# define max 3
int stack[max];
void pop(int *top);
void push(int item,int *top);
int main()
{
int top=-1,choice,i,item;
clrscr();
do
{
printf("Enter 1 for push \nEnter 2 for pop \nEnter 3 for Display ");
scanf("%d",&choice);
switch(choice)
{
case 1:{printf("Enter the element ");
	scanf("%d",&item);
	push(item,&top);
	break;
	}
case 2:{pop(&top);
	break;
	}

case 3:{if(top==-1)
	printf("Stack is empty\n");
	else
	{printf("Stack elements are	");
	for(i=top;i>=0;i--)
	printf("%d\t",stack[i]);
	}
	break;
	}
}
}while(choice==1||choice==2||choice==3);
getch();
return 0;

}


void pop(int *top)
{
if(*top==-1)
printf("Stack underflow\n");
else
*top=*top-1;
}
void push(int item,int *top)
{
if(*top==max)
printf("Stack overflow\n");
else
{*top=*top+1;
 stack[*top]=item;
}
}