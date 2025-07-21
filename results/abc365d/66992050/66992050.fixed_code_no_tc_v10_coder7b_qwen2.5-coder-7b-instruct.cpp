#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;
  
  // Initialize variables to track the last action and the count of changes
  char lastAction = '.';
  int changeCount = 0;

  // Iterate through each character in the string
  for (char c : S) {
    if (c == 'P') {
      if (lastAction != 'R') {
        lastAction = 'R';
        changeCount++;
      }
    } else if (c == 'R') {
      if (lastAction != 'S') {
        lastAction = 'S';
        changeCount++;
      }
    } else if (c == 'S') {
      if (lastAction != 'P') {
        lastAction = 'P';
        changeCount++;
      }
    }
  }

  // Output the total number of changes needed
  cout << changeCount << endl;
  return 0;
}