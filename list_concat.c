#include<stdlib.h>
#include<stdio.h>

struct node
{
	int data;
  	struct node *next;
};
typedef struct node *Node;

Node getnode()
{
  	Node x;
  	x=(Node) malloc (sizeof(Node));
  	if(x!=NULL)
    	return x;
  	else
    	{
      		printf("Memory is not allocated");
      		exit(0);
    	}
}


Node insert(Node first,int item)
{
  	Node temp,x;
  	x=getnode();
  	x->data=item;
  	x->next=NULL;
  	if(first==NULL)
     		return x;
  	temp=first;
  	while(temp->next!=NULL)
     		temp=temp->next;
  	temp->next=x;
  	return first;
}

Node concat(Node first1,Node first2)
{ 
	Node temp,x;
	if(first1 != NULL&&first2 != NULL)
	{temp=first1;
	while(temp->next!=NULL)
	{
	temp=temp->next;
	}
	temp->next=first2;
	return first1;
	}
	else
	printf("Node is null ");
}

Node sort(Node first)
{
	Node temp,x,i,j;
	int val; 
	if(first!=NULL)
	{x=first;
	
	temp=first;
	for(i=temp;i!=NULL;i=i->next)
	{for(j=i->next;j!=NULL;j=j->next)
	{
	if(i->data > j->data)
	{
	val=i->data;
	i->data=j->data;
	j->data=val;
	}}
	}
	}
	return first;
}

  
void display(Node first)
{
	Node temp;
  	if(first==NULL)
    	{
      		printf("list is empty\n");
    	}
  	else
    	{
      		temp=first;
      		printf("Element in the list: ");
      		while(temp!=NULL)
        	{
          		printf("%d ",temp->data);
          		temp=temp->next;
         	}
      		printf("\n");
     	}
}

int main()
{
  Node first1=NULL;
  Node first2=NULL;
  int ch,ch1,value;


printf("Enter 1 for sort 2 for concatinate 3 for exit ");
scanf("%d",&ch);
switch(ch)
{      
case 1: {printf("Enter list data : ");
  	do
  	{scanf("%d",&value);
  	 first1=insert(first1,value);
  	 printf("Do you want to add one more node...? Press 1 : ");
  	 scanf("%d",&ch1);
  	}while(ch1==1);
	printf("Before sorting ");
	display(first1);
	first1=sort(first1);
	printf("After sorting ");
	display(first1);
	}break;
case 2:	{printf("Enter first list : ");
  	do
  	{scanf("%d",&value);
  	 first1=insert(first1,value);
  	 printf("Do you want to add one more node...? Press 1 : ");
  	 scanf("%d",&ch1);
  	}while(ch1==1);
  
 	 printf("Enter second list : ");
 	 do
 	 {scanf("%d",&value);
 	  first2=insert(first2,value);
 	  printf("Do you want to add one more node...? Press 1 : ");
 	  scanf("%d",&ch1);
 	 }while(ch1==1);
	printf("List 1 : ");
	display(first1);
	printf("\nList 2 : ");
	display(first2);
	first1=concat(first1,first2);
	printf("\nList after merging : ");
	display(first1);
 	 }break;

}
	
return 0;
}
