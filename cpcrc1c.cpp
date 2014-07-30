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

int ds[] = {0,1,3,6,10,15,21,28,36,45};

int digitsum(ll N){
	int result = 0;
	while(N){
		result += N%10;
		N /= 10;
	}
	return result; 
}

ll solve(ll N,ll multiplier){
	ll result = 0;
	ll temp;
	if(N > 0){
		int lastdig = N%10;
		N /= 10;
		result = ds[lastdig] + digitsum(N)*(1+lastdig);
		result *= multiplier;
		temp = 45*N;
		temp *= multiplier;
		result += temp + solve(N-1,10*multiplier);
	}	
	return result;
}

int main()
{
	ll a,b;
	scanf("%lld %lld",&a,&b);
	while(a != -1 and b != -1){
		printf("%lld\n",solve(b,1) - solve(a-1,1));
		scanf("%lld %lld",&a,&b);
	}
	return 0;
}
