//program on pointers and arrays
#include<stdio.h>
int main()
{
	int x[5]={1,2,3,4,5};
	
	int *ptr;
	for(ptr=x+4;ptr>=x;ptr--)
		printf("%d  ",x[ptr-x]);
}

//prints 5 4 3 2 1	