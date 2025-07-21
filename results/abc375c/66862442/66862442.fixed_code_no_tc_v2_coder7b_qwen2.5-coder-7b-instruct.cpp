#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    long double curX = 0, curY = 0;
    long double total = 0;          // Use long double for precision

    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;

        long double dx = curX - x;
        long double dy = curY - y;
        total += sqrtl(dx * dx + dy * dy); // Calculate distance using sqrtl

        curX = x; curY = y;
    }
    total += sqrtl(curX * curX + curY * curY); // Return to origin

    // Print result directly without converting to string
    printf("%.10Lf\n", total);
}