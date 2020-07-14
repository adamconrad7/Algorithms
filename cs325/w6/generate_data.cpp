#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <fstream>
#include <vector>
using namespace std;

string random_string( size_t length )
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(length,0);
    std::generate_n( str.begin(), length, randchar );
    return str;
}

int main(){

  // CHANGE SIZE OF INPUT HERE:

  int n = 99;
  int r = 106;
  vector<string> vs;

  ofstream of;
  of.open("data.txt");

  of<<n<<endl;
  for(int i=0; i<n; i++){
    string s = random_string(5);
    vs.push_back(s);
    of<<s<<endl;
  }
  of<<r<<endl;
  for(int i = 0; i<r; i++){
    of<<vs[i]<<" "<<vs[n-(i+1)]<<endl;
  }

  //

  // of << base <<" "<< n <<" "<< target<<'\n';
  // of.close();
  return 0;
}
