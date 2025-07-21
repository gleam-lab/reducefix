#include <iostream>
#include <set>
using namespace std;

int main() {
  int Q;
  cin >> Q;

  set<int> a;  // Use set to store unique integers

  while (Q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;
      a.insert(x);  // Add x to the set
    } else if (type == 2) {
      int x;
      cin >> x;
      a.erase(x);  // Remove x from the set
    } else if (type == 3) {
      cout << a.size() << endl;  // Output the size of the set
    }
  }

  return 0;
}