#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  set<int> a;
  
  while (n--) {
    int op; cin >> op;
    if (op == 1) {
      int x; cin >> x;
      a.insert(x);
    } else if (op == 2) {
      int x; cin >> x;
      a.erase(a.find(x));
    } else if (op == 3) {
      cout << a.size() << endl;
    }
  }

  return 0;
}