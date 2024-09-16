//implementation of doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int key;
  struct node *next;
  struct node *prev;
  };
  
  typedef struct node node_t;
  
  struct dlist
  {
	  node_t* head;
  };
  
  typedef struct dlist dlist_t;
  
  void init_list(dlist_t*);
  void insert_head(dlist_t*,int);
  void display(dlist_t*);
  void insert_tail(dlist_t*,int);
  void delete_first(dlist_t*);
  void delete_last(dlist_t *);
  void delete_node(dlist_t*, int);
  void delete_pos(dlist_t*,int);
  void insert_pos(dlist_t*,int,int);
  void insert_after(dlist_t*, int, int);
   void insert_before(dlist_t*, int, int);
   
   int main()
{
	int ch,key,pos,value;
	dlist_t l;
	init_list(&l);

    while(1)
	{
		display(&l);
		printf("\n1..insert_head");
		printf("\n2..insert_tail");
		printf("\n3..Display");
		printf("\n4.delete first node");
		printf("\n5. Delete Last Node..");
		printf("\n6 .Delete a node given value");
		printf("\n7.Delete at a position");
		printf("\n8.Insert at a Given Position");
		printf("\n9. Insert after given value..\n");
		printf("\n10. Insert before given value..\n");
		printf("\n11.Exit");
		
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\nEnter the key...");
			             scanf("%d",&key);
			            insert_head(&l,key);
			            break;
			case 2:printf("\nEnter the key...");
			             scanf("%d",&key);
			              insert_tail(&l,key);
			              break;			 
		  	case 3:display(&l);
			             break;
			case 4:delete_first(&l);
              			 break;		
			/*case 5:delete_last(&l);
              			break;				
		 	case 6:printf("\nEnter the key...");
			             scanf("%d",&key);
			             delete_node(&l,key);	
                        			 break;	
		 	 case 7:printf("\nEnter the position");
			             scanf("%d" ,&pos);
			            delete_pos(&l,pos);
			            break;	
			case 8:printf("\nEnter the key and position");
			             scanf("%d %d" ,&key,&pos);
			              insert_pos(&l,key,pos);
			             break;
			/*case 9:printf("\nEnter the value and key");
			             scanf("%d %d" ,&value,&key);
			            insert_after(&l,value,key);
			            break;		 
			case 10:printf("\nEnter the value and key");
			             scanf("%d %d" ,&value,&key);
			           insert_before(&l,value,key);
			           break;	*/ 
			case 11:exit(0);
		}
	}
}

  void init_list(dlist_t *ptr_list)
  {
	  ptr_list->head=NULL;
  }
   
     void insert_head(dlist_t *ptr_list, int x)
	 {
		 node_t *temp,*pres;
		 //create node
		 temp=(node_t*)malloc(sizeof(node_t));
		 temp->key=x;
		 temp->prev=temp->next=NULL;
		 
		 //is the list empty?
		 if(ptr_list->head==NULL)
			 ptr_list->head=temp;
		 else //not an empty list
		 {
			 pres=ptr_list->head;
			 temp->next=pres;
			 pres->prev=temp;
			 ptr_list->head=temp;
		 }
	 }
			 
	void display(dlist_t *ptr_list)
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
			  printf("%d<-->",pres->key);
			  pres=pres->next;
		  }
	  }
	}
			 
			 
		 void insert_tail(dlist_t* ptr_list,int x)
		 {
			 node_t *temp,*pres;
		 //create node
		 temp=(node_t*)malloc(sizeof(node_t));
		 temp->key=x;
		 temp->prev=temp->next=NULL;
		 
		 //is the list empty?
		 if( ptr_list->head==NULL)
		     ptr_list->head=temp;
		 else
		 {
			 pres=ptr_list->head; //copy the address of the first node
			 //go to the last node
			 while(pres->next!=NULL)
				   pres=pres->next;
			   
			   //link the new node to the last node
			   pres->next=temp;
			   temp->prev=pres;
		   }
		 }	 
			   
		 void delete_first(dlist_t* ptr_list)
		 {
			   node_t *pres;
			   //is the list empty ?
               			 if(ptr_list->head==NULL)
			       printf("Empty list cannot delete");
			else //list not empty
			    {
			       pres=ptr_list->head;
			      if(pres->next==NULL) //only one node in the list
			         ptr_list->head=NULL;
			       else
			          {
				ptr_list->head=pres->next;
				ptr_list->head->prev=NULL;
			          }
			      free(pres);
			}
		 }

						 
					
					
				
				
  

			 
		 
			 
		 
		 
		 
		 
		 
		 
		 
		 
      
      	