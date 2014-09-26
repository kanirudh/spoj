#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#define i64 long long

using namespace std;

const unsigned int MAXN = 1e8;
const unsigned int LEN = 5761456; 
unsigned int isPrime[MAXN/64];
int a[LEN+10], total;

#define ifc(x) (isPrime[x>>6] & (1<<((x>>1)&31)))
#define isc(x) (isPrime[x>>6] |= (1<<((x>>1)&31)))     


int generate_primes(){
	for(unsigned int i = 3;i*i < MAXN;i += 2) 
		if(!ifc(i))	for(unsigned int j = 3*i;j < MAXN;j+=2*i) isc(j);
	unsigned int k = 2;
	a[0] = -1;
	a[1] = 2;
	for(unsigned int i = 3;i < MAXN;i += 2) if(!ifc(i)) a[k++] = i;
	return k-1;
}		

int binary_search(int start, int finish, int val){
	if(start == finish){ if(a[start] > val) return start-1;
		else return start;
	}
	int mid = (start + finish)/2;
	if( val < a[mid] ) return binary_search(start,mid,val);
	else if(val > a[mid] ) return binary_search(mid+1,finish,val);
	else return mid;	
	return 0;
}

int main()
{
	int n,total = generate_primes();
	scanf("%d",&n);
	while(n){
		int p = binary_search(1,total,n);
		double result = fabs(p - n / log(n))/p;
		result *= 100;
  		printf("%0.1lf\n",result);
		scanf("%d",&n);
	}
	return 0;
}
