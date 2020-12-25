/*
Hey  why peeping here -_'_- ?
I believe on myself and I will achieve
this->author = Fuad Ashraful Mehmet, CSE ,University of Asia Pacific
Problem: https://www.spoj.com/problems/ADAMONEY/
category:matrix expo
Date:26th Dec 2020
*/
#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<(int)n;++i)
#define all(o) (o).begin(),(o).end()
#define sz(o) (o).size() 
#define dbg(o)  cerr<<"at "<<__LINE__<<" response = "<<o<<endl;
#define dbgV(O) cerr << #O << "=["; for(auto o : O) cerr << o << ", "; cerr << "E]\n";
#define pb push_back
using namespace std;
using pii=pair<int,int>;
typedef long long ll;
ll n,m,tc,cs=1,q,k;
const int N=6;
ll t[N];
const ll mod=1e9+7;

struct matrix
{
	int r,c;
	ll f[N][N];
};

matrix multiply(matrix a,matrix b)
{
      matrix ret;
      ret.r=a.r;
      ret.c=b.c;
 
      for(int i=1;i<=a.r;++i)
      {
            for(int j=1;j<=b.c;++j)
            {
                  ll sum=0;
                  for(int k=1;k<=a.c;++k)
                  {
                        sum+=a.f[i][k]*b.f[k][j];
                        sum%=mod;
                  }
 
                  ret.f[i][j]=sum;
            }
      }
      return ret;
}

matrix matrix_expo(matrix mat,ll b)
{
	if(b==1)return mat;

	if(b&1) return multiply(mat,matrix_expo(mat,b-1));

	matrix ret=matrix_expo(mat,b>>1);

	return multiply(ret,ret);
}
void HalfDead()
{
	for(int i=0;i<5;++i)cin>>t[i]; cin>>n;
	if(n<5)
	{
		cout<<t[n]<<endl;
		return;
	}

	matrix mat;
	memset(mat.f,0,sizeof mat.f);

	mat.r=mat.c=5;
	mat.f[1][1]=1;
	mat.f[1][2]=2;
	mat.f[1][4]=5;
	mat.f[1][5]=1;
	
	for(int i=2;i<=5;++i)mat.f[i][i-1]=1;

	matrix ret=matrix_expo(mat,n-4);
	ll res=0;
	for(int i=1,j=4;i<=5;++i,j--)
	{
		res=res+(1LL*ret.f[1][i]*t[j])%mod;
		res%=mod;
	}

	cout<<res<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);  cout.tie(nullptr);
    //cout<<setprecision(10)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--){
		HalfDead();
	}
 	return 0;
}