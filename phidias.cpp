#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>

using namespace std;

typedef long long ll;

int main()
{
	int test,W,H,n,w,h;
	int waste[601][601];
	scanf("%d",&test);
	while(test--){
		scanf("%d %d",&W,&H);
		scanf("%d",&n);
		//Intializing the waste matrix
		for(int i=0;i<W+1;i++) for(int j=0;j<H+1;j++) waste[i][j] = i*j;
		for(int i=0;i<n;i++){
			scanf("%d %d",&w,&h);
			waste[w][h] = 0;
		}	 	
		for(int i=1;i<W+1;i++){
			for(int j=1;j<H+1;j++){
				for(int k=1;k<=i;k++){
					waste[i][j] = min(waste[i][j], waste[k][j] + waste[i-k][j]);				}
				for(int k=1;k<=j;k++){
					waste[i][j] = min(waste[i][j],waste[i][k] + waste[i][j-k]);
				}
			}
		}
		printf("%d\n",waste[W][H]);	
	}
	return 0;
}
