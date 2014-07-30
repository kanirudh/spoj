#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;


int main()
{
	int x,k;
	int temp;
	scanf("%d %d",&x,&k);
	//printf("%d %d\n",x,k);
	int v[5];
	for(int i=0;i<k;i++) scanf("%d\n",&v[i]);
	for(int i=1;i<k;i++) v[i] += v[i-1];
	//for(int i=0;i<k;i++) printf("%d\n",v[i]);
	bool memo[100001];
	memo[0] = true;
	for(int i=1;i<100001;i++) memo[i] = false;
	for(int j=k-1;j>=0;j--){
		for(int i=v[j];i<=x;i++) memo[i] = (memo[i] or memo[i-v[j]]);
	}
	if(memo[x]) printf("YES\n");
	else printf("NO\n");
	return 0;
}
