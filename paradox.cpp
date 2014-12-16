#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <climits>
#include <cmath>

using namespace std;
typedef vector<int> vi;

struct node{
	int index,weight;
	node(int _index,int _weight){index = _index; weight = _weight;}
};

int dist[101][101];
vector<vector<node> > adjlist;

void floydwarshall(int n){
	for(int i = 1;i < n+1;i++) for(int j = 1;j < n+1;j++) dist[i][j] = INT_MAX;
	for(int i = 1;i < n+1;i++) dist[i][i] = 0;
	for(int i = 1;i < n+1;i++){
		for(int j = 0;j < adjlist[i].size();j++) 
			dist[i][adjlist[i][j].index] = adjlist[i][j].weight;
	}
	for(int k = 1;k < n+1;k++){
		for(int i = 1;i < n+1;i++){
			for(int j = 1 ;j<n+1;j++){
				if( dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][j] > dist[i][k] + dist[k][j])
					dist[i][j] =  dist[i][k] + dist[k][j];
			}
	}

	}

}

int main()
{
	int n,temp,flag;
	char input[10];
	adjlist = vector<vector<node> > (101);
	scanf("%d",&n);
	while(n){
		flag = 1;
		for(int i = 0;i<n+1;i++) adjlist[i].clear();	
		for(int i = 0;i<n;i++){
			scanf("%d",&temp);
			scanf("%s",input);
			if(input[0] == 't') adjlist[i+1].push_back(node(temp,2));
			else adjlist[i+1].push_back(node(temp,1));
		}
		floydwarshall(n);
		for(int i=1;i<n+1;i++){
			for(int j = 1;j<n+1;j++){
				if( dist[i][j] != INT_MAX && dist[j][i] != INT_MAX){
				if( i != j && (dist[i][j] + dist[j][i]) % 2 != 0) flag = 0;}
			}
			if( dist[i][i] % 2 != 0 ) flag = 0;
		}
		if(flag ) printf("NOT PARADOX\n");
		else printf("PARADOX\n");
		scanf("%d",&n);
	}
	return 0;
}
