#include<cstdio>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
map < string, string >M;
set < pair < LL, string > >S;
map < string, LL >last;

void
print_map (void)
{

  map < string, string >::iterator it;
  for (it = M.begin (); it != M.end (); it++)
    {
      cout << it->first << " " << it->second << endl;
    }
}


int
main ()
{
  int N, cnt = 0, BS;
  //ios_base::sync_with_stdio(0);
  cin >> N;

  
  while (N--)
    {
	
      cnt++;
      string s, x;
      string val;
      cin >> s;
      if (s == "BOUND")
	cin >> BS;
      if (s == "SET")
	{
	  cin >> x >> val;
	  set < pair < LL, string > >::iterator its = S.begin ();
	  if(M.count(x)==0){
		S.insert(make_pair(cnt,x));
		
	  } else {
		S.erase(make_pair(last[x],x));
		S.insert(make_pair(cnt,x));
	  }

	  if(S.size()>BS) { 
		its=S.begin();
		if(last.count(its->second) && (last[its->second]==its->first)){
			M.erase(its->second);
			last.erase(its->second);
		}
		S.erase(S.begin());
	   }

	  M[x] = val;
	  last[x] = cnt;
	}
      if (s == "GET")
	{
	  cin >> x;
	  if (last.count (x))
	    {
	      cout << M[x] << endl;
	      set < pair < LL, string > >::iterator its;
	      S.erase (make_pair (last[x], x));
	      S.insert (make_pair (cnt, x));
	      last[x] = cnt;
	    }
	  else
	    cout << "NULL" << endl;
	}

      if (s == "PEEK")
	{
	  cin >> x;
	  if (M.count (x))
	    cout << M[x] << endl;
	  else
	    cout << "NULL" << endl;

	}
      if (s == "DUMP")
	{
	  print_map ();
	}

    }
  return 0;
}
