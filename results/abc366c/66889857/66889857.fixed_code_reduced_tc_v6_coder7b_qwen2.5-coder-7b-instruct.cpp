#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int q; cin >> q;
  map<int, int> countMap;
  int uniqueCount = 0;

  while(q--) {
    int t; cin >> t;
    if(t == 1) {
      int x; cin >> x;
      if(countMap[x] == 0) uniqueCount++;
      countMap[x]++;
    } 
    else if(t == 2) {
      int x; cin >> x;
      countMap[x]--;
      if(countMap[x] == 0) uniqueCount--;
    } 
    else if(t == 3) {
      cout << uniqueCount << '\n';
    }
  }

  return 0;
}