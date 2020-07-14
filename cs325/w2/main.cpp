#include <iostream>
#include <vector>
#include <stdlib.h>     /* srand, rand */
#include <math.h>       /* floor */
//#include "badsort.h"
using namespace std;
//void badSort(vector<int> arr, int n, float alpha);
//void badSort(vector<int> arr, int n, float alpha, int start, int stop);
void badSort(int arr[], float alpha, int l, int h);
// vector<int> newarr(vector<int>, int start, int stop);
// vector<int> create_arr(int n);
//int* get_arr(int n);



//
// vector<int> create_arr(int n){
//   srand (time(NULL));
//   vector<int> v;
//   for(int i=0; i<n; i++){
//     v.push_back( rand() % 10 );
//   }
//     return v;
// }
//
// vector<int> newarr(vector<int> v, int start, int stop){
// // from start to stop, copy that part of the old array into the new one
// //   //need to copy chunk of input array into newarr
//     int n = stop - start + 3;
//     vector<int> nv;
//     for(int i = start; i< stop + 1 ; i++){
//       nv.push_back(v[i]);
//     }
//     return nv;
// }
//


/*
badSort(A[0···n−1])
  if (n= 2) and (A[0]> A[1])
    swapA[0] andA[1]
  else if (n >2)
    m = ceiling(α·n) m = 5
    badSort(A[0···m−1]) 0-5
    badSort(A[n−m···n−1]) 5 - 9
    badSort(A[0···m−1]) 0 - 5
*/

void badSort(int arr[], float alpha, int l, int h){
  if (l >= h)
    return;
  // if( n == 2 && arr[0] > arr[1]){
  if (arr[l] > arr[h]){
    int temp = arr[0];
    arr[0] = arr[1];
    arr[1] = temp;
  }
  // else if(n > 2){
  if(h-l+1>2){
  //  float m = ceil( alpha * n);
    float m = ceil( alpha * (h-l+1));
    int k = (h-l+1) - m;
    int t = (h-l+1) - k + 1;

    //sort from bottom to top minus partition size
    //sort from bottom plus partition size to top
    //sort from bottom to top minus partition size again
    badSort(arr, alpha, l, h-t);

    // Recursively sort last 2/3 elements
    badSort(arr, alpha, l+t, h);

    // Recursively sort first 2/3 elements
    // again to confirm
    badSort(arr, alpha, l, h-t);
  }
};


// void badSort( int arr[], int l, int h, float alpha){
//   if (l >= h)
//     return;
//   if (arr[l] > arr[h])
//     int temp = arr[0];
//     arr[0] = arr[1];
//     arr[1] = temp;
//   if(h-l+1>2){
//
//   }
//
// }
// void badSort(vector<int> arr, int n, float alpha){
//   if(n == 2 && (arr[0]) > arr[1]){
//     cout<<"Array is ["<<arr[0]<<','<<arr[1]<<']'<<endl;
//     int temp = arr[0];
//     arr[0] = arr[1];
//     arr[1] = temp;
//     cout<<"Array is now ["<<arr[0]<<','<<arr[1]<<']'<<endl;
//   // cout<<'\n';
//   }else if(n > 2){
//     float m = ceil( alpha * n);
//     cout << " m is "<<m<<endl;
//     cout<< " n - m  = " << n - m << endl;
//     cout<< " n - 1  = " << n - 1<< endl;
//     cout<<'\n';
//
// //
// //     vector<int> low = newarr( arr, 0, m-1);
// //
// // //    vector<int> v2( v.begin() + x, v.begin() + x + y );
// //     vector<int> other = newarr( arr, n-m, n-1);
//     vector<int> low( arr.begin(), arr.begin() + m - 1);
//     vector<int> other( arr.begin() + n-m + 1, arr.begin() + n );
//   //  cout<<"other array goes from"<<n-m<<" to "<< n-1<< endl;
//   //  cout<<"here"<<endl;
//     for(int i=0; i<low.size(); i++){
//       cout<< low[i] <<" ";
//     }
//     cout<<'\n';
//     for(int i=0; i<other.size(); i++){
//       cout<< other[i] <<" ";
//     }
//     cout<<'\n';
//     badSort(low, low.size(), alpha);
//
//   //  cout<<"here"<<endl;
//     badSort(other, other.size(), alpha);
//
//     badSort(low, low.size(), alpha);
//
//     //return low;
//   }
// }
//

//
//
// void badSort(vector<int> arr, int n, float alpha, int start, int stop){
//   if(n == 2 && (arr[start]) > arr[start + 1]){
//   //  cout<<"Array is ["<<arr[0]<<','<<arr[1]<<']'<<endl;
//     int temp = arr[start];
//     arr[start] = arr[start + 1];
//     arr[start + 1] = temp;
//   //  cout<<"Array is now ["<<arr[0]<<','<<arr[1]<<']'<<endl;
//   // cout<<'\n';
//   }else if(n > 2){
//     float m = ceil( alpha * n);
//     cout << " m is "<<m<<endl;
//     cout<< " n - m  = " << n - m << endl;
//     cout<< " n - 1  = " << n - 1<< endl;
//     cout<<'\n';
//   //   vector<int> low( arr.begin(), arr.begin() + m - 1);
//   //   vector<int> other( arr.begin() + n-m + 1, arr.begin() + n );
//   // //  cout<<"other array goes from"<<n-m<<" to "<< n-1<< endl;
//   //  cout<<"here"<<endl;
//     // for(int i=0; i<low.size(); i++){
//     //   cout<< low[i] <<" ";
//     // }
//     // cout<<'\n';
//     // for(int i=0; i<other.size(); i++){
//     //   cout<< other[i] <<" ";
//     // }
//     cout<<'\n';
//     badSort(arr, m, alpha, 0, m - 1);
//     badSort(arr, n - m, n-m+1, n -1 );
//     badSort(arr, n, alpha, 0, m - 1);
//   }
// }
//



//
// int* badsort(int * arr, int n, float alpha){
//   if(n == 2 && (arr[0]) > arr[1]){
//     //cout<<"Array is ["<<arr[0]<<','<<arr[1]<<']'<<endl;
//     int temp = arr[0];
//     arr[0] = arr[1];
//     arr[1] = temp;
//   //  cout<<"Array is now ["<<arr[0]<<','<<arr[1]<<']'<<endl;
//   // cout<<'\n';
//   }else if(n > 2){
//     float m = ceil( alpha * n);
//     vector<int> low = newarr( arr, 0, m-1);
//     vector<int> other = newarr( arr, n-m, n-1);
//   //  cout<<"other array goes from"<<n-m<<" to "<< n-1<< endl;
//     cout<<"here"<<endl;
//     badSort(low, low.size(), alpha);
//
//   //  cout<<"here"<<endl;
//     badSort(other, other.size(), alpha);
//
//     badSort(low, low.size(), alpha);
//
//     return low;
//   }
// }
//
// int* get_arr(int n){
//   srand (time(NULL));
//   int* arr = new int[n];
//   for(int i=0; i<n; i++){
//     arr[i] =  rand() % 10;
//   }
//   return arr;
// }
//
// int* new_arr(int* arr, int start, int stop){
//   int* newarr = new int[stop-start];
//   for(int i = start; i< stop + 1 ; i++){
//     newarr[i] = i;
//   }
// }

int main() {
  //int n = 6;
  float alpha = .75;
//  vector<int> v = create_arr(n);
  // for(int i=0; i<v.size(); i++){
  //   cout<< v[i]<<" ";
  // }
//  badSort(v, n, alpha, 0, n-1);
  int arr[] = {2, 4, 5, 3, 1};
  int n = sizeof(arr)/sizeof(arr[0]);

  badSort(arr, alpha, 0, n-1);
//  int* parr;
  // parr = get_arr(n);
  // for(int i = 0; i< n; i++){
  //   cout<< parr[i] << " ";
  // }
  for(int i=0; i<n; i++){
    cout<< arr[i]<<" ";
  }
  cout<<'\n';
  return 0;
}
