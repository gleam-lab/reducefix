#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int q; cin >> q;
  map<int, int> mp;

  while(q--) {
    int type; cin >> type;
    if(type == 1) {
      int x; cin >> x;
      mp[x]++;
    } else if(type == 2) {
      int x; cin >> x;
      mp[x]--;
      if(mp[x] == 0) mp.erase(x);
    } else if(type == 3) {
      cout << mp.size() << endl;
    }
  }

  return 0;
}