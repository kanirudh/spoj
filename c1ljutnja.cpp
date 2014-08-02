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

long a[100001];

int main()
{
	long m,n;
	scanf("%ld %ld",&m,&n);
	i64 ang,result = 0,sum = 0;
	for(int i=0;i<n;i++){
		scanf("%ld",&a[i]);
		sum += a[i];
	}
	sort(a,a+n);
	sum -= m;
	for(int i=0;i<n;i++){
		ang = min((i64)a[i],sum/(n-i));
		sum -= ang;
		result += (i64)ang*ang;
	}
	printf("%lld\n",result);
	return 0;
}
