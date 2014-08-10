/*It is a standard algorithm with slight modificaiton to also return the indices of the pair*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <climits>
#include <cfloat>
#include <cmath>
#define i64 long long

using namespace std;

typedef struct {
	int pos,x,y;
}Point;

bool compareX(Point a,Point b){ return a.x < b.x;}

bool compareY(Point a,Point b){ return a.y < b.y;}

Point points[500000];

double dist(Point a,Point b){
	return sqrt((double)((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)));
}

double bruteforce(int start,int end,int *coord){
	double temp, mind = FLT_MAX;
	for(int i=start;i<end;i++){
		for(int j=i+1;j<end;j++){
			temp = dist(points[i],points[j]);
			if( temp < mind ) {
				mind = temp;
				coord[0] = i;coord[1] = j;
			}	
		}
	}
	return mind;
}	

double stripClosest(Point strip[],int size,double d,int *coord){
	double temp,min = d;
	sort(strip,strip+size,compareY);
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size and (strip[j].y - strip[i].y) < min;j++){
			temp = dist(strip[i],strip[j]);
			if(temp < min){
				min = temp;
				coord[0] = strip[i].pos;coord[1] = strip[j].pos;
			}
		}
	}
	return min;
}
double closestpair(int start,int end,int *coord){ 
	if( end - start < 4) return bruteforce(start,end,coord);
	int coordsl[2],coordsr[2],j,mid = (end+start)/2;
	Point midPoint = points[mid];
	double dl = closestpair(start,mid,coordsl);
	double dr = closestpair(mid,end,coordsr);
	double mind = dl;
	for(int i=0;i<2;i++) coord[i] = coordsl[i];
	if(mind > dr ){
		mind = dr;
		for(int i=0;i<2;i++) coord[i] = coordsr[i];
	}
	Point *strip = new Point[end-start];
	j = 0;
	for(int i= start;i<end;i++){
		if(abs(points[i].x - midPoint.x) <= mind){
			strip[j] = points[i];
			strip[j++].pos = i;
		}
	}
	dr = stripClosest(strip,j,mind,coordsr);
	if(mind > dr ){
		mind = dr;
		for(int i=0;i<2;i++) coord[i] = coordsr[i];
	}
	delete[] strip;
	return mind;	
}

int main()
{
	int N,*coords;
	double minimum;
	scanf("%d",&N);
	coords = new int[2];
	for(int i=0;i<N;i++){
		scanf("%d %d",&points[i].x,&points[i].y);	
		points[i].pos = i;
	}
	sort(points,points+N,compareX);
	minimum  = closestpair(0,N,coords);
	if(points[coords[0]].pos > points[coords[1]].pos) printf("%d %d %0.6lf\n",points[coords[1]].pos,points[coords[0]].pos,minimum);
	else printf("%d %d %0.6lf\n",points[coords[0]].pos,points[coords[1]].pos,minimum);
	return 0;
}
