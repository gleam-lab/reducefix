#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0L;
    long double curX = 0.0L, curY = 0.0L;

    for (int i = 0; i < N; ++i) {
        long double x, y;
        cin >> x >> y;

        long double dx = curX - x;
        long double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);

        curX = x;
        curY = y;
    }

    // Return to origin
    total += sqrt(curX * curX + curY * curY);

    // Print with sufficient precision
    cout.precision(15);
    cout << fixed << total << '\n';

    return 0;
}