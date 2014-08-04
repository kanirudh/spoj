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

int main()
{
	int test,W,B;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&W,&B);
		if(B%2==0) printf("0.000000\n");
		else printf("1.000000\n");
	}
	return 0;
}
