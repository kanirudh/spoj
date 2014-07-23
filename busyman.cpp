/*Intreval Scheduling Problem , greedy method*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <cmath>

using namespace std;

typedef long long ll;

typedef struct {
	int start,finish;
}task;

bool myfunction(task a,task b){
	if(a.finish == b.finish) return a.start <= b.start;
	else return a.finish<b.finish;	
}

int main()
{
	int test,n;
	scanf("%d",&test);
	task tasks[100000] ;
	while(test--){
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d %d",&tasks[i].start,&tasks[i].finish);
		sort(tasks,tasks+n,myfunction);
		int count =0, lastfinish = 0;
		for(int i=0;i<n;i++){
			//printf("%d %d\n",tasks[i].start,tasks[i].finish);
			if(tasks[i].start >= lastfinish){
				count++;
				lastfinish = tasks[i].finish;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
