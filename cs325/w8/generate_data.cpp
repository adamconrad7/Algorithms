#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <vector>
using namespace std;

int main(){
  srand(time(NULL));
  //NUMBER OF TEST CASES:
  int n = 20;
//  int target = 99;
  ofstream of;
  of.open("bin1.txt");
  of<<n<<endl;
  for(int i = 0; i< n; i++){
    int bin_size = rand() % 20 + 1;
    of<<bin_size<<endl;
    int m = rand() % 50 + 1;
    of<<m<<endl;
    for(int j=0; j<m; j++){
      of<<rand() % 10 + 1<<" ";
    }
    of<<endl;
    // cout<<endl;
  }

  // of << base <<" "<< n <<" "<< target<<'\n';
  // of.close();
  return 0;
}
