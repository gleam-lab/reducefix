#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;   // 現在位置（原点）
    double total = 0;             // 総コスト (double型で平方根を計算するため)

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // 平方根を取ってコストを加算

        curX = x; curY = y;
    }

    // 最後の点から原点へ戻る
    total += sqrt(curX * curX + curY * curY);

    /* --- 出力 ---
       整数のまま文字列化して出力すれば誤差 0。 */
    printf("%.10f\n", total);  // 少数点以下10桁まで表示
    return 0;
}