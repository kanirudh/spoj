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
const int MAXN = 1E6;
int  N, trees[MAXN];

i64 woodcut(i64 height){
	i64 wood = 0;
	for(int i=0;i<N;i++){
		if( trees[i] > height ) wood += trees[i] - height;
	}
	return wood;
}

int main()
{
	i64 M,maxheight= INT_MIN;
	scanf("%d %lld",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&trees[i]);
		maxheight = maxheight>trees[i]?maxheight:trees[i];
	}
	i64 mid,left = 0,right = maxheight;
	maxheight = 0;
	while(left <= right){
		mid = (left + right ) / 2;
		i64 wood = woodcut(mid);
		if( wood == M){ maxheight = mid; break;}
		else if(wood < M ) right = mid - 1;
		else {left = mid + 1;maxheight = max(maxheight,mid);}
	}
	printf("%lld\n",maxheight);
	return 0;
}
