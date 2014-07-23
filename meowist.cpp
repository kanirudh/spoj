#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

typedef long long ll;

typedef struct {
	char name[10];
	int length;
	int age;
}person;

bool stringcmp(char a[],int l1,char b[],int l2){
	//cout<<"Length1:"<<l1<<"Length2:"<<l2<<endl;
	int i = 0;
	while(i<l1 and i<l2){
		if(a[i] == b[i]) i++;
		else return a[i]<b[i];
	}
	if(i==l1) return true;
	else return false;	
}

bool myfunction(person a,person b){
	if(a.age > b.age) return true;
	else if(a.age == b.age) return stringcmp(a.name,a.length,b.name,b.length);
	else return false; 
}
int main()
{
	vector<person> persons;
	char temp;
	temp = getchar();
	while(temp!= EOF){
		//cout<<"While loop entered\n";
		person ptemp;
		ptemp.length = 0;
		while(temp!=' '){
			ptemp.name[ptemp.length++] = temp;
			temp = getchar();
		}
		int itemp;
		scanf("%d",&itemp);
		ptemp.age = itemp;
		persons.push_back(ptemp);
		getchar();
		temp = getchar();
	}
	sort(persons.begin(),persons.end(),myfunction);	
	for(int i=0;i<persons.size();i++){
		for(int j=0;j<persons[i].length;j++) putchar(persons[i].name[j]);
		putchar('\n');
		//printf("%d\n",persons[i].age);
	}
	return 0;
}
