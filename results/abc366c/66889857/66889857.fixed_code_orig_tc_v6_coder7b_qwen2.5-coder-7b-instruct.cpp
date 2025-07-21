#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  set<int> a;

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
    else {
      cout << a.size() << '\n';
    }
  }

  return 0;
}