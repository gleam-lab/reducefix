#include <iostream>
#include <set>
using namespace std;

int main() {
  int q; cin >> q;
  set<int> a;
  
  for (int i = 0; i < q; i++) {
    int type; cin >> type;
    if (type == 1) {
      int x; cin >> x;
      a.insert(x);
    } else if (type == 2) {
      int x; cin >> x;
      a.erase(x);
    } else if (type == 3) {
      cout << a.size() << endl;
    }
  }
  
  return 0;
}