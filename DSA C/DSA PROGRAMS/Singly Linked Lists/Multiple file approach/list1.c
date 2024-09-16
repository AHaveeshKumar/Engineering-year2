//Another implementation of insertion at end 
//list has another pointer (rear) that points to the last node
#include"list1.h"

void init_list(list_t *ptr_list)
{
	ptr_list->head=NULL;
	ptr_list->rear=NULL;
}
	
	void insert_end( list_t *ptr_list, int x)
	{
		 node_t *temp,*last; 
		  
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		  
		  //is this the first node ?
		  if(ptr_list->head==NULL)
		  {
				ptr_list->head=ptr_list->rear=temp;
		  }
		  else
		  {
			  last = ptr_list->rear;
			  last->link=temp;
			  ptr_list->rear=temp;
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
			  
			  
		  
		  
		  
	  




		
  		
		  
		  
		  
			  
		  
		  
		  
		  
		  
		  
		  
		  
		
		
		
		
	