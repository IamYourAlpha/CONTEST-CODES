/*** *****/

using namespace std;
# include <iostream>
# include <fstream>
# include <sstream>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <cctype>
# include <climits>
#define pb push_back

typedef long long ll;
typedef unsigned long long ULL;
typedef pair<ll,ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;


int main() {

                vector<ll> set_A;
                vector<ll> set_B;
                bool found=false;
                ll key,key1;
                ll n;
                scanf("%lld",&n);
                for(ll i=0; i<n; i++) {
                                scanf("%lld",&key);
                                set_A.pb(key);
                                scanf("%lld",&key);
                                set_B.pb(key);
                }

                bool visited_[1000000];
                memset(visited_,false,sizeof(visited_));
                for(ll i=0; i<n; i++) {
                                found = false;
                                for(ll j=0; j<n; j++) {
                                                if(set_A[i]==set_B[j] && !visited_[ set_A[i] ]) {
                                                                visited_[ set_A[i] ]=true;
                                                                found=true;
                                                                break;
                                                }
                                                if(found) break;
                                }
                                if(found==false) {
                                                key=set_A[i];
                                                visited_[set_A[i]]=true;
                                }
                }
                for(ll i=0; i<n; i++) if(!visited_[set_B[i]] && set_B[i]!=0) key1=set_B[i];

                // printf("key :::::::::  %lld %lld\n",key,key1);
                queue<ll>q;
                q.push(0);
                q.push(key);
                ll  flag=0;
                ll  flag_=0;

                bool visited[1000000];
                memset(visited,false,sizeof(visited));
                while(true) {
                                for(ll i=0; i<n; i++) {
                                                ll demo=q.front();
                                                //  if(set_A[i]==0){ flag_=1; break;}
                                                if(demo==set_A[i] && !visited[demo]) {
                                                                q.push(set_B[i]);
                                                                if(q.front()!=0) {
                                                                                printf("%lld ",q.front());
                                                                                flag++;
                                                                }
                                                                q.pop();
                                                                if(flag==(n-1)) {
                                                                                flag_=1;
                                                                                break;
                                                                }
                                                }
                                }
                                if(flag_) break;
                }
                printf("%lld",key1);
                return 0;
}
