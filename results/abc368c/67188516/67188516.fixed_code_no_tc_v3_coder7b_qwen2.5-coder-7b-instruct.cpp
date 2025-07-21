#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> H(N);
  for(int i = 0; i < N; ++i) {
    std::cin >> H[i];
  }

  long long T = 0;
  while(true) {
    bool all_zero = true;
    for(int i = 0; i < N; ++i) {
      if(H[i] > 0) {
        all_zero = false;
        if((T + 1) % 3 == 0) {
          H[i] -= 3;
        } else {
          H[i] -= 1;
        }
        ++T;
      }
    }
    if(all_zero) break;
  }

  std::cout << T << std::endl;
  return 0;
}