#include"list1.h"
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



			  
		  
		  
		  
	  




		
  		
		  
		  
		  
			  
		  
		  
		  
		  
		  
		  
		  
		  
		
		
		
		
	