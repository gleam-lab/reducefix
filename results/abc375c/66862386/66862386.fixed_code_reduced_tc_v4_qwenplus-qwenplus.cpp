#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0;
    int prevX = 0, prevY = 0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        long double dx = static_cast<long double>(x - prevX);
        long double dy = static_cast<long double>(y - prevY);
        total += sqrt(dx * dx + dy * dy);
        prevX = x;
        prevY = y;
    }

    // Return to origin
    long double dx = static_cast<long double>(0 - prevX);
    long double dy = static_cast<long double>(0 - prevY);
    total += sqrt(dx * dx + dy * dy);

    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}