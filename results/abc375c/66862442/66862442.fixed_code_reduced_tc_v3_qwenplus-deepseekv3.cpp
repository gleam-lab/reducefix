#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0;
    long long curX = 0, curY = 0;

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long long dx = curX - x;
        long long dy = curY - y;
        total += sqrtl((long double)dx * dx + (long double)dy * dy);

        curX = x;
        curY = y;
    }
    total += sqrtl((long double)curX * curX + (long double)curY * curY);

    cout << fixed << setprecision(20) << total << '\n';
}