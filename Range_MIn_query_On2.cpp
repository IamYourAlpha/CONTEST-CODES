#include<stdio.h>

int main() {
    int arr[100];
    int grid[100][100];
    int n;
    while(scanf("%d",&n)!=EOF) {
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++) grid[i][j] = 0;

        for(int i=0; i<n; i++) scanf("%d",&arr[i]);
        for(int i=0; i<n; i++) grid[i][i] = i;

        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(arr[grid[i][j-1]] < arr[j])
                    grid[i][j] = grid[i][j-1];
                else grid[i][j] = j;

        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",arr[grid[a][b]]);
    }
    return 0;
}

