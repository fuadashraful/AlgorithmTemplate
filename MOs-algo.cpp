/*
  Ashraful Islam
  University of Asia Pacific
  Category : MO'S Algorithm
  Problem :DQuery (SPOJ)
 
*/
#include<bits/stdc++.h>
#define ll long long int
 
const int N=1e6+5;
int n,m,q;
int frequency[N];
int block;
using namespace std;
int A[30005];
int currentAns;
int finalAns[200005];
 
struct node
{
    int l,r,pos;
};
vector<node>query;
bool cmp(const node &a,const node &b)
{
    if(a.l/block!=b.l/block)
        return a.l<b.l;
    return a.r<b.r;
}/// end fun
void Remove(int idx)
{
    frequency[A[idx]]-=1;
    if(frequency[A[idx]]==0)
        currentAns--;
}
void Add(int idx)
{
    frequency[A[idx]]++;
 
    if(frequency[A[idx]]==1)
        currentAns++;
 
} ///end
void processQuery()
{
 
    int curL=0,curR=0;
 
    for(int i=0; i<q; ++i)
    {
 
        int L=query[i].l;
        int R=query[i].r;
      //  cout<<"l r "<<L<<" "<<R<<endl;
        while(curR<R)
        {
            ++curR;
            Add(curR);
        }
        while(curR>R)
        {
            Remove(curR);
            curR--;
        }
        while(curL<L)
        {
            Remove(curL);
            curL++;
        }
        while(curL>L)
        {
            curL--;
            Add(curL);
        }
        finalAns[query[i].pos]=currentAns;
       // cout<<"current L  R "<<curL<<" "<<curR<<endl;
        // cout<<"ans "<<currentAns<<endl;
    }
    for(int i=1; i<=q; ++i)cout<<finalAns[i]<<endl;
} /// end func
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   // freopen("input.txt","r",stdin);
    cin>>n;
    currentAns=0;
    for(int i=1; i<=n; ++i)cin>>A[i];
    cin>>q;
    int u,v;
    for(int i=1; i<=q; ++i)
    {
        cin>>u>>v;
        query.push_back({u,v,i});
    }

    block=sqrt(30000);
    sort(query.begin(),query.end(),cmp);
    processQuery();
    return 0;
} /// end func