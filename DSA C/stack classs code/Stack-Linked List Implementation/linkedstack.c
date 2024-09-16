#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	struct node *link;
};
typedef struct node node_t;

struct stack
{
	node_t *top;
};

typedef struct stack stack_t;

void init(stack_t*);
void push(stack_t *, int);
int pop(stack_t*);
void display(stack_t*);
int main()
{
	stack_t st;
	int ch,key,k;
	
	init(&st);
	while(1)
	{
		display(&st);
		printf("\n1..push");
		printf("\n2.pop");
		printf("\n3. display");
		printf("\n4.exit");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("enter the element..");
						  scanf("%d",&key);
						  push(&st,key);
						  break;
			case 2: k=pop(&st);
						  if(k>0)
							    printf("The element popped = %d\n",k);
						  break;			  
			case 3: display(&st);
						break;
			case 4 : exit(0);
		}
	}
}

void init(stack_t*ptr_stk)
{
	ptr_stk->top=NULL;
}

void push(stack_t * ptr_stk, int  x)
{
	node_t *temp;
	//create a node
	temp=(node_t*)malloc(sizeof(node_t));
	temp->key=x;
	
	temp->link=ptr_stk->top;
	ptr_stk->top=temp;
}

int pop(stack_t* ptr_stk)
{
	int key;
	node_t *pres;
   if(ptr_stk->top==NULL)
	   return 0;
   else
   {
	   pres=ptr_stk->top; //get the first node
	   
	   key=pres->key;
	   ptr_stk->top=pres->link;
	   free(pres);
       return key;
   }
}
	   
void display(stack_t *ptr_stk)
{
  node_t *pres;

  pres=ptr_stk->top;

  if(pres==NULL)
     printf("\nEmpty stack..");
 else
 {
	 //traverse the list
	 while(pres!=NULL)
	 {
		 printf("%d->",pres->key);
		 pres=pres->link;
	 }
 }
}
	 
	 
	 
	  
	 
	 
	 
	 
	 
	 
	 
	 
	 
	
	
	
	