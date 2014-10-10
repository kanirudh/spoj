#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <string>
#include <climits>
#define i64 unsigned long long

const i64 mod = 1E9+7;

using namespace std;

int main()
{
	int test,n;
	i64 a,b,c,f,sum;
	scanf("%d",&test);
	while(test--){
		scanf("%llu %llu %llu %d",&a,&b,&c,&n);
		//printf("%llu %llu %llu %d\n",a,b,c,n);
		priority_queue<int,vector<int>,greater<int> >  min_heap;
		priority_queue<int,vector<int>,less<int> > max_heap;
		sum = 1;
		max_heap.push(1);
		for(int i=1;i<n;i++){
			f = a*max_heap.top();
			if( f > mod ) f = f% mod;
			f += b*(i+1) + c;
			if( f > mod ) f = f%mod;
			sum += f;
			if( f > max_heap.top()) min_heap.push(f);
			else max_heap.push(f);
			if(min_heap.size() - max_heap.size() == 1 ){
				max_heap.push(min_heap.top());
				min_heap.pop();
			}
			else if(max_heap.size() - min_heap.size() == 2){
				min_heap.push(max_heap.top());
				max_heap.pop();
			} 
		}
		printf("%llu\n",sum);		
	}
	return 0;
}
