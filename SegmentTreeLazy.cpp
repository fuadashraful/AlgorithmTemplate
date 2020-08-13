/*
 this->author = Fuad Ashraful Mehmet, CSE-UAP
 category: Segment Tree (lazy Propagration)
 Problem : 1135 - Count the Multiples of 3
*/
#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<(int)n;++i)
#define all(o) (o).begin(),(o).end()
#define dbg(o)  cerr<<"at "<<__LINE__<<" response = "<<o<<endl;
using namespace std;

const int N=1e5+5;
typedef  long long ll;
int n,m,k,cs=1;

int tree[3][N*4];
int lazy[N*4];

void build(int l,int r,int nd=1)
{
      if(l==r)
      {
            lazy[nd]=0;
            tree[0][nd]=1;
            tree[1][nd]=tree[2][nd]=0;
            return;
      }

      int mid=(l+r)>>1;
      build(l,mid,nd<<1);
      build(mid+1,r,nd<<1|1);
      lazy[nd]=0;

      forn(i,3)
      {
            tree[i][nd]=tree[i][nd<<1]+tree[i][nd<<1|1];
      }
      return;
}

void push_down(int nd,int val)
{
      vector<int>temp;
      for(int i=0;i<3;++i)
      {
            int p=i-val;
            if(p<0)p+=3;
            temp.push_back(tree[p][nd]);
      }
      for(int i=0;i<3;++i)
      {
            tree[i][nd]=temp[i];
      }

      lazy[nd]+=val;
}
int query(int l,int r,int x,int y,int nd=1)
{
      if(l>y or r<x)return 0;
      if(l>=x and r<=y)
      {
            return tree[0][nd];
      }
      
      if(lazy[nd])
      {
            push_down(nd<<1,lazy[nd]%3);
            push_down(nd<<1|1,lazy[nd]%3);
            lazy[nd]=0;
      }
      
      int mid=(l+r)>>1;
      int r1=query(l,mid,x,y,nd<<1);
      int r2=query(mid+1,r,x,y,nd<<1|1);
      for(int i=0;i<3;++i)tree[i][nd]=tree[i][nd<<1]+tree[i][nd<<1|1];
      return r1+r2;
}

void update(int l,int r,int x,int y,int nd=1)
{
      if(l>y or r<x)return;
      if(l>=x and r<=y)
      {
            lazy[nd]++;
            int temp=tree[2][nd];
            tree[2][nd]=tree[1][nd];
            tree[1][nd]=tree[0][nd];
            tree[0][nd]=temp;
            return;
      }

      if(lazy[nd])
      {
            push_down(nd<<1,lazy[nd]%3);
            push_down(nd<<1|1,lazy[nd]%3);
            lazy[nd]=0;
      }

      int mid=(l+r)>>1;

      update(l,mid,x,y,nd<<1);
      update(mid+1,r,x,y,nd<<1|1);

      for(int i=0;i<3;++i)tree[i][nd]=tree[i][nd<<1]+tree[i][nd<<1|1];
      return;
}

void HalfDead()
{
      scanf("%d%d",&n,&m);
      build(1,n);

      printf("Case %d:\n",cs++);

      int c,x,y;
      while(m--)
      {
            scanf("%d%d%d",&c,&x,&y);
            x++;
            y++;
            if(c)
            {
                  printf("%d\n",query(1,n,x,y));
            }
            else
            {
                  update(1,n,x,y);
            }
            
      }
}
int main()
{
      //ios_base::sync_with_stdio(0); cin.tie(nullptr);
      int tc=1;
      scanf("%d",&tc);
      while(tc--)
      {
            HalfDead();
      }
      return 0;
}