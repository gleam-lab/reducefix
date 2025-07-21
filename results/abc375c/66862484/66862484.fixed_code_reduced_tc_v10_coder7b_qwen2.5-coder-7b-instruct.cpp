#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0, curY = 0;   // 現在位置（原点）
    double total = 0;             // 総コスト (double型で浮動小数点を使用)

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // √を計算するように修正

        curX = x; curY = y;
    }

    // 最後の点から原点へ戻る
    total += sqrt(curX * curX + curY * curY);

    /* --- 出力 ---
       浮動小数点に変換して出力すれば誤差 10^-6 以下になる。 */
    printf("%.15f\n", total);  // 15桁まで出力以降の精度を保証

    return 0;
}