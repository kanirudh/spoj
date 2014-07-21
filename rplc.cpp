/* Just find what will be the minimum health at any point of time*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

typedef long long ll;

int main()
{
	int test,n,temp;
	ll sum,minimum;
	scanf("%d",&test);
	for(int j=0;j<test;j++){
		scanf("%d",&n);
		sum = 0;
		minimum = LONG_MAX;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			sum += temp;
			if(minimum > sum) minimum = sum;
		}
		minimum = minimum>0? 1:(-1*minimum)+1;
		printf("Scenario #%d: %lld\n",j+1,minimum);
	}
	return 0;
}
