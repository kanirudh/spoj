//find the two largest number in the given range
#include <cstdio>

int main()
{
	char option;
	int n,q,x,y;
	long *segtree; 
	scanf("%d",&n);
	segtree = new long[2*n];
	for(int i=n;i<2*n;i++)scanf("%ld",segtree+i);
	for(int i=n-1;i>0;i--)*(segtree+i) = *(segtree+2*i)>*(segtree+2*i+1)?*(segtree+2*i):*(segtree+2*i+1);
	//for(int i=0;i<2*n;i++)printf("%ld",*(segtree+i));		
	scanf("%d",&q);
	while(q--){
		getchar();
		option = getchar();
		scanf("%d %d",&x,&y);
		if(option == 'U'){
			*(segtree+n+x-1)=y;
			for(int i=(n+x-1)/2;i>0;i--)*(segtree+i) = *(segtree+2*i)>*(segtree+2*i+1)?*(segtree+2*i):*(segtree+2*i+1);
			/*for(int i=0;i<2*n;i++)printf("%ld\t",*(segtree+i));	
			putchar('\n');*/	
		}
		else {
			int i=x;int j=y;
			while(j-i!=1){
				else if(i%2==0 && j%2==0)i=i/2;j=(j-1)/2;
				else if(i%2==0 && j%2==1)i=i/2;j=j/2;		
				else if(i%2==1 && j%2==1)i=(i+1)/2;j=j/2;
				else i=(i+1)/2;j=(j-1)/2;
			}
			else if(x%2==0 && j%2==0)result(3,
			else if(x%2==0 && y%2==1)printf("%d"		
			else if(x%2==1 && y%2==1)i=(i+1)/2;j=j/2;
			else i=(x+1)/2;y=(j-1)/2;			
		}		
		//printf("%c %d %d",option,x,y); 	
	}	
	return 0;												
}

