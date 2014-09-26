#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	int test,n,temp;
	map<int,int> mymap;
	map<int,int>::iterator it;
	int index,max;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			if(mymap.find(temp) != mymap.end()) mymap[temp] = mymap[temp] +1 ;
			else mymap.insert(pair<int,int>(temp,1));
		}
		max = 0;
		index = 0;
		for(it = mymap.begin();it != mymap.end();++it){
			if(it->second>max){
				max = it->second;
				index = it->first;
			}
		}
		if(2*max >n) printf("YES %d\n",index);
		else printf("NO\n");
		mymap.clear();
	}
	return 0;
}
