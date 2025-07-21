#include <bits/stdc++.h>
using namespace std;

int main() {
  int Q;
  cin >> Q;

  map<int, int> count_map;  // To count occurrences of each number
  int distinct_count = 0;   // To keep track of number of distinct integers

  while (Q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      cin >> x;
      if (count_map[x] == 0) {
        distinct_count++;
      }
      count_map[x]++;
    } 
    else if (type == 2) {
      int x;
      cin >> x;
      count_map[x]--;
      if (count_map[x] == 0) {
        distinct_count--;
      }
    } 
    else if (type == 3) {
      cout << distinct_count << endl;
    }
  }

  return 0;
}