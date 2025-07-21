#include <bits/stdc++.h>
using namespace std;

int main() {
  int Q;
  cin >> Q;
  
  unordered_map<int, int> countMap;  // Tracks count of each integer
  int distinctCount = 0;             // Tracks number of distinct integers

  while (Q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;
      if (countMap[x] == 0) {
        distinctCount++;
      }
      countMap[x]++;
    } 
    else if (type == 2) {
      int x;
      cin >> x;
      countMap[x]--;
      if (countMap[x] == 0) {
        distinctCount--;
      }
    } 
    else if (type == 3) {
      cout << distinctCount << endl;
    }
  }

  return 0;
}