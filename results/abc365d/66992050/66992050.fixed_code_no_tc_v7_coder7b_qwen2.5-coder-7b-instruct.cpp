#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  string S;
  cin >> N >> S;
  
  // Initialize the previous character as something that will always be different from any valid move ('X' is used here)
  char past = 'X';
  int ans = 0;
  
  for(char c : S) {
    if(past == 'X') { // Initial case when no moves have been made yet
      past = c; // Set the first move as the initial past character
      continue; // Skip the rest of the loop for the first iteration
    }
    
    if((c == 'P' && past != 'S') || (c == 'R' && past != 'P') || (c == 'S' && past != 'R')) {
      ans++; // Increment answer if the current move can defeat the past one
      past = c; // Update the past character to the current one
    } else {
      past = c; // If not, just update the past character to the current one without incrementing the answer
    }
  }
  
  cout << ans;
  return 0;
}