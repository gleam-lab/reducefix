#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0, curY = 0;
    double total = 0;

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy);

        curX = x; 
        curY = y;
    }

    // Add the distance from the last point back to the origin
    total += sqrt(curX * curX + curY * curY);

    // Print the result with precision up to 10^-6
    printf("%.10f\n", total);

    return 0;
}