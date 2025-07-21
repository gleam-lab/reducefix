#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;
    double total = 0;  // Use double for floating-point calculations

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Calculate Euclidean distance correctly

        curX = x; curY = y;
    }
    total += sqrt(curX * curX + curY * curY);  // Distance back to origin

    printf("%.6f\n", total);  // Print result with 6 decimal places of precision
}