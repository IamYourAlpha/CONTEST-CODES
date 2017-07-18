using namespace std;
#include<bits/stdc++.h>

int n,e,tot;
char woke[100];
int wake[100];
int matrix[100][100];

int getIndex(char a) {
    var = mp[a-65];
    if(!var) var = mp[a-65] = ++var;
    return var;
}

int found() {

    int ans = 0;
    int virus = 0;
    while(true) {

        for(int i=0; i<n ; i++)
            if(!wake[i]) {
                virus = 0;
                for(int j=0; j<n; j++)
                    if(matrix[i][j] && wake[j]) {
                        virus++;
                        if(virus>=3) wl.push_back(i);
                    }
            }
        if(wl.size()) {
            for(int i=0; i<wl.size(); i++) wake[wl[i]] = 1;
            ans++;
            bool stop = true;
            for(int i=0; i<)





            int main() {

                init();
                while(scanf("%d",&n)!=EOF) {
                    scanf("%d",&e);
                    scanf("%s",woke);
                    for(int i=0; i<3; i++) {
                        int temp;
                        temp = getIndex(woke[i]);
                        wake[temp] = 1;
                    }
                    for(int i=0; i<e; i++) {
                        char dummy;
                        int u,v;
                        scanf("%s",dummy);
                        u = getIndex(dummy[0]);
                        v = getIndex(dummy[1]);
                        matrix[u][v] = 1;
                        matrix[v][u] = 0;
                    }
                    if(!found()) cout<< " wake up brain" << endl;
                }


            }
