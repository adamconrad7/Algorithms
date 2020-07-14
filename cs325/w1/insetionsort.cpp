#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
using namespace std::chrono;

void insertionsort(int arr[], int size);

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
    insertionsort(arr, n);
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
  offf <<"\n"<< times/p <<"\n\n";
  offf.close();
  return 0;
}

void insertionsort(int arr[], int size) {
   int key, j;
   for(int i = 1; i<size; i++) {
      key = arr[i];
      j = i;
      while(j > 0 && arr[j-1]>key) {
         arr[j] = arr[j-1];
         j--;
      }
      arr[j] = key;
   }
}
