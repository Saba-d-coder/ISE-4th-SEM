//Program to print all nodes reachable from a given starting node in a digraph using BFS

#include<stdio.h>
#define S 20

int q[S],vis[S],adj[S][S],r=-1,f=0,s,n;

void insert(int v)
{
	q[++r]=v;
}

int del()
{
	return q[f++];
}

int Empty()
{
	if(r<f)
		return 1;
	else
		return 0;
}

void BFS(int v)
{
	int w;
	vis[v]=1;
	insert(v);
	
	while(!Empty())
	{
		v=del();
		
		for(w=0;w<n;w++)
			if(adj[v][w]==1 && vis[w]==0)
			{
				vis[w]=1;
				printf("v%d\t",w);
				insert(w);
			}
			
			
	}
	
	for(int i=0;i<n;i++)
		if(vis[i]==0)
		 printf("\n node %d\t is not reachable",i); 
}

void main()
{
	int v,w;
	printf("\n Enter no. of vertices\n");
	scanf("%d",&n);
	
	printf("Enter adjacency matrix:\n");
	
	for(v=0;v<n;v++)
	{
		for(w=0;w<n;w++)
		scanf("%d",&adj[v][w]);
	}
	
		
	printf("enter starting node:");
	scanf("%d",&s);
	
	for(v=0;v<n;v++)
		vis[v]=0;
	
	printf("Nodes reachable from %d are:",s);
	
	printf("\n v%d\t",s);
		
	BFS(s);
	
}

