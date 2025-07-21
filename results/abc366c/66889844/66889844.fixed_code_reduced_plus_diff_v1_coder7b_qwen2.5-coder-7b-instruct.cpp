#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  set<int> bag;
  map<int, int> freq;

  for(int i = 0; i < n; ++i) {
    int op;
    cin >> op;
    if(op == 1) {
      int x;
      cin >> x;
      if(freq[x] == 0) {
        bag.insert(x);
      }
      ++freq[x];
    } else if(op == 2) {
      int x;
      cin >> x;
      --freq[x];
      if(freq[x] == 0) {
        bag.erase(x);
      }
    } else if(op == 3) {
      cout << bag.size() << '\n';
    }
  }

  return 0;
}