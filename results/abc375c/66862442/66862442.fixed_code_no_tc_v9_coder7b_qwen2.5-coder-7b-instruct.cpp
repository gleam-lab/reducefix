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
        double x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);

        curX = x; curY = y;
    }
    total += sqrt(curX * curX + curY * curY); // 原点へ戻る

    printf("%.6f\n", total); // 使用printf输出，保留6位小数

}