#include<bits/stdc++.h>
using namespace std;

#define MAX 1<<30

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vii;
int tot;
int f;
int max_flow;
int grid[1000][1000];
vi visited;
vi p;
char input[1000];
char c[1000];

void print(int i) {
	for(int j=1; j<27; j++) {
		if(grid[i][j] == 1) {
			printf("%c", j+'A'-1);
			return;
		}
	}
	cout << "_" ;
	// cout << "ok" << endl;
}

void augment(int node,int x) {
	//cout << "in" << endl;
	if(node==0) {
		f = x;
		return ;
	} else if(p[node]!=-1) {
		augment( p[node], min(x,grid[p[node]][node]) );
		grid[ p[node] ][node] -= f;
		grid[node][p[node]]   += f;
	}
}

int main() {
	freopen("input.txt","r",stdin);

	while(true) {
		tot = 0;
		if(gets(input)==0) break;
		memset(grid,0,sizeof(grid));
		do {
			if(strcmp(input,"")==0) break;
			char a,b;
			sscanf(input,"%c%c %s",&a,&b,c);
			grid[0][a-'A'+1] = b-'0';
			tot+= b-'0';
			//   cout << "toot : " << tot << endl;
			for(int i=0;; i++) {
				if(c[i]==';') break;
				grid[ a-'A'+1 ][ 27+ c[i]-'0' ] = INT_MAX;
			}
		} while(gets(input));
		max_flow = 0;
		for(int i=27; i<37; i++) grid[i][37] = 1;

		while(true) {
			queue <int> q;
			p.assign(100,-1);
			visited.assign(100,0);
			q.push(0);
			f = 0;
			visited[0] = 1;

			while(!q.empty()) {
				int temp = q.front();
				if(temp==37) break;
				q.pop();
				for(int v=0; v<38; v++) {
					if(grid[temp][v]>0 && !visited[v]) {
						visited[v] = 1;
						p[v] = temp;
						q.push(v);
					}
				}
			}
			augment(37,INT_MAX);
			if(f ==0)  break;
			max_flow+= f;
		}
		//   cout << max_flow << endl;
		if(max_flow == tot) {
			for(int i=27; i<37; i++)
				print(i);
		} else printf("!");
		cout << endl;
		// cout << max_flow << endl;
	}
	return 0;
}
