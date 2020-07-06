/*
	this.author = Fuad Ashraful Mehmet
	Date: 06th July 2020
	Algo:suffix array of string
*/
#include<bits/stdc++.h>


using namespace std;

void radix_sort(vector<pair<pair<int,int> ,int> > &a)
{
	int n=a.size();
	// soring 2nd part
	{
		vector<int>cnt(n),pos(n);
		for(int i=0;i<n;++i)
		{
			cnt[a[i].first.second]++;
		}

		pos[0]=0;
		for(int i=1;i<n;++i)
		{
			pos[i]=pos[i-1]+cnt[i-1];
		}
		vector<pair<pair<int,int>,int> >new_a(n);
		for(int i=0;i<n;++i)
		{
			int p=a[i].first.second;
			new_a[pos[p]]=a[i];
			pos[p]++;
		}
		a=new_a;
	}
	// sorting 1st part
	{
		vector<int>cnt(n),pos(n);
		for(int i=0;i<n;++i)
		{
			cnt[a[i].first.first]++;
		}

		pos[0]=0;
		for(int i=1;i<n;++i)
		{
			pos[i]=pos[i-1]+cnt[i-1];
		}
		vector<pair<pair<int,int>,int> >new_a(n);
		for(int i=0;i<n;++i)
		{
			int p=a[i].first.first;
			new_a[pos[p]]=a[i];
			pos[p]++;
		}
		a=new_a;
	}
	return;
}
void HalfDead()
{
	string s;
	cin>>s;
	s+="$";

	int n=s.size();
	int k=0;
	vector<int>p(n),c(n); // p for position of sorted suffix array ,c for equivlent classs

	// calculation for k=0
	vector<pair<char,int> >a(n);
	for(int i=0;i<n;++i)a[i]={s[i],i};
	sort(a.begin(),a.end());

	for(int i=0;i<n;++i)p[i]=a[i].second;
	c[p[0]]=0;
	for(int i=1;i<n;++i)
	{
		if(a[i].first==a[i-1].first)c[p[i]]=c[p[i-1]];
		else c[p[i]]=c[p[i-1]]+1;
	}

	while((1<<k)<n)
	{
		vector<pair<pair<int,int> ,int> >pr(n);
		for(int i=0;i<n;++i)
		{
			pr[i]=make_pair(make_pair(c[i],c[(i+(1<<k))%n]),i); // making pair from class
		}
		radix_sort(pr);

		for(int i=0;i<n;++i)p[i]=pr[i].second;  // assigning position
		c[p[0]]=0;
		
		for(int i=1;i<n;++i)
		{
			if(pr[i].first==pr[i-1].first)
			{
				c[p[i]]=c[p[i-1]];
			}
			else
			{
				c[p[i]]=c[p[i-1]]+1;
			}
		}
		k++;
	}

	for(int i=0;i<n;++i)cout<<p[i]<<" "; cout<<endl;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(nullptr);
	HalfDead();

	return 0;
}