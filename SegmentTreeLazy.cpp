/*************
 Author :Fuad Ashraful
 category: Segment Tree (lazy Propagration)
 date:27 Nov 2019
 Problem : Lightoj 1164 - Horrible Queries 
*********/
#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define ones(x) __builtin_popcount(x)
#define mem(a,b) memset(a,b,sizeof(a))
#define debug(x) cerr<<"at "<<__LINE__<<" value is "<<x<<endl
using namespace std;
const ll mod=1000000007;
const int N=1e5+5;
int n,q,m,cs=1,len,Q,tc=1;
string f;
inline void scan(int &x)
{
  scanf("%d",&x);
} /// end func

struct Node
{
  ll lazy;
  ll sum;
}segment[N*4];

void update(int l,int r,int x,int y,int node,int val)
{ 

  if(l>y||r<x||l>r)
  return;

  if(l>=x&&r<=y)
  {
    segment[node].lazy+=val;

    segment[node].sum+=(r-l+1)*val;
    return;
  } // end

  int mid=(l+r)>>1;
  int left=(node<<1);
  int right=left+1;
  update(l,mid,x,y,left,val);
  update(mid+1,r,x,y,right,val);

  segment[node].sum=segment[left].sum+segment[right].sum+(ll)segment[node].lazy*(r-l+1);
  return;

} /// end func

ll Query(int l,int r,int x,int y,int node,int p)
{

  if(l>y||r<x||l>r)
  return 0;
  if(l>=x&&r<=y)
  {
    return segment[node].sum+(ll)(r-l+1)*p;
  }

  int mid=(l+r)>>1;
  int left=(node<<1);
  int right=left+1;


  ll ans=Query(l,mid,x,y,left,p+segment[node].lazy)+Query(mid+1,r,x,y,right,p+segment[node].lazy);

  return ans;

} /// end func
int main()
{
      
        ios_base::sync_with_stdio(false);   
       // freopen("input.txt","r",stdin);
      // freopen("output.txt","w",stdout);

      for(scan(tc);tc--;)
      {

        printf("Case %d:\n",cs++);
        scan(n);
        scan(q);
        memset(segment,0,sizeof segment);
        int cmd,x,y,val;
        while(q--)
        {

        scan(cmd);
        scan(x);
        scan(y);
        if(0==cmd)
        {
          scan(val);
          update(1,n,x+1,y+1,1,val);
        }
        else
        {
          ll ans=Query(1,n,x+1,y+1,1,0);
          printf("%lld\n",ans);
        }

        } /// end query
        
      }
    return 0;
}
