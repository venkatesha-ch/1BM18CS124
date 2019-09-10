#include<stdio.h>
#include<conio.h>


void push(int ele,int *q,int *ft,int *r)
{
if(*ft==-1)
{*ft=0;*r=0;
q[*r]=ele;
}

else if(*r==6)
 printf("Queue full..! \n");
else
{
*r=*r+1;
q[*r]=ele;
}
}

int pop(int *q,int *ft,int *r)
{
int ele;
if(*ft==-1||*ft>*r)
{
return;
}
else if(*ft<=*r)
{ele = q[*ft];
*ft=*ft+1;
return ele;
}
}

 int main()
 {
	int q1[6],q2[6],ft1=-1,r1=-1,ft2=-1,r2=-1,n,i,j,ele,cunt=0;
	clrscr();
	printf("Enter the no.of elements  : ");
	scanf("%d",&n);
	printf("Enter the elements of queue  : ");
	for(i=0;i<n;i++)
	{scanf("%d",&ele);
	 push(ele,q1,&ft1,&r1);
	 }
	 for(j=0;j<=n;j++)
	{ cunt=0;
	 ele=pop(q1,&ft1,&r1);
	{for(i=1;i<=10;i++)
	 {
	 if(ele%i==0)
	  cunt=cunt+1;}
	 if(cunt==10)
	 push(ele,q2,&ft2,&r2);
	 }
	 }
	if(ft2==-1)
	printf("No element is evenly divisible ");
	else
	{printf("Elements evenly divisible are : ");
	for(i=0;i<=r2;i++)
	{ele=pop(q2,&ft2,&r2);

	printf("%d  ",ele);
	}
	}
 getch();
 return 0;
 }

