//program to dynamically allocate array
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n,i;
	int *a;
	printf("Enter the no of elemnts...\n");
	scanf("%d",&n);
	
	a=(int*)malloc(sizeof(int)*n);//dynamically allocate memory for n elements
	printf("Enter the Values..\n");
	/*for(i=0;i<5;i++)
		scanf("%d",&a[i]);*/
	for(i=0;i<5;i++)
		scanf("%d",(a+i));
	
	printf("The values entered in the array are...\n");
	for(i=0;i<5;i++)
		printf("%d  ",a[i]);
}
	
	
	

	
	
	

	