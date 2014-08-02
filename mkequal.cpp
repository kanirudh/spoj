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

//int array[1E5+1];

int main()
{
	int test,n,temp;
	long sum =0;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		sum =0;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			sum+=temp;
		}
		if(sum%n==0) printf("%d\n",n);
		else printf("%d\n",n-1);
	}
	return 0;
}
