#include<stdio.h>

void dp(int n,float weight[],float profit[],float capacity)
{
    float x[20],tp=0;
    int i,j,u;
    u= capacity;

    for(i=0; i<n; i++)
        x[i]= 0.0;
    for(i=0; i<n; i++)
    {
        if(weight[i]>u)
            break;
        else
        {
            x[i]=1.0;
            tp+=profit[i];
            u-=weight[i];
        }
    }
    if(i<n)
        x[i]=u/weight[i];
    tp+=x[i]*profit[i];
    printf("the max profit  :: %f",tp);
    for(int i=0; i<n; i++)
        printf("\n the ratio :: %f",x[i]);
}

int main()
{
    float weight[20],profit[20],capacity;
    int n,i,j;
    float ratio[20],temp;

    printf("enter the number of the object\n");
    scanf("%d",&n);

    printf("enter the weight and profit of the object\n");
    for( i=0; i<n; i++)
        scanf("%f %f",&weight[i],&profit[i]);

    printf("enter the capacity of the bag\n");
    scanf("%f",&capacity);
    for(i=0; i<n; i++)
        ratio[i]= profit[i]/weight[i];

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(ratio[i]<ratio[j])
            {
                temp= ratio[j];
                ratio[j]= ratio[i];
                ratio[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp = profit[j];
                profit[j]=profit[i];
                profit[i]=temp;
            }
        }
    }
    dp(n,weight,profit,capacity);
    return 0;
}
