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
const int MAXN = 101;

int matrix[MAXN][MAXN],dp[2*MAXN][MAXN][MAXN],f[2*MAXN][MAXN][MAXN];
int R,C,cs;

int solve(int step,int r1,int r2){
	if(step == R+C-2){
		if( step - r1 == C-1 and r1 == R-1 and r1 == r2) return matrix[r1][step-r1]-1; 
		else return -1;
	}
	if( f[step][r1][r2] == cs) return dp[step][r1][r2];
	f[step][r1][r2] = cs;
	int c1 = step - r1;int c2 = step - r2;
	int &ret = dp[step][r1][r2]; ret = -1; 
	if(c1 < C and c2 < C and matrix[r1][c1] and matrix[r2][c2]){
		ret = solve(step + 1,r1,r2);
		if(r1 +1 < R) ret = max(ret,solve(step+1,r1+1,r2));
		if(r2 + 1 <R) ret = max(ret,solve(step+1,r1,r2+1));
		if(r1 + 1< R and r2 + 1<R) ret = max(ret,solve(step+1,r1+1,r2+1));
		if(ret != -1){
			if(matrix[r1][c1] == 2) ret++;
			if( r1 != r2 and matrix[r2][c2] == 2) ret++;			
		}
	}
	return ret;
}

int main()
{
	int test,h,w;
	char temp;
	scanf("%d",&test);
	for(cs = 1;cs < test+1;cs++){
		scanf("%d %d",&C,&R);
		//cout<<R<<" "<<C<<endl;
		getchar();
		for(int i=0;i<R;i++){
			for(int j=0;j<C;j++){
				temp = getchar();
				if(temp == '*') matrix[i][j] = 2;
				else if(temp == '.') matrix[i][j] = 1;
				else matrix[i][j] = 0;
				//printf("%d ",matrix[i][j]);		
			}
			getchar();
			//printf("\n");
		}
		printf("%d\n",solve(0,0,0));		
	}
	return 0;
}
