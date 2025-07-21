#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int Q; cin >> Q;
  map<int, int> countMap;
  int uniqueCount = 0;
  
  while(Q--) {
    int type; cin >> type;
    if(type == 1) {
      int x; cin >> x;
      if(countMap[x] == 0) uniqueCount++;
      countMap[x]++;
    } else if(type == 2) {
      int x; cin >> x;
      if(--countMap[x] == 0) uniqueCount--;
    } else if(type == 3) {
      cout << uniqueCount << '\n';
    }
  }
  
  return 0;
}