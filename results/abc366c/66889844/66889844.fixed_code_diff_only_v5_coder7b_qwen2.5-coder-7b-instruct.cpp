#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int Q; cin >> Q;
  set<int> a;

  while(Q--) {
    int t; cin >> t;
    if(t == 1) {
      int x; cin >> x;
      a.insert(x);
    } else if(t == 2) {
      int x; cin >> x;
      a.erase(a.find(x));
    } else if(t == 3) {
      cout << a.size() << '\n';
    }
  }

  return 0;
}