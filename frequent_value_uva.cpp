#include<bits/stdc++.h>

using namespace std;


#define MAX  200005
#define C    100000
#define MAX1 1000000

int n,q;
int arr[MAX];
int Stree[MAX];
int Cnt[MAX];
int Start[MAX1];

void Construct_Seg_Tree(int low,int high,int pos) {
    if(low == high) {
        Stree[pos] = Cnt[ arr[low] ];
        return ;
    }
    int  mid = (high+low)/2;
    int n1 = (2*pos) + 1;
    int n2 = (2*pos) + 2;
    Construct_Seg_Tree(low,mid,n1);
    Construct_Seg_Tree(mid+1,high,n2);
    if(Stree[n1]>=Stree[n2]) Stree[pos] = Stree[n1];
    else Stree[pos] = Stree[n2];
}

int RMQ(int low,int high,int range1,int range2,int pos) {
    int ret;
    if(range1>high || range2<low) return -1;
    if(low>=range1 && high<=range2) return Stree[pos];
    int mid = (low+high)/2;
    int n1 = (2*pos) + 1;
    int n2 = (2*pos) + 2;
    int v1 = RMQ(low,mid,range1,range2,n1);
    int v2 = RMQ(mid+1,high,range1,range2,n2);
    if(v1==-1) ret = v2;
    if(v2==-1) ret = v1;
    if(v1>=v2) ret = v1;
    else  ret = v2;
    return ret;
}

int main() {
//    freopen("input.txt","r",stdin);
    while(scanf("%d",&n) == 1) {
        if(n==0) break;
        memset(Start,-1,sizeof(Start));
        memset(Stree,0,sizeof(Stree));
        memset(Cnt,0,sizeof(Cnt));
        scanf("%d",&q);

        for(int i=0; i<n; i++) {
            scanf("%d",&arr[i]);
            arr[i] = arr[i] + C;
            Cnt[ arr[i] ]++;
            if(Cnt[ arr[i] ]==1) Start[ arr[i] ] = i;
        }
        Construct_Seg_Tree(0,n-1,0);

        for(int i=0; i<q; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            a--;
            b--;
            if(arr[a]==arr[b]) {
                printf("%d\n",b-a+1);
                continue;
            }

            int temp;
            int ans;

            int var1 = (Cnt[ arr[a] ]  + Start[ arr[a] ] )-a;
            int var2 = b - Start[arr[b]] +1;
            if(var1>var2) ans = var1;
            else  ans = var2;
            int r1 = Start[arr[a]] + Cnt[arr[a]];
            int r2 = Start[arr[b]] -1;
            if(r1<=r2) {
                temp = RMQ(0,n-1,r1,r2,0);
                if(temp>ans) ans = temp;
            }
            printf("%d\n",ans);
            //  cout << Cnt [1+C] << endl;
        }
    }

    return 0;

}

