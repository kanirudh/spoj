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
const int MAXN = 501;

int S[MAXN][MAXN],dp[MAXN][MAXN];

int main()
{	
	int test,r,c;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&r,&c);
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++) scanf("%d",&S[i][j]);
		}
		dp[r-1][c-1] = 1;
		for(int i=c-2;i>=0;i--){
			dp[r-1][i] = max(1,dp[r-1][i+1] - S[r-1][i]);
		}
		for(int i=r-2;i>=0;i--){
			dp[i][c-1] = max(1,dp[i+1][c-1] - S[i][c-1]);
		}
		for(int i=r-2;i>=0;i--) for(int j=c-2;j>=0;j--){
			dp[i][j] = max(1,min(dp[i+1][j],dp[i][j+1])-S[i][j]);
		}
		printf("%d\n",dp[0][0]);
	}
	return 0;
}
