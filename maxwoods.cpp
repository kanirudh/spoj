/*
	User: kanirudh
	Category: DP
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <climits>
#define i64 long long

using namespace std;
const int MAXN = 202;

int matrix[MAXN][MAXN],dp[MAXN][MAXN][2];

int solve(int m,int n){
	memset(dp,0,sizeof(dp));
	for(int i = m;i>0;i--){
		for(int j = 1;j<=n;j++)	if(matrix[i][j]){
				dp[i][j][0] = max(dp[i][j-1][0],dp[i+1][j][1])+matrix[i][j]-1;
		}
		for(int j = n;j>0;j--)	if(matrix[i][j]){
				dp[i][j][1] = max(dp[i][j+1][1],dp[i+1][j][0])+matrix[i][j]-1;
		}
	}	
	return dp[1][1][1];
}

int main()
{
	int test,m,n;
	char temp;
	string a;
	scanf("%d",&test);
	//cout<<test<<endl;
	while(test--){
		scanf("%d %d",&m,&n);getchar();
		//cout<<m<<" "<<n<<endl;
		for(int i=1;i<=m;i++){
			getline(cin,a);
			for(int j=1;j<=n;j++){
				temp = a[j-1];
				if(temp =='T') matrix[i][j] = 2;
				else if(temp =='#') matrix[i][j] = 0;
				else matrix[i][j] = 1;
				//printf("%d ",matrix[i][j]);
			}
			//cout<<endl;
			//getchar();	
		}
		printf("%d\n",solve(m,n));
	}
	return 0;
}
