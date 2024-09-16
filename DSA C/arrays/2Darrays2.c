#include<stdio.h>
#include<stdlib.h>
void display(int **p,int rows, int cols);
int main(){
	int rows=3;
	int cols=4;
	int **p;
	int i,j;

	p=(int**)malloc(sizeof(int*)*rows);
	for(i=0;i<rows;i++)
		p[i]=(int**)malloc(sizeof(int)*cols);

	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++)
			scanf("%d",&p[i][j]);
	}

	display(p,rows,cols);

}

void display(int **p,int rows,int cols){
	printf("The elements of the array are: \n");
	int i,j;
	for(i=0;i<rows;i++){
		for(j=0;j<cols;j++)
			printf("%d  ",p[i][j]);
		printf("\n");
	}
}