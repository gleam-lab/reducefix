#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double curX = 0, curY = 0;
    double total = 0;          // Change to double for floating-point arithmetic

    for (int i = 0; i < N; ++i) {
        double x, y;
        cin >> x >> y;

        double dx = curX - x;
        double dy = curY - y;
        total += sqrt(dx * dx + dy * dy); // Calculate Euclidean distance using sqrt

        curX = x; curY = y;
    }
    total += sqrt(curX * curX + curY * curY); // Calculate distance back to origin

    cout << setprecision(10) << total << '\n'; // Set precision for output
}