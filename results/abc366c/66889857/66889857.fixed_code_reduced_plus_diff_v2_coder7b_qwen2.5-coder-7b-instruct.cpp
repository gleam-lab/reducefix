#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n; cin >> n;
  map<int, int> mp;

  while(n--) {
    int t; cin >> t;
    if(t == 1) {
      int x; cin >> x;
      mp[x]++;
    } 
    else if(t == 2) {
      int x; cin >> x;
      mp[x]--;
      if(mp[x] == 0) mp.erase(x);
    } 
    else if(t == 3) {
      cout << mp.size() << '\n';
    }
  }

  return 0;
}