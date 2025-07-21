#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int Q; cin >> Q;
  unordered_map<int, int> count_map;
  
  rep(i, Q){
    int type; cin >> type;
    if(type == 1){
      int x; cin >> x;
      count_map[x]++;
    } else if(type == 2){
      int x; cin >> x;
      if(--count_map[x] == 0){
        count_map.erase(x);
      }
    } else if(type == 3){
      cout << count_map.size() << endl;
    }
  }
}