#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define S 10    
int n;

//function named Warshall to find transitive closure
void Warshall(int A[S][S])
{
	int i,j,k;
			
	for(k=0;k<n;k++)		
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				A[i][j]=A[i][j] || (A[i][k] && A[k][j]);
			
		
	//displaying the matrix
	printf("\nTransitive closure is\n");
	
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
	 		
	//Calling Warshall function
	Warshall(A);
}
