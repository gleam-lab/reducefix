#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int Q; cin >> Q;
  set<int> a;
  
  rep(i, Q) {
    int query; cin >> query;
    if (query == 1) {
      int x; cin >> x;
      a.insert(x);
    } else if (query == 2) {
      int x; cin >> x;
      a.erase(x);
    } else if (query == 3) {
      cout << a.size() << endl;
    }
  }
}