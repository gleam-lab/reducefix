#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    double curX = 0, curY = 0;   // 現在位置（原点）
    double total = 0;             // 総コスト

    for (int i = 0; i < N; ++i) {
        long long x, y;
        std::cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += std::sqrt(dx * dx + dy * dy);  // 計算平方根以获取实际成本

        curX = x; curY = y;
    }

    // 最後の点から原点へ戻る
    total += std::sqrt(curX * curX + curY * curY);

    // 結果を小数点以下15桁で出力
    std::cout << std::fixed << std::setprecision(15) << total << '\n';

    return 0;
}