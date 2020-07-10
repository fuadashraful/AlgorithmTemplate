/*
 this->author = Fuad Ashraful Mehmet, CSE-UAP
 algo: suffix_array from cf
 added : 10th July 2020
*/
#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<(int)n;++i)
#define all(o) (o).begin(),(o).end()
#define dbg(o)  cerr<<"at "<<__LINE__<<" response = "<<o<<endl;

using namespace std;

typedef long long ll;
int n,m;

void counting_sort(vector<int> & pn ,vector<int> & c)
{
      vector<int>cnt(n),pos(n);
      for(int i=0;i<n;++i)
      {
            cnt[c[pn[i]]]++;
      }
      pos[0]=0;
      for(int i=1;i<n;++i)
      {
            pos[i]=pos[i-1]+cnt[i-1];
      }

      vector<int>new_pn(n);
      for(int i=0;i<n;++i)
      {
           int p=pos[c[pn[i]]];
           new_pn[p]=pn[i];
           pos[c[pn[i]]]++;
      }
      pn=new_pn;

      return;

} /// end counting sort
void HalfDead()
{
      string s;
      cin>>s;
      s+="$";
      n=(int)s.size();
      
      // cyclick shift when k=0
      vector<pair<char,int> >a(n);
      for(int i=0;i<n;++i)
      {
            a[i]={s[i],i};
      }
      sort(all(a));
      vector<int>pn(n),c(n);
      for(int i=0;i<n;++i)
      {
            pn[i]=a[i].second;
      }
      c[pn[0]]=0;
      for(int i=1;i<n;++i)
      {
            if(a[i].first==a[i-1].first)c[pn[i]]=c[pn[i-1]];
            else c[pn[i]]=c[pn[i-1]]+1;
      }
      // while 2^k <n then cyclic shift
      int k=0;
      while((1<<k)<n)
      {
            for(int i=0;i<n;++i)
            {
                  pn[i]=(pn[i]-(1<<k)+n)%n;
            }
            counting_sort(pn,c);
            //  assigning new class
            vector<int>new_c(n);
            new_c[pn[0]]=0;
            for(int i=1;i<n;++i)
            {
                  pair<int,int>now={c[pn[i]],c[(pn[i]+(1<<k))%n]};
                  pair<int,int>prev={c[pn[i-1]],c[(pn[i-1]+(1<<k))%n]};
                  if(now==prev)new_c[pn[i]]=new_c[pn[i-1]];
                  else new_c[pn[i]]=new_c[pn[i-1]]+1;
            }
            c=new_c;
            ++k;
      }

      for(int i=0;i<n;++i)cout<<pn[i]<<" "; cout<<endl;
}
int main()
{
      ios_base::sync_with_stdio(0); cin.tie(nullptr);
      int tc=1;
     // cin>>tc;
      while(tc--)
      HalfDead();
      return 0;
}