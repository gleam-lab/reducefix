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
    } else if(x == 2){
      int y; cin >> y;
      if(a[y] > 0) a[y]--;
    } else if(x == 3){
      int count = 0;
      for(auto &p : a) if(p.second > 0) count++;
      cout << count << endl;
    }
  }

  return 0;
}