//SPOJ problem for solving large integer multiplication , 
// Algorithm Used : Karastuba Multiplication Algorithm
// Category : Recursive 
// Author : Anirudh Agrawal
// Date: 04/06/2013

#include <cstdio>
#include <cstring>

void karatsuba(char* num1, char* num2,char *num3,int l1, int h1 , int l2,int h2,){
	

}

int main()
{
	char input1[1001],input2[1001],output[2003];
	int test,ol;
	scanf("%d",&test);
	while(test--){	
		scanf("%s %s",input1,input2);
		int length1 = strlen(input1);
		int length2 = strlen(input2);
		//Converting it into numbers 
		for(int i=0;i<length1;i++) input1[i] -='0';
		for(int i=0;i<length2;i++) input2[i] -='0';
		if(length1==1 && input[0]=='0')output[0]=0;ol=1;
		if(length1==1 && input[0]=='0')output[0]=0;ol=1;
		karatsuba(input1,input2,output,0,length1,0,length2);
		for(int i=0;i<length1+length2+1;i++)output[i]+='0';
		for(int i=0;i<ol;i++)putchar(output[i-1]);
		printf("\n");
	}
	return 0;
}
