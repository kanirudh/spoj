#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

typedef long long ll;

int array[100],dp[100][100];

int csum(int a,int b){
	int sum = 0;
	for(int i=a;i<=b;i++) sum = (sum+array[i])%100;
	return sum;
}

int solve(int a,int b){
	if(a==b) return 0;
	if(dp[a][b] != -1) return dp[a][b];
	
	int ret = INT_MAX;
	for(int k=a;k<b;k++){
		int temp = solve(a,k) + solve(k+1,b) + csum(a,k)*csum(k+1,b);
		if(ret > temp) ret = temp;
	}	
	dp[a][b] = ret;
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)==1){
		//cout<<n<<endl;
		for(int i=0;i<n;i++) for(int j=0;j<n;j++) dp[i][j] = -1;
		for(int i=0;i<n;i++) scanf("%d",&array[i]);
		printf("%d\n",solve(0,n-1));
	}
	return 0;
}
