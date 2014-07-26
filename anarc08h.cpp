/* This is simple case of josephus problem. Read it up on wikipedia for ex
planation*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
	int N,D;
	scanf("%d %d",&N,&D);
	while(N and D){
		int result = 0;
		for(int i=1;i<N+1;i++) result = (result + D) %i;	
		printf("%d %d %d\n",N,D,result+1);
		scanf("%d %d",&N,&D);
	}
	return 0;
}
