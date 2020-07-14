#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <chrono>
using namespace std;
using namespace std::chrono;
void merge(int arr[], int low, int high, int mid);
void mergesort( int arr[], int low, int high);

int main(int argc, char* argv[]) {
  //Variables for storing runtime information
  int p = 5;
  int tarr[p];
  //repeats to collect multiple runtime samples
  for(int i =0; i<p; i++){
    string delimiter = " ";
    string s;
    vector<string> tokens;

    //read file
    ifstream f(argv[1]);
    getline(f, s);
    f.close();


    //extract n
    string token = s.substr(0, s.find(delimiter));
    s.erase(0, s.find(delimiter) + delimiter.length());
    int n = stoi(token);

    //make array to be sorted and populate with data from file
    int arr[n];
    istringstream iss(s);
    copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
    for(int i=0; i<n; i++){
      arr[i] = stoi(tokens[i]);
    }
    int low = 0;
    int high = n -1;

    //sort list and record elapsed time
    auto start = high_resolution_clock::now();
    mergesort(arr, low, high);
    auto stop = high_resolution_clock::now();

    //write sorted list
    ofstream of;
    of.open("merge.out");
    for(int i=0; i<n; i++){
      of << arr[i] <<" ";
    }
    of.close();

    //write runtime and store in array
    auto duration = duration_cast<microseconds>(stop - start);
    ofstream off;
    off.open("times.out", fstream::app);
    off << duration.count() <<" ";
    off.close();
    tarr[i] = duration.count();

  }
  //Find average runtime and write to file
  int times = 0;
  for(int i=0; i<p; i++){
    times += tarr[i];
  }
  ofstream offf;
  offf.open("times.out", fstream::app);
  offf <<"\n"<< times/p <<"\n";
  offf.close();
  return 0;
}

void mergesort( int arr[], int low, int high){
   if(low < high){

     int mid;
     mid = (low + high) /2;
     mergesort(arr, low, mid);
     mergesort(arr, mid+1, high);
     merge(arr, low, high, mid);
   }
   return;
 }

void merge(int arr[], int low, int high, int mid){

     int i, j, k, c[20000];
     i = low;
     k = low;
     j = mid + 1;
     while (i <= mid && j <= high)
     {
         if (arr[i] < arr[j])
         {
             c[k] = arr[i];
             k++;
             i++;
         }
         else
         {
             c[k] = arr[j];
             k++;
             j++;
         }
     }
     while (i <= mid)
     {
         c[k] = arr[i];
         k++;
         i++;
     }
     while (j <= high)
     {
         c[k] = arr[j];
         k++;
         j++;
     }
     for (i = low; i < k; i++)
     {
         arr[i] = c[i];
     }
 }
