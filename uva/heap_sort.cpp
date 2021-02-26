#include<stdio.h>

int main(){
    int heap[100];
    int n,i,j,c,root,temp;

    printf("enter the number of the element \n");
    scanf("%d",&n);
    for( i=0;i<n;i++)
     scanf("%d",&heap[i]);
    for(int i=0;i<n;i++)
    {
        c=i;
        do{
        root=(c-1)/2;
        if(heap[root]<heap[c])
        {
            temp=heap[root];
            heap[root]=heap[c];
            heap[c]=temp;
        }
        c=root;
           } while(c!=0);
    }
    printf("printing heap \n");
    for(i=0;i<n;i++) printf("%d\t",heap[i]);

    for(j=n-1;j>=0;j--){
    temp=heap[0];
    heap[0]=heap[j];
    heap[j]=temp;
    root=0;
    do{
    c=2*root-1;
    if((heap[c]<heap[c+1]) && c<j-1)
    c++;
    if(heap[root] '[p0o'

    }

}
