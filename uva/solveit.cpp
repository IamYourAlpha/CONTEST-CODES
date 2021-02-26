#include<stdio.h>
#include<iostream>
#include<math.h>
#define EPS 1e-7
using namespace std;

int p,q,r,s,t,u;


double f(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double bisection()
{
    double lo=0;
    double hi = 1;
    while(lo+ EPS)
    {
        double mid = (hi+lo)/2;
        if(f(lo)*f(mid)<=0)
        {
            hi=mid;
        }
        else
        {
            lo=mid;

        }
    }
    return (lo+hi)/2;
       }

       int main()
{
    while( scanf("%d %d %d %d %d %d",&p,&q,&r,&s,&t,&u)!=EOF  )
    {
        if(f(0)*f(1)>0)printf("No solution\n");
        else
        {
            printf("%.4lf\n",bisection());
        }
    }
    return 0;
}



