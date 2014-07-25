#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <climits>
#include <cmath>

using namespace std;
#define s(n) scanf("%d",&n);
int months[] = {0,3,2,5,0,3,5,1,4,6,2,4};

string days[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

int main()
{
	int test,dd,mm,y;
	s(test);
	while(test--){
		s(dd);s(mm);s(y);
		y -= mm<3;
		//cout<<y;
		int displace =( y + y/4 - y/100 + y/400 + months[mm-1] + dd) %7 ; 
		cout<<days[displace]<<endl;
	}
	return 0;
}
