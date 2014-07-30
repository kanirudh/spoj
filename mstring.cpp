#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;

int len1,len2,dp[1001][1001];

string voki,toki;

int search(string a,int start,int end,char temp){
	int i = start;
	for(;i<end;i++)	if(temp == a[i]) return i;
	return -1;
}

int solve(int x,int y){
	if( x == len1) return 1500;
	else if(dp[x][y]!=-1) return dp[x][y];
	else{
		for(int i=y;i<len2;i++){
			if(voki[x] == toki[i]){
				dp[x][y] = min(solve(x+1,y),1 + solve(x+1,i+1));
				return dp[x][y];
			}
		}
		return 1;
	}
}

int main()
{
	getline(cin,voki);
	getline(cin,toki);
	len1 = voki.size();
	len2 = toki.size();
	memset(dp,-1,sizeof(dp));
	printf("%d\n",solve(0,0));
	return 0;
}
