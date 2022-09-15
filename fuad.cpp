#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define all(o) (o).begin(), (o).end()
#define rall(o) (o).rbegin(), (o).rend()
#define sz(o) int(o.size())
#define FAST_IO  ios_base::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define dbg(o) cerr << "at " << __LINE__ << " response = " << o << endl;
#define dbgV(O) cerr << #O << "=["; for (auto o : O) cerr << o << ", "; cerr << "E]\n";
#define dbgA(a,L,R) cerr<<#a<<"=[";for(int i=L;i<=R;i++) cerr<<a[i]<<(i==R?"]\n":" ");
#define pb push_back
using namespace std;
using pii = pair<int, int>;
typedef long long ll;

const int N=1e5+5, LOG=20;
int n,m,k,tc=1;
set<int>g[N];

int par[N][LOG];
int P[N],sub[N], ans[N],d[N];

inline void add(int u, int v){
	g[u].insert(v);
	g[v].insert(u);
}

inline void remove(int u, int v){
	g[u].erase(v);
	g[v].erase(u);
}

void dfs1(int from, int f){
	par[from][0]=f;
	d[from] = 1+ d[f];

	for(int to:g[from]){
		if(to!=f)
			dfs1(to,from);
	}
}

void build_lca(){
	dfs1(1,0);

	for(int j=1;j<LOG;++j){
		for(int i=1;i<=n;++i){
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}

	return;
}

void dfs(int from, int pa){
	sub[from]=1;

	for(int to:g[from]){
		if(to!=pa){
			dfs(to, from);
			sub[from]+=sub[to];
		}
	}

	return;
}

int find_centroid(int from, int pa, int range){
	for(int to:g[from]){
		if(to==pa)continue;
		if(sub[to] > range)
			return find_centroid(to,from,range);
	}

	return from;
}

void build_tree(int node, int pa){
	dfs(node,0);

	int c = find_centroid(node,0,sub[node]>>1);
    P[c]=pa;
	vector<int>v;

	copy(all(g[c]), back_inserter(v));

	for(int x:v){
		remove(x,c);
		build_tree(x,c);
	}
	
	return;
}

int lca(int u, int v){
	if(d[u]>d[v])
		swap(u,v);
	
	for(int i=LOG-1;i>=0;--i){
		if(d[v]-(1<<i)>=d[u]){
			v=par[v][i];
		}
	}

	if(u==v)
		return u;
	

	for(int i=LOG-1;i>=0;--i){
		if(par[u][i]!=par[v][i]){
			u=par[u][i];
			v=par[v][i];
		}
	}

	return par[u][0];
}

inline int dist(int p, int q) {
	return d[p] + d[q] - (2 * d[lca(p, q)]);
}

void update(int x){
	int k=x;

	while(k!=0){
		ans[k]=min(ans[k], dist(x,k));
		k = P[k];
	}

	return;
}

int query(int x) {
	int res = 10000000;
	int k = x;
	while(k != 0) {
		res = min(res, dist(x, k) + ans[k]);
		k = P[k];
	}
	return res;
}

void solve(){
	cin>>n>>m;
	int x,y;
	for(int i=1;i<n;++i){
		cin>>x>>y;
		add(x,y);
	}

	build_lca();
	memset(ans, 63, sizeof ans);
	build_tree(1,0);

	

	update(1);

	int t, node;

	for(int i=1;i<=m;++i){
	
		cin>>t>>node;

		if(t==1){
			update(node);
		}else{
			cout<<query(node)<<'\n';
		}
	}

	return;
}

int main(){
	FAST_IO
	//cout<<setprecision(20)<<fixed;
	//cin>>tc;
	while(tc--){
		solve();
		//dbgA(ans,1,n)
	}

	return 0;
}
