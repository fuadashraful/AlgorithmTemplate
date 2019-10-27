/**********
Category:dp
date:27 oct 2019
Problem :ASSIGN - Assignments
https://www.spoj.com/problems/ASSIGN/
*******/
#include<bits/stdc++.h>
#define ll long long int
#define mem(a,b) memset(a,b,sizeof(a))
#define debug(x) cerr<<"at "<<__LINE__<<" value is  "<<x<<endl;
#define FastIO_ ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
const int N=22;
const int M=(1<<22)+2;
int tc,cs=1,target,n;
int task[N][N];
ll dp[N][M];

using namespace std;


ll ways(int idx,int mask)
{
    if(idx>n)
        return 1;

    ll ans=0;

    if(-1!=dp[idx][mask])
    {
        // cout<<"mororized"<<endl;
        return dp[idx][mask];
    }

    for(int i=0; i<n; ++i)
    {
        if(!(mask&(1<<i))&&task[idx][i+1]==1)
        {

            int mask2=(mask|(1<<i));
            ans+=ways(idx+1,mask2);

        }
    }

    return dp[idx][mask]= ans;

} /// end func


void resetDp()
{

    int mx=(1<<n)+2;
    for(int i=0; i<=n; ++i)
        for(int j=0; j<=mx; ++j)
            dp[i][j]=-1;
} /// end func

int main()
{

//FastIO_

    // freopen("input.txt","r",stdin);

    cin>>tc;
// tc=1;
    while(tc--)
    {

        cin>>n;
        // mem(dp,-1);

        resetDp();
        // cout<<"n "<<n<<endl;
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=n; ++j)
                cin>>task[i][j];
        }


        ll ans=ways(1,0);

        cout<<ans<<endl;

    } /// end func

    return 0;
}
