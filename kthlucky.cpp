#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
using namespace std;

long long N;

vector<long long> M(64);
vector<long long > presum(64);

string go(int lvl,long long X)
{
	int i;
	if(lvl<=1 && X<=0) return "";
	if(lvl<=1 && X==1) return "4";
	if(lvl<=1 && X==2) return "7";
	long long sum=0;
	for(i=1;i<63;i++){
		if(((presum[i]))>=X) break;
		sum=presum[i];
	}
	
//	printf("num of digits=%d,sum=%lld,M[i-1]=%lld,X=%lld\n",i,sum,M[i-1],X);

	if(sum+(M[i-1]) >= X ) {
//		printf("starts with 4\n");
	return "4"+go(i-1,X-sum + ((i>1)?presum[i-2]:-1));
	} else  {
//		printf("stars with 7\n");
	return "7" + go(i-1,X-presum[i-1]-M[i-1] + ((i>1)?presum[i-2]:-1) );
	}
}


int main()
{
	int t;

	int i;
	long long prod=2;
	presum[0]=0;
	M[0]=1;
	for(i=1;i<63;i++)
	{
		M[i]=prod;
		presum[i]=presum[i-1]+M[i];
		prod*=2;
	}
	scanf(" %d",&t);
	while(t--){
		scanf(" %lld",&N);
		cout <<go(0,N)<<endl;
	}
	return 0;
}
