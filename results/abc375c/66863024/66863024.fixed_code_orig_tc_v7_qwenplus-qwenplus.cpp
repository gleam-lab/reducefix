#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0;
    long double prevX = 0.0, prevY = 0.0;

    for (int i = 0; i < N; ++i) {
        long double x, y;
        cin >> x >> y;
        long double dx = x - prevX;
        long double dy = y - prevY;
        total += sqrtl(dx * dx + dy * dy);
        prevX = x;
        prevY = y;
    }

    // Return to origin
    total += sqrtl(prevX * prevX + prevY * prevY);

    // Print with sufficient precision
    cout.precision(15);
    cout << fixed << total << '\n';

    return 0;
}