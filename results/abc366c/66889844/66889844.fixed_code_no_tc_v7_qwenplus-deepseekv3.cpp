#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

int main() {
  int Q; cin >> Q;
  unordered_map<int, int> countMap;
  int distinctCount = 0;

  rep(i, Q) {
    int queryType; cin >> queryType;
    if (queryType == 1) {
      int x; cin >> x;
      if (countMap[x] == 0) {
        distinctCount++;
      }
      countMap[x]++;
    } else if (queryType == 2) {
      int x; cin >> x;
      countMap[x]--;
      if (countMap[x] == 0) {
        distinctCount--;
      }
    } else if (queryType == 3) {
      cout << distinctCount << endl;
    }
  }
}