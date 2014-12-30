#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long i64;

int main()
{
	vector<i64> input;
	int N;
	i64 temp,maxl = 1;
	scanf("%d",&N);
	for(int i=0;i<N;i++){ scanf("%lld",&temp); input.push_back(temp);}
	sort(input.rbegin(),input.rend());
	while( maxl <= input[0] ) maxl = maxl << 1;
	maxl >>= 1;
	int i,start = 0;
	for(; maxl >= 1;maxl >>=1){
		//Pivoting		
		for(i = start; i< N && (input[i] &  maxl) == 0;i++ );
		if( i >= N) continue;
		swap(input[start],input[i]);
		for(i = 0;i<N;i++){
			if(i!=start && (input[i] & maxl) != 0) input[i] = input[i]^input[start];
		}
		start++;
	}	
	i64 result = 0;
	// Note here that elements after the index corresponding to highest bit will be zero
	for(int i=0;i<N;i++){
			result = result^input[i];
	}
	printf("%lld\n",result);
	return 0;
}
