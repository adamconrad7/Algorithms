// C++ code to implement stooge sort
#include <iostream>
#include <math.h>       /* floor */
using namespace std;

// Function to implement stooge sort
void stoogesort(int arr[],int l, int h)
{
    if (l >= h)
      return;

    // If first element is smaller than last,
    // swap them
    if (arr[l] > arr[h])
       swap(arr[l], arr[h]);

    // If there are more than 2 elements in
    // the array
    if(h-l+1>2)
    {
        //int t = (h-l+1)/3; // t is equal to m

        int s = (h-l+1) - floor( ((2/3) * (h-l+1)) );
        float m = ceil( (2/3) * (h-l+1));
        int k = (h-l+1) - m;
        int t = (h-l+1) - k + 1;
      //  cout<<"(t,j,s) = "<< t <<" "<<j<<" " <<s<<endl;
        // Recursively sort first 2/3 elements
        stoogesort(arr, l, h-t);

        // Recursively sort last 2/3 elements
        stoogesort(arr, l+t, h);

        // Recursively sort first 2/3 elements
        // again to confirm
        stoogesort(arr, l, h-t);
    }
}

// Driver Code
int main()
{
    int arr[] = {2, 4, 5, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Calling Stooge Sort function to sort
    // the array
    stoogesort(arr, 0, n-1);

    // Display the sorted array
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout<<'\n';
    return 0;
}
