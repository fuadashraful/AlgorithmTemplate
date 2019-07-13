#include<bits/stdc++.h>
#define pi acos(-1.0);
#define loop(i,n) for(int i=0;i<n;++i)
using namespace std;

typedef long long int LL;


/*
  Ashraful Islam Babu
  Solve date: 12 july 2019
  remarks: Segment Tree Basic Implementation

*/



const int N=100005;

int ar[N];
int segment[N*4];

void  init_segment(int l,int r,int node)
{

    if(l==r)
    {
        segment[node]=ar[l];
        return;
    }

    int mid=(l+r)>>1;

    int l_c=node<<1;
    int r_c=l_c+1;

    init_segment(l,mid,l_c);
    init_segment(mid+1,r,r_c);

    segment[node]=min(segment[l_c],segment[r_c]);
    return;


} ///end

int query(int l,int r,int x,int y,int node)
{

    if(l>y||r<x)
        return 10e6;

    if(l>=x&&r<=y)
        return segment[node];

    int mid=(l+r)>>1;

    int l_c=node<<1;
    int r_c=l_c+1;

    return min(query(l,mid,x,y,l_c),query(mid+1,r,x,y,r_c));

} /// end

int main()
{


   ios_base::sync_with_stdio(NULL);
   cin.tie(NULL);
   cout.tie(NULL);

//  freopen("input.txt","r",stdin);

   int tc,cs=1;
   cin>>tc;
   while(tc--)
   {


       cout<<"Case "<<cs++<<":"<<endl;

       int n,q;
       cin>>n>>q;
       for(int i=1;i<=n;++i)
        cin>>ar[i];

       init_segment(1,n,1);

       loop(i,q)
       {

           int x,y;
           cin>>x>>y;

           int res=query(1,n,x,y,1);


           cout<<res<<endl;
       }



   }


    return 0;
}

