#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

long mod = 1E7+7;

long long modular_exponentiation(long long base,long long  pow){
	long long result = 1;
	base = base%mod;
	while(pow>0){
		if(pow%2==1) result = (result*base)%mod;
		pow = pow >>1;
		base = (base*base) %mod;
	}
	return result;
}

int main()
{
	long n,k;
	scanf("%ld %ld",&n,&k);
	while(n and k){
		ll temp = modular_exponentiation(n,k);
		//cout<<temp<<endl;
		temp = (temp+2*modular_exponentiation(n-1,k))%mod;
		//cout<<temp<<endl;
		temp = (temp+modular_exponentiation(n,n))%mod;
		//cout<<temp<<endl;
		temp = (temp+2*modular_exponentiation(n-1,n-1))%mod;
		printf("%lld\n",temp);
		scanf("%ld %ld",&n,&k);
	}
	return 0;
}
