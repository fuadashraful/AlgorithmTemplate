/*
Hey  why peeping here -_'_-?
I believe on myself and I will achieve
this->author = Fuad Ashraful Mehmet, CSE ,University of Asia Pacific
Todo:
https://codeforces.com/problemset?tags=1500-2400
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
const int N=1e5+2;
int n,m,tc=1,len,q,c[N],sz[N];
vector<int>g[N];

void cal_size(int from,int par=-1){
	sz[from]=1;
	for(int to:g[from]){
		if(to==par || c[to])continue;
		cal_size(to,from);
		sz[from]+=sz[to];
	}
	return;
}
int centroid(int from,int total,int par=-1){
	for(int to:g[from]){
		if(to==par or c[to])continue;
		if(sz[to]>total/2)return centroid(to,total,from);
	}
	return from;
}
void dfs(int from,int color){
	cal_size(from);
	int center=centroid(from,sz[from]);
	c[center]=color;
	for(int to:g[center]){
		if(!c[to])dfs(to,color+1);
	}
}
void solve(){
	cin>>n;
	int x,y;
	for(int i=1;i<n;++i){
		cin>>x>>y;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,1);
	for(int i=1;i<=n;++i)assert(c[i]);
	for(int i=1;i<=n;++i)cout<<char('A'+c[i]-1)<<" \n"[i==n];
	return;
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