#include <iostream>
#include <vector>
#include <stdlib.h>
#include <fstream>
#include <cstring>
#include <cmath>
using namespace std;
vector<string> split(string str,string sep);
vector<int> get_denoms(vector<int> v);

class Tuple
{
    // Access specifier
    public:

    // Data Members
    int denom;
    int n;


    // Member Functions()
    Tuple(){
      denom = 0;
      n = 0;
    }
    Tuple(int d, int nn){
      denom = d;
      n = nn;
    }
    void set(int d, int n){
      denom = d;
      n = n;
    }
    int get_denom(){
      return denom;
    }
    int get_n(){
      return n;
    }
    void printdata(){
    //  cout<<"denom: "<< denom<<'\n'<<"n: "<<n<<endl;
    cout<<denom<<' '<<n<<endl;

    }
};

vector<Tuple> get_change(vector<int> denoms, int n);
void write(vector<Tuple> T);

int main(int argc, char* argv[]){
  ifstream f(argv[1]);
  string delimiter = " ";
  vector<int> v;
  string line;
  if (f.is_open()) {
    getline(f, line);
    vector<string> chars = split(line, delimiter);
    for(int i=0; i<chars.size(); i++){
      v.push_back(stoi(chars[i]));
    }
    f.close();
  }else{
    std::cerr << "Failure to open file" << '\n';
    exit(0);
  }
  //we now have vector of ints from file
  vector<int> denoms = get_denoms(v);
  vector<Tuple> pairs = get_change(denoms, v[2]);
  write(pairs);
  return 0;
}

void write(vector<Tuple> T){
  ofstream o;
  o.open("change.out");
  //o << "Denomination n Coins " <<" "<< T[i].get_n()<<endl;
  for(int i=0; i<T.size(); i++){
    o << T[i].get_denom() <<" "<< T[i].get_n()<<endl;
  }
  o.close();
}

vector<Tuple> get_change(vector<int> denoms, int n){
  int sum = 0;
  int i = denoms.size() - 1;
  int nn = 0;
  vector<Tuple> pairs;
  while(sum < n){
    //use denoms in descending order
    if( sum + denoms[i] <= n){
      sum += denoms[i];
      nn++;
    }else{
      if(nn != 0){
        Tuple T(denoms[i], nn);
        pairs.push_back(T);
      }
      i--;
      nn = 0;
   }
  }
  Tuple T(denoms[i], nn);
  pairs.push_back(T);
  return pairs;
}

vector<int> get_denoms(vector<int> v){
  vector<int> denoms;
  for (size_t i = 0; i <v[1] + 1; i++) {
    denoms.push_back(pow(v[0], i));
  }
  return denoms;
}

vector<string> split(string str,string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current!=NULL){
        arr.push_back(current);
        current=strtok(NULL,sep.c_str());
    }
    return arr;
}
