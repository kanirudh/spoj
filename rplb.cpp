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

int dp[1001][1001],array[1001];

int main()
{
	int test,N,K;
	scanf("%d",&test);
	for(int k=0;k<test;k++){
		scanf("%d %d",&N,&K);
		for(int i=1;i<=N;i++) scanf("%d",&array[i]);
		for(int i=0;i<=N;i++) dp[i][0] = 0;
		for(int i=0;i<=K;i++) dp[0][i] = 0;
		for(int i=1;i<=N;i++){
			for(int j=1;j<array[i];j++) dp[i][j] = dp[i-1][j];
			for(int j=array[i];j<=K;j++){
				int temp = array[i] + (i>1?dp[i-2][j-array[i]]:0); 
				dp[i][j] = max(dp[i-1][j],temp); 
			}
		}
		printf("Scenario #%d: %d\n",k+1,dp[N][K]);	
	}
	return 0;
}
