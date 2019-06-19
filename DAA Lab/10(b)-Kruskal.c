#include<stdio.h>

void main()
{
	int i,j,a,b,u,v,min,n,ne=1;

	printf("\nEnter no. of vertices\n");
	scanf("%d",&n);

	int cost[n][n],parent[n];

	printf("\nEnter cost matrix\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cost[i][j]);

	for(i=0;i<n;i++)
		parent[i]=0;

	
	
	printf("Minimum spanning tree is\n");
	while(ne<n)
	{
		min=999;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(cost[i][j] < min)
				{
					min=cost[i][j];
					a=u=i;
					b=v=j;
					
				}
			}
		}

	while(parent[u])
		u=parent[u];

	while(parent[v])
		v=parent[v];

		if(u!=v)
		{
			printf("\n %d->%d=%d",a,b,min);
			parent[v]=u;
			ne++;
		}
		cost[a][b]=cost[b][a]=999;
	}
}











