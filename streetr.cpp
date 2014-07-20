#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

long gcd(long a,long b){
	if(a == 0) return b;
	if(a>b) return gcd(a%b,b);
	else return gcd(b%a,a);
}

int main()
{
	int n;
	int answer;
	long *array;
	scanf("%d",&n);
	array = new long[n];
	for(int i=0;i<n;i++) scanf("%ld",array +i);
	long *diff = new long[n-1];
	for(int i=0;i<n-1;i++)diff[i] = array[i+1] - array[i];
	long hcf = gcd(diff[0],diff[1]);	
	for(int i=2;i<n-2;i++) hcf = gcd(hcf,diff[i]); 	
	int result = 0;
	for(int i=0;i<n-1;i++) result += diff[i]/hcf -1; 	
	cout<<result<<endl;
	return 0;
}
