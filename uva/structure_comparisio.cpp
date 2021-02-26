#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{

int a;
} b[1000];


bool comp(const node &f,const node &g){
return f.a < g.a;
}

int main(){

int n = 5;

for(int i=0; i<5; i++) scanf("%d",&b[i].a);
sort(b,b+5,comp);
for(int i=0; i<5; i++) printf("%d ",b[i].a);

}
