/**********
Category:Hashing(string)
date:27 oct 2019
problem: https://toph.co/p/eet-izz-phet
*******/
#include<bits/stdc++.h>
#define ll long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define debug(x) cerr<<"at "<<__LINE__<<" value is  "<<x<<endl;
#define FastIO_ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const ll mod=1e9+7;
const ll p1=997;
const ll p2=929;
int n,m;
vector<pair<ll,ll> >h,h2;
string f;
ll hashOne(string t)
{

    ll res=0,mul=1;

    for(int i=0;i<(int)t.size();++i)
    {

        res=(res+mul*t[i])%mod;
        mul=(mul*p1)%mod;
    }


 return res;

} /// end func

ll hashTwo(string t)
{

    ll res=0,mul=1;

    for(int i=0;i<(int)t.size();++i)
    {

        res=(res+mul*t[i])%mod;
        mul=(mul*p2)%mod;
    }


 return res;

} /// end func
int main()
{

   ios_base::sync_with_stdio(false);
   cin.tie(0);

 //  freopen("input.txt","r",stdin);

    cin>>n;

    for(int i=0;i<n;++i)
    {
        cin>>f;

        ll val1=hashOne(f);
        ll val2=hashTwo(f);

        h.push_back({val1,val2});
    }



  sort(h.begin(),h.end());

    cin>>m;

    for(int i=1;i<=m;++i)
    {
        cin>>f;
      ll val1=hashOne(f);
      ll val2=hashTwo(f);

      if(binary_search(h.begin(),h.end(),make_pair(val1,val2)))
      cout<<"yes"<<endl;
      else
        cout<<"no"<<endl;

    }

return 0;
}
