#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int q;
  cin >> q;
  
  int x;
  set<int> bag;
  
  while (q--) {
    cin >> x;
    if (x == 1) {
      cin >> x; // Read the value of x again to use in the set operations
      bag.insert(x);
    } else if (x == 2) {
      cin >> x; // Read the value of x again to use in the set operations
      bag.erase(x);
    } else if (x == 3) {
      cout << bag.size() << endl;
    }
  }
  
  return 0;
}