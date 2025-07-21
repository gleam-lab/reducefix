#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    long double total = 0.0;
    long double prevX = 0.0, prevY = 0.0;
    long double currentX, currentY;

    for (int i = 0; i < N; ++i) {
        cin >> currentX >> currentY;

        long double dx = currentX - prevX;
        long double dy = currentY - prevY;

        total += sqrtl(dx * dx + dy * dy);

        prevX = currentX;
        prevY = currentY;
    }

    // Return to origin
    long double dx = 0.0 - prevX;
    long double dy = 0.0 - prevY;
    total += sqrtl(dx * dx + dy * dy);

    cout.precision(15);
    cout << fixed << total << endl;

    return 0;
}