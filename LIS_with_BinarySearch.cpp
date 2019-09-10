#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define _FasterIO  ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
#define white 0
#define black 1
#define gray 2
/*
 Author: Fuad Ashraful Mehmet
 University of Asia Pacific
 created :10 Sep 2019  8.30  pm
 Category :LIS using binary_search
 Problem:
*/
using namespace std;
//long long int row[]= {-1,0,1,0};
//long long int col[]= {0,-1,0,1};

//long long int row [] = {+1,-1,+0,+0,-1,-1,+1,+1}; ///fuck array for eight direction
//long long int col [] = {+0,+0,+1,-1,+1,-1,-1,+1}; /// fuck array for eight direction
int n,m;
int tc,cs=1;
const int N=5005;
int len;
vector<int>v;
int inf=1e9;
vector<int>lis(1000005,inf);

void debug()
{

    for(int i=0; i<=len; ++i)
        cout<<lis[i]<<" ";
    cout<<endl;
} /// .. end func

int upperBound(int l,int r,int num)
{

    if(l>r)
    {


        return l;
    }


    int mid=(l+r)>>1;

    if(lis[mid]<num)
        return upperBound(mid+1,r,num);
        return upperBound(l,mid-1,num);
} /// end

int LIS_with_BinarySearch()
{

    len=v.size();
    lis[0]=-inf;

    for(int i=0; i<len; ++i)
    {

        int idx=upperBound(0,len,v[i]);

        if(v[i]<lis[idx])
            lis[idx]=v[i];
        //  cout<<"idx "<<idx<<endl;
    }

    // debug();

    for(int i=len;i>0;--i)
    {
        if(lis[i]!=inf)
            return i;
    }

    return 0;
} /// .. end func

void Solve()
{

    int n;
    cin>>n;



    for(int i=0; i<n; ++i)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    int result=LIS_with_BinarySearch();


    cout<<result<<endl;


} /// ... end

int main()
{

    _FasterIO
    //  freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    tc=1;
    // cin>>tc;
    while(tc--)
    {

        Solve();
    }

    return 0;
}


