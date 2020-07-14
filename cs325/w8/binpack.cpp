#include <iostream>
#include <fstream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

struct bin{
  int capacity;
  vector<int> weights;
};

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

vector<string> get_data(ifstream& f){
  string names;
  vector<string> v;
  if (f.is_open()) {
    while(getline(f, names,'\n')){
      //names.erase(names.length()-1);
      v.push_back(names);
    //  cout<<names<<endl;
    }
    f.close();
  }else{
    cerr << "Failure to open file" << '\n';
    exit(0);
  }
  return v;
}

vector<bin> make_bins(vector<string> v){
  vector<bin> bins;
  for(int i=1; i<v.size(); i+=3){
      bin b;
      vector<string> weightsstr = split(v[i+2]," ");

      for(auto i : weightsstr){
        b.weights.push_back(stoi(i));

      }
      b.capacity = stoi(v[i]);
      bins.push_back(b);
  }
  return bins;
}

vector<int> first_fit(vector<bin> b){
  vector<int> n_bins;
  for(auto i : b){//loops thru each test case
  //  int bins = 1;
    int bin_rem[i.weights.size()];
    int res = 0;
  //  int sum = 0;
    vector<int> caps;
    for(auto weight : i.weights){
      int j;
      for(j=0; j< res; j++){
        if(bin_rem[j] >= weight){
          bin_rem[j] = bin_rem[j] - weight;
          break;
        }
      }
      if(j == res){
        bin_rem[res] = i.capacity - weight;
        res++;
      }
    }
    n_bins.push_back(res);
  }
  return n_bins;
}

vector<int> first_fit_sorted(vector<bin> b){
  vector<int> n_bins;
  for(auto i : b){//loops thru each test case
    int bin_rem[i.weights.size()];
    int res = 0;
    vector<int> caps;
    sort(i.weights.begin(), i.weights.end());
    reverse(i.weights.begin(), i.weights.end());
    for(auto weight : i.weights){
      int j;
      for(j=0; j< res; j++){
        if(bin_rem[j] >= weight){
          bin_rem[j] = bin_rem[j] - weight;
          break;
        }
      }
      if(j == res){
        bin_rem[res] = i.capacity - weight;
        res++;
      }
    }
    n_bins.push_back(res);
  }
  return n_bins;
}

vector<int> best_fit(vector<bin> b){
  vector<int> n_bins;
  for( auto bin : b){
    int res = 0;
    int bin_rem[bin.weights.size()];
  //  cout<<bin.capacity<<endl;
    for(auto weight : bin.weights){
    //  vector<int> bin_rem = {};
      int j;
      int min = bin.capacity, bi = 0;
      for(j=0; j<res; j++){
        //cout<<"hella"<<endl;

        if(bin_rem[j] >= weight && bin_rem[j] - weight < min){
          bi = j;
          min = bin_rem[j] - weight;
        }
      }
      if(min == bin.capacity){
        bin_rem[res] = bin.capacity - weight;
        res++;
      }else{
          bin_rem[bi] -= weight;
      }
    }
    n_bins.push_back(res);
  }
  return n_bins;
}

vector<vector<int>> pack(vector<bin> bins){
  vector<vector<int>> res;
  vector<int> ff =  first_fit(bins);
  vector<int> ffs =  first_fit_sorted(bins);
  vector<int> bf =  best_fit(bins);
  res.push_back(ff);
  res.push_back(ffs);
  res.push_back(bf);
  return res;
}

void print(vector<vector<int>> res){
  int c = 0;
  for(auto alg : res){
    switch (c) {
      case 0:
        cout<<"First fit:"<<endl;
        break;
      case 1:
        cout<<"First fit descending:"<<endl;
        break;
      case 2:
        cout<<"Best fit:"<<endl;
        break;
    }
    for(auto c : alg){
      cout<<c<<endl;
    }
    c++;
    cout<<endl;
  }
}

//
// int knapSack(int W, int n, vector<Tuple> pairs)
// {
//   // W is the bin size aka capacity
//   // n is the amount of items to be packed
//   // instead of pairs we can use the weights and assume benefit = 1 for every item;
//    int i, w;
//    int K[n+1][W+1];
//
//    // Build table K[][] in bottom up manner
//    for (i = 0; i <= n; i++)
//    {
//        for (w = 0; w <= W; w++)
//        {
//            if (i==0 || w==0)
//               K[i][w] = 0;
//            else if (pairs[i-1].get_weight() <= w)
//               K[i][w] = max(1 + K[i-1][w-pairs[i-1].get_weight()], K[i-1][w] );
//               K[i][w] = max(pairs[i-1].get_benefit() + K[i-1][w-pairs[i-1].get_weight()], K[i-1][w] );
//            else
//               K[i][w] = K[i-1][w];
//        }
//    }
//    return K[n][W];
// }


int main(int argc, char* argv[]){
  ifstream f("bin1.txt");
  print(pack(make_bins(get_data(f))));
  return 0;
}
