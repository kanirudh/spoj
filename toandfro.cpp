i#include <iostream>
#include <cstdio>

int main(){
	int columns,size;
	char temp;
	char matrix[205];
	scanf("%d",&columns);
	while(columns){
		size = 0;
		printf("%d\n",columns);
		getchar();
		while((temp=getchar())!='\n'){			
			matrix[size++] = temp;
			putchar(matrix[size-1]);
		}
		printf("\n");int rows = size/columns;
		for(int i=0;i<columns;i++){
			for(int j=0;j<rows;j++){
				if(j%2==0)putchar(matrix[j*columns+i]);
				else putchar(matrix[j*columns+columns-i+1]);
			}
		}
		putchar('\n');
		scanf("%d",&columns);
	}
	return 0;
}
