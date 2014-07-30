#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <cmath>

const int size = 550;
const float EPS = 0.001;

using namespace std;

typedef long long ll;

long double nways[551][3301];

void init(){
	for(int i=1;i<=6;i++) nways[1][i] = 1.0/6.0;
	for(int i=2;i<size+1;i++){
		for(int j=1;j<i;j++) nways[i][j] = 0;
		for(int j=i;j<6*i+1;j++){
			nways[i][j] = 0;
			for(int k = 1;k<=6 and k<j;k++) nways[i][j] += nways[i-1][j-k]/6.0;
		}
	}
}

int main()
{
	int test,n,k;
	init();
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&n,&k);
		if(n<=550 and k<=3300){
			long double temp = nways[n][k]*100.0;
			//cout<<temp<<" ";
			//for(int i=0;i<n;i++) temp/=6.0;
			printf("%d\n",(int)temp);
		}
		else printf("0\n");
	}
	return 0;
}
