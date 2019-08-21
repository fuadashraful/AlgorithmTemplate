#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define _FasterIO  ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
/*
 Author: Fuad Ashraful Mehmet
 University of Asia Pacific
 created :20 Aug 2019  8.30  pm
 Category :  Merge Sort (Divide and conquer)
 Problem:
*/
using namespace std;
//int row[]= {-1,0,1,0};
//int col[]= {0,-1,0,1};

//int row [] = {+1,-1,+0,+0,-1,-1,+1,+1}; ///fuck array for eight direction
//int col [] = {+0,+0,+1,-1,+1,-1,-1,+1}; /// fuck array for eight direction
int tc,cs=1;

void merge_array(int A[],int lo,int hi)
{

  int M=hi-lo+1;
  int temp[M];
  int mid=(lo+hi)>>1;
  int idx1=lo,idx2=mid+1,idx=0;

  for(int i=lo;i<=hi;++i)
  {

      if(idx1>mid)
          temp[idx++]=A[idx2++];
      else if(idx2>hi)
        temp[idx++]=A[idx1++];
      else if(A[idx1]<A[idx2])
        temp[idx++]=A[idx1++];
      else
        temp[idx++]=A[idx2++];
  } /// end loop

 idx=0;
  for(int i=lo;i<=hi;++i)
  {

      A[i]=temp[idx++];
  }

} /// .. end func

void  merge_sort(int A[],int lo,int hi)
{

    if(lo>=hi)
        return;

    int mid=(lo+hi)>>1;

    merge_sort(A,lo,mid);
    merge_sort(A,mid+1,hi);

    merge_array(A,lo,hi);
} /// end sort func


void Solve()
{

    int A[10000];
   for(int i=0;i<10000;++i)
      A[i]=rand()%1001;


      merge_sort(A,0,10000-1);



    cout<<"The sorted array after merge sort is "<<endl;

    for(int i=0;i<10000;++i)
        cout<<A[i]<<" ";

    cout<<endl;


} /// ... end function

int main()
{

    _FasterIO

    // freopen("input.txt","r",stdin);
    //  freopen("output.txt","w",stdout);

//   cin>>tc;
//   while(tc--)
    Solve();


    return 0;
}
