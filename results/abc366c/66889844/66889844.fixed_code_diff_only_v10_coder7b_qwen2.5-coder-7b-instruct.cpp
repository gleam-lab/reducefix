#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n; cin >> n;
  map<int, int> freq;
  
  while(n--) {
    int type; cin >> type;
    if(type == 1) {
      int value; cin >> value;
      freq[value]++;
    } else if(type == 2) {
      int value; cin >> value;
      if(freq[value] > 0) {
        freq[value]--;
        if(freq[value] == 0)
          freq.erase(value);
      }
    } else if(type == 3) {
      cout << freq.size() << '\n';
    }
  }
  
  return 0;
}