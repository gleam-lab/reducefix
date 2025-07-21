#include <iostream>
#include <cmath>
#include <iomanip>

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
        total += std::sqrt(dx * dx + dy * dy);

        curX = x; curY = y;
    }
    total += std::sqrt(curX * curX + curY * curY); // 原点へ戻る

    // 計算結果を指定の精度で出力
    std::cout << std::fixed << std::setprecision(6) << total << '\n';

    return 0;
}