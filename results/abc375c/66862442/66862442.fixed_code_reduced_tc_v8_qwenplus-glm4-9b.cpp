#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;
    double total = 0; // Use double for higher precision

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        double dx = static_cast<double>(curX - x);
        double dy = static_cast<double>(curY - y);
        total += dx * dx + dy * dy;

        curX = x; curY = y;
    }
    total += curX * curX + curY * curY; // Add the distance back to the origin

    // Calculate the square root of the total sum
    double distance = sqrt(total);
    
    // Print the result with the required precision
    cout.precision(20);
    cout << fixed << distance << '\n';
}