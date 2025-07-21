#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
  int N;
  string S;
  cin >> N >> S;
  char past = 'N';  // Initialize to 'N' to handle the first character properly.
  int ans = 0;
  for(char c:S){
    if(c=='P' || c=='R' || c=='S') {
      char next;
      switch(past) {
        case 'N':  // First character case
          next = c;
          break;
        case 'P':
          next = (c == 'R') ? 'S' : 'R';
          break;
        case 'R':
          next = (c == 'S') ? 'P' : 'S';
          break;
        case 'S':
          next = (c == 'P') ? 'R' : 'P';
          break;
      }
      if(past != 'N' && next != past) {  // Avoid counting the last character again.
        ans++;
      }
      past = next;
    }
  }
  cout << ans;
  return 0;
}