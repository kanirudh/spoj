#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

typedef long long ll;

int primes[1010];
int sp2[501];
int memo[7994][4];

int findprimes(int limit){
	int i,count = 1;
 	int *isprime = new int[limit];
	for( i=0;i<limit;i++) isprime[i] = 1;
	for( i=2;i<limit;i+=2) isprime[i] =0;
	primes[0] = 2;
	for( i=3;i*i<limit;i+=2){
		if(isprime[i]){
			primes[count++] = i;
			for(int j=i*i;j<limit;j+=i) isprime[j] = 0;
		}
	}
	for(;i<limit;i+=2) if(isprime[i]) primes[count++]=i;
	return count;
}

int precomputeprimes(int count){
	int count2=0;	
	for(int i=0;i<count;i++){
		int temp1,temp = primes[i];
		bool flag = true;
		int m = 0;
		int n = sqrt(temp);
		while(flag and m*m<temp){
			temp1 = m*m+n*n;
			if(temp1==temp) flag = false;
			if(temp1<temp) m++;
			else n--;
		}
		if(!flag) sp2[count2++] = temp;
	}
	return count2;
}

int precompute(){
	int nprimes = findprimes(7994);
	for(int i=0;i<7994;i++) memo[i][1] = 1;
	int nsprimes = precomputeprimes(nprimes);
	for(int i=2;i<4;i++){
		memo[0][i] = 1;
		memo[1][i] = 1;
	}
	for(int i=2;i<7994;i++){
		for(int j=2;j<4;j++){
			memo[i][j] = 0;	
			for(int k=1;k<=j;k++){
				memo[i][j] += memo[i-k][k];
			}
		}
	}	
}

int main()
{
	precompute();	
	int test,n,k;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&n,&k);
		printf("%d\n",memo[sp2[n-1]][k]);
	}
	return 0;
}
