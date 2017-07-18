// =====================================================================================
//
//       Filename:  akib.cpp
//
//    Description:  expression evalution
//
//        Version:  1.0
//        Created:  08/23/2015 03:55:34 PM
//       Revision:  none
//       Compiler:  g++
//
//         Author:  INTISAR (),
//   Organization:  Ahsanullah University of Science and technology
//   Editor :  Vim
//   Please do not tamper or mimics  code without permission .
// happy coding :)
//
// =====================================================================================

using namespace std;
#include<bits/stdc++.h>
int main() {
    string str;
    //string ts  [10000];
    char opr[10000];
    string demo = "";
    map <int,string>out;
    map <string,string> ans;
    cin >> str;

    int len = str.length();
    int m = 0;
    bool start = true;
    for(int i = 0; str [ i ]; ) {
        if( str [ i ] != '(' ) {
            if( start ) {
                while( str [ i ] != '(' && str [ i ] ) {
                    demo += str [ i ];
                    i++;
                }
                demo [ demo.length()-1  ]  = NULL;
                out [ m ]  =   demo;
                demo = "";
                start = false;
                m++;//cout << " ok" ;
            } else {
              i++; i++;
                demo = "";
                m++;
                while( str [ i ] != '(' && str [ i ] ) {
                    demo += str [ i ];
                    i++;
                    //   cout << " debug " << demo << endl;
                }

                demo [ demo.length()-1  ]  = NULL;
                out [ m ] =   demo;
                demo = "";
                m++;
            }
        } else if(str [ i ] == '(') {
            demo = "";
            i++;
            while( str [ i ] != ')' && str [ i ] ) {
                demo += str [ i ];
                i++;
                //  cout << " debug " << " : " << demo << endl;
            }
            //opr [ m ] = str [ demo [ demo.length() - 1] ];
            //cout << str [ i + 1];
            //	demo [ demo.length()-1  ]  = NULL;
            //	demo [ demo.length()-2  ]  = NULL;
            out [ m ] =   demo;
            demo = "";

        }
        demo = "";
    }
    m = 0;

    for(int i=0; i<str.length(); i++)  if( str [ i ] == '('  && str [ i - 1] ) opr [ m++ ] = str [ i-1 ];
        else if ( str [ i ] == ')'  && str [ i + 1] )  opr [ m++ ] = str [ i + 1];

    for(int i=0; i<out.size(); i++)  ans [ out [ i ]  ] = 'A' + i;
    for(int i=0; i<out.size(); i++)  cout  <<  ans [ out [ i ]  ]   <<  " : " << out [ i ] <<endl;
    cout << " --- out put --  " << endl;
    for(int i=0; i<out.size(); i++)  cout  <<  ans [ out [ i ]  ]    << opr [ i ];

    return 0;
}
