#include <stdio.h>
#include<stdlib.h>
struct student
	{
		char name[100];
		int srn;
		char address[100];
	};
typedef struct student student_t;
int main()
{
    void display(student_t *);
	
    student_t s;
	
   printf("Enter the name..\n");
   scanf("%s",s.name);
   printf("Enter the srn\n");
   scanf("%d",&s.srn);
   printf("Enter the adress..\n");
   scanf("%s",s.address);
   
   display(&s); // pass address of structure to display
   
}
   
   void display( student_t *p)
   {
	printf("The details are..\n");
    	printf("%s\n",p->name);
	printf("%d\n",p->srn);
	printf("%s\n",p->address);
   }

	
	   
   

	


	