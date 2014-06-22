#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>

using namespace std;

int predicate(vector<long>positions,int C,int value);

int binarysearch(int start,int end,vector<long>positions,int C);

int main()
{
	int test,N,C;
	int temp;
	scanf("%d",&test);
	vector<long>positions;
	while(test--){
		scanf("%d %d",&N,&C);
		for(int i=0;i<N;i++){
			scanf("%d",&temp);
			positions.push_back(temp);
		}
		sort(positions.begin(),positions.end());
		//for(int i=0;i<positions.size();i++) cout<<positions[i]<<" ";	
		printf("%d\n",binarysearch(0,positions.back(),positions,C));
		positions.clear();
	}
	return 0;
}

int predicate(vector<long>positions,int C,int value){
	int cowsplaced = 1;
	int lastplaced = positions[0];
	for(int i=1;i<positions.size();i++){
		if(positions[i] - lastplaced >= value){
			cowsplaced++;
			lastplaced = positions[i];
		}
		if(cowsplaced == C) return 1;
	}
	return 0;
}

int binarysearch(int start,int end,vector<long>positions,int C){
	if(start == end) return start;	
	int mid = start + (end-start+1)/2;
	if(predicate(positions,C,mid) == 0 ) return binarysearch(start,mid-1,positions,C);
	else return binarysearch(mid,end,positions,C);
}
