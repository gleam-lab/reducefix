#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> cnt;

  while(n--) {
    int q; cin >> q;
    if(q == 1) {
      int x; cin >> x;
      cnt[x]++;
    } else if(q == 2) {
      int x; cin >> x;
      cnt[x]--;
      if(cnt[x] == 0) cnt.erase(x);
    } else {
      cout << cnt.size() << '\n';
    }
  }

  return 0;
}