#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double total = 0.0;
    long double prevX = 0.0, prevY = 0.0;
    long double currX, currY;

    for (int i = 0; i < N; ++i) {
        cin >> currX >> currY;
        long double dx = currX - prevX;
        long double dy = currY - prevY;
        total += sqrtl(dx * dx + dy * dy);
        prevX = currX;
        prevY = currY;
    }

    // Return to origin
    total += sqrtl(prevX * prevX + prevY * prevY);

    // Print with sufficient precision
    cout << fixed << setprecision(15) << total << endl;

    return 0;
}