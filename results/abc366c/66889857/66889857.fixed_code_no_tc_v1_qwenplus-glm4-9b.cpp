#include <bits/stdc++.h>
using namespace std;

int main() {
  int Q; cin >> Q;
  set<int> a;
  
  while (Q--) {
    int x; cin >> x;
    if (x == 1) {
      int y; cin >> y;
      a.insert(y);
    } else if (x == 2) {
      int y; cin >> y;
      a.erase(y);
    } else if (x == 3) {
      cout << a.size() << endl;
    }
  }
  
  return 0;
}