#include <iostream>
#include <vector>
#include <queue>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> h[i];
    }

    long long time = 0;
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> pq;
    for (int i = 0; i < n; ++i) {
        if (h[i] > 0) {
            pq.push({h[i], i});
        }
    }

    while (!pq.empty()) {
        auto [health, index] = pq.top();
        pq.pop();

        if (time % 3 == 0) {
            health -= 3;
        } else {
            --health;
        }

        if (health > 0) {
            pq.push({health, index});
        }

        ++time;
    }

    std::cout << time << std::endl;
    return 0;
}