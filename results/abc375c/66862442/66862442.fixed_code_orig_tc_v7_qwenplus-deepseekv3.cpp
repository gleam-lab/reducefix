#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double total = 0.0;
    double prevX = 0.0, prevY = 0.0;

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;

        double dx = prevX - x;
        double dy = prevY - y;
        total += sqrt(dx * dx + dy * dy);

        prevX = x;
        prevY = y;
    }

    // Add the distance back to the origin
    total += sqrt(prevX * prevX + prevY * prevY);

    // Output with sufficient precision
    cout << fixed << setprecision(15) << total << '\n';

    return 0;
}