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
	int n;
	int *numbers;
	scanf("%d",&n);
	while(n>0){
		//cout<<n<<endl;
		numbers = new int[n];
		for(int i=0;i<n;i++) scanf("%d",numbers+i);
		//for(int i=0;i<n;i++) cout<<numbers[i]<<endl;
		sort(numbers,numbers+n);
		bool flag = true;
		for(int i=0;flag and i<n-1;i++) flag = (numbers[i+1]-numbers[i]<=200);
		flag = flag and (1422-numbers[n-1]) <=100;
		if(flag) printf("POSSIBLE\n");
		else printf("IMPOSSIBLE\n");	
		scanf("%d",&n);
	}
	return 0;
}
