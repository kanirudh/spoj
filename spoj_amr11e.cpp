#include <cstdio>
#include <ctime>

void init(int *array){
	long limit = 200000;
	long *n;
	n = new long[limit];
	int counter=0;
	long i=2,j;
	while(i*i<limit && counter<1000){
		if(n[i]==0){
			j=i*2;
			while(j<limit){
				n[j]+=1;
				j+=i;
			}		
		}
		else if(n[i]>2){
			*(array+counter++)=i;
			//printf("%d\n",i);
		}
		i++;
	}
	while(counter<1000){
		if(n[i]>2){
			*(array+counter++)=i;
			//printf("%d\n",i);
		}
		i++;	
	
	}
}

int main()
{
	clock_t start = clock();
	int numbers[1000];
	init(numbers);
	int test,n;
/*	scanf("%d",&test);
	while(test--){
		scanf("%d",&n);
		printf("%d\n",numbers[n-1]);	
	}
*/
	printf("%lf\n",(double)(clock()-start)/CLOCKS_PER_SEC);
	return 0;}
