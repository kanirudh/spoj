#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <climits>
#include <cmath>
#define i64 long long

using namespace std;
const int MAXN = 1E5+1;
int magneto[MAXN],wolverine[MAXN];

int lis(int size){
	int *P = new int[size];
	int *M = new int[size+1];
	int lo,hi,mid,length = 0;
	for(int i=0;i<size;i++){
		lo = 1;hi = length;
		while(lo <= hi){
			mid = (lo+hi)/2;
			if(wolverine[M[mid]] < wolverine[i]) lo = mid + 1;
			else hi = mid -1;
		}
		int newL = lo;
		P[i] = M[newL-1];
		if(newL > length){
			M[newL] = i;
			length = newL;
		}
		else if ( wolverine[i] < wolverine[M[newL]]) M[newL] = i;
	}
	return length;
}

int main()
{
	int test,n,temp;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);	
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			magneto[temp] = i;
		}
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			wolverine[i] = magneto[temp];
		}
		printf("%d\n",lis(n));	
	}
	return 0;
}
