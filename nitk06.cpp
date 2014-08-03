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
	int test,n,sum,temp;
	scanf("%d",&test);
	while(test--){
		sum = 0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			if(i&1) sum+= temp;
			else sum -= temp;
		}
		if(sum) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
