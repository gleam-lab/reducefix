#include <bits/stdc++.h>
using namespace std;
#include <cmath> // Include cmath for sqrt()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;
    double total = 0.0; // Use double for higher precision

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);

        curX = x; curY = y;
    }
    total += sqrt(curX * curX + curY * curY); // Add the distance back to the origin

    cout.precision(20); // Set precision for cout to 20 decimal places
    cout << fixed << total << '\n'; // Print the total cost
}