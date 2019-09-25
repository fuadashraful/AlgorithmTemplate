#include<bits/stdc++.h>

/***
 Author: Fuad Ashraful Mehmet
 University of Asia Pacific
 created :25 Sept 2019 10.58 am
 Category : Articulation Point (dfs)
 Problem:  https://www.spoj.com/problems/EC_P/

***/

using namespace std;
int n,m,g,cs=1;
const int N=1005;
vector<int>graph[N];
int parent[N],low[N],dis[N];
bitset<N>visit;
vector<pair<int,int> >ans;

inline int getInt()
{

    char ch=getchar();
    int num,sign=1;

    for(; ch<'0'||ch>'9'; ch=getchar())
        if(ch=='-')
            sign=-1;

    for(num=0; ch>='0'&&ch<='9'; ch=getchar())
    {
        ch-='0';
        num=num*10+ch;
    }


    return num*sign;
} /// end


void   dfs1(int node)
{

    visit[node]=true;
    dis[node]=g;
    low[node]=g++;


    for(auto x:graph[node])
    {
        if(parent[node]==x)
            continue;

        if(false==visit[x])
        {

            parent[x]=node;
            dfs1(x);
            low[node]=min(low[node],low[x]);
        }
        else
        {
            low[node]=min(low[node],dis[x]);
        }
    }

} /// end func

void dfs2(int node)
{

    visit[node]=true;

    for(auto x:graph[node])
    {
        if(visit[x]==false)
        {

            if(dis[node]<low[x])
            {
                if(node>x)
                ans.push_back({x,node});
                else
                ans.push_back({node,x});
            }


            dfs2(x);
        }
    }
} /// .. end function


void FindArticluationPoint()
{
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        graph[i].clear();
        parent[i]=0;
        low[i]=0;
        dis[i]=0;
    }


    int u,v;
    for(int i=1; i<=m; ++i)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    visit.reset();

    g=1;
    for(int i=1; i<=n; ++i)
    {
        if(false==visit[i])
        {
            dfs1(i);
        }
    }


    ans.clear();
    visit.reset();

    for(int i=1; i<=n; ++i)
    {
        if(false==visit[i])
        {
            dfs2(i);
        }
    }

} /// end func

bool comp(const pair<int,int> &a,const pair<int,int> &b)
{

    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;

} /// end func

void PrintAnswer()
{

    sort(ans.begin(),ans.end(),comp);

    cout<<"Caso #"<<cs++<<endl;
    if(ans.size()==0)
    {
        cout<<"Sin bloqueos"<<endl;
        return;
    }
    /*
      cout<<"low values are "<<endl;
        for(int i=1;i<=n;++i)
        {
            cout<<low[i]<<" ";
        }

        cout<<endl;
    */

    cout<<ans.size()<<endl;
    for(auto x:ans)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
} /// end

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


 //   freopen("input.txt","r",stdin);

    int tc;
    cin>>tc;
    while(tc--)
    {
        FindArticluationPoint();
        PrintAnswer();

    }

    return 0;
}


