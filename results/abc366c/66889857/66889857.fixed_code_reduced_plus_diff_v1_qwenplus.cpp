#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int q; cin >> q;
  map<int, int> count;
  
  rep(i,q){
    int type; cin >> type;
    if(type == 1){
      int x; cin >> x;
      count[x]++;
    }
    
    else if(type == 2){
      int x; cin >> x;
      count[x]--;
      if(count[x] == 0){
        count.erase(x);
      }
    }
    
    else if(type == 3){
      cout << count.size() << endl;
    }
  }
}