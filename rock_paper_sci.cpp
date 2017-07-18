#include<bits/stdc++.h>
using namespace std;
char RPS[200][200];

int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};

char RPS1[100][100];
int r,c;
bool is_valid(int x,int y) {
      if(x<r && x>=0 && y>0 && y<=c ) return true;
      return false;
}

void check(int x,int y,char key) {
      int X,Y;
      if(key=='R') {
            for(int i=0; i<4; i++) {
                  X= x+dx[i];
                  Y= y+dy[i];
                  if(is_valid(X,Y)) {
                        if(RPS[X][Y]=='S') {
                              // RPS[X][Y]='R';
                              RPS1[X][Y]='R';
                        }//visited[X][Y]=true;
                  }
            }

            //RPS[x][y]='R';
      } if (key=='P') {
            for(int i=0; i<4; i++) {
                  X= x+dx[i];
                  Y= y+dy[i];
                  if(is_valid(X,Y)) {
                        if(RPS[X][Y]=='R') {
                              //RPS[X][Y]='P';
                              RPS1[X][Y]='P';
                        }
                        //               visited[X][Y]=true;
                  }
            }
            //     RPS1[x][y]='P';
            // RPS1[x][y]='P';
      }  if(key=='S') {
            for(int i=0; i<4; i++) {
                  X= x+dx[i];
                  Y= y+dy[i];
                  if(is_valid(X,Y) ) {
                        if(RPS[X][Y]=='P') {
                              //RPS[X][Y]='S';
                              RPS1[X][Y]='S';
                        }
                        //visited[X][Y]=true;
                  }
            }
            //  RPS1[x][y]='S';
      }
}

void copy_() {
      for(int i=0; i<r; i++)
            for(int j=0; j<c; j++) RPS[i][j]=RPS1[i][j];
}

int main() {
      int tc;
      int days;
      scanf("%d",&tc);
      while(tc--) {
            scanf("%d %d %d",&r,&c,&days);
            for(int i=0; i<r; i++)
                  for(int j=0; j<c; j++) { cin>>RPS[i][j]; RPS1[i][j]=RPS[i][j];}
            //    memset(RPS1,'I',sizeof(RPS1));
            for(int k=0; k<days; k++) {
                  for(int i=0; i<r; i++) {
                        for(int j=0; j<c; j++) {
                              check(i,j,RPS[i][j]);
                              // printf("ok\n");
                        }
                  }
copy_();
            }

//cout<<endl<<endl;
            for(int i=0; i<r; i++) {
                  for(int j=0; j<c; j++) {
                        cout<<RPS[i][j];
                  }
                  cout<<endl;
            }
            cout<<endl;
      }
      return 0;
}
