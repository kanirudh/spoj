#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main()
{
	int test,n,k,temp;
	scanf("%d",&test);

	while(test--){
		scanf("%d %d",&n,&k);
		long *heights = new long[n];
		for(int i=0;i<n;i++) scanf("%ld",heights+i);
		sort(heights,heights+n);
		//for(int i=0;i<n;i++) cout<<heights[i]<<" ";	
		long  *diff = new long[n-k+1];
		//cout<<"\n";
		for(int i=0;i<n-k+1;i++){
			 diff[i] = heights[i+k-1] - heights[i];
			//cout<<diff[i]<<" ";	
		}
		long min = LONG_MAX;
		for(int i=0;i<n-k+1;i++) min = min<diff[i] ? min:diff[i];
		cout<<min<<"\n";
		delete[] heights;
		delete[] diff;
	}
	return 0;
}
