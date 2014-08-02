#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;

int len,dp[32][256];
char input[32];

int solve(int pos,int prev){
	if(pos == len) return 1;
	else if(dp[pos][prev] != -1) return dp[pos][prev];
	else{
		dp[pos][prev]  = 0;
		for(int i=pos,sum =0;i<len;i++){
			sum += input[i]-'0';
			if(sum >= prev) dp[pos][prev] += solve(i+1,sum);
		}
	}
	return dp[pos][prev];
}

int main()
{
	int test = 0;
	while(scanf("%s",input) != 0 and isdigit(input[0])){
		len = strlen(input);
		memset(dp,-1,sizeof(dp));
		printf("%d. %d\n",++test,solve(0,0));
	}
	return 0;
}
