// =====================================================================================
//
//       Filename:  recur.cpp
//
//    Description:  
//
//        Version:  1.0
//        Created:  08/04/2015 12:40:51 AM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  INTISAR (), 
//   Organization:  
//
// =====================================================================================


#include<bits/stdc++.h>
using namespace std;

void call(int node){
	if(node==0)  return;
	else {
		node--;
		call(node);
		cout << node << endl;
	}
}

int main(){
	call(10);
	return 0;
}
