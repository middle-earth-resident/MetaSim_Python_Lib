#include<stdio.h>

#define MAX 100
#define pol int
#define ABC(x) mem[x].M.p
#define COEFF(x) mem[x].M.coeff
#define LINK(x) mem[x].link

int cmp(int A[MAX],int B[MAX])
{
	int i,eq=0,l=0,g=0;
	for(i=0;i<MAX;i++)
	{
		if(A[i]>B[i])
			g=1; goto EX:
		else if(A[i]<B[i])
			l=1;goto EX:
	}	
	eq=1;
	EX:
	return(eq==1)?:((l==0)?-1:1);

	
}
int neg(int neg A[MAX])
{
	int i,n=0;
	for(i=0;i<MAX;i++)
		if(A[i]<0)n=1;
	return n;
}
void assign(int A[MAX],int B[MAX])
{
	int i;
	for(int i=0;i<MAX;i++)
		A[i]=B[i];
}
struct mon
[
	float coeff;
	int p[MAX];
};
Struct poly
{
	mon M;
	int link;
};
static poly mem[100000];



