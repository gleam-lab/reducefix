#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int Q; cin >> Q;
  set<int> a;
  
  while(Q--){
    int x; cin >> x;
    if(x == 1){
      int y; cin >> y;
      a.insert(y);
    } else if(x == 2){
      int y; cin >> y;
      a.erase(a.find(y));
    } else {
      cout << a.size() << '\n';
    }
  }

  return 0;
}