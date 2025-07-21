#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;   // 現在位置（原点）
    double total = 0;              // 総コスト (double型で平方根を計算できるように)

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = curX - x;
        long long dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // 平方根を取って実際の移動コストを計算

        curX = x; curY = y;
    }

    // 最後の点から原点へ戻る
    total += sqrt(curX * curX + curY * curY);

    /* --- 出力 ---
       浮動小数点数を使用しているため、直接文字列化すると誤差が出ることがある。
       因此、固定精度出力を使う。*/
    printf("%.6f\n", total);
    return 0;
}