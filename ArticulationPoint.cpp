#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define _FasterIO  ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);

/***
 Author: Fuad Ashraful Mehmet
 University of Asia Pacific
 created :24 sept 2019 10.58 am
 Category : Articulation point (DFS)
 Problem: Uva 315 - Network

***/
using namespace std;
//int row[]= {-1,0,1,0};
//int col[]= {0,-1,0,1};
//int row [] = {+1,-1,+0,+0,-1,-1,+1,+1}; /// array for eight direction
//int col [] = {+0,+0,+1,-1,+1,-1,-1,+1}; ///  array for eight direction

static const int UNVISIT=0;
static const int FIX=102;
vector<vector<int> >graph;
vector<int>discover;
vector<int>low;
vector<int>parent;
vector<bool>ArtPoint;
int rootChild;
int timeClock;

void DFS(int node,int root)
{

    discover[node]=timeClock;
    low[node]=timeClock++;


    for(auto x:graph[node])
    {

        if(discover[x]==UNVISIT)
        {

            parent[x]=node;
            if(node==root)
            {
                rootChild++;
            }

            DFS(x,root);

            if(node!=root&&low[x]>=discover[node])
            {
                ArtPoint[node]=true; /// here is articulation point
            }


            low[node]=min(low[node],low[x]);
        }
        else if(x!=parent[node]) /// back-edge found here
        {
            low[node]=min(low[node],discover[x]);

        }
    }
} /// end func

void initAll() /// initialize all require variable
{

    graph.clear();
    graph.resize(FIX);
    discover.clear();
    discover.resize(FIX,UNVISIT);
    low.clear();
    low.resize(FIX,UNVISIT);
    parent.clear();
    parent.resize(FIX,UNVISIT);
    ArtPoint.clear();
    ArtPoint.resize(FIX,false);
    timeClock=1;

} /// end


void FindArticulationPoint(int N)
{

    for(int i=1; i<=N; ++i)
    {

        if(discover[i]==UNVISIT)
        {
            rootChild=0;
            DFS(i,i);

            if(rootChild>1)
                ArtPoint[i]=true;
        }
    }
} /// end func

int main()
{

    _FasterIO
    //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);

    int N;

    while(cin>>N,N!=0)
    {

        cin.ignore();

        initAll();

        string f;
        while(getline(cin,f),f!="0")
        {

            stringstream sin(f);  ///  this function convert from string to integer
            int u,v;
            sin>>u;
            while(sin>>v)
            {
                graph[u].push_back(v);
                graph[v].push_back(u);
            }
        } /// end input


        FindArticulationPoint(N);

       cout<<count(ArtPoint.begin(),ArtPoint.end(),true)<<endl; /// count total ArtPoint

    }

    return 0;
}
