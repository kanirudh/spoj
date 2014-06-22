/* 	SPOJ Problem : Adjacent Bit Counts
	Author : Anirudh Agrawal
	Solution : Using memoization and Dynamic Programming one can easily arrive at the given solution.
*/

#include <cstdio>

int memo[101][100];

void init(){
	memo[0][0] = 1;
	memo[1][0]=2;
	for(int i=2;i<101;i++){
		memo[i][0] = memo[i-1][0]+memo[i-2][0];	
		memo[i][i-1] = 1;
	}		
	for(int i=2;i<101;i++){
		for(int j=1;j<i-1;j++){
			memo[i][j] = memo[i-1][j]+memo[i-2][j]+memo[i-1][j-1]-memo[i-2][j-1];    
		}
	}
}

int main()
{
	init();	
	int test,n,k,temp;
	scanf("%d",&test);
	for(int i=1;i<test+1;i++){
	    scanf("%d %d %d",&temp,&n,&k);
	    printf("%d %d\n",i,memo[n][k]);
	}	
	return 0;
}
