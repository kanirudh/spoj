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

int bsearch(int *array,int lo,int hi,int value){
	int mid;
	while(lo<=hi){
		mid = (lo+hi)/2;
		if(array[mid] == value) return mid;
		else if(array[mid] > value ) hi = mid-1; 
		else lo = mid+1;
	}	
	return -1;
}

int main()
{
	int test,n,m,count;
	scanf("%d",&test);
	//printf("%d\n",test);
	while(test--){
		scanf("%d %d",&n,&m);
		//printf("%d %d\n",n,m);
		count = 0;
		int *array = new int[n];
		for(int i=0;i<n;i++) scanf("%d",array+i);
		sort(array,array+n);
		for(int i=0;i<n;i++){
			if(bsearch(array,i+1,n-1,m-array[i])!= -1) count++;
		}
		printf("%d\n",count);
		delete[] array;
	}
	return 0;
}
