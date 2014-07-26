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

int memo[1001][1001],greedy[1001][1001],array[1000];

int find_loss(int len){
	int first=true;
	//for(int i=0;i<len;i++) for(int j=0;j<len;j++) memo[i][j] = -1;
	for(int i=0;i<len;i++){
		memo[i][i] = array[len];
		greedy[i][i] = 0;
	}
	for(int i=0;i<len-1;i++){
		memo[i][i+1] = max(array[i],array[i+1]);
		greedy[i][i+1] = min(array[i],array[i+1]);
	}
	for(int i=len-1;i>=0;i--){
		for(int j=i+2;j<len;j++){
			first = true;
			int start,end;
			if(array[i+1]>=array[j]){
				memo[i][j] = memo[i+2][j] + array[i];
				start = i+2;end = j;
			}	
			else{
				memo[i][j] = memo[i+1][j-1] + array[i];
				start = i+1;end=j-1;
			}
			if(array[i] >= array[j-1]){
					if(memo[i][j]<memo[i+1][j-1]+array[j]){
						memo[i][j] = memo[i+1][j-1] + array[j];
						first = false;start = i+1;end =j-1;
					}
			}
			else{
				if(memo[i][j]<memo[i][j-2]+array[j]){
					memo[i][j] = memo[i][j-2] + array[j];
					first = false;start = i;end=j-2;
				}
			}
			if(first) greedy[i][j] = greedy[start][end] + max(array[i+1],array[j]);
			else greedy[i][j] = greedy[start][end] + max(array[i],array[j-1]);
		}
	}
	return memo[0][len-1]- greedy[0][len-1];
}

int main()
{
	int game = 0;
	int n;
	scanf("%d",&n);
	while(n){
		for(int i=0;i<n;i++) scanf("%d",&array[i]);
		printf("In game %d, the greedy strategy might lose by as many as %d points.\n",++game,find_loss(n));	
		scanf("%d",&n);	
	}
	return 0;
}
