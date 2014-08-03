#include <cstdio>
#include <iostream>
#include <climits>
#define i64 long long

using namespace std;

int m,k,pages[500];

bool ok(i64 sum){
	int cnt = 1;
	i64 current = 0;
	for(int i=0;i<m;i++){
		if(pages[i] > sum ){cnt = INT_MAX;break;}
		if( current + pages[i] > sum ) {
			cnt++;
			current = 0;
		}
		current += pages[i];
	}
	return cnt <= k;
}

void print(int idx,i64 s,int tk){
	i64 t=0;
	int i;
	for(i=idx;i>=0;i--){
		if(t+pages[i] > s || i+1 == tk-1){
			print(i,s,tk-1);
			break;
		} 
		t += pages[i];
	}
	if(i>=0) printf("/ ");
	for(i=i+1;i<=idx;i++){
		printf("%d ",pages[i]);
		if(i<m-1) printf(" ");
	}	
}

int main()
{
	int N;
	i64 mid,left,right=0;
	scanf("%d",&N);
	while(N--){
		scanf("%d %d",&m,&k);
		right = 0;
		for(int i=0;i<m;i++){
			scanf("%d",&pages[i]);
			right += pages[i];
		}
		left =0;
		while(left<right){
			mid = (left + right ) /2LL;
			if(ok(mid)) right = mid;
			else left = mid +1;
		}
		print(m-1,right,k);
		printf("\n");
	}
	return 0;
}
