#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
map<int,string> M;

int main()
{
	srand(time(NULL));
	int n=10,n1=n-2;
	printf("%d\n",n);
	printf("BOUND %d\n",1+(rand()%3));
	M[0]="SET";
	M[1]="GET";
	M[2]="PEEK";
	M[3]="DUMP";
	while(n1--){
		int key=rand()%2;
		printf("%s ",M[key].c_str());
		if(key==3){ printf("\n"); continue; }
		char ch=(rand()%26)+'a';
		printf("%c",ch);
		if(key==0) printf(" %d",rand()%n);
		printf("\n");
	}
	printf("DUMP\n");
	
	
	return 0;
}
