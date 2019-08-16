#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define _FasterIO  ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
/*
 Author: fuad Ashraful Mehmet
 University of Asia Pacific
 created :16 Aug 2019 10.58 am
 Category :Number thoery (BigMod Problem)
 Problem: uva 1230
*/
using namespace std;
//int row[]= {-1,0,1,0};
//int col[]= {0,-1,0,1};

//int row [] = {+1,-1,+0,+0,-1,-1,+1,+1}; ///fuck array for eight direction
//int col [] = {+0,+0,+1,-1,+1,-1,-1,+1}; /// fuck array for eight direction
int tc,cs=1,n;
const int N=150005;

ll BinaryExpo(ll x,ll y,ll n) /// this function  return x^y mod n
{

    ll res=1LL;
  /// here n is mod number

    while(y!=0)
    {

        if(y&1)
        {
            res=(res*x)%n;
        }

        x=(x*x)%n;

        y>>=1;
    }

   return res;

} /// ... end func

void Solve()
{

   ll x,y,n;
   cin>>x>>y>>n;
   cout<<BinaryExpo(x,y,n)<<endl;

} /// .. end func
int main()
{

    _FasterIO

      // freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);

   cin>>tc;
   while(tc--)
    Solve();

    bool x;
    cin>>x;

    return 0;
}
