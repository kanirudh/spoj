#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <cmath>
#define i64 long long

using namespace std;
double A,B,C;

double eps = 0.000001;
int IMAX = 150;

double newton_raphson(){
	double x2 = (C-B)/A,x1 = 0;
	int count = 0;
	while(abs(x2 - x1) > eps and ++count<IMAX){
		x1 = x2;
		x2 = x1 - (A*x1+B*sin(x1)-C)/(A+B*cos(x1));
	}
	return x2;
}

int main()
{
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%lf %lf %lf",&A,&B,&C);
		printf("%0.6lf\n",newton_raphson());
	}
	return 0;
}
