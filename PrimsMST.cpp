#include<bits/stdc++.h>

#define sq(i)  (i*i)
using namespace std;
/*
 Problem : Spoj MST( Minimum Spanning Tree)
 category: graph
 Date: 21 july 2019
 Ashraful Islam Fuad

 University of Asia Pacific
 Dhaka,Bangladesh

*/
//int row[]= {-1,0,1,0};
//int col[]= {0,-1,0,1};

//int row [] = {+1,-1,+0,+0,-1,-1,+1,+1}; ///fuck array for eight direction
//int col [] = {+0,+0,+1,-1,+1,-1,-1,+1}; /// fuck array for eight direction

const int N=10005;
bitset<N>visit;
typedef long long int LL;

vector<pair<LL,LL> >graph[N];


int node,edge;

void  Prims_MST()
{

    priority_queue<pair<LL,LL> >pq;


    visit[1]=true;

   LL _Cost=0;
   for(int i=0;i<graph[1].size();++i)
   {

      pair<LL,LL> temp=graph[1][i]; /// first = node ,second = cost
       pq.push({temp.second*-1,temp.first});
   } /// ... init with first

    while(!pq.empty())
    {

        pair<LL,LL> tp=pq.top();
        pq.pop();

        if(visit[tp.second]==true)
            continue;

        visit[tp.second]=true;
            _Cost+=tp.first;

            for(auto x :graph[tp.second])
            {

                if(visit[x.first]==false)
                {
                    pq.push({x.second*-1,x.first});
                }
            }

    } /// ... end



    cout<<_Cost*-1<<endl;


}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //  freopen("input.txt","r",stdin);

    cin>>node>>edge;


     LL e1,e2,cost;

     for(int i=1;i<=edge;++i)
     {
         cin>>e1>>e2>>cost;
         graph[e1].push_back({e2,cost});
         graph[e2].push_back({e1,cost});
     }


     Prims_MST();


    return  0;
}

