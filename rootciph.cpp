//This idea here is to ue the property of polynomials
#include <cstdio>

int main()
{
	int test;
	long long a,b,c;
	scanf("%d",&test);
	while(test--){
		scanf("%lld %lld %lld",&a,&b,&c);
		printf("%lld\n",a*a -2*b);
	}
	return 0;

}
