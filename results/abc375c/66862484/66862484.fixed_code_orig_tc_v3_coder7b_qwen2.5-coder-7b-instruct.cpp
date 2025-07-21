#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double curX = 0, curY = 0;   // 現在位置（原点）
    long double total = 0;             // 総コスト (128bit)

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long double dx = curX - x;
        long double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // 正しく平方根を取る

        curX = x; curY = y;
    }

    // 最後の点から原点へ戻る
    total += sqrt(curX * curX + curY * curY);

    // 結果を出力
    printf("%.15Lf\n", total);  // 浮動小数点で出力

    return 0;
}