#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <cmath>

using namespace std;
typedef long long i64;
typedef vector<int> vi;

int main()
{
	int test,n,I,h,m,s;
	vi texttimes;
	int mingf;
	scanf("%d",&test);
	for(int t=0;t<test;t++){
		mingf = 0;
		scanf("%d",&n);
		for(int i = 0;i < n;i++){
			scanf("%d:%d:%d",&h,&m,&s);
			//printf("%d:%d:%d\n",h,m,s);
			texttimes.push_back(h*3600 + m * 60 + s);
		}
		scanf("%d",&I);
		sort(texttimes.begin(),texttimes.end());
		int *positions = new int[n];
		int i = 0;
		while(texttimes[i] - texttimes[0] < I and i < n)i++;
		positions[0] = i;
	 	for( i = 1;i < n;i++){
			int j= positions[i-1];
			while( texttimes[j] - texttimes[i] < I && j < n ) j++;
			positions[i] = j;	
		}
		for(int i=0;i<n;i++){ 
			//printf("%d %d\n",i,positions[i]);
			mingf = max( mingf,positions[i] - i);
		}
		printf("Case %d: %d\n",t+1,mingf);
		texttimes.clear();
	}
	return 0;
}
