#include<bits/stdc++.h>
#define pb push_back
#define pf push_front
#define sq(i)  (i*i)
using namespace std;

/*
 Problem :  uva 11456

 category:  DP (LIS) modified
 difficulty :medium

 Date: 23 july 2019
 Ashraful Islam Fuad

 University of Asia Pacific
 Dhaka,Bangladesh

*/

//int row[]= {-1,0,1,0};
//int col[]= {0,-1,0,1};

//int row [] = {+1,-1,+0,+0,-1,-1,+1,+1}; ///fuck array for eight direction
//int col [] = {+0,+0,+1,-1,+1,-1,-1,+1}; /// fuck array for eight direction

const int N=2005;
typedef long long int LL;
int tc,cs=1;
int train[N];
int n;
int _dpinc[N],_dpdec[N];

int _I()
{
    int x;
    scanf("%d",&x);
    return x;
}
int _II()
{
    LL x;
    scanf("%lld",&x);
    return x;
}
/// ... end func

int incLIS(int i)
{

    if(i>n)
        return 0;

    if(_dpinc[i]!=-1)
        return _dpinc[i];

    int mx=0;

    for(int j=i+1; j<n; ++j)
    {

        if(train[j]>train[i])
        {
              _dpinc[j]=incLIS(j);
            mx=max(_dpinc[j],mx);
        }
    }

    return _dpinc[i]=1+mx;

} /// ... end func

int decLIS(int i)
{

    if(i>n)
        return 0;

    if(_dpdec[i]!=-1)
        return _dpdec[i];

    int mx=0;

    for(int j=i+1; j<n; ++j)
    {

        if(train[j]<train[i])
        {
              _dpdec[j]=decLIS(j);
            mx=max(_dpdec[j],mx);
        }
    }

    return _dpdec[i]=1+mx;

} /// ... end func


void Solve()
{

    cin>>n;

    if(n==0)
    {
        cout<<"0"<<endl;
        return;
    }
    for(int i=0; i<n; ++i)
    {
        cin>>train[i];
    }

    /// ... calculating lis increasing and decreasing

    memset(_dpinc,-1,sizeof(_dpinc));
    memset(_dpdec,-1,sizeof(_dpinc));
    int mx=0;
    int mn=1<<29;

    int idx=-1;


    for(int i=0; i<n; ++i)
    {


        _dpinc[i]=incLIS(i);
        _dpdec[i]=decLIS(i);

     //   cout<<_dpinc[i]<<endl;

     if(_dpinc[i]+_dpdec[i]>mx)
     {
         mx=_dpinc[i]+_dpdec[i];
     }

      //  mx=max(mx,_dpinc[i]);
    }

    cout<<mx-1<<endl;

} /// ... end func

int main()
{


//   freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);

    tc=_I();

    while(tc--)
        Solve();

    return  0;
}