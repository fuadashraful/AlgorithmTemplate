/*
Hey  why peeping here -_'_-?
I believe on myself and I will achieve
this->author = Fuad Ashraful Mehmet, CSE ,University of Asia Pacific
Todo:
https://codeforces.com/problemset?tags=1500-2300
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
int  n,m,k,tc=1,len,q;
const int N=5e6+2;
ll dp[N];
string s;
struct Hash{
	int len,base,mod;
	vector<int>p,h;
	Hash(int len,int base,int mod):len(len),base(base),mod(mod){
		p.resize(len+1);
		h.resize(len+1);
		p[0]=1;
		for(int i=1;i<=len;++i)p[i]=(1ll*p[i-1]*base)%mod;
	}
	void init(string &str){
		for(int i=1;i<=len;++i){
			h[i]=(1ll*h[i-1]*base+(int)str[i-1])%mod;
		}
	}
	int substr_hash(int l,int r){
		return ((1ll*h[r]-(1ll*h[l-1]*p[r-l+1])%mod)+mod)%mod;
	}
};

void solve(){
	cin>>s;
	n=sz(s);
	Hash obj1(n,997,1e9+7);
	obj1.init(s);
	reverse(all(s));
	Hash obj2(n,997,1e9+7);
	obj2.init(s);

	ll ans=0;
	for(int i=1;i<=n;++i){
		if(obj1.substr_hash(1,i)==obj2.substr_hash(n-i+1,n)){
			dp[i]=dp[i>>1]+1;
			ans+=dp[i];
		}
	}
	cout<<ans<<'\n';
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