// Program to Implement Horspool algorithm for String matching for multiple occurances of a string.

#include<stdio.h>
#include<string.h>
#define MAX 250

int table[MAX],a[MAX],no=0;

// creating shift table
void shiftTable(char p[])
{
	int i,j,m=strlen(p);
	
	for(i=0;i<MAX;i++)
		table[i]=m; // initialising with length of pattern
		
	for(j=0;j<m-1;j++)
		table[p[j]]=m-1-j;
}

void Horspool(char src[],char p[])
{
	
	int i,k;
	int m=strlen(p);
	int n=strlen(src);
	i=m-1;
	
	while(i<n)
	{
		k=0;
		
		while((k<m) && (p[m-1-k] == src[i-k]))
			k++;
		 
		if(k==m)
		{
			a[no]=i-m+1;
	 		no++;
	 	}

		
		i=i+table[src[i]]; //shifting i by shift value of character calculated in shift table
		
	}
	
}

void main()
{
	char src[100],p[100];
	
	printf("Enter String\n:");
	gets(src);
	
	printf("\nEnter pattern to be matched:\n");
	gets(p);
	
	shiftTable(p); // function to call shift table
	
	Horspool(src,p); 
	
	int i;

	// if string is present print all the position where it occurs
	if(no!=0)
	{
		printf("\n Pattern found at position(s):\n");
		for(i=0;i<no;i++)
			printf("%d\t",a[i]);
	}		
	else
		printf("\nPattern not found \n"); 

		
	
		
	
}
