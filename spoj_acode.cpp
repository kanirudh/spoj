#include <cstdio>

#define i64 long long

int main()
{
	i64 ans[5001];
	char temp[2];
	int measure,count;
	temp[0] = getchar();
	while(temp[0]!='0'){
		//putchar(temp[0]);	
		count = ans[0] = 1;
		temp[1] = getchar();
		if(temp[1]=='\n')printf("1\n");
		else {		
			measure = (temp[0]-'0')*10+(temp[1]-'0');
			if(measure <27 && measure>9)ans[1] =2;
			else ans[1] =1;
			temp[0]=temp[1];		
			while((temp[1]=getchar())!='\n'){
				count++;
				measure = (temp[0]-'0')*10+(temp[1]-'0');
				ans[count] = ans[count-1];
				if(measure<27)ans[count]+=ans[count-2];				
				temp[0] = temp[1];		
			}
			printf("%lld\n",ans[count]);
		}	
		temp[0] = getchar();	
	}
	return 0;
}
