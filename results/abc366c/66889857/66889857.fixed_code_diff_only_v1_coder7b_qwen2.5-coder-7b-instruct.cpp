#include <bits/stdc++.h>
using namespace std;

int main() {
  int q; cin >> q;
  set<int> a;
  
  while(q--){
    int type; cin >> type;
    if(type == 1){
      int x; cin >> x;
      a.insert(x);
    }
    
    else if(type == 2){
      int x; cin >> x;
      a.erase(a.find(x));
    }
    
    else if(type == 3){
      cout << a.size() << endl;
    }
  }
}