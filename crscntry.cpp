#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

int agness[2005],tom[2005];
int memo[2001][2001];

int lcs(int l1,int l2){
	for(int i=0;i<l1+1;i++) memo[i][0] = 0;
	for(int i=1;i<l2+1;i++) memo[0][i] = 0;
	for(int i=1;i<l1+1;i++){
		for(int j=1;j<l2+1;j++){
			if(agness[i-1] == tom[j-1])  memo[i][j] = memo[i-1][j-1] +1;
			else memo[i][j] = max(memo[i-1][j],memo[i][j-1]); 
		}
	}	
	return memo[l1][l2];	
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		int count1 = 0,count2=0;
		int temp = 1;
		int maxl = 0;
		scanf("%d",&temp);
		while(temp){
			agness[count1++] = temp;
			scanf("%d",&temp);
		}
		//cout<<"printing agness route\n";
		//for(int i=0;i<count1;i++) printf("%d\n",agness[i]);		
		scanf("%d",&temp);
		while(temp){
			count2=0;
			while(temp){
				tom[count2++] = temp;	
				scanf("%d",&temp);
			}
			//cout<<"Printin the current route for tom\n";
			//for(int i=0;i<count2;i++) printf("%d\n",tom[i]);
			maxl = max(maxl,lcs(count1,count2));
			scanf("%d",&temp); 
		}
		printf("%d\n",maxl);
	}
	return 0;
}
