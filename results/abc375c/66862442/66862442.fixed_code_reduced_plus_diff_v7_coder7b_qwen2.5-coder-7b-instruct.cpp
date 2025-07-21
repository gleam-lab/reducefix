#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0, curY = 0;
    double total = 0;  // Change to double for precise calculations

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);  // Calculate Euclidean distance

        curX = x; 
        curY = y;
    }
    total += sqrt(curX * curX + curY * curY);  // Return to origin

    // Print the result with 15 decimal places
    printf("%.15f\n", total);

    return 0;
}