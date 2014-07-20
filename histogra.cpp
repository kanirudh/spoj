#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

int main()
{
	int n,temp;
	int *array = NULL;
	ll result = 0;	
	scanf("%d",&n);
	while(n){
		stack<int> mystack;
		array = new int[n];
		result = 0;
		for(int i=0;i<n;i++) scanf("%d",array + i);
		int i = 0;
		while(i<n){
			if(mystack.empty() or array[mystack.top()] <= array[i]) mystack.push(i++);
			else{
				int top = mystack.top();
				mystack.pop();
				ll tresult = (ll)array[top] * (mystack.empty()?i:i-mystack.top()-1);
				if(tresult > result) result = tresult; 
			}
		}	
		while(!mystack.empty()){
			int top = mystack.top();
			mystack.pop();
			ll tresult = (ll)array[top]*(mystack.empty()?i:i - mystack.top() -1);
			if(tresult > result) result = tresult; 	
		}
		printf("%lld\n",result);
		delete[] array;
		scanf("%d",&n);	
	}	
	return 0;
}
