#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0, curY = 0;
    double total = 0; 

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);

        curX = x; curY = y;
    }
    total += sqrt(curX * curX + curY * curY); // 原点へ戻る

    cout << fixed << setprecision(15) << total << '\n'; // 設定精度を指定
}