//solving for coefficients for coordinate polynomial 'a' and using//unknown coordinate beta. 1 dimensional
//*NOTE: MAKE FOR MULTIPLE CHANGES IN THE STATE
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
float control(float xf,float xi)
{
//float xf,xi;
//printf("Enter value for xf and xi");//initial and final values of the state of the given physical system


float X,S=0;
X=xf-xi;//control parameter
float A[N]={1,1,2};//potential
for(int i=1;i<10;i++)
{
S=S+bcoeff(i,A)/fact(i);
X=X-a(i,A)/fact(i);
//printf("%f\n",X/S);
}
X=X/S;//Unknown parameter required to move the system from state xi to state xf


//printf("%f",X);//generating control parameter

return X;
}
float a_x(int i,float A[N],float xf,float xi)
{
	if(i==0||i==1)
		return 0.5;
	if(i==2)
		return -2*A[2]*a_x(0,A,xf,xi)+control(xf,xi)*A[1];	  else
	        return -2*A[2]*a_x(i-2,A,xf,xi);



}

/*float *mapping()
{
int bits;
printf("Enter no. of bits.16 bit max");
scanf("%d",&bits);
int map[70000];
float beta[70000];
printf("Enter mapped values of x");
for(int i=0;i<=(pow(2,bits)-1);i++)
{
scanf("%d",&map[i]);
beta[i]=control((float)map[i],(float)i);
}
for(int i=0;i<(pow(2,bits)-1);i++)
{
printf("%f",beta[i]);

}

return beta;
}*/


int main()
{
	
	float xf,xi;
	printf("Enter value for initial and final state:\n");
	scanf("%f",&xi);
	scanf("%f",&xf);
	float p;
	float sum=0;
	float A[N]={1,1,2};
	float t=0;
	FILE *f1;
	int i;
	f1=fopen("temp.dat","w");
	 p=control(xf,xi);
	printf("Value of unknown parameter is': %f\n",p);
	while(t<5){
	for( i=0;i<10;i++)
	{
		sum+=(a_x(i,A,xf,xi)*pow(t,i))/fact(i);
	}
	t+=0.1;
	
	
	fprintf(f1,"%f %f\n",sum,t);
	sum=0;
	}
	
	float arr[4][70000];// signifies no of logic gates and bits for each gate
return 0;
}


