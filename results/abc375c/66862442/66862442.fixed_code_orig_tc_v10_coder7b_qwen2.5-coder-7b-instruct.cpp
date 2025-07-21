#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    double curX = 0, curY = 0;
    double total = 0;

    for (int i = 0; i < N; ++i) {
        long long x, y;
        std::cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);

        curX = x; 
        curY = y;
    }
    total += sqrt(curX * curX + curY * curY); // 原点へ戻る

    std::cout << std::fixed << std::setprecision(15) << total << '\n';

    return 0;
}