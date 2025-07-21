#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  multiset<int> ms;
  unordered_map<int, int> countMap;

  while (n--) {
    int type; cin >> type;
    if (type == 1) {
      int x; cin >> x;
      if (countMap[x] == 0) {
        ms.insert(x);
      }
      ++countMap[x];
    } else if (type == 2) {
      int x; cin >> x;
      --countMap[x];
      if (countMap[x] == 0) {
        ms.erase(ms.find(x));
      }
    } else if (type == 3) {
      cout << ms.size() << '\n';
    }
  }

  return 0;
}