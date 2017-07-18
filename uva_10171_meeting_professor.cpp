#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define min_(a,b) (int) a <  (int) b ? a : b

int young[30][30];
int old[30][30];
char age,dir,u,v,source1,source2;
int nodes,val;

void floyd() {
      for(int c = 0; c<26; c++) {
            for(int a = 0; a<26; a++) {
                  for(int b = 0; b<26; b++) {
                        young[a][b] = min_ (young[a][b],young[a][c] + young[c][b]);
                        old[a][b] = min_ (old[a][b],old[a][c] + old[c][b]);

                  }
            }
      }
}



int main() {
     //freopen("input.txt","r",stdin);
      while(scanf("%d",&nodes)!=EOF) {
            if(nodes==0) return 0;

            for(int i=0; i<30; i++) {
                  for(int j=0; j<30; j++) {
                              young[i][j]=1e7;
                              old[i][j]=1e7;
                        }
                  }
                  for(int i=0;i<30;i++) {young[i][i]=0; old[i][i]=0;}
            for(int i =0; i<nodes; i++) {
                  cin >> age >> dir >> u >> v >> val;
                  if(age=='Y') {
                   //   cout << u - 'A' << " "<< v-'A' << endl;
                        young[u-'A'][v-'A'] = val;
                        if(dir=='B') young[v-'A'][u-'A'] = val;
                  } else if(age=='M') {
                     // cout << u - 'A' << endl;
                        old[u-'A'][v-'A'] = val;
                        if(dir=='B')  old[v-'A'][u-'A'] = val;
                  }
            }
            //     reset();

            floyd();
            cin >> source1 >> source2;
            int ans = 1e7;
            for(int a=0; a<26; a++) {
                  ans = min(ans,young[source1-'A'][a] + old[source2-'A'][a]);
            }
            if(ans==1e7) cout << "You will never meet."<<endl;
            // cout << ans << endl;
            else {
                  cout << ans << " ";
                  for(int a=0; a<26; a++) {
                        if(ans == (young[source1-'A'][a]+old[source2-'A'][a]) )
                              printf("%c ",a+'A');

                  }
                  cout << endl;
            }
      }
      return 0;
}
