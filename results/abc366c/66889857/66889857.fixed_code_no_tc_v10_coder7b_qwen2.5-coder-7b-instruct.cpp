#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int n; cin >> n;
  map<int, int> a;
  
  rep(i,n){
    int x; cin >> x;
    if(x == 1){
      int y; cin >> y;
      a[y]++;
    }
    
    else if(x == 2){
      int y; cin >> y;
      a[y]--;
      if(a[y] == 0) a.erase(y);
    }
    
    else if(x == 3){
      cout << a.size() << endl;
    }
  }

  return 0;
}