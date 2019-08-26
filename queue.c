#include<stdio.h>

int main()
{
int front=-1,rear=-1,choice,queue[10],i,item;
int max=3;
do
  {
	printf("Enter 1 for insert\nEnter 2 for delete\nEnter 3 for display\nEnter other to exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1: {if(rear==max)
		 printf("Queue overflow \n");
		else
		{
		if(front==-1)
		{front=0;
		rear=0;
 		}
		else
		rear=rear+1;
		printf("Enter the element to be inserted  ");
		scanf("%d",&item);
		queue[rear]=item;
		printf("Element %d inserted \n",item);
		}}
		break;
	case 2:if(rear==-1)
		printf("Queue empty");
		else
		{item=queue[front];
		 printf("Element %d is removed \n",item);
		 front=front+1;
		}
		break;
	case 3:if(rear<front)
		printf("Queue is empty \n");
		else
		{printf("Queue elements are  ");
		for(i=front;i<=rear;i++)
		printf("%d  ",queue[i]);
		}
		break;
	}
  }while(choice==1||choice==2||choice==3);
return 0;
}
