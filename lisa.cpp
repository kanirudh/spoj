#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

typedef long long ll;

ll memo[105][105];
char expr[105];

ll f(int a,int b){
	if(a==b) return expr[a] -'0';
	else if(memo[a][b] != -1) return memo[a][b]; 
	else {
		ll ans = 0;
		for(int i=a+1;i<b;i+=2){
			ll left = f(a,i-1);
			ll right = f(i+1,b);
			if(expr[i] == '+') ans = max(ans,left+right);
			else ans = max(ans,left*right);
		}
		memo[a][b] = ans;
		return ans;
	}
}

ll maxValue(int length){
	for(int i=0;i<length;i++)for(int j=0;j<length;j++)  memo[i][j] = -1;
	return f(0,length-1);
}

ll f1(int a,int b){
	if(a==b) return expr[a] -'0';
	else if(memo[a][b] != -1) return memo[a][b]; 
	else {
		ll ans = INT_MAX;
		for(int i=a+1;i<b;i+=2){
			ll left = f1(a,i-1);
			ll right = f1(i+1,b);
			if(expr[i] == '+') ans = min(ans,left+right);
			else ans = min(ans,left*right);
		}
		memo[a][b] = ans;
		return ans;
	}
}

ll minValue(int length){
	for(int i=0;i<length;i++)for(int j=0;j<length;j++)  memo[i][j] = -1;
	return f1(0,length-1);
}

int main()
{
	int test;
	scanf("%d",&test);
	getchar();
	while(test--){
		int length=0;
		char temp;
		while((temp=getchar())!='\n') expr[length++] = temp;
		//cout<<minValue(length)<<endl;	
		printf("%lld %lld\n",maxValue(length),minValue(length));		
	}
	return 0;
}
