#include<stdio.h>
#include<stdlib.h>
struct node
{
	int key;
	struct node *link;
};
typedef struct node node_t;

struct list
{
	node_t *head;
};
typedef struct list list_t;
void init_list(list_t*);
void insert_end(list_t*, int);
void display(list_t*);
int main()
{
   list_t l;
   int ch,n;
   init_list(&l);
   
   while(1)
   {
	   display(&l);
	   printf("\n1..Insert at end");
	   printf("\n2..display");
	   printf("\n3..Exit");
	   scanf("%d",&ch);
	   switch(ch)
	   {
		   case 1: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						insert_end(&l,n);
						break;  
						
		  case 2:display(&l);
		               break;
	    }
    }				  
}		


void init_list(list_t *ptr_list)
{
	ptr_list->head=NULL;
}
	
	void insert_end( list_t *ptr_list, int x)
	{
		  node_t *temp,*pres;
		  //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		  
		  //is the list empty ?
		  if(ptr_list->head==NULL)
			  ptr_list->head=temp;
		  else
		  {
			  pres=ptr_list->head;//copy the address of the first node;
			  //go to the last node
			  while(pres->link!=NULL)
				      pres=pres->link;
			  pres->link=temp;
		  }  
	}
			  
			  
	void display(list_t *ptr_list)
    {
      node_t *pres;
	  //if list empty ?
	  if(ptr_list->head==NULL)
	     printf("\nEmpty list");
      else
	  {
		  pres=ptr_list->head;
		  //move along the list and the print the key value
		  //till the end of the list
		  while(pres!=NULL)
		  {
			  printf("%d-->",pres->key);
			  pres=pres->link;
		  }
	  }
	}
			  
			  
		  