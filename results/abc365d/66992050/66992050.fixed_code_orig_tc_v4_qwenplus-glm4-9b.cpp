#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int N;
  string S;
  cin >> N >> S;
  char past = 'N';  // 'N' is a placeholder for 'Not Used'
  int ans = 0;
  for(char c:S){
    // If the past character is 'N' or does not create a valid transition, initialize past
    // Otherwise, increment ans, count it as a valid transition, and update past
    if (past == 'N' || c != past) {
      ans++;
      past = c;
    } else {
      // If the current character is the same as the past character, continue without incrementing
      past = c;
    }
  }
  cout << ans;
  return 0;
}