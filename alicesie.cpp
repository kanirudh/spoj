#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
	int test,n;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		if(n%2==0)printf("%d\n",n/2);
		else printf("%d\n",(n+1)/2);			
	}
	
	return 0;
}
