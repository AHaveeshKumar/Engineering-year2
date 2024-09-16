//program an pointers and arrays
#include<stdio.h>
int main()
{
	int x[5]={1,2,3,4,5};
	void display(int *,int);
	
	display(x,5);
}

void display(int *a,int n)
{
	int i;
	printf("The address of the elemnts of the array.\n");
	for(i=0;i<n;i++)
	{
	   printf("\nthe address of the %d element = %u",i, (a+i));
	   printf("The value of the %d element = %d",i, *(a+i));
	}
}
	
	
	
	
	
	