#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define S 10    
int n;

// min function to calculate minimum of 2 numbers
int min(int a,int b)
{
	if(a<b)
		return a;
	else 
		return b;
}

//function named Floyd to find transitive closure
void Floyd(int A[S][S])
{
	int i,j,k;
			
	for(k=0;k<n;k++)		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				A[i][j]=min(A[i][j] ,(A[i][k]+A[k][j])); 
			
		
	//displaying the matrix
	printf("\n Matrix of all-pairs-shortest path is\n");
	
	for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%d\t",A[i][j]);
		
			printf("\n");
		}		
	
}

void main()
{
	int i,j,A[S][S];
	
	printf("\nEnter no. of vertices\n");
	scanf("%d",&n);
	
	
	printf("\nEnter the adjacency matrix\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
	 		scanf("%d",&A[i][j]);
	 		
	//Calling Floyd function
	Floyd(A);
}
