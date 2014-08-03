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

int main()
{
	i64 N;
	int p;
	scanf("%lld",&N);
	while(N){
		for(i64 i = 2;i*i <= N;i++){
			//printf("%lld\n",i);
			p = 0;
			if(N % i == 0) {
				//printf("%lld",N);
				while(N % i == 0){
					p++;
					N /= i;
				}
				printf("%lld^%d ",i,p);	
			}		
		}
		if(N>1) printf("%lld^1\n",N);
		scanf("%lld",&N);
	}
	return 0;
}
