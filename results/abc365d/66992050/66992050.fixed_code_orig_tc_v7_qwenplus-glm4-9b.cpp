#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int N;
  string S;
  cin >> N >> S;
  char past = 'N'; // Initialize to 'N' so that the first change is always counted.
  int ans = 0;
  
  for(char c : S){
    if (past != 'N' && ((c == 'P' && past != 'R') || (c == 'R' && past != 'S') || (c == 'S' && past != 'P'))){
      ans++;
    }
    past = c;
  }
  
  cout << ans;
  return 0;
}