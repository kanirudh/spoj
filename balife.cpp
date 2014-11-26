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
	int N, data[9001],left[9001],right[9001],steps,d;
	i64 sum ;
	scanf("%d",&N);
	while( N != -1){
		sum = 0;
		for(int i=0;i<N;i++){
			scanf("%d",&data[i]);
			sum += data[i];
		}
		//printf("%d %lld\n",N,sum);
		if( sum % N != 0) printf("-1\n");
		else{
			d = sum / N;
		    left[0] = 0;
			for(int i=0;i<N-1;i++){
				int V = data[i] + right[i-1] - left[i];
				if(d > V ){
					right[i] = 0;
					left[i+1] = d - V;
				}
				else{
					right[i] = V - d;
					left[i+1] = 0;
				}
			}
			right[N-1] = 0;
			int max = INT_MIN;
			for(int i=0;i<N;i++){
				if(max < left[i] ) max = left[i];
				if(max < right[i] ) max = right[i];
			}
			printf("%d\n",max);
			
		}
		scanf("%d",&N);
	}
	return 0;
}
