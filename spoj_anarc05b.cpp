#include <cstdio>

long compute(int *array1,int *array2,int n1,int n2){
	long sum,tempSum;
	int i,j;
	i=j=0;
	while(i<n1 && i<n2){
		while(*(array1+i)!=*(array2+j)){
		}
	
	}	

	return sum;
}

int main()
{
	int n1,n2;
	int *array1,*array2;
	scanf("%d",&n1);
	while(n1>0){
		array1 = new int[n1];
		for(int i=0;i<n1;i++)scanf("%d",array1+i);
		scanf("%d",&n2);
		for(int i=0;i<n2;i++)scanf("%d",array2+i);
		printf("%ld\n",compute(array1,array2,n1,n2);
		delete[] array1;
		delete[] array2;		
		scanf("%d",&n1);	
	}
	return 0;
}
