#include <bits/stdc++.h>
using namespace std;

int main() {
  int Q;
  cin >> Q;

  multiset<int> bag;
  
  for (int i = 0; i < Q; ++i) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;
      bag.insert(x);
    } 
    else if (type == 2) {
      int x;
      cin >> x;
      // Remove one occurrence of x
      auto it = bag.find(x);
      if (it != bag.end()) {
        bag.erase(it);
      }
    } 
    else if (type == 3) {
      // Print number of distinct integers
      cout << bag.size() << endl;
    }
  }

  return 0;
}