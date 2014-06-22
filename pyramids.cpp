#include <iostream>
#include <cstdio>
#include <cmath>	

float cosine(int a,int b,int c){

	return (a*a + b*b - c*c)/(2.0*a*b);
}

int main()
{
	int test;
	int ab,bc,ac,bd,cd,ad;
	float cosa,cosb,cosc;
	float volume;
	scanf("%d",&test);
	while(test--){
		scanf("%d %d %d %d %d %d",&ab,&ac,&ad,&bc,&bd,&cd);
		cosa = cosine(ab,ac,bc);
		cosb = cosine(ab,ad,bd);
		cosc = cosine(ac,ad,cd);
		printf("%f %f %f\n",cosa,cosb,cosc);
		volume = ab*ac*ad*sqrt(1+2*cosa*cosb*cosc - cosa*cosa - cosb*cosb - cosc*cosc)/6;
		printf("%0.4f\n",volume);
	}
	return 0;
}
