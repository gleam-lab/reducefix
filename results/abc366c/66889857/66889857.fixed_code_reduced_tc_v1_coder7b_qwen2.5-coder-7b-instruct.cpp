#include <bits/stdc++.h>
using namespace std;

int main() {
  int q; cin >> q;
  map<int, int> a;
  
  while(q--){
    int x; cin >> x;
    if(x == 1){
      int y; cin >> y;
      a[y]++;
    }
    
    else if(x == 2){
      int y; cin >> y;
      if(a[y] > 0){
        a[y]--;
        if(a[y] == 0) a.erase(y);
      }
    }
    
    else if(x == 3){
      cout << a.size() << endl;
    }
  }
}