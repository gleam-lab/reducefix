#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_set<int> s;

  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;
      s.insert(x); // Insert directly without checking count
    } else if (type == 2) {
      int x;
      cin >> x;
      s.erase(s.find(x)); // Remove using find to ensure correct element is removed
    } else if (type == 3) {
      cout << s.size() << endl; // Number of unique elements in set
    }
  }

  return 0;
}