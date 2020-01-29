/*
  Ashraful Islam Mehmet
  University of Asia Pacific
  Category : MO'S Algorithm
  problem:lightoj 1188 fastqueries
 
*/
#include<bits/stdc++.h>
 
using namespace std;
int tc,n,k,m,cs=1;
typedef long long ll;
const int N=1e5+5;
int A[N],ans[N],cnt[N];
int block,curAns;
struct Data{
 int l,r,pos;
};
Data q[50003];
 
bool cmp(Data x, Data y)
{
    if((x.l/block)==(y.l/block))
        return x.r<y.r;
   return x.l/block<y.l/block;
}
 
 
void add(int num)
{
    cnt[A[num]]++;
    if(cnt[A[num]]==1)curAns++;
}
void Remove(int num)
{
    cnt[A[num]]--;
    if(cnt[A[num]]==0)curAns--;
}
int main()
{
   // freopen("input.txt","r",stdin);
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d %d",&n,&m);
        block=sqrt(n);
 
        for(int i=0;i<n;++i)
            scanf("%d",&A[i]);
        int x,y;
        for(int i=0;i<m;++i)
        {
            scanf("%d %d",&x,&y);
           // cout<<"x y "<<x<<" "<<y<<endl;
            x--; y--;
            q[i].l=x;
            q[i].r=y;
            q[i].pos=i;
        }
        sort(q,q+m,cmp);
        curAns=0;
        int cl=0,cr=0;
        memset(cnt,0,sizeof cnt);
 
        for(int i=0;i<m;++i)
        {
            x=q[i].l;
            y=q[i].r;
            while(cl<x)
            {
                Remove(cl);
                cl++;
            }
            while(cl>x)
            {
                cl--;
                add(cl);
            }
            while(cr<=y)
            {
                add(cr);
                cr++;
            }
            while(cr>y+1)
            {
                Remove(cr-1);
                cr--;
            }
            ans[q[i].pos]=curAns;
//            cout<<"cx cy "<<cl<<" "<<cy<<end;
        } /// end query
 
        printf("Case %d:\n",cs++);
        for(int i=0;i<m;++i)
            printf("%d\n",ans[i]);
    }/// end case
    return 0;
}