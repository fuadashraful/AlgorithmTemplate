/*************
 Author :Fuad Ashraful
 category: Digit DP 
 date:22 Nov 2019
 Problem : https://www.spoj.com/problems/CPCRC1C/

 description:
 this is the solution to find sum of digit 
 between two interval a,b where  0<=a<=b<=1e9
 
*********/
#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long
#define ones(x) __builtin_popcount(x)
#define mem(a,b) memset(a,b,sizeof(a))
#define debug(x) cerr<<"at "<<__LINE__<<" value is "<<x<<endl
using namespace std;

int n,k,m,cs=1,len,Q,tc=1;
const int N=5005;
string f;
inline void scan(int &x)
{
  scanf("%d",&x);
} /// end func

vector<int>v;

ll dp[11][100005][2];

ll sumOfdigit(int idx,int sum,int isGreater)
{
   if(idx>=len)
   return sum;

   ll &ret=dp[idx][sum][isGreater];

   if(-1!=ret)
   {
    // cout<<"memo"<<endl;
     return ret;
   }

   int l=v[idx];

   if(isGreater)
   l=9;


   ll ans=0;

   int flag=1;

   for(int i=0;i<=l;++i)
   {
      
   
      if(!isGreater&&i==l)
          flag=0;


        ans+=sumOfdigit(idx+1,sum+i,flag);
   }

   return ret=ans;
} /// end func

ll process(int num)
{
  v.clear();

  while(num>0)
  {
    v.push_back(num%10);
    num/=10;
  }
 
  reverse(v.begin(),v.end());

  mem(dp,-1);

   len=v.size();
  return sumOfdigit(0,0,0);
} /// end func
 
int main()
{
      
    ios_base::sync_with_stdio(false);
      
      // freopen("input.txt","r",stdin);
      //freopen("output.txt","w",stdout);

    int a,b;
    while(true)
    {
      scan(a);
      scan(b);

      if(a+b==-2)
      return 0;
      
       if(a>0)
       a-=1;
      ll ans=process(b)-process(a);
      printf("%lld\n",ans);

    }

    return 0;
}
