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

int main()
{
	queue<int> mq;
	int n,M,temp;
	int sum = 0,max = INT_MIN;
	scanf("%d %d",&n,&M);
	for(int i=0;i<n;i++){
		scanf("%d",&temp);
		sum+= temp;
		mq.push(temp);
		while(sum>M ) {
			int t = mq.front();
			mq.pop();
			sum-= t;
		}
		if(sum>max) max = sum;
	}
	printf("%d\n",max);
	return 0;
}
