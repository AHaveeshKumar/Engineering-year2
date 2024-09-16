//program for towers of hanoi
#include<stdio.h>
  void main()
  {
   void toh(int, char, char, char);
   int n;
   printf("\nEnter the no of disks..");
   scanf("%d",&n);
   toh(n,'A','B','C');
   printf("\n");
   }

  void toh( int n, char src, char tmp, char dst)
  {
	  if(n==1)
		  printf("\nMove disc %d from %c to % c",n, src, dst);
	  else
	  {
		  toh(n-1,src,dst,tmp);
		  printf("\nMove disk %d form %c to % c",n,src,dst);
		  toh(n-1,tmp,src,dst);
	  }
		  
  }
  
  
  
	  
	  






 /*void toh(int n, char s, char t, char d)
 {
	 if(n==1)
	 {
		 printf("Move disk  % d form %c to %c\n", n,s,d);
		 return;
	 }
	 toh(n-1,s,d,t); // move n-1 disks from source to temp
	 printf("Move disk %d from %c to %c \n",n,s,d); // move nth disk from src to dest
	 toh(n-1,t,s,d); // move n-1 disk from temp to dest
 } */
 
	 
	 
	 
	 









  