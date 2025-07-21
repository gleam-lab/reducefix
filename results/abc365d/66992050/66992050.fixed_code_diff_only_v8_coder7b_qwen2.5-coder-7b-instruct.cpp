#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int N;
  string S;
  cin >> N >> S;
  char past = 'X'; // Initialize past to a value that will never match any of the characters in S
  int ans = 0;
  for(char c : S){
    if((c == 'P' && past != 'R') || (c == 'R' && past != 'S') || (c == 'S' && past != 'P')){
      ans++;
      past = c; // Update past to the current character after incrementing ans
    }
  }
  cout << ans;
  return 0;
}