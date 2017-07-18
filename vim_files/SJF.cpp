// =====================================================================================
//
//       Filename:  SJF.cpp
//
//    Description: An algorithm for process schedualing
//
//        Version:  1.0
//        Created:  09/02/2015 01:51:15 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  INTISAR CHOWDHURY
//   Organization:  Ahsanullah University of Science and Technology
// 
// =====================================================================================
using namespace std;
#include<bits/stdc++.h>

struct Sjf {
	int Bt;
	string job;
} node [10000];

bool myfun(Sjf a,Sjf b){
	return (a.Bt<b.Bt);
}


int main(){
	int n;
	cout << " enter the number of process " << endl; 
	cin >> n;
	for(int i=0; i<n; i++) cin >> node [i].job >> node [i].Bt;
	sort(node,node+n,myfun);
	//printing the process
	for(int i =0; i<n; i++) cout << node [i].job << "---- " <<  node [i].Bt << endl;
	return 0;
}



