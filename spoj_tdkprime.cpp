#include <cstdio>
#include <ctime>

const int max = 5e6;

void init(long *primes){
	long limit = 9e7;
	int step;
	char *pon = new char[limit];
	step = 2;
	for(int i=5;i<limit;){
		pon[i]=0;
		i+=step;
		step = 6-step;
	}
	long  i=2,j,counter=2;
	primes[0] = 2;primes[1] = 3;
	//for(int i = 2;i<limit;i+=2)pon[i]=1;
	//for(int i = 3;i<limit;i+=3)pon[i]=1;
	i=5;
	while(i*i<limit){
		if(pon[i]==0){
			primes[counter++] = i;	
			j=i*i;
			while(j<limit){
			pon[j]=1;
				j+=i;
			}		
		}	i+=2;
		if(pon[i]==0){
			primes[counter++] = i;	
			j=i*i;
			while(j<limit){
				pon[j]=1;
				j+=i;
			}		
		}	i+=4;
	}
	step = 2;
	while(counter<5e6){
		if(pon[i]==0)primes[counter++]=i;
		i+=step;	
		step = 6-step;
	}
}

int main()
{
	clock_t start = clock();
	long *primes,n;
	primes = new long[max];
	init(primes);
	int test;
	scanf("%d",&test);
	while(test--){
		scanf("%ld",&n);
		printf("%ld\n",primes[n-1]);	
	}
	printf("%lf\n",(double)(clock()-start)/CLOCKS_PER_SEC);
	return 0;
}
