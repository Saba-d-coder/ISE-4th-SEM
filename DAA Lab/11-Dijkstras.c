//Program to find the shortest paths to every vertex from a single source from the given weighted connected graph entered as a cost matrix

#include<stdio.h>
#include<stdlib.h>

int cost[20][20];
void dijkstra(int n,int source)
{
	int dis[20],visited[20],count,min,nextnode,i,j;
	for(i=1;i<=n;i++)
	{
		dis[i]=cost[source][i]; //initializing dis[] with the respective distances from the source
		visited[i]=0;   // all nodes are not visited 
	}

	dis[source]=0;  //distance of source from itself is 0
	visited[source]=1; //source is visited,marking it as 1
	count=1; //1 node is visited(source)

	while(count<n) //loops until all the nodes are visited
	{
		min=999;
		//nextnode gives the node at minimum distance
		for(i=1;i<=n;i++)
			if(dis[i]<min && !visited[i])
			{
				min=dis[i];
				nextnode=i;
			}

			//checking if a better path exists via nextnode
			visited[nextnode]=1;
			for(i=1;i<=n;i++)
				if(!visited[i])
					if(min+cost[nextnode][i]<dis[i])
						dis[i]=min+cost[nextnode][i];
		count++;
	}

	//printing distance of each node from the source node
	for(i=1;i<=n;i++)
		if(i!=source)
			printf("\nDistance of node %d from %d = %d",i,source,dis[i]);
}

int main()
{
	int i,j,n,source;
	printf("Enter no. of vertices:");
	scanf("%d",&n);
	printf("\nEnter the cost matrix:\n");

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
		{
		    scanf("%d",&cost[i][j]);
		}

	printf("\nEnter the starting node:");
	scanf("%d",&source);
	dijkstra(n,source); //calling the function

	return 0;
}
