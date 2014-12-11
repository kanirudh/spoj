#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
typedef long long i64;

int ITERATION_MAX = 75;
double EPS = 1e-4;

struct box{
	double b,h,area;
}*mybox;

double volume;

double calVolume(double height,int n) {
	double volume = 0.0;
	for(int i=0;i<n;i++){
		if(height > mybox[i].b){
			 if( height <= mybox[i].b+mybox[i].h) volume += mybox[i].area*(height-mybox[i].b);
			else volume += mybox[i].area*mybox[i].h;
		}
	}
	return volume;
}

double bsearch(double low,double high,int n){
	double mid;
	for(int iter = 0;iter < ITERATION_MAX && (high - low ) > EPS;iter++) {
		mid = (low + high) /2;
		double vol = calVolume(mid,n);
		//printf("%d %f %f %lf %lf \n",iter,low,high,vol,volume);
		//if( abs(vol - volume ) < eps ) return mid ;
		if ( vol + EPS < volume ) low = mid ;
		else high = mid; 
	}
	return (high + low ) /2;
}

int main()
{
	int test,n,w,d;
	double low,high;
	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		mybox = new box[n];
		low = INT_MAX;
		high = INT_MIN;
		for(int i=0;i<n;i++){
			scanf("%lf %lf %d %d",&mybox[i].b,&mybox[i].h,&w,&d);
			mybox[i].area = w*d;
			low = min(low,mybox[i].b);
			high = max(high,mybox[i].b + mybox[i].h);
		}
		scanf("%lf",&volume);
		//tvolume = 0;
		//for(int i = 0;i<n;i++) tvolume += mybox[i].area * mybox[i].h;
		if( volume - calVolume(high,n) > EPS) printf("OVERFLOW\n");
		else printf("%0.2f\n",bsearch(low,high,n));
		delete[] mybox;
	}
	return 0;
}
