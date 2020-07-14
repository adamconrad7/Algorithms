#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <string.h>
using namespace std;

class Bimap{
  public:
  vector<pair<string, int>> v;

  void add_pair(pair<string, int> p){
    v.push_back(p);
  }

  void print(){
    for(auto i : v){
      cout<<i.second<<" ";
    }
    cout<<endl;
    for(auto i : v){
      cout<<i.first<<" ";
    }
    cout<<endl;
  }

  int find_int(string s){
    for(auto i : v){
      if(i.first == s){
        return i.second;
      }else if(i == v.back()){
        cout<<"could not find an int matching "<<s<<"."<<endl;
      //  exit(0);
      }
    }
    return -1;
  }

  string find_str(int n){
    for(auto i : v){
      if(i.second == n){
        return i.first;
      }else if(i == v.back()){
        cout<<"could not find a string matching "<<n<<"."<<endl;
        //exit(0);
      }
    }
    return "0";
  }

};

struct result{
  vector<vector<int>> adj;
  Bimap b;
};

void edge(vector<vector<int>>& adj, int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

bool isBipartite(struct result res, vector<bool>& visited, vector<int>& color){
  vector<vector<int>>& adj = res.adj;
  int r = 0;
  int c = 0;
  for ( const std::vector<int> &v : adj){
    for(auto x : v){
      if(x){
        if(!visited[r] && !visited[c]){
          visited[r] = true;
          visited[c] = true;
          color[r] = !color[c];
        }else if(!visited[r]){
          visited[r] = true;
          color[r] = !color[c];
        }else if(!visited[c]){
          visited[c] = true;
          color[c] = !color[r];
        }else if(color[r] == color[c]){
          return false;
        }
      }
      r++;
    }
    c++;
    r = 0;
  }
  //cout<<"r: "<<r<<"c: "<<c<<endl;
  return true;
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

vector<string> get_data(ifstream& f){
  string names;
  vector<string> v;
  if (f.is_open()) {
    while(getline(f, names,'\n')){
      names.erase(names.length()-1);
      v.push_back(names);
    }
    f.close();
  }else{
    std::cerr << "Failure to open file" << '\n';
    exit(0);
  }
  return v;
}

struct result graph(vector<string> v){
  result res;
  map<string, int> m;
  Bimap b;
  int n = stoi(v[0]);
  int r = stoi(v[n+1]);
  vector<vector<int>> adj(n+1, vector<int>(n+1));
  vector<string> rivals;
  for(int i=1; i<= n; i++){
    pair<string, int> p;
    p.first = v[i];
    p.second = i;
    m.insert(pair<string, int>(v[i], i));
    b.add_pair(p);

  }

  for(int i=n+2; i<=n+r+1; i++){
     rivals = split(v[i], " ");
     map<string, int>::iterator it0 = m.find(rivals[0]);
     map<string, int>::iterator it1 = m.find(rivals[1]);
     int fst = b.find_int(rivals[0]);
     int scd = b.find_int(rivals[1]);

     edge(adj, fst, scd);
  }

  res.adj = adj;
  res.b = b;
  return res;
}

void print_results(bool b, int N, vector<bool>& visited, vector<int>& color, struct result& r){
system("tput bold");

  cout<<endl;
  if (b) {
    cout <<"Wrestlers can be seperated by rivalries, such as: \n\n";
    cout<<"Heels: "<<endl;
    for(int i=1; i<=N; i++){
        if(color[i]){
          string s = r.b.find_str(i);
          cout<<s<<endl;
        }
    }
    cout<<endl;
    cout<<"Babys: "<<endl;
    for(int i=1; i<=N; i++){
        if(!color[i]){
          string s = r.b.find_str(i);
          cout<<s<<endl;
        }
    }
  }else{
    cout <<"Wrestlers cannot be seperated by rivalries."<<'\n';
  }
  cout<<endl;
  system("tput sgr0");
}

int main(int argc, char* argv[]){

  ifstream f(argv[1]);
  vector<string> v = get_data(f);
  int N(stoi(v[0]));
  vector<bool> visited(N + 1);
  vector<int> color(N + 1);

  result R = graph(v);
  bool B = isBipartite(R, visited, color);
  print_results(B, N, visited, color, R);

  return 0;
}
