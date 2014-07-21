#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
	int n;
	int *prices,*students;
	scanf("%d",&n);
	while(n){	
		prices = new int[n];
		students = new int[n];
		for(int i=0;i<n;i++) scanf("%d",students+i);
		for(int i=0;i<n;i++)scanf("%d",prices+i);
		unsigned long long result = 0;
		sort(students,students+n);
		sort(prices,prices+n);
		for(int i=0;i<n;i++){
			result += (unsigned long long)students[i]*prices[n-1-i];
		}
		printf("%lld\n",result);
		scanf("%d",&n);
	}
	return 0;
}
