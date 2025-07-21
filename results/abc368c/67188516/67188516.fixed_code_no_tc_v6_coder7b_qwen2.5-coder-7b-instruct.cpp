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
    ans += ((H + 2) / 3); // This calculates the number of turns needed to reduce the health to 0 or less
  }
  
  cout << ans << endl;
}