#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

void precompute(int *lps, char *text,int length){
	//cout<<"Precompute Started\n";
	int len =0 ;
	lps[0] = 0;
	int i =1;
	while(i<length){
		if(text[i] == text[len]) lps[i++] = ++len;			
		else{
			if(len) len = lps[len-1] ;
			else lps[i++] = len;
		}
	}
	//cout<<"Precompute Ended\n";
}

int main()
{
	int length,*lps;
	char *needle,temp;
	while(scanf("%d",&length) == 1){
		//cout<<length<<"\n";
		needle = new char[length];
		lps = new int[length];
		getchar();
		for(int i=0;i<length;i++) needle[i] = getchar();
		precompute(lps,needle,length);
		char temp = 'a' ;
		getchar();
		temp = getchar();
		int i=0,j=0,count=0;
		while(temp != '\n'){
			if(needle[j] == temp){
				j++;i++;
				temp = getchar();
			}
			if(j==length){
				j = lps[j-1];
				printf("%d\n",i-length);
				count++;
			}
			else if(needle[j] != temp){
				if(j) j = lps[j-1];
				else{
					temp = getchar();
					i++;
				}
			}
		}
		if(!count) printf("\n");
		delete[] lps;
		delete[] needle;
	}
	return 0;
}
