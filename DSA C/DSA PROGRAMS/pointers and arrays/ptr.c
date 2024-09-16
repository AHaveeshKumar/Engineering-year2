//program to demonstrate pointers
#include <stdio.h>
int main()
{
	int x=10;
	int *y;
	int **z;
	y=&x;
	
	printf("x= %d",x);
	printf("\nThe address of x = %p",&x);
	printf("\nThe value of x = %d", *(&x));
	printf("\nThe value of x = %d", *y);
	
	z=&y;
	
	printf("\nThe address of z = %p",&z);
	printf("\nThe value contained in z = %p",z);
	
	printf("the value of x = %d",**z);
}
	