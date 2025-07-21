#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  set<int> a;
  
  for(int i=0; i<n; ++i){
    int x; cin >> x;
    if(x == 1){
      int y; cin >> y;
      a.insert(y);
    }
    
    else if(x == 2){
      int y; cin >> y;
      a.erase(a.find(y));
    }
    
    else if(x == 3){
      cout << a.size() << endl;
    }
  }
  return 0;
}