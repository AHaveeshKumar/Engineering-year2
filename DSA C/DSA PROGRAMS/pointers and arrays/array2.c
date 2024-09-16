//program on pointers and array
#include<stdio.h>
int main()
{
	int x[5]={1,2,3,4,5};
	
	int *ptr;
	for(ptr=&x[0];ptr<=&x[4];ptr++)
		printf("%d  ",*ptr);
}
//prints 	1,2,3,4,5