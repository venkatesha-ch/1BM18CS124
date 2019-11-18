#include<stdlib.h>
#include<stdio.h>

struct node
{
	int data;
  	struct node *next;
  	struct node *prev;
};
typedef struct node *Node;

Node getnode()
{
  	Node x;
  	x=(Node) malloc (sizeof(struct node));
  	if(x==NULL)
    	{
      		printf("Memory is not allocated");
      		exit(0);
    	}
    	return x;
}

Node insert(Node first,int item)
{
  	Node temp,x;
  	x=getnode();
  	x->data=item;
  	x->next=NULL;
  	x->prev=NULL;
  	if(first==NULL)
     		{first=x;
     		return first;
     		}
  	temp=first;
  	while(temp->next!=NULL)
     		temp=temp->next;
  	temp->next=x;
  	x->prev=temp;
  	return first;
}
Node insert_left(Node first,int item,int pos)
{
	int count=1;
	Node temp,curr,prev;
	temp=getnode();
	temp->data=item;
	temp->next=NULL;
	temp->prev=NULL;
	if(first==NULL && pos==1)
 		{
 		temp->prev=first;
 		return temp;
 		}
	if(first==NULL && pos!=1)
	printf("invalid\n");
	curr=first;
	prev=NULL;
	while(curr->next!=NULL&&count!=pos)
	{
	 	curr=curr->next;
	 	count++;
	}
	if(count==pos)
	{
		prev = curr;	
	 	curr=curr->prev;
	 	curr->next=temp;
	 	temp->prev=curr;
	 	temp->next=prev;
	 	return first;
	}
	else
	printf("NOT A VALID POSITION\n");
}	
Node delete_pos(Node first,int val)
{
	int count=1;
	Node curr,prev;
	if(first==NULL)
	printf("List is empty\n");
	 else
	 {
	 	curr=first;
	 	prev=NULL;
	 	while(curr->next!=NULL&&curr->data!=val)
	 	{
	 		prev=curr;
	 		curr=curr->next;
	 		count++;
	 	}
	 	if(curr->data==val)
	 	{
	 		printf("Item deleted \n");
	 		prev->next=curr->next;
	 		free(curr);
	 		return first;
	 	}
	 	else
	 	printf("NOT A VALID POSITION\n");
	 }
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
  Node first=NULL;
  int ch,value,pos;
  char ch1;
  while(1)
	{
		printf("1.Create a doubly list\n");
		printf("2.Insert a new node to left of the node\n");
		printf("3.Delete the node based on specifed value\n");
		printf("4.Display\n");
		printf("5.Exit\n");
		scanf("%d",&ch);
   		switch(ch)
       		{
         		case 1: do{printf("Enter the element to be inserted: ");
                 		scanf("%d",&value);
                 		first=insert(first,value);
                 		printf("Do you want to add one more node..?y/n");
                 		scanf("%c",ch1);
                 		}while(ch1=='y');
                 		break;
         		case 2: printf("Enter the element to be inserted: ");
                 		scanf("%d",&value);
                 		printf("Enter the position to be inserted: ");
              	 		scanf("%d",&pos);
                 		first=insert_left(first,value,pos);
                 		break;
          		case 3: printf("Enter the element to be Deleted: ");
          	     		scanf("%d",&value);
                 		first=delete_pos(first,value);
                 		break;        
         		case 4: display(first);
         			break;
         		case 5: exit(0);
         		default: printf("Invalid choice\n");
       }
    }
  return 0;
}
