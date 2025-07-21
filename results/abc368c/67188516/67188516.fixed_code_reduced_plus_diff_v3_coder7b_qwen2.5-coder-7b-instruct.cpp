#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> H(N);
  for(int i = 0; i < N; ++i) {
    std::cin >> H[i];
  }

  long long ans = 0, syo, amari, pos = 0;
  for(int i = 0; i < N; ++i){
    syo = H[i] / 3;
    ans += syo * 3;
    amari = H[i] % 3;
    if (amari == 1 && (pos == 0 || pos == 1)){
      ans++;
      pos++;
    }
    else if (amari == 2 && pos == 0){
      ans += 2;
      pos += 2;
    }
    else if (amari == 2 && pos != 0){
      ans += 2;
      pos += 2;
      pos %= 3;
    }
    else if (amari == 3 && (pos == 0 || pos == 1)){
      ans += 3;
      pos += 3;
      pos %= 3;
    }
    else if (amari == 3 && pos == 2){
      ans += 1;
      pos = 0;
    }
    else if (amari == 4 && pos == 0){
      ans += 3;
      pos += 3;
      pos %= 3;
    }
    else if (amari == 4 && (pos == 1 || pos == 2)){
      ans += 2;
      pos += 2;
      pos %= 3;
    }
  }
  std::cout << ans << std::endl;

  return 0;
}