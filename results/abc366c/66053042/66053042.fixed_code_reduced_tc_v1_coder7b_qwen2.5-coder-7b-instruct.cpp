#include <bits/stdc++.h>
using namespace std;

int main() {
  map<int, int> m;
  set<int> s; // Use a set to keep track of unique elements

  int Q;
  cin >> Q;
  
  for (int i = 0; i < Q; i++) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;

      if (m.find(x) != m.end()) {
        m[x]++;
      } else {
        m.emplace(x, 1);
        s.insert(x); // Insert into the set as well
      }
    } else if (type == 2) {
      int x;
      cin >> x;

      if (m[x] > 1) {
        m[x]--;
      } else {
        m.erase(x); // Remove from the map
        s.erase(x); // Remove from the set as well
      }
    } else if (type == 3) {
      cout << s.size() << endl; // Output the size of the set
    }
  }

  return 0;
}