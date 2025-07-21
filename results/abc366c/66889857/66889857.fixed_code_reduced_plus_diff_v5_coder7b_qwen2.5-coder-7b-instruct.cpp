#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  set<int> a;
  
  while(n--) {
    int q; cin >> q;
    if(q == 1) {
      int x; cin >> x;
      a.insert(x);
    } 
    else if(q == 2) {
      int x; cin >> x;
      a.erase(a.find(x));
    } 
    else {
      cout << a.size() << '\n';
    }
  }

  return 0;
}