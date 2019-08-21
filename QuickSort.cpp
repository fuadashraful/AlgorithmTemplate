#include<bits/stdc++.h>
#define ll long long int
#define pb push_back
#define _FasterIO  ios_base::sync_with_stdio(false);  cin.tie(0); cout.tie(0);
/*
 Author: Fuad Ashraful Mehmet
 University of Asia Pacific
 created :20 Aug 2019  8.30  pm
 Category :  Quick Sort
 Problem:
*/
using namespace std;
//int row[]= {-1,0,1,0};
//int col[]= {0,-1,0,1};

//int row [] = {+1,-1,+0,+0,-1,-1,+1,+1}; ///fuck array for eight direction
//int col [] = {+0,+0,+1,-1,+1,-1,-1,+1}; /// fuck array for eight direction
int tc,cs=1;

void  quick_sort(int A[],int lo,int hi)
{


    if(lo>=hi)
    {
        return;  /// .base case
    }


     int idx=lo;

     for(int i=lo;i<hi;++i)
     {

         if(A[i]<A[hi])
         {

             swap(A[idx],A[i]);
             idx++;
         }
     }

     ///  hi is pivot
     swap(A[idx],A[hi]); /// swaping with pivot

     quick_sort(A,lo,idx-1);
     quick_sort(A,idx+1,hi);

} /// .. end function

void Solve()
{

    int A[10000];
   for(int i=0;i<10000;++i)
      A[i]=rand()%1001;

   quick_sort(A,0,10000-1);

    cout<<"the sorted array is "<<endl;
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
