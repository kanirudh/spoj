/* 
	User : Anirudh 
	Category : Simple Maths
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
#define i64 long long

using namespace std;

int main()
{
	int test,H,P,A,n1,n2;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d %d",&H,&P,&A);
		if(H <= P) {
			printf("1\n");continue;
		}
		double a = P;
		double b = 2.0*A-3.0*P;
		double c = 2.0*H-2.0*P;
		double result2 =  (b + sqrt(b*b+4*a*c))/(2*a);
		n1 = 2*ceil(result2)+1;
		printf("%d\n",n1);
	}
	return 0;
}
