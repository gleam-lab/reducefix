#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  unordered_set<int> s;

  while (n--) {
    int type, x;
    cin >> type >> x;
    if (type == 1) {
      s.insert(x);
    } else if (type == 2) {
      s.erase(s.find(x));
    } else {
      cout << s.size() << '\n';
    }
  }

  return 0;
}