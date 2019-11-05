#include<bits/stdc++.h>
#define ll long long int
using namespace std;
/****
Fuad Ashraful Mehmet
University of Asia Pacific
category:Subsring hashing
lightoj : 1255 - Substring Frequency

**/

const int N=1e6+7;
const ll P=1e8+5e4+1;
const ll INVP=678791932;
const ll mod=1e9+7;
ll pwr[N],inv[N],h[N];

string a,b;
int tc,cs=1,la,lb;
void  preCal()
{

 pwr[0]=inv[0]=1;

 for(int i=1;i<N;++i)
 {

     pwr[i]=(pwr[i-1]*P)%mod;
     inv[i]=(inv[i-1]*INVP)%mod;
 }

} /// end precal

ll getHash()
{

    ll mul=1;
    ll ret=0;

    for(int i=0;i<lb;++i)
    {

        ret=(ret+mul*b[i])%mod;
        mul=(mul*P)%mod;
    }


    return ret;

} /// end func

void initaHash()
{

    h[0]=0;
    for(int i=0;i<la;++i)
    {
        h[i+1]=(h[i]+pwr[i]*a[i])%mod;
    }

} /// end func


inline ll getSubHash(int i,int j)
{


  ll ret=((h[j+1]-h[i])*inv[i])%mod;

  if(ret<0)
    ret+=mod;

  return ret;

}/// end func

int main()
{


   preCal();

     //freopen("input.txt","r",stdin);

    scanf("%d",&tc);
  // cout<<"tc "<<tc<<endl;
    while(tc--)
    {

        cin>>a>>b;
        la=a.size();
        lb=b.size();

        ll hashb=getHash();

           initaHash();


           int ans=0;

           for(int i=0;i<=la-lb;++i)
           {

           ll suba=getSubHash(i,i+lb-1);

             if(suba==hashb)
                ans+=1;

           }


          printf("Case %d: %d\n",cs++,ans);


    }

    return 0;
} /// end func

