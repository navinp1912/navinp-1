#include<cstdio>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;

int myrank(const string &s)
{
	int i;
	int spaces=0,dots=0,commas=0;
	for(i=0;i<s.size();i++){
		if(s[i]==',') commas++;
		if(s[i]=='.') dots++;
		if(s[i]==' ') spaces++;
	}
	if(spaces==2) return 5;
	if(dots==1) return 4;
	if(dots==2) return 3;
	if(spaces==1) return 2;
	return 1;
}
int commarank(const string &s)
{
	int i;
	int spaces=0,dots=0,commas=0;
	for(i=0;i<s.size();i++){
		if(s[i]==',') commas++;
		if(s[i]=='.') dots++;
		if(s[i]==' ') spaces++;
	}
	if(commas==1 && spaces==1) return 4;
	if(commas==1) return 2;
	return 1;
}

string reorder(string &s)
{
	string tmp=s;
	int currank=commarank(s);
	if(currank==2) {
		int idx=s.find(",");
		string suffix=s.substr(idx+1);
		string prefix=s.substr(0,idx);
		return suffix+" "+prefix;
	}
	if(currank==4){
		int idx=s.find(",");
		string suffix=s.substr(idx+1);
		string prefix=s.substr(0,idx);
		return suffix+" "+prefix;
	}

	return tmp;
}

int main()
{
	int N,i;
	string s;
	getline(cin,s);
	sscanf(s.c_str()," %d",&N);
	vector<string> v;
	map<string,string> M;
	for(i=0;i<N;i++){
		getline(cin,s);
		int idx=s.find(":");
		string suffix=s.substr(idx+1);
		string prefix=s.substr(0,idx);
		prefix=reorder(prefix);
		
	//	cout <<suffix<<" "<<prefix<<endl;
		if(v.size()==0 || (v.back()!=suffix)) v.push_back(suffix);

		if(M.count(suffix)==0){
			M[suffix]=prefix;
		} else {
			string key=M[suffix];
	//		cout <<key<<":"<<rank(key)<<endl;
	//		cout <<prefix<<":"<<rank(prefix)<<endl;
			if(myrank(key)< myrank(prefix)){
				M[suffix]=prefix;
			}
		}

	}
	for(i=0;i<v.size();i++){
		cout <<M[v[i]]<<":"<<v[i]<<'\n';
	}
	return 0;
}
