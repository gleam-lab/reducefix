#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  cin >> N;
  
  long long ans = 0;
  
  for(int i = 0; i < N; i++) {
    long long H;
    cin >> H;
    
    while(H > 0) {
      ans++;
      if(ans % 3 == 0) {
        H -= 3;
      } else {
        H -= 1;
      }
    }
  }
  
  cout << ans << endl;
  
  return 0;
}