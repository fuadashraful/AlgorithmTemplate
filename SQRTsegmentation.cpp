/*************
 Author :Fuad Ashraful Mehmet
 category: SqrtSementation + binary Search 
 date:09 Nov 2019
 TODO--
https://www.spoj.com/problems/GIVEAWAY/
this is to find  total A[i]  where l<=i<=r and A[i]>=c
*********/
#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

const int N=5e5+5;
const int M=710;
int A[N];
int tc=1,cs=1,n,m,k,q,len;
vector<int>segment[M];

void Solve()
{
  cin>>n;
  int sqrtn=sqrt(n);

  for(int i=0;i<n;++i)
  {

    cin>>A[i];
    segment[i/sqrtn].push_back(A[i]);

  } /// end input

  cin>>q;
  int numofBlocks=ceil((double)n/sqrtn);

  for(int i=0;i<numofBlocks;++i)
  sort(segment[i].begin(),segment[i].end());
  /// query started

  int cmd,a,b,c;

  for(int i=q;i--;)
  {
  cin>>cmd;

    if(0==cmd)
    {
       cin>>a>>b>>c;
      a--;
      b--;
      int l=a/sqrtn;
      int r=b/sqrtn;
      int ans=0;
      if(l==r)
       {
         for(int i=a;i<=b;++i)
         {
           if(A[i]>=c)
           ans+=1;
         }
       }
       else
       {
           for(int i=l+1;i<r;++i)
           {
             ans+=segment[i].size()-(lower_bound(segment[i].begin(),segment[i].end(),c)-segment[i].begin());
           }

          /// ... counting most-left
           for(int i=a;i<sqrtn*(l+1);++i)
            {
              if(A[i]>=c)
              ans++;
            }
          /// counting most-right
            for(int i=r*sqrtn;i<=b;++i)
            {
              if(A[i]>=c)
              ans++;
            }  
       }
       
      cout<<ans<<endl;
    }
    else
    {
      cin>>a>>b;
      a--;
      int prev=A[a];
      A[a]=b;
      int l=a/sqrtn;
      int idx=lower_bound(segment[l].begin(),segment[l].end(),prev)-segment[l].begin();
      segment[l][idx]=b;
      sort(segment[l].begin(),segment[l].end());

    }

  }

} /// end func
int main()
{
       ios_base::sync_with_stdio(false); cin.tie(NULL);

       // freopen("input.txt","r",stdin);
     // freopen("output.txt","w",stdout);

     Solve();
    return 0;
}
