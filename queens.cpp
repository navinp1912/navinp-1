#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 55;
char arr[MAX][6];
int lasthash[MAX][6];
const int MOD = 1000000007;


int dp[MAX][1<<5][1<<5][1<<5];

int N, M;

int
isgood (int row, int curmask, int prevmask, int lmask, int rmask,
	int curbadmask)
{
  if (curmask & curbadmask)
    return 0;
  if (curmask & prevmask)
    return 0;
  if (curmask & (lmask))
    return 0;
  if (curmask & (rmask))
    return 0;
  vector < int >v;
  int i;
  for (i = 0; i < M; i++)
    if (curmask & (1 << i))
      v.push_back (i);

  for (i = 0; i + 1 < v.size (); i++)
    {
      if ((v[i + 1] - v[i]) == 1)
	return 0;
      int x = v[i], y = v[i + 1];
      int j;
      for (j = x + 1; j < y; j++)
	if (arr[row][j] == '#')
	  break;
      if (j == y)
	return 0;
    }


  return 1;
}


int
go (int row, int prevmask, int lmask, int rmask)
{
  int i, sum = 0, curbadmask = 0;


  if (row == N)
    {
      //for (i = 0; i < row; i++) printf ("row=%d , prevmask=%x\n", i, state[i]);
      return 1;
    }
	lmask&=((1<<M)-1);
	rmask&=((1<<M)-1);
	prevmask&=((1<<M)-1);



  for (i = 0; i < M; i++)
    if (arr[row][i] == '#')
      curbadmask |= (1 << i);

  	prevmask &= ~curbadmask;
	lmask &=~curbadmask;
	rmask &=~curbadmask;

   if(dp[row][prevmask][lmask][rmask]!=-1) return dp[row][prevmask][lmask][rmask];
  for (i = 0; i < (1 << M); i++)
    {

      if (isgood (row, i, prevmask, lmask, rmask, curbadmask))
	{
	  //      printf("choosing row=%d,mask=%x\n",row,i);
	  sum +=
	    go (row + 1, prevmask | (i & (~curbadmask) & ((1 << M) - 1)),
		(lmask | i) << 1, (rmask | i) >> 1);
	  if(sum>=MOD) sum-=MOD;
	}
    }

  return dp[row][prevmask][lmask][rmask]=sum;
}



int
main ()
{
  int T;
  scanf (" %d", &T);
  while (T--)
    {
      scanf (" %d %d", &N, &M);
      int i, j;
      for (i = 0; i < N; i++)
	scanf (" %s", arr[i]);

      for (i = 0; i < N; i++)
	{
	  int firstcol = -1;
	  for (j = 0; j < M; j++)
	    {
	      lasthash[i][j] = firstcol;
	      if (arr[i][j] == '#')
		{
		  firstcol = j;
		}

	    }
	}


      int ans = 0;

	memset(dp,-1,sizeof(dp));
      i = j = 0;
      ans = go (0, 0, 0, 0);
	ans--;
	if(ans<0) ans+=MOD;
      printf ("%d\n", ans);
    }
  return 0;
}
