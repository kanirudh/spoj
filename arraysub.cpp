/* Explanation : In a double ended queue store the values realted ot hte current window. Pop the the values if they are smaller than the current input values 
beacuse they do not matter*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

void findKMax(int *numbers,int n,int k){
	deque<int> Qk(k);
	int i=0;
	for(;i<k;i++){
		while(!Qk.empty() and numbers[i] >= numbers[Qk.back()]) Qk.pop_back();		
		Qk.push_back(i);
	}
	for(;i<n;i++){
		//Element at the front is the maximum
		printf("%d ",numbers[Qk.front()]);
		while(!Qk.empty() and Qk.front() <= i-k) Qk.pop_front();
		while(!Qk.empty() and numbers[i] >= numbers[Qk.back()]) Qk.pop_back();		
		Qk.push_back(i);
	}
	printf("%d\n",numbers[Qk.front()]);
}

int main()
{
	int n,k;
	scanf("%d",&n);
	int *numbers = new int[n];
	for(int i=0;i<n;i++) scanf("%d",numbers+i);
	scanf("%d",&k);
	findKMax(numbers,n,k);
	return 0;
}
