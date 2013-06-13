#include <cstdio>
#include <fstream>
#include <cstdlib>

using namespace std;

long limit = 5e6;

int main()
{
	ofstream myfile;
	myfile.open("generatedinput.txt");
	myfile<<"50000\n";
	for(long i=0;i<10000;i++)myfile<<(rand()%10000)<<" ";
	myfile.close();
	printf("File written\n");
	return 0;
}
