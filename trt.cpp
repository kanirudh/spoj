#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;

int values[2000];
int memo[2001][2001];

int solve(int a,int b,int time){
	if(a==b) return values[a]*time;
	else if(memo[a][b] !=-1) return memo[a][b];
	else {
		memo[a][b] = max(values[a]*time+solve(a+1,b,time+1),values[b]*time + solve(a,b-1,time+1));
	}
	return memo[a][b];
}

int maximize(int length){
	for(int i=0;i<length;i++) for(int j=0;j<length;j++) memo[i][j] = -1;
	return solve(0,length-1,1);
}	

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&values[i]);
	printf("%d\n",maximize(n));
	return 0;
}
