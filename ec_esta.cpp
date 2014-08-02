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
	int test,n;
	long temp, median = -1;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		median = -1;
		priority_queue<long,vector<long>,greater<long> > minheap;
		priority_queue<long> maxheap;
		for(int i=0;i<n;i++){
			scanf("%ld",&temp);
			//printf("%d  ",temp);
			if(temp <=median || median ==-1) maxheap.push(temp);
			else minheap.push(temp);
			if(minheap.size()>maxheap.size()){
				maxheap.push(minheap.top());
				minheap.pop();
			}
			if(maxheap.size()-minheap.size() > 1){
				minheap.push(maxheap.top());
				maxheap.pop();
			}
			//printf("%lu %lu\n",maxheap.size(),minheap.size());
			if(minheap.size() != maxheap.size()) printf("%ld\n",(median = maxheap.top()));
			else {
				double ans = (double)(maxheap.top()+minheap.top())/2.0;
				if(ans - (long)ans == 0) printf("%ld\n",(median = (long)ans));
				else printf("%ld.5\n",(median = (long)ans));	
			}
			//if(maxheap.size()>0) printf("Max: %d\n",maxheap.top());
			//if(minheap.size()) printf("Min : %d\n",minheap.top());
		}
	}
	return 0;
}
