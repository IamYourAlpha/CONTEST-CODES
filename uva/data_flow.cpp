// =====================================================================================
//
//       Filename:  data_flow.cpp
//
//    Description:
//
//        Version:  1.0
//        Created:  08/25/2015 02:18:36 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  INTISAR (),
//   Organization:
//
// =====================================================================================


using namespace std;
#include<bits/stdc++.h>

#define Read(x)  { int x; scanf("%d",&x); }

typedef long long ll;

struct S{
int u,v,next;
ll cap,cost;
}edge[6000];

int e,v;

int main(){
    while(scanf(" %d %d ",&e,&v)!=EOF && e && v ){
       for( int i = 0; i<e; i++ ) scanf( "%d %d %d ",&u [ i ],&v [ i ],&cost [ i ] );
       scanf("%d %d",&Data,&Cap);
       for( int i = 0; i<e ;i++ ) {
         AddEdge(u [ i ],v [ i ],cost [ i ],Cap);
         AddEdge(v [ i ],u [ i ],-cost [ i ],Cap);
         AddEdge(u [ i ],v [ i ],cost [ i ],Cap);
         AddEdge(u [ i ],v [ i ],cost [ i ],Cap);

         }
       return 0;
}

