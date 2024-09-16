//program to create an ordered list
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
void display(list_t *);
void insert_order(list_t *, int);

int main()
{
   list_t l;
   init_list(&l);
   int n;
   while(1)
  {
	   printf("\nEnter the element<0 to end>");
	   scanf("%d",&n);
	   if(n==0)
		   break;
	   insert_order(&l,n);
	   display(&l);
   }
}
  
  void init_list(list_t *ptr_list)
  {
	  ptr_list->head=NULL;
  }
  
  void insert_order(list_t *ptr_list, int x)
  {
	    node_t *temp,*pres, *prev;
	  
	  //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
	 
	    	  pres=ptr_list->head; //copy the address of the first node
		  prev=NULL;
		  while((pres!=NULL) &&(x>pres->key))
		  {
              			prev=pres;
			pres=pres->link;
		  }
		  if(pres!=NULL) 
		  {
			  if(prev!=NULL)//inserts x somewhere beween the first and last node
			  {
				  temp->link=pres;
				  prev->link=temp;
			  }
				else //prev=NULL
				{
					//insert x before the first node
					temp->link=pres;
					ptr_list->head=temp;
				}
		  }
		else //pres==NULL
		{		
                  	//empty list, insert x is the first node			
		    if(prev==NULL)
			ptr_list->head=temp; 
		          else
			prev->link=temp;//insert x at the end
		}
  }
			  

void display(list_t *ptr_list)
 {
	    node_t *pres;
	    //copy the addres of the first node
	    pres = ptr_list->head;

    	if(pres==NULL) //if empty list
	       printf("\nThe list is empty\n");
	   else
 	     {		
    	   printf("\n");
  	      //keep moving forward until you go beyond the last node
	      while(pres!=NULL)
	     {
		    printf("%d->",pres->key);
		    pres=pres->link; //copy the address of the next node
	      }
	}
 }
		  
	  
	  

	  
	  
	  
	  
	  
  
  