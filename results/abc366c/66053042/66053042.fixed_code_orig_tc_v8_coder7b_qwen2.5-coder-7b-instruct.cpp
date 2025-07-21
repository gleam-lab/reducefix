#include <bits/stdc++.h>
using namespace std;

int main() {
  unordered_set<int> s;
  
  int Q;
  cin >> Q;
  
  while (Q--) {
    int type;
    cin >> type;
    
    if (type == 1) {
      int x;
      cin >> x;
      
      if (s.find(x) == s.end()) {
        s.insert(x);
      }
    } else if (type == 2) {
      int x;
      cin >> x;
      
      s.erase(x);
    } else if (type == 3) {
      cout << s.size() << endl;
    }
  }

  return 0;
}