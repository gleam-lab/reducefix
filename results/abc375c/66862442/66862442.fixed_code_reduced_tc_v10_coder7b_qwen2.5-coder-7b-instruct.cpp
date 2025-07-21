#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;
    double total = 0.0;          // Change to double for floating-point arithmetic

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Calculate Euclidean distance using sqrt

        curX = x; curY = y;
    }
    total += sqrt(curX * curX + curY * curY);  // Distance back to origin

    printf("%.15f\n", total);  // Print with high precision
}