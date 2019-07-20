#include<bits/stdc++.h>
#define scan(a) scanf("%d",&a);
#define sq(ii) (ii*ii)
using namespace std;
/*

 Problem : uva 10305
 category: tropological sort
 Date: 20 july 2019
 Ashraful Islam Fuad
 University of Asia Pacific
 Dhaka,Bangladesh
*/

void init_graph();

const int N=105;
bitset<N>visit;
int fin_time[N];
vector<int>graph[N];

int node,edge;
int t;


void dfs(int n)
{

    visit[n]=true;
    for(auto x:graph[n])
    {
        if(!visit[x])
            dfs(x);
    }

    fin_time[n]=t++;

} /// ... end func

bool comp(const pair<int,int> &a,const pair<int,int> &b)
{

    return a.first>b.first;
}

void  TopSort()
{

    t=1;

    for(int i=1;i<=node;++i)
    {
     if(!visit[i])
     {
         dfs(i);
     }

    }

    vector<pair<int,int> >tp_sort;

    for(int i=1;i<=node;++i)
    {

        tp_sort.push_back({fin_time[i],i});
    }


    sort(tp_sort.begin(),tp_sort.end(),comp);


      for(int i=0;i<tp_sort.size();++i)
      {

          cout<<tp_sort[i].second<<" ";
      }

    cout<<endl;
}


int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    // freopen("input.txt","r",stdin);
//   freopen("output.txt","w",stdout);


    while(true)
    {
        cin>>node>>edge;

        if(node+edge==0)
            return 0;

        for(int i=1; i<=node; ++i)
            graph[i].clear();
            memset(fin_time,0,sizeof(fin_time));
            visit.reset();
        for(int i=1; i<=edge; ++i)
        {
            int e1,e2;
            cin>>e1>>e2;
            graph[e1].push_back(e2);
        }


        TopSort();


      //  cout<<"completed "<<endl;

    }


    return 0;


}

