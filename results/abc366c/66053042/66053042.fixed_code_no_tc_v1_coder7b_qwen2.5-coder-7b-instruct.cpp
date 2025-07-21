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
      s.insert(x); // Inserting directly without checking as set automatically handles duplicates
    } else if (type == 2) {
      int x;
      cin >> x;
      s.erase(x); // Erasing directly without checking as set will handle if element does not exist
    } else if (type == 3) {
      cout << s.size() << endl; // Size of the set gives the number of unique elements
    }
  }
}