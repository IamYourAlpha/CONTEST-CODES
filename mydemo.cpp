#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,m;
    char str[100][100];
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    cin>>str[i][j];
            }
    }
    int c=0;
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                   // cout<<str[j][i];
                 if(str[j][i]>str[j+1][i]){c++; break;}
            }
    }
    printf("%d",c);
}



