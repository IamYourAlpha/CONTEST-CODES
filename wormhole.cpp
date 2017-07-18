#include<stdio.h>

struct SS {
	int u;
	int v;
	int w;
} e[4000];

int D[4000];
int ne;
int nv;
void input() { 
	scanf("%d",&ne);
	scanf("%d",&nv);
	for(int i=0; i<nv; i++) {
		scanf("%d %d",&e[i].u,&e[i].v);
		scanf("%d",&e[i].w);
	}
}

bool bellman() {
	D[0]=0;
	for(int i=0; i<ne; i++)
	{
		for(int j=0; j<nv; j++) {
			if( D[ e[j].u ]+e[j].w<D[e[j].v]) {
				D[e[j].v]=D[e[j].u]+e[j].w;
			}
		}
	}
	for(int i=0; i<nv; i++)
		if(D[e[i].u]+e[i].w<D[e[i].v])
			return true;
	return false;
}

int main() {
	int tc;
	scanf("%d",&tc);
	while(tc--) {
		input();
		for(int i=0; i<3999; i++) D[i]=9999999;
		if (bellman()) printf("possible\n");
		else printf("not possible\n");
	}
	return 0;
}

