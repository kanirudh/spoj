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
const long mod = 1E6+7;

int main()
{
	int test;
	i64 n;
	scanf("%d",&test);
	while(test--){
		scanf("%lld",&n);
		printf("%lld\n", (n*(3*n+1)/2)%mod);
	}
	return 0;
}
