#include <bits/stdc++.h>
using namespace std;

int main() {
  int q; cin >> q;
  map<int, int> count;
  
  while(q--) {
    int op; cin >> op;
    if(op == 1) {
      int x; cin >> x;
      count[x]++;
    } 
    else if(op == 2) {
      int x; cin >> x;
      count[x]--;
      if(count[x] == 0)
        count.erase(x);
    } 
    else if(op == 3) {
      cout << count.size() << endl;
    }
  }

  return 0;
}