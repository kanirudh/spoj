#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int storedinfo[13][99];

void precomputation(){
	for(int i=1;i<13;i++) storedinfo[i][0] = 1;
	for(int i=0;i<99;i++) storedinfo[0][i] = 0;
	for(int i=1;i<13;i++){
		for(int j=1;j<99;j++){
			storedinfo[i][j] = 0;
			for(int k = 0 ;k<i and k<=j;k++){
				storedinfo[i][j] += storedinfo[i-1][j-k] ;
			}	
		}
	}
}

int main()
{
	int test,n,k;
	precomputation();
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&n,&k);
		printf("%d\n",storedinfo[n][k]);
	}
	return 0;
}
