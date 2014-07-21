#include <cstdio>
#include <iostream>

int main()
{
	long base[7];
	long answer;
	int n,dots,dashes,number;
	char temp;
	base[0] = 1;
	base[1] = 20;
	base[2] = 360;
	for(int i=3;i<7;i++) base[i] = base[i-1]*20;
	scanf("%d",&n);
	while(n){
		answer = 0;
		temp = getchar();
		for(int i=0;i<n;i++){
			dots = 0;
			dashes = 0;
			while((temp = getchar())!='\n'){
				if(temp == '.' ) dots++;
				else if(temp == '-')dashes++;
			}
			number = dashes*5+dots;
			answer += number*base[n-i-1];
		}
		printf("%ld\n",answer);	
		getchar();
		scanf("%d",&n);
	}
	return 0;
}
