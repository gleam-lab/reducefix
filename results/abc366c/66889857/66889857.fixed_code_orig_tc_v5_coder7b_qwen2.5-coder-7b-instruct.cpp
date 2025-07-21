#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> cnt;
  
  while(n--) {
    int t; cin >> t;
    if(t == 1) {
      int x; cin >> x;
      cnt[x]++;
    } else if(t == 2) {
      int x; cin >> x;
      if(cnt[x] > 0) cnt[x]--;
    } else {
      cout << cnt.size() << '\n';
    }
  }

  return 0;
}