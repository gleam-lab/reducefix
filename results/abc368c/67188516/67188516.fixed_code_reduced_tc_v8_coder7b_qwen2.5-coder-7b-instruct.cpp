#include <iostream>
#include <vector>
#include <queue>

int main() {
  int N;
  std::cin >> N;
  
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
  for(int i = 0; i < N; i++) {
    int H;
    std::cin >> H;
    pq.push(H);
  }

  int T = 0;
  while(!pq.empty()) {
    int h = pq.top();
    pq.pop();
    if(h > 0) {
      if((T + 1) % 3 == 0) h -= 3;
      else h -= 1;
      T++;
      if(h > 0) pq.push(h);
    }
  }

  std::cout << T << std::endl;

  return 0;
}