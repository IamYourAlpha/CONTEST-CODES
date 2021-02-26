#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;

int input[1000][1000];
int dist[1000][1000];
int row,col;
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};


bool valid(int x,int y) {
    if(x>=0 && x<row && y>=0 && y<col) return true;
    return false;
}


void dij() {
    priority_queue<piii,vector<piii>,greater<piii> >pq;
    dist[0][0] = input[0][0];
    pq.push( make_pair( dist[0][0],pii(0,0)) );
    while(!pq.empty()) {
        piii node = pq.top();
        pq.pop();
        int now =  node.first;
        int xcor = node.second.first;
        int ycor = node.second.second;
        if(dist[xcor][ycor]==now)
        for(int i=0; i<4; i++) {
            int newx = xcor + dx[i];
            int newy = ycor + dy[i];
            if(valid(newx,newy)) {
                if(dist[newx][newy]>input[newx][newy]+now) {
                    dist[newx][newy] = input[newx][newy]+now;
                    pq.push(make_pair(dist[newx][newy],pii(newx,newy)));
                }
            }
        }
    }
}



int main() {
    freopen("input.txt","r",stdin);
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> row >> col;
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                cin >> input[i][j];
            }
        }
        memset(dist,10000000,sizeof(dist));
        dij();
        cout << dist[row-1][col-1] << endl;
    }
    return 0;
}

