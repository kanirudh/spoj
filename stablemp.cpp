#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
#include <cmath>
#define i64 long long

using namespace std;

int men[501],women[501];

vector<queue<int> > menPref;
vector<vector<int> > womenPref;

bool prefernew(int n,int m1,int m2,int w){
	for(int i=0;i<n;i++){
		if(womenPref[w][i] == m1) return true;
		if(womenPref[w][i] == m2) return false;
	}
}

void stablemp(int n){
	queue<int> freemen;
	for(int i=1;i<=n;i++) freemen.push(i);
	memset(men,-1,sizeof(men));
	memset(women,-1,sizeof(women));
	while(!freemen.empty()){
		int current = freemen.front();
		freemen.pop();
		bool paired = false;
		while(!menPref[current].empty() and paired == false){
			int currentwomen = menPref[current].front();
			menPref[current].pop();
			if(women[currentwomen] == -1){
				women[currentwomen] = current;
				men[current] = currentwomen;
				paired = true;
			}
			else{
				int m2 = women[currentwomen];
				if(prefernew(n,current,m2,currentwomen)){
					freemen.push(m2);
					men[current] = currentwomen;
					women[currentwomen] = current;
					paired = true;				
				}	
			}
		}	
	}
};

int main()
{
	int test,n,temp;
	scanf("%d",&test);
	while(test--){
		womenPref.push_back(vector<int>());
		menPref.push_back(queue<int>());
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			womenPref.push_back(vector<int>());
			for(int j=0;j<n;j++){
				scanf("%d",&temp);
				womenPref[i+1].push_back(temp);
			}
		}
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			menPref.push_back(queue<int>());
			for(int j=0;j<n;j++){
				scanf("%d",&temp);
				menPref[i+1].push(temp);
			}
		}
		stablemp(n);
		for(int i=1;i<=n;i++) printf("%d %d\n",i,men[i]);
		menPref.clear();
		womenPref.clear();
	}
	return 0;
}
