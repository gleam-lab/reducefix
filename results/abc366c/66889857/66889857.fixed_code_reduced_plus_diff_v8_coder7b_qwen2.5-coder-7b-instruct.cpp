#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n; cin >> n;
  unordered_set<int> a;

  while(n--) {
    int type; cin >> type;
    if(type == 1) {
      int x; cin >> x;
      a.insert(x);
    } 
    else if(type == 2) {
      int x; cin >> x;
      a.erase(a.find(x));
    } 
    else if(type == 3) {
      cout << a.size() << '\n';
    }
  }

  return 0;
}