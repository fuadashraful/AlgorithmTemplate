#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define _FasterIO  ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
#define inf (1<<30)
/*
 Author: Fuad Ashraful Mehmet
 University of Asia Pacific
 created :24 sept 2019 10.58 am
 Category :   SCC(Strongly Connected Component)
 Problem: https://www.spoj.com/problems/CAPCITY/
 description:Maximum sizeed SCC in a graph
*/
using namespace std;
//int row[]= {-1,0,1,0};
//int col[]= {0,-1,0,1};
//int row [] = {+1,-1,+0,+0,-1,-1,+1,+1}; /// array for eight direction
//int col [] = {+0,+0,+1,-1,+1,-1,-1,+1}; ///  array for eight direction
int cs=1,tc,n,m;

const int N=100005;
vector<int>graph1[N],graph2[N];
bitset<N>visit;
stack<int>stk;
int t=1;
vector<int>temp,res;

inline int getInt()  /// .. fase scan
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

void dfs1(int node)
{

    visit[node]=true;

    for(auto x:graph1[node])
    {
        if(false==visit[x])
            dfs1(x);
    }
    stk.push(node);
} /// end dfs1


void  dfs2(int node)
{

    visit[node]=true;
    temp.push_back(node);
    for(auto x:graph2[node])
    {
        if(false==visit[x])
        {
            dfs2(x);
        }
    }
} /// end dfs2

int main()
{

    _FasterIO

     //  freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);


    n=getInt();
    m=getInt();
    int u,v;

    for(int i=1;i<=m;++i)
    {

        u=getInt();
        v=getInt();

      //  cout<<u<<" u "<<v<<endl;

        graph1[u].push_back(v);
        graph2[v].push_back(u);
    }



     for(int i=1;i<=n;++i)
     {
         if(false==visit[i])
         {
             dfs1(i);
         }
     }

    visit.reset();

    while(!stk.empty())
    {
        int tp=stk.top();
        stk.pop();
        if(false==visit[tp])
        {
            temp.clear();
            dfs2(tp);


            if(temp.size()>res.size())
            {
                res=temp;
            }


            /// here i am
        }
    } /// ...end ssc

    sort(begin(res),end(res));

      cout<<res.size()<<endl;
    for(vector<int>::iterator it=begin(res);it!=end(res);++it)
    {
        cout<<*it<<" ";
    }

    cout<<endl;

    return 0;
}


