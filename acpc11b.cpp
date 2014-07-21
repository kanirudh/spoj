#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> mountain1,mountain2;

int binarySearch(int start,int end,int value){
	if(start==end) return start;
	int mid = (start + end)/2;
	if(mountain1[mid] == value) return mid;
	if(mountain1[mid] > value) return binarySearch(start,mid,value);
	else return binarySearch(mid+1,end,value);
}

int main()
{
	int test,n,m;
	int temp,left,right;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			mountain1.push_back(temp);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d",&temp);
			mountain2.push_back(temp);
		}
		//printf("%d %lu %d %lu\n",n,mountain1.size(),m,mountain2.size()); 
	    sort(mountain1.begin(),mountain1.end());
		//for(int i=0;i<n;i++) printf("%d %d\n",i,mountain1[i]);	
		int minimum = INT_MAX;
		for(int i=0;i<m;i++){
			
			//printf("Searching for %d ",mountain2[i]);
			int index = binarySearch(0,n-1,mountain2[i]);
			//printf(" Index: %d\n",index);
			int dist = abs(mountain1[index] - mountain2[i]);
			if(index > 0){
				left = abs(mountain1[index-1] - mountain2[i]);
				dist = min(dist,left);
			}
			if(index < m-1){
				right = abs(mountain1[index+1] - mountain2[i]);
				dist = min(dist,right);		
			} 
			if(minimum > dist) minimum = dist;
		}
		printf("%d\n",minimum);
		mountain1.clear();
		mountain2.clear();
	}
	return 0;
}
