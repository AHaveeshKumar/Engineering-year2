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
	void read(student_t*);
	student_t *s;
   	 s=(student_t*)malloc(sizeof(student_t)) ;//allocate memory for structure dynamically
	read(s); 
  	display(s);
   
}
   
   void read(student_t *p)
   {
	   
	   printf("Enter the details..");
	   printf("Enter the name...\n");
	   scanf("%s",p->name);
	   printf("Enter the srn...");
	   scanf("%d", &p->srn);
	   printf("Enter the address...\n");
	   scanf("%s",p->address);
   }
	   
	void display( student_t *p)
 	{
	printf("The details are..\n");
 	printf("%s\n",p->name);
	printf("%d\n",p->srn);
	printf("%s\n",p->address);
  	 }

	
	   
   

	


	