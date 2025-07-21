#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int Q; cin >> Q;
  set<int> balls;

  while(Q--) {
    int op; cin >> op;
    if(op == 1) {
      int x; cin >> x;
      balls.insert(x);
    } else if(op == 2) {
      int x; cin >> x;
      balls.erase(balls.find(x));
    } else if(op == 3) {
      cout << balls.size() << '\n';
    }
  }

  return 0;
}