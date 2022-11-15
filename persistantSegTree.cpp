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

const int N=1e5+5, LOG=31;
int n,m,k,tc=1,q;

namespace PersitantSegTree{

	struct Vertex {
		Vertex *l, *r;
		int sum;

		Vertex(int val) : l(nullptr), r(nullptr), sum(val) {}
		Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
			if (l) sum += l->sum;
			if (r) sum += r->sum;
		}
	};

	Vertex* build(int a[], int tl, int tr) {
		if (tl == tr)
			return new Vertex(a[tl]);
		int tm = (tl + tr) / 2;
		return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
	}

	int get_sum(Vertex* v, int tl, int tr, int l, int r) {
		if (l > r)
			return 0;
		if (l == tl && tr == r)
			return v->sum;
		int tm = (tl + tr) / 2;
		return get_sum(v->l, tl, tm, l, min(r, tm))
			+ get_sum(v->r, tm+1, tr, max(l, tm+1), r);
	}

	Vertex* update(Vertex* v, int tl, int tr, int pos, int new_val) {
		if (tl == tr)
			return new Vertex(v->sum+new_val);
		int tm = (tl + tr) / 2;
		if (pos <= tm)
			return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
		else
			return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
	}

};

using namespace PersitantSegTree;

Vertex* version[N];

int a[N];

void solve(){
	cin>>n;

	forn(i,n)
		cin>>a[i];

	version[0] = build(a, 0, n-1);	


	int w,x,y,z;
	cin>>q;
	k=1;

	while(q--){
		cin>>w>>x>>y>>z;


		if(w==1){
			y--;
			version[k] = update(version[x], 0, n-1, y, z);
			k++;
		}else{
			y--;
			z--;

			int ret = get_sum(version[x], 0, n-1, y, z);

			cout<<ret<<'\n';
		}
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