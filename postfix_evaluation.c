#include<stdio.h>
#include<ctype.h>
#define max 20

double stack[max];
int top=-1;

double pop()
{
	double item;
	if(top<0)
		printf("Stack under flow\n");
	else
	{	item = stack[top];
		top=top-1;
		
	}
	return item;
}

void push(double item)
{
	if(top>=max-1)
		printf("Stack over flow \n");
	else
	{
		top=top+1;
		stack[top]=item;
	}
}

 void calculation(char exp[])
{
	char ch;
	double a,b;
	int i;
	double res;
	for(i=0;exp[i]!='\0';i++)
	{
		ch=exp[i];
		if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
		{	a=pop();
			b=pop();
			switch(ch)
			{
				case '*':res=b*a;
					break;
				case '+':res=b+a;
					break;
				case '-':res=b-a;
					break;
				case '/':res=(b/a);
			}
		push(res);
		}
		else 
		{if (isdigit(ch))
				
                        push(ch-'0');
		}
	}
	printf("Result = %.2f",pop());
}
int main()
{
	char exp[20];
	printf("Enter the exp  ");
	scanf("%s",exp);
	calculation(exp);
	return 0;
}

