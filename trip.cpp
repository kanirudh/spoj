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
const int MAXN = 81;
int dp[MAXN][MAXN],lcslen,l1,l2;
string string1,string2;
char output[MAXN];

int lcs(){
	for(int i=l1;i>=0;i--) dp[i][l2-1] = 0;
	for(int i=l2;i>=0;i--) dp[l1-1][i] = 0;
	for(int i=l1-1;i>=0;i--) for(int j=l2;j>=0;j--){
		if(string1[i] == string2[j]) dp[i][j] = 1 + dp[i+1][j+1];
		else dp[i][j] = max(dp[i+1][j],dp[i][j+1]);	
	}
	return dp[0][0];
}

void printAll(int na,int nb,int d){
	if(d == lcslen){
		output[d] = 0;
		puts(output);
		return;
	}
	else if(na == l1 or nb == l2) return ;
	else{
		for(char ch = 'a';ch != 'z';ch++){
			bool done = false;
			for(int i=na;i<l1;i++){
				if(string1[i] == ch){
					for(int j=nb;j<l2;j++){
						if(string2[j] == string1[i] and dp[i][j] == lcslen-d){
							done = true;
							output[d] = string1[i];	
							printAll(i+1,j+1,d+1);
							break;
						}
					}
				}
				if(done) break;
			}
		}
	}
}

int main()
{
	int test;
	scanf("%d",&test);
	getchar();
	while(test--){
		getline(cin,string1);
		getline(cin,string2);
		l1 = string1.size();
		l2 = string2.size();
		lcslen = lcs();
		printAll(0,0,0);
		if(test) printf("\n");
	}
	return 0;
}
