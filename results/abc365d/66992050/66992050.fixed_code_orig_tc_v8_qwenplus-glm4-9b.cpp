#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int N;
  string S;
  cin >> N >> S;
  char prev = 'N';  // Initialize with 'N' to handle the first character comparison
  int ans = 0;
  for(char c : S){
    if (prev != 'N' && prev != c) { // Only consider transitions if we have a previous character and it's different from current
      ans++;
    }
    prev = c;  // Update previous character
  }
  cout << ans;
  return 0;
}