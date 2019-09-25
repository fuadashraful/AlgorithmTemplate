#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define _FasterIO  ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
#define inf (1<<30)
/*
 Author: Fuad Ashraful Mehmet
 University of Asia Pacific
 created :24 sept 2019 10.58 am
 Category :  Bridge (dfs)
 Problem: uva 796
*/

using namespace std;
//int row[]= {-1,0,1,0};
//int col[]= {0,-1,0,1};
//int row [] = {+1,-1,+0,+0,-1,-1,+1,+1}; /// array for eight direction

static const int unvisited=-1;

/// variable declearation part

vector<vector<int> >graph;
vector<int>parent;
vector<int>discover;
vector<int>low;
int globalTime,m;
vector<pair<int,int> >bridge;


void dfs(int node)
{

    discover[node]=globalTime;
    low[node]=globalTime++;

    for(auto x:graph[node])
    {


        if(unvisited==discover[x])
        {
            parent[x]=node;
            dfs(x);

            if(low[x]>discover[node])
            {
                bridge.pb(make_pair(min(x,node),max(x,node)));
            }

            low[node]=min(low[node],low[x]);
        }
        else if(x!=parent[node])
        {

            low[node]=min(low[node],discover[x]);
        }
    }
} /// ... end function
int main()
{

    _FasterIO
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    int n;
    while(cin>>n)
    {

        /// init variable
        graph.clear();
        graph.resize(n);
        parent.clear();
        parent.resize(n,unvisited);
        discover.clear();
        discover.resize(n,unvisited);
        low.clear();
        low.resize(n,unvisited);
        bridge.clear();
        globalTime=1;
        /// end init all variable

           for(int i=0;i<n;++i)
           {
               int u,node,v;
               char temp;
               cin>>u;
               cin>>temp>>node>>temp;


               for(int j=0;j<node;++j)
               {
                   cin>>v;
                   graph[u].push_back(v);
                   graph[v].push_back(u);
               }
           }

        for(int i=0; i<n; ++i)
        {

            if(discover[i]==unvisited)
            {
                dfs(i);
            }
        }

        sort(bridge.begin(),bridge.end());
        cout<<bridge.size()<<" critical links"<<endl;

        for(auto x:bridge)
            cout<<x.first<<" - "<<x.second<<endl;
        cout<<endl;

    }

    return 0;
}


