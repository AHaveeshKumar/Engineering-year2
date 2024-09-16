
#include"list.h"

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
			  
			  
		  
		  
		  
	  




		
  		
		  
		  
		  
			  
		  
		  
		  
		  
		  
		  
		  
		  
		
		
		
		
	