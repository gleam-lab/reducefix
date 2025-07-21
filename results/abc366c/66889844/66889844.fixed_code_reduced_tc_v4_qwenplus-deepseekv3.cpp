#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int Q; cin >> Q;
  unordered_map<int, int> count;
  int distinct = 0;
  
  rep(i, Q) {
    int query_type; cin >> query_type;
    if (query_type == 1) {
      int x; cin >> x;
      if (count[x] == 0) {
        distinct++;
      }
      count[x]++;
    } else if (query_type == 2) {
      int x; cin >> x;
      count[x]--;
      if (count[x] == 0) {
        distinct--;
      }
    } else if (query_type == 3) {
      cout << distinct << endl;
    }
  }
}