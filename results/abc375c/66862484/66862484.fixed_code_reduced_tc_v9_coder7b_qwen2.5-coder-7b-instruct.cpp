#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0, curY = 0;   // 現在位置（原点）
    double total = 0;             // 総コスト (double型を使用)

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // 正しい距離を計算

        curX = x; curY = y;
    }

    // 最後の点から原点へ戻る
    total += sqrt(curX * curX + curY * curY);

    /* --- 出力 ---
       double値を文字列化して出力すれば誤差 1e-6 以下。 */
    cout << fixed << setprecision(15) << total << '\n';

    return 0;
}