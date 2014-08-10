#include <iostream>
#include <cstdio>
#include <cfloat>
#include <algorithm>
#include <cmath>

using namespace std;
 
struct Point
{
    int pos,x,y;
};

bool compareX(Point a,Point b){ return (a.x < b.x); }
bool compareY(Point a,Point b){ return (a.y < b.y); }
 
double dist(Point p1, Point p2)
{
    return sqrt((double) ((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y)));
}
 
double bruteForce(Point P[], int n,int *coord){
    double temp,min = FLT_MAX;
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j){
			temp = dist(P[i],P[j]);
            if (temp < min){
				coord[0] = P[i].pos;coord[1] = P[j].pos;
                min = temp;
			}
		}
    return min;
}
 
double stripClosest(Point strip[], int size, double d,int *coord)
{
    double temp,min = d;  // Initialize the minimum distance as d
    for (int i = 0; i < size; ++i)
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j){
			temp = dist(strip[i],strip[j]);
            if (temp < min){
                min = dist(strip[i], strip[j]);
 				coord[0] = strip[i].pos;coord[1] = strip[j].pos;
			}
		}
    return min;
}
 
double closestUtil(Point Px[], Point Py[], int n,int *coord)
{
    if (n <= 3) return bruteForce(Px, n,coord);
 
    int coordl[2],coordr[2],mid = n/2;
    Point midPoint = Px[mid];
    Point Pyl[mid+1];   // y sorted points on left of vertical line
    Point Pyr[n-mid-1];  // y sorted points on right of vertical line
    
	int li = 0, ri = 0;  // indexes of left and right subarrays
    for (int i = 0; i < n; i++){
      if (Py[i].x <= midPoint.x) Pyl[li++] = Py[i];
      else Pyr[ri++] = Py[i];
    }
 
    double dl = closestUtil(Px, Pyl, mid,coordl);
    double dr = closestUtil(Px + mid, Pyr, n-mid,coordr);
	double d;
	if( dl < dr) {
		d = dl;
		for(int i=0;i<2;i++) coord[i] = coordl[i];
	}
    else{
		d = dr;
		for(int i=0;i<2;i++) coord[i] = coordr[i];
	}
 
    Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (abs(Py[i].x - midPoint.x) < d) strip[j] = Py[i], j++;
 	
	dl = stripClosest(strip,j,d,coordl);
	if( dl < d) {
		d = dl;
		for(int i=0;i<2;i++) coord[i] = coordl[i];
	} 
    return d;
}
 
int main()
{
    int N;
	scanf("%d",&N);
	int *coord = new int[2];
	Point *Px = new Point[N];
	Point *Py = new Point[N];
	for(int i=0;i<N;i++){
		scanf("%d %d",&Px[i].x,&Px[i].y);
		Px[i].pos = i;
		Py[i].x = Px[i].x; Py[i].y = Px[i].y;
		Py[i].pos = i;
	}	
	sort(Px,Px+N,compareX);
	sort(Py,Py+N,compareY);
	double mind = closestUtil(Px,Py,N,coord);
    printf("%d %d %0.6lf\n",min(coord[0],coord[1]),max(coord[0],coord[1]),mind);
	return 0;
}
