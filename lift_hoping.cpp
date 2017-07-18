using namespace std;
#include<bits/stdc++.h>

struct LiftInfo {
    int time;
    int floor[100+666];
} Lift[10];

struct FloorInfo {
    int cost;
    int lift;
    int floor_num;
} temp,cur;


bool operator < ( FloorInfo A, FloorInfo B )
{
    return A.cost > B.cost;
}

int n,k;
char input[2000];
int dist[20][666];
priority_queue<FloorInfo> pq;

void CallDijstra()
{

    while(!pq.empty()) {
        cur = pq.top();
        pq.pop();

        if(cur.cost>dist[cur.lift][cur.floor_num]) continue;
        for(int i=0; i<150; i++) {
            int newcost = cur.cost + Lift[cur.lift].time * abs(cur.floor_num-i);
            if(Lift[cur.lift].floor[i]==1 && dist[cur.lift][i]>newcost) {
                temp.floor_num = i;
                temp.lift = cur.lift;
                temp.cost =  dist[cur.lift][i] = newcost;
                pq.push(temp);
            }
        }
        for(int i=0; i<10; i++) {
            if(Lift[i].floor[cur.floor_num]==1) {
                temp.floor_num = cur.floor_num;
                temp.cost = cur.cost + 60;
                temp.lift = i;
                if(dist[i][cur.floor_num]>temp.cost) {
                    dist[i][cur.floor_num] =  temp.cost;
                    pq.push(temp);
                }
            }
        }
    }
    return ;
}

int main()
{
    //freopen("input.txt","r",stdin);


    while(scanf("%d %d",&n,&k)!=EOF) {
        for(int i=0; i<10; i++) {
            Lift[i].time = 0;
            memset( Lift[i].floor,0,sizeof(Lift[i].floor)) ;
            for(int i=0; i<10; i++) for(int j=0; j<150; j++) dist[i][j] = 0;
        }
        for(int i=0; i<n; i++) scanf("%d",&Lift[i].time);
        getchar();

        for(int i=0; i<n; i++) {
            gets(input);
            char *ch;
            ch = strtok(input," ");
            while(ch!=NULL) {
                Lift[i].floor[atoi(ch)] =  1;
                ch = strtok(NULL," ");
            }
        }

        for(int i=0; i<10; i++)
            for(int j=0; j<150; j++) dist[i][j] = INT_MAX;
        for(int i=0; i<10; i++) dist[i][0] = 0;
        // cout << "out " << endl;
        cur.floor_num =0;
        cur.cost = 0;

        for(int i=0; i<10; i++)
            for(int j=0; j<150; j++)
                if(Lift[i].floor[0]==1) {
                    cur.lift = i;
                    pq.push(cur);
                }
        //temp = pq.top();
        //  cout << temp.cost << " " << temp.floor_num << " " << temp.lift << endl;

        CallDijstra();
        int ans = INT_MAX;
        for(int i=0; i<7; i++) if(dist[i][k]<ans) ans = dist[i][k];
        if(ans==INT_MAX)  cout << "IMPOSSIBLE" << endl;
        else cout << ans << endl;

        while(!pq.empty()) pq.pop();
    }
    return 0;
}

