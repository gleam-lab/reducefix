#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> H(N);
  for(int i = 0; i < N; i++)
    cin >> H[i];
  
  long long ans = 0;
  
  for(int i = 0; i < N; i++) {
    while(H[i] > 0) {
      ans++;
      if(ans % 3 == 0)
        H[i] -= 3;
      else
        H[i]--;
    }
  }
  
  cout << ans << '\n';
  
  return 0;
}