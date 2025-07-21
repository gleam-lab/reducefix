#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0, curY = 0;
    double total = 0;          // Change to double for floating-point calculations

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Calculate Euclidean distance correctly

        curX = x; curY = y;
    }
    total += sqrt(curX * curX + curY * curY);  // Correctly calculate distance back to origin

    printf("%.10f\n", total);  // Print with high precision
}