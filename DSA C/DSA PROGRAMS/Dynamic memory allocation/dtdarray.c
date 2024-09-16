#include <stdio.h>
#include<stdlib.h>
//program to dynamically create a 2d array
void display(int **,int , int);
int main()
{
	int i,j;
	int rows=3;
	int cols=4;
	int **p;
	 
	 p=(int**)malloc(sizeof(int*)*rows);
	
	for(i=0;i<rows;i++)
		 p[i]=(int*) malloc(sizeof(int)*cols);
	//enter the elements into the array
	
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
			scanf("%d",&p[i][j]);//or (p[i]+j)
	}
	
	display(p,rows,cols);
}
	
void display(int **p, int r, int c)
{
  int i,j;
  printf("The elements of the array are..\n");
  for(i=0;i<r;i++)
  {
	  for(j=0;j<c;j++)
		  printf("%d  ",p[i][j]);
	  printf("\n");
  }
}
  
	
	
	

	