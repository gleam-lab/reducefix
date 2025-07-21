#include <iostream>
#include <vector>
#include <queue>

int main() {
    int N;
    std::cin >> N;
    std::vector<int> H(N);
    for(int i = 0; i < N; i++) {
        std::cin >> H[i];
    }

    long long T = 0;
    std::priority_queue<std::pair<int, int>> pq;
    for(int i = 0; i < N; i++) {
        if(H[i] > 0) {
            pq.push({-H[i], i});
        }
    }

    while(!pq.empty()) {
        auto [health, idx] = pq.top();
        pq.pop();

        health *= -1;
        if(health == 1) {
            T++;
        } else if(health % 2 == 0) {
            T += 2;
            pq.push({-(health/2), idx});
        } else {
            T += 3;
            pq.push({-(health/2), idx});
            pq.push({-(health%2), idx});
        }
    }

    std::cout << T << std::endl;

    return 0;
}