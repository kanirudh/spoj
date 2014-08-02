#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
#include <map>
#define i64 long long

using namespace std;

int main()
{
	i64 ans = 0;
	map<i64,int> mymap;
	int test,n,temp;
	i64 sum = 0;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		sum = 0;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			sum += temp;
			mymap[sum]++;
		}
		ans = 0;
		for(map<i64,int>::iterator it = mymap.begin();it!=mymap.end();++it){
			i64 c = it->second;
			if(it->first == 0) ans += c + (c*(c-1))/2;
			else ans += (c*(c-1))/2;
		}
		mymap.clear();
		printf("%lld\n",ans);
	}
	return 0;
}
