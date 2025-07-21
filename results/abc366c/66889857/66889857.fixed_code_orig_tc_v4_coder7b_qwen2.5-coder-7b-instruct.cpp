#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n; cin >> n;
  map<int, int> mp;
  
  while(n--) {
    int t, x; cin >> t >> x;
    if(t == 1) mp[x]++;
    else if(t == 2) mp.erase(x);
    else cout << mp.size() << '\n';
  }

  return 0;
}