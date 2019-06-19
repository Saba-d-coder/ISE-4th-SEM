//Program to find the order in which all the nodes of a graph are traversed using Depth First Search(DFS) traversal

#include<stdio.h>
int G[10][10],vis[10],n;

void DFS(int v)
{
	int j;
	
	printf("%c ",v+64);
	// mark node v as visited
	vis[v]=1;

	for(j=1; j<=n; j++)
	{
		// if node j is not visited and there exists a path from node v to j
		if(!vis[j] && G[v][j])
			DFS(j);
		
	}
}

void main()
{
	int i,j,s;
	printf("enter no. of vertices\n");
	scanf("%d",&n);
	
	printf("\nenter the adjacency matrix\n");
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&G[i][j]);

	printf("\nEnter the source node: ");
        scanf("%d",&s);

    	if(s>0 && s<=n) //to check if the source node is present in the graph or not
   	 {
       		 printf("\nThe order in which the vertices are visited:\n");
       		
		 for(i=s;i<=n;i++)
            		if(!vis[i])
            		{
              		  DFS(i); //call the function for the vertex which isn't visited
               		  printf("\n");
            		}
        
		 for(i=1;i<s;i++)
           		 if(!vis[i])
            		 {
                		DFS(i); //call the function for the vertex which isn't visited
                		printf("\n");
           		 }
    	}
    	
	else
	        printf("\nSource node not found!");
}
