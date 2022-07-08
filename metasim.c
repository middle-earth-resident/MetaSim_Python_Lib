//#include<iostream.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "init.h"
//user defined potential
/*double force(double x1,double x0)
{
double force1=(pot(x1)-pot(x0))/(x1-x0);
return force1;
}*/

double pot(double x)
{

}
int main(int argc,char *argv[])
{
double mem,newmem;
double force;
//read instruction
int a=1,b=1;

FILE *f1;
f1=fopen("test.dat","w");
//int a=1,b=1;;//initiliastion instruction
mem=0+pow(10,-3)*a+pow(10,-4)*b;
//update instructions
for(int i=0;i<=10;i++)
{


a=a+b;

newmem=mem+pow(10,-3)*a+pow(10,-4)*b;
force=(pot(newmem)-pot(mem))/(newmem-mem);

fprintf(f1,"%1lf %1lf %1lf\n",force,newmem,mem);
mem=newmem;
}
for(int i=0;i<argc;i++)
{
printf("argv[%d]: %s\n",i,argv[i]);
}

return 0;



}



