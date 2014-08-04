#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#define i64 long long

using namespace std;

i64 b[51];

int solve(i64 N,int size){
	int i;
	stack<int> pos;
	for(int i = size;i>0;i--){
		if(b[i] <= N){
			pos.push(i);
			N -= b[i];
		}
	}
	if(N != 0){
		printf("-1\n");
	}			
	else {
		while(pos.size()>1){
			printf("%d ",pos.top());
			pos.pop();
		}
		printf("%d\n",pos.top());
	}
}

int main()
{
	int test,K,temp;
	i64 N;
	b[0] = 0;
	scanf("%d",&test);
	//cout<<test<<endl;
	while(test--){
		scanf("%lld %d",&N,&K);
		//cout<<N<<" "<<K<<endl;
		for(int i=0;i<K;i++){
			scanf("%d",&temp);
			b[i+1] = 2*b[i] + temp;  
		}
		//for(int i=0;i<K;i++) printf("%lld\n",b[i+1]);
		solve(N,K);		
	}
	return 0;
}
