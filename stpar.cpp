#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
	int n,temp;
	bool possible = true;
	scanf("%d",&n);
	while(n){
		//printf("%d\n",n);
		stack<int> side;
		int last = 0;
		possible = true;
		for(int i=0;i<n;i++){
			scanf("%d",&temp);
			if(temp == last + 1){
				last++;
				while(!side.empty() and side.top() == last+1) {
					side.pop();last++;
				}
			}	
			else{
				if(!side.empty() and temp > side.top() ) possible = false;
				else side.push(temp);
			}
			//if(possible) printf("%d",temp);
		}
		if(possible) printf("yes\n");
		else printf("no\n");	
		scanf("%d",&n);
	}
	return 0;
}
