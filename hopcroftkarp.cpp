 /*
I believe on myself and I will achieve
author = Fuad Ashraful Mehmet, CSE ,University of Asia Pacific
Todo:
*/
#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define all(o) (o).begin(), (o).end()
#define rall(o) (o).rbegin(), (o).rend()
#define sz(o) int(o.size())
#define FAST_IO  ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define dbg(o) cerr << "at " << __LINE__ << " response = " << o << endl;
#define dbgA(a,L,R) cerr<<#a<<"=[";for(int i=L;i<=R;i++) cerr<<a[i]<<(i==R?"]\n":" ");
#define dbgV(O) cerr << #O << "=["; for (auto o : O) cerr << o << ", "; cerr << "E]\n";
#define pb push_back
using namespace std;
using pii = pair<int, int>;
typedef long long ll;
const int N=31;
int n,m,k,tc=1,l;

struct HopcroftKarp{
	static const int NIL=0,INF=(1<<29),SZ=1e5+5;
	int match[SZ],dist[SZ],n,m;
	vector<int>g[SZ];
	HopcroftKarp(int lft,int rgt):n(lft),m(rgt){
		for(int i=0;i<=lft+rgt+1;++i){
			g[i].clear();
		}
	}

	inline void addEdge(int u,int v){
		g[u].pb(v+n);
	}

	bool bfs(){
		queue<int>q;
		for(int i=1;i<=n;++i){
			if(match[i]==NIL)dist[i]=0,q.push(i);
			else dist[i]=INF;
		}
		dist[NIL]=INF;

		while(!q.empty()){
			int tp=q.front(); q.pop();
			if(tp!=NIL){
				for(int to:g[tp]){
					if(dist[match[to]]==INF){
						dist[match[to]]=dist[tp]+1;
						q.push(match[to]);
					}
				}
			}
		}

		return bool(dist[NIL]!=INF);
	}

	bool dfs(int from){
		if(from!=NIL){
			for(int to:g[from]){
				if(dist[match[to]]==dist[from]+1){
					if(dfs(match[to])){
						match[to]=from;
						match[from]=to;
						return true;
					}
				}
			}
			dist[from]=INF;
			return false;
		}
		return true;
	}


	int run(){
		memset(dist,0,sizeof dist);
		memset(match,0,sizeof match);
		int matching=0;
		while(bfs()){
			for(int i=1;i<=n;++i){
				if(match[i]==NIL && dfs(i))matching++;
			}
		}
		return matching;
	}
};

vector<tuple<int,int,int> >edges;

bool ok(int mid){
	HopcroftKarp obj(n,n);
	for(int i=0;i<=mid;++i){
		obj.addEdge(get<1>(edges[i]),get<2>(edges[i]));
	}
	return obj.run()==n;
 
}
void solve(){
	cin>>n>>m;
	int u,v,x;
	for(int i=1;i<=m;++i){
		cin>>u>>v>>x;
		edges.push_back(make_tuple(x,u,v));
	}
	sort(all(edges));

	int lo=0,hi=m-1;
	while(lo<=hi){
		int mid=lo+hi>>1;
		if(ok(mid))hi=mid-1;
		else lo=mid+1;
	}
	if(lo>=m){
		cout<<-1<<'\n';
		exit(0);
	}else{
		cout<<get<0>(edges[lo])<<'\n';
	}
}
int main(){
	FAST_IO
	//cout<<setprecision(20)<<fixed;
	//cin>>tc;
	while(tc--){
		solve();
	}
	return 0;
}