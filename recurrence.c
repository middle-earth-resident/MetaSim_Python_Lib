#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define S 100//no of monomials for coordinate
#define D 100//no of monomials for potential V
#define N 100//no of particles
#define poly struct polynomial
float B[100][100];

int l;
struct polynomial{
float coeff[100];
float var[100][100];
int p[100][100];

};
//computing polynomial generally
double compute(poly P,int argc, float args[1000])
{
int i,j;
float sum=0,prod;
for(i=0;i<argc;i++)
{
prod=1;
for(j=0;P.var[i][j]!=-1;j++)
{
prod=prod*pow(args[P.var[i][j]],P.p[i][j]);
}
sum=sum+(P.coeff[i]*prod);
}
return sum;
}



//jth for the ith particle 
float Be(int i,int j)
{


//initial conditions for polynomial
if(j==0||j==1)
{
if(i==0)
 return 1;
else if(i==1)
return 2;
else if(i==2)
return 3;
else
return 0;
}


//Concatenation
/*
int l=0;
while(l!=d){
double sum=0;

sum+=summation();
printf("%lf",sum);
l++
}

*/

float a(int n)//coefficient for V
{

return 1/n;

}

float f(int d,int twodarray[100][100]) //computing terms in recurrence relation
{
int i;
float sum=0,prod=1;
for(i=0;i<=pow(N+1,d);i++)
{
for(int j=0;j<N;j++)
{
prod=prod*twodarray[(i/int(pow(N,j))%N]

