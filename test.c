//solving for coefficients for coordinate polynomial 'a' and using 
//unknown coordinate beta. 1 dimensional
#include<stdio.h>

#include<math.h>

#define N 3 //no of monomials for potential V
float a(int i,float A[N])
{
if(i==0||i==1)
return 0.5;//initial conditions
else if(i>=2)
return -2*A[2]*a(i-2,A);

}
float bcoeff(int i, float A[N])
{
if(i==0||i==1)
return 0;
else if(i==2)
return A[1];
else if(i>2 && i%2==0)
return -2*A[2]*a(i-2,A);
if(i%2==1 && i>1)
return 0;
}
float fact(int i){
if(i==0||i==1)
return 1;
else
return fact(i-1)*i;
}
int main(void)
{
float xf,xi;
printf("Enter value for xf and xi");
scanf("%f %f",&xf,&xi);

float X,S=0;
X=xf-xi;//control parameter
float A[N]={0,1,2};//potential
for(int i=1;i<10;i++)
{
S=S+bcoeff(i,A)/fact(i);
X=X-a(i,A)/fact(i);
printf("%f,%f\n",X,S);
}
//X=X/S;
//printf("%f",X);
return 0;
}






