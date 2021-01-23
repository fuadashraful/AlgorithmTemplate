/*
Hey  why peeping here -_'_- ?
I believe on myself and I will achieve
this->author = Fuad Ashraful Mehmet, CSE ,University of Asia Pacific
Todo:
https://www.youtube.com/watch?v=n_oP9Onj0r0
uva :10080
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
int n,m,sec,vel,k,tc=1,q,cs=1,len;
const int N=505;
pair<double,double>gop[N],holes[N];

struct FlowEdge
{
	int u,v;
	long long cap,flow=0;
	FlowEdge(int u,int v,long long cap):u(u),v(v),cap(cap){}
};

struct Dinic
{
	const long long inf=1e18;
	vector<FlowEdge>edges;
	vector<vector<int> >adj;
	int n,s,t,m=0;
	vector<int>level,ptr;
	queue<int>q;
	Dinic(int n,int s,int t):n(n),s(s),t(t){
		adj.resize(n);
		level.resize(n);
		ptr.resize(n);
	}

	void add_edge(int u,int v,long long cap)
	{
		edges.emplace_back(u,v,cap);
		edges.emplace_back(v,u,0);
		adj[u].pb(m);
		adj[v].pb(m+1);
		m+=2;
		return;
	}

	bool bfs()
	{
		while(!q.empty())
		{
			int from=q.front();
			q.pop();
			for(int to:adj[from])
			{
				if(edges[to].cap-edges[to].flow<1)continue;
				if(level[edges[to].v]!=-1)continue;
				level[edges[to].v]=level[from]+1;
				q.push(edges[to].v);
			}
		}
		return level[t]!=-1;
	}

	long long dfs(int from,long long pushed)
	{
		if(pushed==0)return 0;
		if(from==t) return pushed;

		for(int &cid=ptr[from];cid<(int)adj[from].size();cid++)
		{
			int id=adj[from][cid];
			int to=edges[id].v;
			if(level[from]+1!=level[to])continue;
			if(edges[id].cap-edges[id].flow<1)continue;
			long long tr=dfs(to,min(pushed,edges[id].cap-edges[id].flow));
			if(tr==0)continue;
			edges[id].flow+=tr;
			edges[id^1].flow-=tr;
			return tr;
		}
		return 0;
	}
	long long flow()
	{
		ll ans=0;
		while(true)
		{
			fill(all(level),-1);
			level[s]=0;
			q.push(s);
			if(!bfs())break;
			fill(all(ptr),0);

			while(long long pushed=dfs(s,inf))
			{
				ans+=pushed;
			}
		}
		return ans;
	}
};

double get_dist(const pair<double,double > &x,const pair<double,double> &y)
{
	return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
}// end func

void Solve()
{
	//cout<<n<<" "<<m<<" "<<s<<" "<<v<<endl;
	forn(i,n)
	{
		cin>>gop[i].first>>gop[i].second;
	}
	forn(i,m)
	{
		cin>>holes[i].first>>holes[i].second;
	}

	Dinic object(N,0,502);

	forn(i,n)
	{
		object.add_edge(0,i+1,1);
	}
	forn(j,m)
	{
		object.add_edge(j+201,502,1);
	}

	double allowed_dist=1.00*sec*vel;
	forn(i,n)
	{
		forn(j,m)
		{
			if(get_dist(gop[i],holes[j])<=allowed_dist)
			{
				object.add_edge(i+1,j+201,1);
			}
		}
	}
	ll ret=object.flow();
	//dbg(ret);
	cout<<n-ret<<endl;
}
int main()
{
	FAST_IO
	//cout<<setprecision(10)<<fixed;
	//cin>>tc;
	int taken=0;
	while(cin>>n>>m>>sec>>vel)
	{
		taken++;
		Solve();
	}
	return 0;
}