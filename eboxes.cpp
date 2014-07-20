#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int test;
	int N,K,T,F;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d %d %d",&N,&K,&T,&F);
		printf("%d\n",N + ((F-N)*K)/(K-1));
	}
	return 0;
}
