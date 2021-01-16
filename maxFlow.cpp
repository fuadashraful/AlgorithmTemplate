/*
Hey  why peeping here -_'_- ?
I believe on myself and I will achieve
this->author = Fuad Ashraful Mehmet, CSE ,University of Asia Pacific
Todo:
https://www.youtube.com/watch?v=n_oP9Onj0r0
lightoj : 1153
*/
#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define all(o) (o).begin(), (o).end()
#define rall(o) (o).rbegin(), (o).rend()
#define sz(o) (o).size()
#define dbg(o) cerr << "at " << __LINE__ << " response = " << o << endl;
#define FAST_IO                   \
	ios_base::sync_with_stdio(0); \
	cin.tie(nullptr);             \
	cout.tie(nullptr);
#define dbgV(O)            \
	cerr << #O << "=[";    \
	for (auto o : O)       \
		cerr << o << ", "; \
	cerr << "E]\n";
#define pb push_back
using namespace std;
using pii = pair<int, int>;
typedef long long ll;
int n,m,k,tc=1,q,cs=1,len;
const int N=105;
int g[N][N],color[N],father[N];

int bfs(int src,int dest)
{
	forn(i,n+1)color[i]=0;
	color[src]=1;
	father[src]=-1;
	queue<int>q;
	q.push(src);
	while(!q.empty())
	{
		int from=q.front();
		q.pop();
		for(int to=1;to<=n;++to)
		{
			if(color[to] or g[from][to]<=0)continue;
			q.push(to);
			color[to]=1;
			father[to]=from;
		}
	}

	return color[dest];
}
int maxFlow()
{
	int src,dest,c;
	scanf("%d",&n);
	scanf("%d%d%d",&src,&dest,&c);
	forn(i,n+1)
	{
		forn(j,n+1)
		{
			g[i][j]=0;
		}
	}

	int u,v,cost;
	forn(i,c)
	{
		scanf("%d%d%d",&u,&v,&cost);
		g[u][v]+=cost;
		g[v][u]+=cost;
	}

	int flow=0;
	while(bfs(src,dest))
	{
		int path=1e9+7;
		for(int i=dest;i!=src;i=father[i])
		{
			path=min(path,g[father[i]][i]);
		}
		for(int i=dest;i!=src;i=father[i])
		{
			g[father[i]][i]-=path;
			g[i][father[i]]+=path;
		}
		flow+=path;
	}
	return flow;
}
int main()
{
	//FAST_IO
	//cout<<setprecision(10)<<fixed;
	//cin >> tc;
	scanf("%d",&tc);
	while (tc--)
	{
		printf("Case %d: %d\n",cs++,maxFlow());
	}
	return 0;
}