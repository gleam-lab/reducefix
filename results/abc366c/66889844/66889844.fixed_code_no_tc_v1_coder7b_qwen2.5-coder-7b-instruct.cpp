#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int q; cin >> q;
  set<int> a;

  while(q--) {
    int op; cin >> op;
    if(op == 1) {
      int x; cin >> x;
      a.insert(x);
    } else if(op == 2) {
      int x; cin >> x;
      a.erase(a.find(x));
    } else if(op == 3) {
      cout << a.size() << '\n';
    }
  }

  return 0;
}