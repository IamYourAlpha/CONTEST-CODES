#include<bits/stdc++.h>
using namespace std;



int main() {
    freopen("input.txt","r",stdin);
    int ans;
    int ox1,ox3;
    int final_ans;
    char grid[100][100];
    int work1[10000][2];
    int work3[10000][2];
    int dim;

    while(scanf("%d\n",&dim)==1) {

        for(int i=0; i<dim; i++)
            scanf("%s\n",grid[i]);


        ox1 = 0;
        ox3 = 0;
        for(int i=0; i<dim; i++) {
            for(int j=0; j<dim; j++) {

                if(grid[i][j]=='1') {

                    work1[ox1][0] = i;
                    work1[ox1][1] = j;
                    ox1++;
                } else if(grid[i][j] =='3') {

                    work3[ox3][0] = i;
                    work3[ox3][1] = j;
                    ox3++;
                }
            }
        }
        final_ans= -1;

        for(int i=0; i<ox1; i++) {
            ans = (1<<30);
            for(int j=0; j<ox3; j++)
                ans = min (  ans,  abs(work1[i][0]-work3[j][0]) + abs(work1[i][1]-work3[j][1])  );
                final_ans = max(ans,final_ans);
        }
        printf("%d\n",final_ans);
    }
    return 0;
}
