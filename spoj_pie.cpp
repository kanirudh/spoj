/*#include <cstdio>
#include <algorithm>

const double eps = 1e-5;

double bin_search(long *array,int length,int friends){
	if(length ==1)return array[0]/friends;	
	double high ;
	for(int i=0;i<length;i++){
		if(array[i]>high)high = array[i];
	}
	//printf("%lf\n",high);
	double low = 0;	
	double mid = (low+high)/2;
	int count=0;
	while(high-low>eps){
		count =0;
		for(int i=0;i<length;i++){
			count+= array[i]/mid;
		}
		
		if(count<friends){
			high = mid;
			mid = (low+high)/2;		
		}
		else{
			low = mid;
			mid = (low+high)/2;		
		}	
		//printf("%lf %lf %lf \n",mid,low,high);
	} 
	return mid;
}

int main()
{
	int test;
	int friends,npies;
	long *radii,temp;
	double pi = 3.14159265358979323846264338327950;
	scanf("%d",&test);
	//printf("%lf\n",eps);
	while(test--){		
		scanf("%d %d",&npies,&friends);
		radii = new long[npies];
		for(int i=0;i<npies;i++){
			scanf("%ld",&temp);
			*(radii+i) = temp*temp;
		}
		//printf("%d %d\n",npies,friends);
		printf("%0.4lf\n",pi*bin_search(radii,npies,friends+1));
		delete[] radii;
	}
	return 0;
}

*/
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int rmax = 10000;

int main () {

  int runs;
  scanf ("%i",&runs);

  while (runs--) {
    int N,F;
    scanf ("%i %i",&N,&F);
    vector<int> r(N);
    for (int i=0; i<N; i++) scanf ("%i",&r[i]);

    double lo=0, hi=M_PI*rmax*rmax;
    for (int go=0; go<100; go++) {
      double x = (lo+hi)/2;
      int cnt=0;
      for (int i=0; i<N; i++) cnt += (int)floor(M_PI*r[i]*r[i]/x);
      if (cnt<F+1) hi=x; else lo=x;
    }

    printf ("%.4f\n",lo);
  }

  return 0;
}
