#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int q; cin >> q;
  map<int, int> mp;
  
  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int x; cin >> x;
      mp[x]++;
    } else if(t == 2) {
      int x; cin >> x;
      if(mp[x] > 0) mp[x]--;
    } else if(t == 3) {
      int count = 0;
      for(auto& [num, freq] : mp) {
        if(freq > 0) count++;
      }
      cout << count << '\n';
    }
  }
  
  return 0;
}