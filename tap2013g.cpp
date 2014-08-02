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
	int S;
	scanf("%d",&S);
	long *Q = new long[S];
	long *N = new long[S];
	for(int i=0;i<S;i++) scanf("%ld",Q+i);
	for(int i=0;i<S;i++) scanf("%ld",N+i);
	sort(Q,Q+S);
	sort(N,N+S);
	int i=0,j=0;
	while(i<S){
		if(N[i] > Q[j]){ i++;j++;}
		else i++;
	}
	printf("%d\n",j);	
	return 0;
}
