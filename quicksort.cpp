#include<stdio.h>

void qs(int x[10],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(x[i]<=x[pivot]) i++;
            while(x[j]>x[pivot])  j--;
            if(i<j)
            {
                temp=x[i];
                x[i]=x[j];
                x[j]=temp;
            }
        }


        temp=x[pivot];
        x[pivot]=x[j];
        x[j]=temp;

        qs(x,first,j-1);
        qs(x,j+1,last);
    }
}


    int main()
    {



        int x[20],size,i;
        printf("enter the size of the array");
        scanf("%d",&size);
        printf("\n enter the elements");
        for(i=0; i<size; i++)
            scanf("%d",&x[i]);
        qs(x,0,size-1);

        printf("sorted elements \n");

        for(i=0; i<size; i++)
            printf("%d",x[i]);
        return 0;
    }

