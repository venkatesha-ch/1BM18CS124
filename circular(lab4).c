#include<stdio.h>

#define max 4

void enqueue(int *queue,int *front,int *rear,int *cunt,int item)
{
	
	if((*cunt)<(max))
	{	if((*front)==-1)
	       	{(*front)++;(*rear)++;}
		if(((*rear)+1)%max==*front){printf("Queue over flow\n");return;}
		else {queue[(*rear)]=item;
		(*rear)=((*rear)+1)%max;
		(*cunt)++;}
	}

	else if((*cunt)==max)
	
		printf("Over flow \n");
}


void disp(int *queue,int *front,int *rear,int *cunt)
{	int i;
	if((*cunt)==0)
	  printf("Empty queue \n");
	else	
	{
		if((*front)<(*rear))
			for(i=(*front);i<(*rear);i++)
			printf("%d  ",queue[i]);
		else
		if((*front)>(*rear))
		{
		for(i=0;i<(*rear);i++)
			printf("%d  ",queue[i]);
		for(i=(*front);i<max;i++)
			printf("%d  ",queue[i]);
	}}
	
}	

void dequeue(int *queue,int *front,int *cunt)
{
	
	if(*cunt==0)
		printf("Queue empty\n");
	else
	{	*front=((*front)+1)%max;
		(*cunt)--;
	}

}


int main()
{	
	int choice,queue[max];
	int front=-1;int rear=-1;int cunt=0;int item;
	do
	{printf("Press\n 1 for enqueue\n 2 for dequeue\n 3 for display  : ");
        scanf("%d",&choice);
        switch(choice)
        {case 1:{printf("Enter the value : ");
		scanf("%d",&item);
		enqueue(queue,&front,&rear,&cunt,item);}
               	break;
		
        case 2:dequeue(queue,&front,&cunt);
               break;
	case 3:disp(queue,&front,&rear,&cunt);break;
        }
	}while(choice==1||choice==2||choice==3);
	printf("Thank you\n");
return 0;
}
