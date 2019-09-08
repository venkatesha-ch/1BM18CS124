#include<stdio.h>

#define max 5

int queue[max];
int front=-1;int rear=-1;int cunt=0;int num=0,num1=0;


void enqueue()
{
	
	if(cunt<=(max-1))
	{	if(front==-1)
	       	{front++;rear++;}
		queue[rear]=++num;
		rear=(rear+1)%max;
		printf("Job %d queued.....!\n",num);
		cunt++;
	 	printf("Total pending jobs : %d\n",cunt);

		}

	else
		printf("Over job.....!\n");
}


void dequeue()
{
	
	if(cunt==0)
		printf("No job......!\n");
	else
	{	num1++;
		front=(front+1)%max;
		cunt--;
		printf("Job %d completed.....!\n",num1);
		printf("Total pending jobs : %d \n",cunt);
	}

}


int main()
{	
	int choice;
	do
	{printf("Press\n 1 for enqueue a job\n 2 for dequeue a job  : ");
        scanf("%d",&choice);
        switch(choice)
        {case 1:enqueue();
                break;
        case 2:dequeue();
               break;
        }
	}while(choice==1||choice==2);
	printf("Thank you\n");
return 0;
}

