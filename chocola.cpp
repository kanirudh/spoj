/*Simple greedy approach is sufficient in this */
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
	int test,m,n;
	scanf("%d",&test);
	int *xvalues,*yvalues;
	while(test--){
		scanf("%d %d",&m,&n);
		xvalues = new int[m-1];
		yvalues = new int[n-1];
		for(int i=0;i<m-1;i++) scanf("%d",xvalues+i);
		for(int i=0;i<n-1;i++) scanf("%d",yvalues+i);
		sort(xvalues,xvalues+m-1);
		sort(yvalues,yvalues+n-1);
		int x = m-2;
		int y = n-2;
		int result = 0;
		while( x>=0 or y>=0){
			if(y==-1 or (x >=0 and xvalues[x] > yvalues[y])) {
				result += xvalues[x--]*(n-1-y);		
			}
			else{
				result += yvalues[y--]*(m-1-x);
			}	
		}
		printf("%d\n",result);
		delete[] xvalues;
		delete[] yvalues;
	}
	return 0;
}
