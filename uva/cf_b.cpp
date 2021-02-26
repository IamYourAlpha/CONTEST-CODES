#include<bits/stdc++.h>
using namespace std;

double get_dist(double x1,double y1,double x2,double y2){
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
int main(){

   double x1,y1,x2,y2;
   double rad;
   cin >> rad;
   double dim = 2 * rad;
    cin >> x1 >> y1 >> x2 >> y2;
    cout << ceil( get_dist(x1,y1,x2,y2)/dim) << endl;
    }


