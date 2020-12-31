/*
Hey  why peeping here -_'_- ?
I believe on myself and I will achieve
this->author = Fuad Ashraful Mehmet, CSE ,University of Asia Pacific
Todo:
uva : 11488 - Hyper Prefix Sets
algo : Trie
*/

#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<(int)n;++i)
#define all(o) (o).begin(),(o).end()
#define sz(o) (o).size() 
#define dbg(o)  cerr<<"at "<<__LINE__<<" response = "<<o<<endl;
#define dbgV(O) cerr << #O << "=["; for(auto o : O) cerr << o << ", "; cerr << "E]\n";
#define pb push_back
using namespace std;
using pii=pair<int,int>;
typedef long long ll;
int n,m,tc,q,k,cs=1,len;
const int N=10005;
int ans=0;

struct node
{
	bool flag;
	int cnt;
	node* next[2];
	node()
	{
		flag=false;
		cnt=0;
		next[0]=next[1]=nullptr;
	}
}*head;

void insert_str(string &s)
{
	node* now=head;
	
	len=(int)sz(s);
	forn(i,len)
	{
		int idx=s[i]-'0';
		if(now->next[idx]==nullptr)
		{
			now->next[idx]=new node();
		}
		now=now->next[idx];
		now->cnt++;

		ans=max(ans,now->cnt*(i+1));
	}
	now->flag=true;
}
void HalfDead()
{	
	head=nullptr;
	head=new node();
	cin>>n;
	string s;
	forn(i,n)
	{
		cin>>s;
		insert_str(s);
	}

	cout<<ans<<"\n";
	ans=1;
	delete(head);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);  cout.tie(nullptr);
    //cout<<setprecision(10)<<fixed;
	int tc=1;
	cin>>tc;
	while(tc--){
		HalfDead();
	}
 	return 0;
}