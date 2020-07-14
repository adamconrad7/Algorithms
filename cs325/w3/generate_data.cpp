#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <vector>

using namespace std;

int main(){
  // CHANGE SIZE OF INPUT HERE:
  int n = 5;

  srand (time(NULL));
  vector <int> wv, bv;
//  vector <int> bv;
  int w, b;
  ofstream of;
  of.open("data.txt");
  of << n << '\n';
  for(int i=0; i<n; i++){
    w =  (rand() % 10 + 1);
  //  b =  (rand() % 100 + 1);
    b = 1;

    if(i==0){
      of << w <<" "<< b <<'\n';
      wv.push_back(w);
      bv.push_back(b);
    }else{
      of << w + wv[i-1] <<" "<< b  <<'\n';
      wv.push_back(w + wv[i-1]);
      bv.push_back(b + bv[i-1]);
    }
  }
  of.close();
  return 0;
}
