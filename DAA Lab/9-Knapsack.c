//Program to implement the 0/1 knapsack problem using dynamic programming technique(bottom up approach)

#include<stdio.h>

int p[10],wt[10],K[10][10],n,C;

//function to return maximum of two integers
int max(int a ,int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void Knapsack()
{
	int i,j,x[10];
	
	for(i=0;i<=n;i++)
		for(j=0;j<=C;j++)
		{
			if(i==0 || j==0)  // if there are no items and capacity is zero
				K[i][j]=0;

			if(wt[i]>j)  // if weight of item is greater than capacity of knapsack
				K[i][j]=K[i-1][j]; //retain the previous value only

			else
				K[i][j]= max(K[i-1][j], K[i-1][j-wt[i]] + p[i]); // assign the value which is maximum either the previous value or sum of present value and value when moving w[i] steps to the left in previous row 

		}
	
	
	int profit=K[n][C];
	i=n;j=C;x[0]=0;
	
	printf("\n Max profit is Rs:%d\n The optimal set of items are :\n",profit);
	
// looping from last element in table
	while(i>0 && j>0)
	{
		if(K[i][j]!=K[i-1][j])  // if previous value is not equal to current value
		{
			x[i]=1;   // marking the item which is selected
			j=j-wt[i]; // too check for next item we move w[i] steps back to the left 
		}
		i--; // previous row
	}

	for(i=1;i<=n;i++)
	{
		if(x[i]==1)
			printf("%d \t ",i);
	}

 
}


void main()
{
	int i;
	
	printf("\nEnter number of items:\n");
	scanf("%d",&n);

	printf("\nEnter weight and profit of each item\n");

	wt[0]=0;
	p[0]=0;
	for(i=1;i<=n;i++)
	{
		printf("item %d",i);
		printf("\nweight: ");
		scanf("%d",&wt[i]);

		printf("profit:");
		scanf("%d",&p[i]);
	}

	printf("\n Enter capacity of knapsack:\n");
	scanf("%d",&C);

	Knapsack();
}



	
