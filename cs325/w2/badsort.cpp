#include <iostream>
#include <math.h>       /* floor */

/*
badSort(A[0···n−1])
  if (n= 2) and (A[0]> A[1])
    swapA[0] andA[1]
  else if (n >2)
    m=floor(α·n) m = 5
    badSort(A[0···m−1]) 0-5
    badSort(A[n−m···n−1]) 5 - 9
    badSort(A[0···m−1]) 0 - 5
*/
// void badSort(int arr[], int n, float alpha){
//   if(n == 2 && (arr[0]) > arr[1]){
//     int temp = arr[0];
//     arr[0] = arr[1];
//     arr[1] = temp;
//   }else if(n > 2){
//     float m = floor( alpha * n);
//     badSort()
//   }
// }
// arr[10] -> arr[2-7]

int* newarr(int arr[], int start, int stop){
// from start to stop, copy that part of the old array into the new one
//   //need to copy chunk of input array into newarr
    int n = stop - start + 1;
    int narr[n];
    for(int i = start; i< n; i++){
      narr[i - n] = arr[i];
    }
    return narr;
}
// }
