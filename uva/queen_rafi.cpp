#include <stdio.h>
#include <math.h>
void nQueen(int k,int n);
int place(int k,int i);
int x[100];
int main()
{
    int n=4;

nQueen(1,n);
    return 0;
}

void nQueen(int k,int n)
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        if(place(k,i)==1)
        {
            x[k]=i;
            if(k==n)
            {
                for(j=1;j<=n;j++)
                {
                    printf("%d ",x[j]);
                }
                printf("\n");
            }
              else
                nQueen(k+1,n);

        }
    }

}


int place(int k,int i)
{
    int j;
    for(j=1;j<=k-1;j++)
    {
        if((x[j]==i) || (fabs(x[j]-i) == fabs (j-k)))
        return 0;
    }
    return 1;
}
