#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int q; cin >> q;
  map<int, int> a;
  
  while(q--) {
    int t, x; cin >> t >> x;
    if(t == 1) {
      a[x]++;
    } else if(t == 2) {
      if(a[x] > 0) {
        a[x]--;
      }
    } else if(t == 3) {
      cout << a.size() << '\n';
    }
  }
  
  return 0;
}