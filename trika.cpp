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
	int N,M,X,Y;
	int powermatrix[21][21];
	int bestsol[21][21];
	scanf("%d %d %d %d",&N,&M,&X,&Y);
	for(int i=1;i<N+1;i++) {
		for(int j=1;j<M+1;j++) scanf("%d",&powermatrix[i][j]);
	}
	for(int j=Y+1;j<M+1;j++)powermatrix[X][j] = powermatrix[X][j-1] -powermatrix[X][j];
	for(int i=X+1;i<N+1;i++){
		powermatrix[i][Y] = powermatrix[i-1][Y]-powermatrix[i][Y];
	}
	for(int i=X+1;i<N+1;i++){
		for(int j=Y+1;j<M+1;j++){
			int temp = max(powermatrix[i-1][j],powermatrix[i][j-1]);
			powermatrix[i][j] = temp-powermatrix[i][j];
		}
	}
	if (powermatrix[N][M]>=0) printf("Y %d\n",powermatrix[N][M]);
	else printf("N\n");
	return 0;
}
