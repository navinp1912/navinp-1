#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long LL;
const int MAX=1003;
LL arr[MAX];
LL left[MAX],right[MAX];

int main()
{
	int N;
	scanf(" %d",&N);
	int i,j;
	for(i=1;i<=N;i++) scanf(" %lld",&arr[i]);

	arr[0]=1ULL;
	left[0]=1ULL;

	for(i=1;i<=N;i++) left[i]=left[i-1]*arr[i-1];

	arr[N+1]=1ULL;
	right[N+1]=1ULL;

	for(i=N;i>=1;i--) right[i]=right[i+1]*arr[i+1];

	for(i=1;i<=N;i++) printf("%lld\n",left[i]*right[i]);
	
	return 0;
}

