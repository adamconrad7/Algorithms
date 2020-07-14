#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <vector>
using namespace std;

int main(){

  // CHANGE SIZE OF INPUT HERE:
  int base = 2;
  int n = 4;
  int target = 99;

  ofstream of;
  of.open("data.txt");
  of << base <<" "<< n <<" "<< target<<'\n';
  of.close();
  return 0;
}
