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

const int MAXN = 1E5+2;
i64 dp[MAXN];

i64 solve(long row[],int size){
	dp[size] = 0;
	dp[size+1] = 0;
	for(int i = size-1;i>=0;i--){
		dp[i] = max( (i64)row[i] + dp[i+2] , dp[i+1]); 	
	}
	return dp[0];
}

int main()
{
	long row[MAXN],rows[MAXN];
	int m,n,temp;
	scanf("%d %d",&m,&n);
	while( m and n){
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++) scanf("%ld",&row[j]);
			rows[i] = solve(row,n);
		}
		//Now solving for the overrall problem
		printf("%lld\n",solve(rows,m));
		scanf("%d %d",&m,&n);
	}	
	return 0;
}
