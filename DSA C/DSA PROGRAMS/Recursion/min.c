//recursive function to find the smallest element of an array
#include <stdio.h>
#include<stdlib.h>

int main()
{
	int min(int *, int);
	int a[5]={4,3,2,1,5};
	k=min(a,4);
	printf("Smallest element = %d",k);
}

  
  int min(int *a, int n)
  {
	  int k;
	  if(n==0)
		  return a[0];
	  k=min(a,n-1);  //find the smallest of n-1 elements
	  if(k<a[n]) 
		  return k;
	  return a[n];
  }
	  
	  
	  
	  




	