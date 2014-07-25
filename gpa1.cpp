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

double chartofloat(char number[],int length){
	double base = 1.0,result = 0;
	int pos = 0;
	while(number[++pos] != '.' and pos<length);		
	for(int i= pos-1;i>=0;i--){
		result += (number[i]-'0')*base;
		base *= 10;
	}
	base = 0.1;
	for(int i=pos+1;i<length;i++){
		result += (number[i]-'0')*base;
		base /= 10;
	}	
	return result;	
}

int main()
{
	int n,credits[6];
	bool passed = true;
	double subjectscores[6];
	float exam, attendance,gpa,internals[3];
	char temp,number[20];
	scanf("%d",&n);
	getchar();
	while(n--){
		passed = true;
		for(int i=0;i<6;i++) scanf("%d",&credits[i]);	
		//for(int i=0;i<6;i++) printf("%d ",credits[i]);
		//cout<<endl;
		for(int i=0;i<6;i++){
			for(int j=0;j<3;j++){
				scanf("%s",number);
				internals[j] = atof(number);
				//printf("%f ",internals[j]);
			}
			scanf("%f %f",&exam,&attendance);
			//printf("%f %f ",exam,attendance);
			//Calculating scores for each subjecti
			sort(internals,internals+3);
			subjectscores[i] = internals[2] + internals[1];
			subjectscores[i] *= (9.0/8.0);
			subjectscores[i] += exam/2;
			if(attendance < 51.0 ) subjectscores[i] += 5;
			else if(attendance <61.0) subjectscores[i] += 4;
			else if(attendance <71.0) subjectscores[i] += 3;
			else if(attendance <81.0) subjectscores[i] += 2;
			else if(attendance <91.0) subjectscores[i] += 1;
			//printf("%f\n",subjectscores[i]);
		}
		//Calculating grade for the student
		gpa = 0;
		int totalcredits = 0;
		for(int i = 0;i < 6;i++){
			if(subjectscores[i]>=91) subjectscores[i] = 10.0;
			else if(subjectscores[i] >= 81) subjectscores[i] = 9.0;
			else if(subjectscores[i] >= 71) subjectscores[i] = 8.0;
			else if(subjectscores[i] >= 61) subjectscores[i] = 7.0;
			else if(subjectscores[i] >= 51) subjectscores[i] = 6.0;
			else if(subjectscores[i] == 50) subjectscores[i] = 5.0;
			else subjectscores[i] = 0;
			if(!subjectscores[i]) passed = false;
			//printf("%f ",subjectscores[i]);
			gpa += credits[i]*subjectscores[i]; 
			totalcredits += credits[i];
		}
		//cout<<endl;
		gpa /= totalcredits;
		if(passed) printf("PASSED, %.2f\n",gpa);
		else printf("FAILED, %.2f\n",gpa);
	}
	return 0;
}
