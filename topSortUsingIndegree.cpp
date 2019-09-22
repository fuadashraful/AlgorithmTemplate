#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define _FasterIO  ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
#define inf (1<<30)
/*
 Author: Fuad Ashraful Mehmet
 University of Asia Pacific
 created :18 Sept 2019 10.58 am
 Category :  Top Sort using in degree
 Problem: uva  11060 Beverages
*/
using namespace std;
//int row[]= {-1,0,1,0};
//int col[]= {0,-1,0,1};
//int row [] = {+1,-1,+0,+0,-1,-1,+1,+1}; /// array for eight direction
//int col [] = {+0,+0,+1,-1,+1,-1,-1,+1}; ///  array for eight direction
int cs=1,tc,n,m;

const int N=105;
string drink[N];


void TopSort()
{

    map<string,int>mp;
    for(int i=1; i<=n; ++i)
    {
        cin>>drink[i];
        mp[drink[i]]=i;
    }

    cin>>m;
    int e1,e2;

   vector<int>graph[N];

    string u,v;
    int indegree[N]={0};
    for(int i=1;i<=m;++i)
    {
        cin>>u>>v;
        e1=mp[u];
        e2=mp[v];

        graph[e1].push_back(e2);
        indegree[e2]++;
    }



    priority_queue<int,vector<int>,greater<int> >Q;   ///   priority queue overloaded using greater key-word


    for(int i=1;i<=n;++i)
    {
        if(0==indegree[i])
            Q.push(i);
    }


    cout<<"Case #"<<cs++<<": Dilbert should drink beverages in this order:";


    while(!Q.empty())
    {

        int tp=Q.top();
        Q.pop();

        for(vector<int>::iterator it=graph[tp].begin();it!=graph[tp].end();++it)
        {
            indegree[*it]--;

            if(0==indegree[*it])
                Q.push(*it);
        }

        cout<<" "<<drink[tp];
    }


    cout<<".\n"<<endl;


} // end fun

int main()
{

    _FasterIO

   //freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);

    while(cin>>n)
    {
        TopSort();
    }

    return 0;
}


