#include<stdio.h>

int matrix[100][100];

int main(){
    int n;
    int dots;
    while(scanf("%d",&n)==1){
        scanf("%d",&dots);
        for(int i=0;i<dots;i++){
            char ch;
        int u,v;
                scanf("%c %d %d",ch,&u,&v);
                if(ch=='H'){
                        matrix[u][v]=1;
                        matrix[u][v+1]=1;
                }
               else if(ch=='V'){
                        matrix[u][v]=1;
                        matrix[u+1][v]=1;
                }
        }
    }
    return 0;
}
