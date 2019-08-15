#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
# define max 9
void pop(int *top);
void push(int *top,int *i);
int cupboard[20];
int main()
{
int top=-1,n,i=0;
clrscr();
do
{printf("TOTAL NUMBER OF SHIRTS IN CUPBOARD %d \n",i);
printf("PRESS 1 FOR ADD SHIRT TO CUPBOARD \n");
printf("PRESS 2 FOR REMOVE SHIRT FROM CUPBOARD \n");
printf("PRESS 3 FOR EXIT \n");
scanf("%d",&n);
switch(n)
{case 1:{push(&top,&i);
          break;
	}
 case 2:{pop(&top);
	break;
	}
 default:{printf("THANK YOU \n");
	  exit(0);
	}
}
}while(1);
getch();	
return 0;
}
void pop(int *top)
{
if(*top==-1)
printf("CUPBOARD IS EMPTY \n");
else
{*top=*top-1;
printf("SHIRT REMOVED \n");
}
}
void push(int *top,int *i)
{
if(*top==max)
printf("CUPBOARD IS FULL \n");
else
{*top=*top+1;
printf("SHIRT ADDED \n");
*i=*i+1;
}
}

