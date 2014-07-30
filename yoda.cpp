#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <cmath>
#include <cctype>

using namespace std;

typedef long long ll;

int count[26];
ll fact[22];
string input;

int main()
{
	char temp;
	fact[0] = 1;
	fact[1] = 1;
	for(int i=2;i<22;i++) fact[i] = fact[i-1]*i;
	while(1){
		for(int i=0;i<26;i++) count[i] = 0;
		getline(cin,input);
		if(cin.eof()) break;
		int l = input.size();
		for(int i=0;i<l;i++){
			temp = input[i];
			temp = tolower(temp);
			if(temp >= 'a' and temp <= 'z') count[temp-'a']++; 
		}
		int j=0,nodds=0;
		for(int i=0;i<26;i++){
			nodds += count[i]&1;
			count[i] = count[i]>>1;
			j+= count[i];
		}
		ll nways = fact[j];
		if(nodds > 1) nways = 0;	
		else for(int i=0;i<26;i++) nways /= fact[count[i]];	
		printf("%lld\n",nways);
	}	
	return 0;
}
