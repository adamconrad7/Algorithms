#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;
vector<string> split(string str,string sep);
int max(int a, int b) { return (a > b)? a : b; }

class Tuple
{
    // Access specifier
    public:

    // Data Members
    int weight;
    int benefit;
    float ratio;

    // Member Functions()
    Tuple(){
      weight = 0;
      benefit = 0;
      ratio = (float)benefit/(float)weight;
    }
    Tuple(int w, int b){
      weight = w;
      benefit = b;
      ratio = (float)benefit/(float)weight;

    }
    void set(int w, int b){
      weight = w;
      benefit = b;
      ratio = (float)benefit/(float)weight;

    }
    int get_weight(){
      return weight;
    }
    int get_benefit(){
      return benefit;
    }
    void printdata(){
      cout<<"Weight: "<< weight<<'\n'<<"Benefit: "<<benefit<<endl;
    }
    void printratio(){
      cout<<"w/b ratio: "<<ratio<<endl;
    }
};

int knapSack(int W, int n, vector<Tuple> pairs);

int main(int argc, char* argv[]){
  // CHANGE MAX WEIGHT OF KNAPSACK HERE:
  int w = 30;

  //read file
  vector<Tuple> pairs;
  int n;
  int i = 0;



  ifstream f(argv[1]);
  if (f.is_open()) {
      string line;
      int w, b;
      string delimiter = " ";
      while (getline(f, line)) {
          if( i == 0){
            n = stoi(line);
          }else{
            vector<string> v = split(line, delimiter);
            Tuple T(stoi(v[0]), stoi(v[1]));
            pairs.push_back(T);
          }
          i++;
        }
        f.close();
  }

  // for (size_t i = 0; i < pairs.size(); i++) {
  //    pairs[i].printdata();
  // }
  int ans = knapSack(w, n, pairs);
  for (size_t i = 0; i < pairs.size(); i++) {
    /* code */
    pairs[i].printratio();
  //  pairs[i].printdata();
  }
  cout<<ans<<endl;
  return 0;
}


int knapSack(int W, int n, vector<Tuple> pairs)
{
   int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
              K[i][w] = 0;
           else if (pairs[i-1].get_weight() <= w)
              K[i][w] = max(pairs[i-1].get_benefit() + K[i-1][w-pairs[i-1].get_weight()], K[i-1][w] );
           else
              K[i][w] = K[i-1][w];
       }
   }
   return K[n][W];
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
