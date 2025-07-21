#include <bits/stdc++.h>
using namespace std;

int main() {
  int q; cin >> q;
  set<int> a;
  
  while(q--){
    int x; cin >> x;
    if(x == 1){
      int y; cin >> y;
      a.insert(y);
    }
    
    else if(x == 2){
      int y; cin >> y;
      auto it = a.find(y);
      if(it != a.end()){
        a.erase(it);
      }
    }
    
    else if(x == 3){
      cout << a.size() << endl;
    }
  }
}