#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <climits>
#define i64 long long

using namespace std;

long mod = 1E9+9;

long input[50001];

int countof(long value,int length){
	int count =0;
	for(int i=1;i<=length;i++) if(input[i] == value) count++;
	return count;	
}

i64 modexp(i64 base,i64 pow){
	i64 result = 1;
	base = base%mod;
	while(pow){
		if(pow % 2==1) result = (result*base)%mod;
		base = (base*base)%mod;
		pow = pow >> 1;
	}
	return result%mod;
}

int main()
{
	int test,n;
	long max;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		max = LONG_MIN;
		for(int i=1;i<n+1;i++){
			scanf("%ld",&input[i]);
			max = max > input[i]?max: input[i];
		}
		if(max < 0) printf("%ld %d\n",max%mod,countof(max,n));
		else if(max == 0) printf("0 %lld\n",modexp(2,countof(0,n))-1);
		else{
			i64 sum = 0;
			for(int i=1;i<n+1;i++){
				if(input[i]>0) sum += input[i];
			}
			printf("%lld %lld\n",sum,modexp(2,countof(0,n)));
		}	
	}
	return 0;
}
