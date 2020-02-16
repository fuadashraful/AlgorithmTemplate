/*
Author:Fuad Ashraful Mehmet
University of Asia Pacific
Date:16 Feb 2020
category: LCA + DFS
problem : https://codeforces.com/contest/1304/problem/E
*/
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5,LOG=20;
int par[N][LOG],depth[N];
vector<int>g[N];

void dfs(int u,int p,int label)
{
    par[u][0]=p;
    depth[u]=label;
    
    for(int v:g[u])
    {
        if(p==v)continue;
        dfs(v,u,label+1);
    }
}
void init(int root,int n)
{
    dfs(root,-1,1);

    for(int k=1;k<LOG;++k)
    {
        for(int i=1;i<=n;++i)
        {
            if(par[i][k-1]!=-1)
            {
                par[i][k]=par[par[i][k-1]][k-1];
            }
            else par[i][k]=-1;
        }
    }
}

int lca(int u,int v)
{
    if(depth[u]<depth[v])swap(u,v);
    int diff=depth[u]-depth[v];

    for(int i=LOG-1;i>=0;--i)
    {
        if(diff>=(1<<i))
        {
            diff-=(1<<i);
            u=par[u][i];
        }
    }

    if(u==v)return v;

    for(int i=LOG-1;i>=0;--i)
    {
        if(par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    }

    return par[v][0];
}
int dist(int a,int b)
{
    return depth[a]+depth[b]-2*depth[lca(a,b)];
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    init(1,n);

    int q;
    cin>>q;
    while(q--)
    {
        int x,y,a,b,k;
        cin>>x>>y>>a>>b>>k;
        int d=k-dist(a,b);
        bool flag=false;
        if(d>=0&&d%2==0)flag=true;
        d=k-(dist(a,x)+dist(b,y)+1);
        if(d>=0&&d%2==0)flag=true;
        d=k-(dist(a,y)+dist(b,x)+1);
        if(d>=0&&d%2==0)flag=true;

        flag?cout<<"YES"<<endl:cout<<"NO"<<endl;
    }

    
    return 0;
}