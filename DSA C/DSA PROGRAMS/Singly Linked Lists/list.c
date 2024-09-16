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
void insert_head(list_t*, int);
void delete_last(list_t*);
void delete_first(list_t*);
void display(list_t*);
void delete_node(list_t *,int);
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
	   printf("\n3..Insert at head");
	   printf("\n4..delete_last");
	   printf("\n5.delete firs");
	   printf("\n6..delete node");
	   scanf("%d",&ch);
	   switch(ch)
	   {
		   case 1: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						insert_end(&l,n);
						break;  
						
		  case 2:display(&l);
		               break;
		
		 case 3: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						insert_head(&l,n);
						break;  
			case 4:delete_last(&l);
						break;  			
			case 5:delete_first(&l);
						break;
			case 6:printf("\nEnter the element to be deleted..");
		                 scanf("%d",&n);
						 delete_node(&l,n);
	    }
    }				  
}		


void init_list(list_t *ptr_list)
{
	ptr_list->head=NULL;
}
	
	void insert_head(list_t *ptr_list, int x)
	{
		  node_t *temp,*pres;
		  //create and populate the node
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		
		 	temp->link=ptr_list->head;
			 ptr_list->head=temp;
		 
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
			  
		void delete_last(list_t * ptr_list)
        {		
		  node_t *pres,*prev;
		  //check if the list empty ?
		  
		  if(ptr_list->head==NULL)
		   printf("Empty list..cannot delete");
	   else
	   {
		  
		   pres=ptr_list->head; //copy the address of the first Node
		   prev=NULL;
		    //move to the last node
		  while(pres->link!=NULL)
		  {
			  prev=pres;
			  pres=pres->link;
		  }
		  if(prev==NULL) //only one node in the list
		    ptr_list->head=NULL;
		else
		    prev->link=NULL;
		  free(pres);
	     }
		}	  
		  
        void delete_first(list_t *ptr_list)
		{
			node_t *pres;
			pres=ptr_list->head;
			if(pres==NULL)
				printf("Empty list..cannot delete");
			else
			{
			  ptr_list->head=pres->link; //copy the address of the secon node
              free(pres);
			}
		}
				
        void delete_node(list_t * ptr_list, int x)
		{
			node_t *pres,*prev;
			//is list empty
			if(ptr_list->head==NULL)
				printf("Empty list..cannot delete..");
			else
			{
				pres=ptr_list->head; //get the address of the first node
				prev=NULL;
			    //move forward until the node is found
				//or go beyond the last node
			    while((pres!=NULL)&&(pres->key!=x))
				{
					prev=pres;
					pres=pres->link;		
				}
				if(pres==NULL)
					printf("Node not found.");
				else//node found
				{
				  if(prev==NULL)//check whether it is first node
                     ptr_list->head=pres->link;//make head point to second node
				 else
				    prev->link=pres->link;
				 free(pres);
				}
			}
		}
			
				  
	  /* 
	  The file list.c contains a C program that implements a singly linked list. I'll break down the code step by step for you:

1. Header Files
c
Copy code
#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>: This includes the standard input-output library, which allows the use of functions like printf and scanf.
#include<stdlib.h>: This includes the standard library, which provides functions like malloc and free for dynamic memory allocation.





2. Node and List Structures
c
Copy code
struct node {
    int key;
    struct node *link;
};
typedef struct node node_t;

struct list {
    node_t *head;
};
typedef struct list list_t;



struct node: Defines a node in the linked list, which contains an integer key and a pointer link to the next node.
typedef struct node node_t: Defines node_t as an alias for struct node.
struct list: Defines a linked list structure with a pointer head that points to the first node in the list.
typedef struct list list_t: Defines list_t as an alias for struct list.




3. Function Declarations
c
Copy code
void init_list(list_t*);
void insert_end(list_t*, int);
void insert_head(list_t*, int);
void delete_last(list_t*);
void delete_first(list_t*);
void display(list_t*);
void delete_node(list_t *,int);
These are the function declarations for various operations on the linked list, including initialization, insertion, deletion, and display.
4. Main Function
c
Copy code
int main() {
    list_t l;
    int ch, n;
    init_list(&l);
    
    while(1) {
        display(&l);
        printf("\n1..Insert at end");
        printf("\n2..display");
        printf("\n3..Insert at head");
        printf("\n4..delete_last");
        printf("\n5.delete firs");
        printf("\n6..delete node");
        scanf("%d", &ch);
        switch(ch) {
            case 1: 
                printf("\nEnter the element to be inserted..");
                scanf("%d", &n);
                insert_end(&l, n);
                break;
            case 2:
                display(&l);
                break;
            case 3: 
                printf("\nEnter the element to be inserted..");
                scanf("%d", &n);
                insert_head(&l, n);
                break;
            case 4:
                delete_last(&l);
                break;
            case 5:
                delete_first(&l);
                break;
            case 6:
                printf("\nEnter the element to be deleted..");
                scanf("%d", &n);
                delete_node(&l, n);
                break;
        }
    }
}
init_list(&l);: Initializes the linked list.
The while(1) loop continuously displays a menu for the user to perform operations on the linked list. The user can choose to insert, delete, or display elements based on the input.
5. Function Definitions
Initialization:

c
Copy code
void init_list(list_t *ptr_list) {
    ptr_list->head = NULL;
}
Sets the head of the list to NULL, indicating that the list is initially empty.
Insert at Head:

c
Copy code
void insert_head(list_t *ptr_list, int x) {
    node_t *temp;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->key = x;
    temp->link = ptr_list->head;
    ptr_list->head = temp;
}
Creates a new node with the given key x.
Inserts the new node at the beginning of the list by adjusting the head pointer.
Insert at End:

c
Copy code
void insert_end(list_t *ptr_list, int x) {
    node_t *temp, *pres;
    temp = (node_t*)malloc(sizeof(node_t));
    temp->key = x;
    temp->link = NULL;
    if (ptr_list->head == NULL)
        ptr_list->head = temp;
    else {
        pres = ptr_list->head;
        while (pres->link != NULL)
            pres = pres->link;
        pres->link = temp;
    }
}
Creates a new node with the given key x.
Traverses to the end of the list and appends the new node.
Delete Last Node:

c
Copy code
void delete_last(list_t *ptr_list) {
    node_t *pres, *prev;
    if (ptr_list->head == NULL)
        printf("Empty list..cannot delete");
    else {
        pres = ptr_list->head;
        prev = NULL;
        while (pres->link != NULL) {
            prev = pres;
            pres = pres->link;
        }
        if (prev == NULL)
            ptr_list->head = NULL;
        else
            prev->link = NULL;
        free(pres);
    }
}
Deletes the last node in the list by adjusting the pointers.
Delete First Node:

c
Copy code
void delete_first(list_t *ptr_list) {
    node_t *pres;
    pres = ptr_list->head;
    if (pres == NULL)
        printf("Empty list..cannot delete");
    else {
        ptr_list->head = pres->link;
        free(pres);
    }
}
Deletes the first node by moving the head pointer to the next node.
Delete Specific Node:

c
Copy code
void delete_node(list_t *ptr_list, int x) {
    node_t *pres, *prev;
    if (ptr_list->head == NULL)
        printf("Empty list..cannot delete..");
    else {
        pres = ptr_list->head;
        prev = NULL;
        while ((pres != NULL) && (pres->key != x)) {
            prev = pres;
            pres = pres->link;
        }
        if (pres == NULL)
            printf("Node not found.");
        else {
            if (prev == NULL)
                ptr_list->head = pres->link;
            else
                prev->link = pres->link;
            free(pres);
        }
    }
}
Deletes a node with a specific key x by traversing the list and adjusting the pointers accordingly.
Display List:

c
Copy code
void display(list_t *ptr_list) {
    node_t *pres;
    if (ptr_list->head == NULL)
        printf("List is empty");
    else {
        pres = ptr_list->head;
        while (pres != NULL) {
            printf("%d-->", pres->key);
            pres = pres->link;
        }
        printf("NULL\n");
    }
}
Traverses the list and prints each node's key, showing the structure of the list.
			  */
			  
		  
		  
		  
			  
			  
		  
	  
	  
	  
	  
	  
	  
	  
	  
		  
		  
	  
			


			
	  




		
  		
		  
		  
		  
			  
		  
		  
		  
		  
		  
		  
		  
		  
		
		
		
		
	