//////////////////////////
//     Algorithm for the  longest non repeating charecters
//
//



#include<bits/stdc++.h>
using namespace std;
const int MAX_ = 10000000;

int visited[MAX_],n;
int input[MAX_];

int LUS() {
    memset(visited,-1,sizeof(visited));
    visited[input[0]] = 0;
    int CurLen = 1;
    int maxL = 1;
    int PrevIndex;
    for(int i=1; i<n; i++) {
        PrevIndex = visited[input[i]];
        if(PrevIndex == -1 || i-CurLen > PrevIndex)
            CurLen++;
        else {
            if(CurLen>maxL) maxL = CurLen;
            CurLen = i - PrevIndex;
        }
        visited[input[i]] = i;
    }
    if(CurLen>maxL) maxL = CurLen;
    return maxL;
}

int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        scanf("%d",&n);
        for(int i=0; i<n; i++) scanf("%d",&input[i]);
        printf("%d\n",LUS());
    }

    return 0;
}
