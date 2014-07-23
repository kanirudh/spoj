#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int test;
	long long input;
	long long i,j,temp;
	bool flag ;	
	scanf("%d",&test);
	while(test--){
		scanf("%lld",&input);
		i = sqrt(input) ;
		j = 0;
		flag = true ;
		while(flag && j*j< input ){
			temp = i*i+j*j;
			if(temp == input) flag = false;
			if (temp < input ) j++;
			else i--;
		}
		if(flag) cout <<"No\n";
		else cout<<"Yes\n";
	}
	return 0;
}
