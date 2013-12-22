#include<cstdio>
#include<iostream>
#include<set>
#include<algorithm>
#include<string>
#include<map>
#include<functional>
using namespace std;

struct node {
	int p;
	string s;
	node(){ p=-1;s=""; }
	node(int x,string &y) :p(x),s(y){}
	bool operator<(const node &n) const {
		if(p!=n.p) return p>n.p;
		if(s!=n.s) return s<n.s;
		return false;
	}
};


int main()
{
	int N;
	cin >> N;
	set<node> ans;
	set<node>::iterator it1;
	map<string,int> M;

	while(N--){
		string str;
		cin >> str;
		int f=0;
		if(M.count(str)) {
			f=M[str];
			ans.erase(node(f,str));
			ans.insert(node(f+1,str));
			M[str]++;
		}
		else  { 
			M[str]=1;
			ans.insert(node(1,str));
		}
		
	}
	int K;
	cin >> K;
	it1=ans.begin();
	while(K-- && (it1!=ans.end())){
		cout <<it1->s<<'\n';
		it1++;
	}
	
	return 0;
}
