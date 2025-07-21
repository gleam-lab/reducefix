#include <iostream>
#include <string>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;
  char past = 'N';
  int ans = 0;

  // Start from the first character
  if (S[0] != 'N') past = S[0];

  for (char c : S) {
    if (past != 'N' && c != past) {
      switch (past) {
        case 'P': 
          if (c == 'S') ans++;
          break;
        case 'R':
          if (c == 'P') ans++;
          break;
        case 'S':
          if (c == 'R') ans++;
          break;
      }
      past = c;
    } else if (c != 'N') {
      past = c;
    }
  }

  cout << ans;
  return 0;
}