#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

  map<int, int> countMap;
  set<int> uniqueNumbers;

  int Q;
  cin >> Q;

  while(Q--) {
    int type;
    cin >> type;

    if(type == 1) {
      int x;
      cin >> x;
      
      auto it = uniqueNumbers.find(x);
      if(it != end(uniqueNumbers)) {
        countMap[*it]++;
      } else {
        uniqueNumbers.insert(x);
        countMap[x] = 1;
      }
    } else if(type == 2) {
      int x;
      cin >> x;
      
      auto it = uniqueNumbers.find(x);
      if(it != end(uniqueNumbers)) {
        countMap[*it]--;
        if(countMap[*it] == 0) {
          uniqueNumbers.erase(*it);
        }
      }
    } else if(type == 3) {
      cout << uniqueNumbers.size() << '\n';
    }
  }

  return 0;
}