#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;
  char past = S[0];  // Initialize past with the first character of S.
  int ans = 0;
  for (int i = 1; i < N; ++i) {  // Start iteration from the second character.
    if (S[i] != past) {  // Check if the current character is different from the past.
      ans++;  // Increment the count for each new sequence.
      past = S[i];  // Update past to the current character.
    }
  }
  cout << ans;
  return 0;
}