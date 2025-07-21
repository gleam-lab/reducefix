#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  
  std::vector<long long> h(N);
  for(int i = 0; i < N; i++) {
    std::cin >> h[i];
  }

  long long ans = 0;
  while(true) {
    bool all_zero = true;
    for(int i = 0; i < N; i++) {
      if(h[i] > 0) {
        all_zero = false;
        if((ans + 1) % 3 == 0) {
          h[i] -= 3;
        } else {
          h[i]--;
        }
        ans++;
      }
    }
    if(all_zero) break;
  }

  std::cout << ans << std::endl;

  return 0;
}