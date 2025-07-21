#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
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
      if(a.find(y) != a.end()){
        a[y]--;
        if(a[y] == 0){
          a.erase(y);
        }
      }
    }
    
    else if(x == 3){
      cout << a.size() << endl;
    }
  }
}