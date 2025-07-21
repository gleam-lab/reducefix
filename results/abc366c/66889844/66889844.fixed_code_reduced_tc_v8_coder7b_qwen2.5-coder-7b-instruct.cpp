#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  map<int, int> freq;
  
  rep(i, n) {
    int x; cin >> x;
    if (x == 1) {
      int y; cin >> y;
      freq[y]++;
    } else if (x == 2) {
      int y; cin >> y;
      if (freq[y] > 0) {
        freq[y]--;
        if (freq[y] == 0) {
          freq.erase(y);
        }
      }
    } else if (x == 3) {
      cout << freq.size() << endl;
    }
  }
}