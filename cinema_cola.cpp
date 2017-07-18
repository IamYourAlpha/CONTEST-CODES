using namespace std;
#include<bits/stdc++.h>
#define mx 200

template <class T> int ToInt(T t) {
    stringstream ss;
    ss<<t;
    int n;
    ss>>n;
    return n;
}

int r,c,p;

int Grid [mx][mx];

int main() {
    string token;
    freopen("input.txt","r",stdin);
    while( (cin >> r >> c) ) {
       if( r + c == 0) return 0;
        scanf("%d",&p);
        memset(Grid,0,sizeof(Grid));

        for( int i = 0; i < p; i++ ) {
            cin >> token;
            int x = token [0] - 'A';
            int y = ToInt(token.substr(1));
          //  cout << x << " " <<  y << endl;
            string side;
            cin >> side;
            if(side  == "-") y--;
            Grid [x][y] = 1;
        }
        int G;
        vector < pair<int,int> >Q(r+10);
        cin >> G;
        for( int i = 0; i < G; i++ ) {
            cin >> token;
            Q [i].first  = token [0] - 'A';
            Q [i].second = ToInt( token.substr(1) );
        }
        sort(Q.begin(),Q.end());
        bool found = false;
        for ( int i = 0; i < G; i++) {
            int x = Q [i].first;
            int y = Q [i].second;
            cout << x << " " << y << endl;
            if ( !Grid [x][y-1] ) Grid [x][y-1] = 1;
            else if ( !Grid [x][y] ) Grid [x][y] = 1;
            else {
                found = true;
                break;
            }
        }
        if(found) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
