#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance squared between two points
long long dist_squared(long long x1, long long y1, long long x2, long long y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long long curX = 0, curY = 0;
    long double total = 0;          // Using long double for higher precision

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        total += sqrt(dist_squared(curX, curY, x, y));  // Add Euclidean distance to total

        curX = x; 
        curY = y;
    }
    total += sqrt(dist_squared(curX, curY, 0, 0));  // Return to origin

    // Output the result with high precision
    printf("%.15Lf\n", total);

    return 0;
}