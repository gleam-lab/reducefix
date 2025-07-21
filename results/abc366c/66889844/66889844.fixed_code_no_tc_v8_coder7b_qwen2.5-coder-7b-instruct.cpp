#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int q; cin >> q;
  map<int, int> countMap;
  int uniqueCount = 0;

  while(q--) {
    int type; cin >> type;
    if(type == 1) {
      int value; cin >> value;
      if(countMap[value] == 0) uniqueCount++;
      countMap[value]++;
    } else if(type == 2) {
      int value; cin >> value;
      if(--countMap[value] == 0) uniqueCount--;
    } else if(type == 3) {
      cout << uniqueCount << '\n';
    }
  }

  return 0;
}