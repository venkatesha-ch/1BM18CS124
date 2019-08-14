
#include<stdio.h>

int main()
{
void swap(int *,int *);
int a,b;
int *x=&a;
int *y=&b;
printf("Enter the 2 numbers : ");
scanf("%d%d",&a,&b);
printf("Number before swapping a = %d, b = %d \n",a,b);
swap(x,y);
printf("Number after swap a = %d,  b = %d ",a,b);
return 0;
}

void swap(int *x,int *y)
{
int temp;
temp=*x;
*x=*y;
*y=temp;
}

