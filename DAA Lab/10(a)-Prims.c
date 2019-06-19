#include<stdio.h>

void main()
{
	int i,j,a,b,min,n,ne=1;

	printf("\nEnter no. of vertices\n");
	scanf("%d",&n);

	int cost[n][n],vis[n];

	printf("\nEnter cost matrix\n");
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			scanf("%d",&cost[i][j]);

	for(i=0;i<n;i++)
		vis[i]=0;

	vis[0]=1;
	
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
					if(vis[i] ==0)
						continue;
					
					else
					{
						min=cost[i][j];
						a=i;
						b=j;
					}
				}
			}
		}

	

		if(vis[a]==0 || vis[b] ==0)
		{
			printf("\n %d->%d=%d",a,b,min);
			vis[b]=1;
			ne++;
		}
		cost[a][b]=cost[b][a]=999;
	}
}











