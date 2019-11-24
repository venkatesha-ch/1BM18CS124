#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

typedef struct node *node;

node getnode()
{
    node x;
    x = (node)malloc(sizeof(node));
    if(x == NULL)
    {
        printf("NO Node created!");
    }
    else
    {
        return x;
    }
}

node insert(node root, int val)
{
    node temp;
    temp = getnode();

    if(root==NULL)
    {
        temp->data = val;
        temp->left=NULL;
        temp->right=NULL;
        root = temp;

    }
    else
    {
        temp = root;
        if(val>temp->data)
        {
            temp->right=insert(temp->right ,val);
            
        }
        if(val<temp->data)
        {
            temp->left=insert(temp->left, val);
        }
    }
    return root;
}

void in_order(node root)
{
        if(root!=NULL)
        {
            in_order(root->left);
            printf("%d\t",root->data);
            in_order(root->right);
        }

}
void pre_order(node root)
{
        if(root!=NULL)
        {
            printf("%d\t",root->data);
	    pre_order(root->left);            
	    pre_order(root->right);
        }
}

void post_order(node root)
{
	if(root!=NULL)
	{
	    post_order(root->left);            
	    post_order(root->right);
	    printf("%d\t",root->data);
	}			
}
int main()
{
int ch , val;   
node root = NULL;
do
{	
printf("Press \n1 for insert \n2 for in order traverse \n3 for pre order travers \n4 for post order travers \n");
scanf("%d",&ch);
switch(ch)
{
  case 1 :printf("Enter the value to be inserted : ");
	  scanf("%d",&val);
	  root = insert(root,val);
          printf("\n");
	  break;
  case 2:if(root==NULL)
	 {printf("Empty tree");
		break;}
	 printf("In order traverse  : ");
         in_order(root);
         printf("\n");
         printf("\n");
         break;
  case 3:if(root==NULL)
	 {printf("Empty tree");
		break;}
	 printf("Pre order traverse  : ");
         pre_order(root);
         printf("\n");
         printf("\n");
         break;
  case 4:if(root==NULL)
	 {printf("Empty tree");
		break;}
	 printf("Post order traverse  : ");
         post_order(root);
         printf("\n");
         printf("\n");
         break;
}
}while(ch <5);
return 0;
}
