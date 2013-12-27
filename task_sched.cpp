#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
using namespace std;

struct node {
	int di,mi,idx;
	bool operator < (const node &p) const {
		if(di!=p.di) return di < p.di;
		return idx < p.idx;

	}
	node(int x=0,int y=0,int i=0):di(x),mi(y),idx(i){}
};

int T;
const int MAX=(1<<17);
node arr[MAX];

int main()
{
	int i,j;
	scanf(" %d",&T);
	for(i=0;i<T;i++) { 
		scanf(" %d %d",&arr[i].di,&arr[i].mi);
		arr[i].idx=i;
		sort(arr,arr+i+1);
		int t=0,ans=-(1<<30);
		for(j=0;j<=i;j++){
			t += arr[j].mi;
		//	printf(" %d %d\n",t,arr[j].di);
			int x=t-arr[j].di;
			if(x>=0) ans=max(ans,x);
		}
		printf("%d\n",ans);
	}
	
	
	return 0;
}
