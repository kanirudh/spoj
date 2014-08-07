#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#define i64 long long

using namespace std;

int weights[501],values[501];
int dp[2][2000001];

int main()
{
	int K,N;
	scanf("%d %d",&K,&N);
	for(int i=1;i<=N;i++) scanf("%d %d",&values[i],&weights[i]);
	for(int i=0;i<K+1;i++) dp[0][i] = 0;
	dp[1][0] = 0;
	for(int i=1;i<=N;i++){
		for(int j=1;j<weights[i];j++) dp[i&1][j] = dp[(i-1)&1][j];
		for(int j=weights[i];j<=K;j++){
		   dp[(i&1)][j] = max(dp[(i-1)&1][j-weights[i]]+values[i],dp[(i-1)&1][j]);
		}
	}
	printf("%d\n",dp[(N&1)][K]);	
	return 0;
}
