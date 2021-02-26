#include<bits/stdc++.h>
using namespace std;


int main() {
    //freopen("input.txt","r",stdin);

    int k;


    while(scanf("%d",&k)!=EOF) {
        vector<pair<int, int> > vii;
        for(int i=k+1; i<=2*k; i++) {
            if(  (k*i)%(i-k) ==0  )
                vii.push_back(make_pair( (k*i)/(i-k),i));
        }
        // cout << "ok" <<endl;
        cout << vii.size() << endl;
        for(size_t j=0; j<vii.size(); j++) {
            printf("1/%d = 1/%d + 1/%d\n",k,vii[j].first,vii[j].second);
        }
    }

    return 0;
}
