#include <cstdio>
#include <algorithm>

const int MAX = 10001;
int a[MAX],b[MAX];

using namespace std;

int main()
{
	int n1,n2,i,j;
	scanf("%d",&n1);
	while(n1>0){
		for(i=1;i<=n1;i++)scanf("%d",&a[i]);
		scanf("%d",&n2); 
		for(i=1;i<=n2;i++) scanf("%d",&b[i]);
		i=j=1;
		//printf("%d %d\n",n1,n2);
		while(i<=n1 || j<=n2){
			if(a[i]==b[j] && i<=n1 && j<=n2){
				a[i]+=a[i-1];
				b[j]+=b[j-1];
				a[i]=b[j]=max(a[i],b[j]);
				i++;j++;			
			}
			else if(i>n1){
				b[j]+=b[j-1];
				j++;			
			}
			else if(j>n2){
				a[i]+=a[i-1];
				i++;			
			}
			else if(a[i]<b[j]){
				a[i]+=a[i-1];
				i++;			
			}
			else if(a[i]>b[j]){
				b[j]+=b[j-1];
				j++;			
			}
		}
		printf("%d\n",max(a[i-1],b[j-1]));
		scanf("%d",&n1);	
	}
	return 0;
}
