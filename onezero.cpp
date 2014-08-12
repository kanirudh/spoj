#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <cmath>
#define i64 long long

using namespace std;
const int MAXN = 20002;

typedef struct {
	int p;char c;
}pred;

bool flag[MAXN];
pred pre[MAXN];

int bfs(int start,int n){
	int qh,qt,p[2],Q[n];
	qh = qt = 0 ;
	pre[start].p = -1;
	pre[start].c = '1';
	Q[qt++] = start;
	flag[start] = 1;
	while( qh <= qt){
		int u = Q[qh++];	
		for(int i=0;i<2;i++){
			p[0] = (u * 10) % n;
			p[1] = ( p[0] + 1)%n;
			if(!flag[p[i]]){
				pre[p[i]].p = u;
				pre[p[i]].c = '0'+i;
				if(!p[i]) return 0;
				Q[qt++] = p[i];
				flag[p[i]] = 1;
			}
		} 	
	}
}



int path(int u){
	if( u == -1) return 0;
	path(pre[u].p);
	putchar(pre[u].c);
}

int main()
{
	int test,n;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		if(n == 1) printf("1\n");
		for(int i=0;i<n;i++) flag[i] = 0;
		bfs(1,n);
		path(0);
		putchar('\n');
	}
	return 0;
}
