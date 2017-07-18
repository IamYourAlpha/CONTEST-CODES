#include<bits/stdc++.h>
using namespace std;


vector < vector<int> >  graph;
string demo;
vector <int> ver_cont;
int visited[1000];
int node_visited;
int sz=0;
int forest;
int acorn;
int c;
void load() {
      c=0;
      for(int i=0; i<demo.length(); i++) {
            if(isalpha(demo[i])) {
                  ver_cont.push_back(demo[i]-65);
            }
      }
}

bool have(int node) {
      for(int i=0; i<ver_cont.size(); i++) {
            if(ver_cont[i]==node) return true;
      }
      return false;
}

void dfs(int node) {

      if(visited[node] || !have(node)) return ;
      if(have(node) && !visited[node]) {
            visited[node]=1;
            node_visited++;
            for(int i=0; i<graph[node].size(); i++) {
                  if(!visited[graph[node][i]] && have(graph[node][i]) ) {
                        // cout<< " debug " << node_visited << endl;
                        dfs(graph[node][i]);
                  }
            }
      }


      return ;
}


void reset() {

      memset(visited,0,sizeof(visited));
      forest=0;
      acorn=0;
      node_visited=0;
}
int main() {
      int tc;
      freopen("input.txt","r",stdin);
      scanf("%d",&tc);
      while(tc--) {
            reset();
            graph.assign(26,vector<int>());
            while(cin>>demo) {
                  if(demo[0]=='*') break;
                  int c1 = demo[1]-65;
                  int c2 = demo[3]-65;
                  graph[c1].push_back(c2);
                  graph[c2].push_back(c1);
                  //cout<< c1 << " " << c2<<endl;
            }
            cin>>demo;
            load();
            for(int i=0; i<graph.size(); i++) {
                  if(!visited[i] && have(i) ) {
                        dfs(i);
                        //    cout<<node_visited<<endl;
                        if(node_visited>1) forest++;
                        else if(node_visited==1) acorn++;
                        node_visited=0;
                  }
            }
            cout << "There are "<< forest << " tree(s) and "<< acorn << " acorn(s)." << endl;
            graph.clear();
            ver_cont.clear();
      }
      return 0;
}

