#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
const int MAX = 55;
char arr[MAX][6];
int lasthash[MAX][6];
int dp[50][5][32][32][5][32];
const int MOD = 1000000007;

int N, M;


static inline int go (int row, int col, int lmask, int rmask,int lastcol,int colmask)
{
  int i, j;


  if (col == M)
    {
      row++;
      lmask <<= 1;
      rmask >>= 1;
      col = 0;
      lastcol = -1;
    }
  //printf("DEBUG: row=%d col=%d lmask=%x rmask=%x lastcol=%d colmask=%x\n",row,col,lmask,rmask,lastcol,colmask);
  if (row == N)
    {
//      if (colmask > 0)
	{
	  //if((colmask+1)==(1<<M)) printf ("@@@@ row=N %x %x\n", colmask);
	  return 1;
	}
      return 0;
    }
  //printf ("row=%d,col=%d  \n", row, col);

  lmask=lmask&((1<<M)-1);
  int slastcol=lastcol;

  if(slastcol == -1) slastcol=M-1;

  if(dp[row][col][lmask][rmask][slastcol][colmask]!=-1) return dp[row][col][lmask][rmask][slastcol][colmask];

  int sum = 0;
  if (arr[row][col] == '#') {
sum=go (row, col + 1, lmask & ~(1 << col), rmask & ~(1 << col),col,colmask & ~(1 << col));
	if(sum>=MOD) sum-=MOD;
    return dp[row][col][lmask][rmask][slastcol][colmask]= sum;
	}


  // printf(" LMASK=%d RMASK=%d\n",(lmask<<1)&(1<<col) , (rmask>>1)&(1<<col));

  if ((((lmask) & (1 << col)) == 0) and (((rmask) & (1 << col)) == 0))
    {
      bool bad = false;

      //printf("row=%d col==%d lasthash[row][col]=%d\n",row,col,lasthash[row][col]);

      if ( lasthash[row][col] < lastcol ) bad=true;

      if (colmask & (1 << col)) bad = true;


      if (!bad)
	{
//	  printf (" choosing %d %d\n", row, col);
	  sum += go (row, col + 1, (lmask) | (1 << col), (rmask) | (1 << col),col,  colmask | (1 << col));
    if(sum>=MOD) sum-=MOD;
	}
    }
    sum += go (row, col + 1, lmask, rmask,lastcol, colmask);
   
    if(sum>=MOD) sum-=MOD;


  return dp[row][col][lmask][rmask][slastcol][colmask]=sum;
}


int
main ()
{
  int T;
  scanf (" %d", &T);
  while (T--)
    {
      scanf (" %d %d", &N, &M);
      int i,j;
      for (i = 0; i < N; i++)
	scanf (" %s", arr[i]);

	for(i=0;i<N;i++){
	 int firstcol=-1;
	for(j=0;j<M;j++){
		lasthash[i][j]=firstcol;
		if(arr[i][j]=='#') {
			firstcol=j;
		}
			
			for(int lmask=0;lmask<(1<<M);lmask++)
			for(int rmask=0;rmask<(1<<M);rmask++)
		  	for(int k=0;k<M;k++)
			for(int colmask=0;colmask<(1<<M);colmask++)
				dp[i][j][lmask][rmask][k][colmask]=-1;
			
		
		}

	  
	}

//      memset(dp,-1,sizeof(dp));

      int ans = 0;


      i = j = 0;
      ans = go (i, j, 0, 0,-1, 0);
      ans--;
      if(ans<0) ans+=MOD;

      printf ("%d\n", ans);
    }
  return 0;
}
