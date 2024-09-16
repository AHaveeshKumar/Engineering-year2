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
	node_t *rear;
};
typedef struct list list_t;
void init_list(list_t*);
void insert_end(list_t*, int);
void insert_start(list_t*, int);
void display(list_t*);
void del(list_t*, int);
void delp(list_t*, int);
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
	   printf("\n3..insert at start");
	   printf("\n4..delete");
	   printf("\n5.delete given position");
	   scanf("%d",&ch);
	   switch(ch)
	   {
		   case 1: printf("\nEnter the element to be inserted..");
		                 scanf("%d",&n);
						insert_end(&l,n);
						break;  
						
		  case 2:display(&l);
		               break;
		  case 3: printf("enter element to be inserted");
		                 scanf("%d", &n);
		                 insert_start(&l,n);
		                 break;
		  case 4: printf("enter element to be deleted");
		                 scanf("%d", &n);
		                 del(&l, n);
		                 break;
		  case 5: printf("enter element to be deleted");
		                 scanf("%d", &n);
		                 delp(&l, n);
		                 break;
	    }
    }				  
}		
void init_list(list_t *ptr_list)
{
	ptr_list->head=NULL;
	ptr_list->rear=NULL;
}
void del(list_t *ptr_list, int x){
    node_t *pres, *temp;
    if(ptr_list->head==NULL){
        printf("empty");
    }
    else{
        pres=ptr_list->head;
        temp=NULL;
        while((pres!=NULL)&&(pres->key!=x)){
            temp=pres;
            pres=pres->link;
        }
        if(temp==NULL)
            ptr_list->head=pres->link;
        else{
            temp->link=pres->link;
            free(pres);
        }
            
        
    }
        }
void delp(list_t *ptr_list, int x){
    node_t *pres, *temp;
    int count=1;
    if(ptr_list->head==NULL){
        printf("empty");
    }
    else{
        pres=ptr_list->head;
        temp=NULL;
        while((pres!=NULL)&&(count!=x)){
            temp=pres;
            pres=pres->link;
            count++;
        }
        if(temp==NULL)
            ptr_list->head=pres->link;
        else{
            temp->link=pres->link;
            free(pres);
        }
            
        
    }
        }
	void insert_end( list_t *ptr_list, int x)
	{
		  node_t *temp;
		  temp=(node_t*)malloc(sizeof(node_t));
		  temp->key=x;
		  temp->link=NULL;
		  if(ptr_list->head==NULL){
		      ptr_list->head=ptr_list->rear=temp;
		  }
		  else{
		      ptr_list->rear->link=temp;
		      ptr_list->rear=temp;
		  }
	}
	void insert_start(list_t *ptr_list, int x){
	    node_t *temp, *pres;
	    temp=(node_t*)malloc(sizeof(node_t));
		temp->key=x;
		temp->link=NULL;
		if(ptr_list->head==NULL){
		    ptr_list->head=temp;
		  }
		  else{
		      pres=ptr_list->head;
		      temp->link=pres;
		      ptr_list->head=temp;
		  }
	}
	void display(list_t *ptr_list)
    {
      node_t *pres;
	  if(ptr_list->head==NULL)
	     printf("\nEmpty list");
      else
	  {
		  pres=ptr_list->head;
		  while(pres!=NULL)
		  {
			  printf("%d-->",pres->key);
			  pres=pres->link;
		  }
	  }
}