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

double const pi = 3.141592653589793;

int main()
{
	int test;	
	double k1,k2,v,theta,points;
	scanf("%d",&test);
	while(test--){
		scanf("%lf %lf %lf",&v,&k1,&k2);
		if(k1 == 0) theta = pi / 2.0;
		else if(k2 == 0) theta = pi / 4.0;
		else theta = atan(-4.0*k1/k2)/2.0 + pi/2.0 ;
		points = (v*v/10.0)*(2.0*k1*cos(theta)*sin(theta) + k2*sin(theta)*sin(theta)/2.0);
		printf("%0.3lf %0.3lf\n",theta,points);
	}
	return 0;
}
