#include<bits/stdc++.h>



const int N=2005;
int parent[N];
using namespace std;
struct edges
{

    int u,v,cost;
    bool operator<(const edges &t)const
    {

        return cost<t.cost;
    }
};

vector<edges>mst;
map<string,int>comp;
int find_parent(int n)
{

    return parent[n]==n?n:find_parent(parent[n]);
} /// end dsu

void  _Kruskal()
{

  int _spanCost=0;
    for(int i=0;i<mst.size();++i)
    {

        int u=find_parent(mst[i].u);
        int v=find_parent(mst[i].v);

        if(u!=v)
        {
            parent[u]=v;
            _spanCost+=mst[i].cost;
        }
    } /// .. end

    cout<<_spanCost<<endl;
}
int main()
{




   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);

    int tc;
    scanf("%d",&tc);

    int newLineFlag=1;

    for(int cs=1; cs<=tc; ++cs)
    {
        mst.clear();
        comp.clear();

        if(newLineFlag>1)
        cout<<endl;
        newLineFlag=4;
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; ++i)
            parent[i]=i;
        int t=1;
        for(int i=1; i<=m; ++i)
        {
            string a,b;
            int c;
            cin>>a>>b;
            cin>>c;

            if(comp.find(a)==comp.end())
                comp[a]=t++;
            if(comp.find(b)==comp.end())
                comp[b]=t++;
                int u,v;
                u=comp[a];
                v=comp[b];
                mst.push_back({u,v,c});
        }
        sort(mst.begin(),mst.end()); /// ... end sorting and init


       _Kruskal();



    }

    return 0;
}
