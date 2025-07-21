#include <bits/stdc++.h>
#include <cmath> // For hypot

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    double total_cost = 0.0;
    long long prev_x = 0, prev_y = 0;
    long long curr_x, curr_y;

    for (int i = 0; i < N; ++i) {
        cin >> curr_x >> curr_y;
        long long dx = curr_x - prev_x;
        long long dy = curr_y - prev_y;
        total_cost += hypot(dx, dy); // sqrt(dx^2 + dy^2)
        prev_x = curr_x;
        prev_y = curr_y;
    }

    // Return to origin
    long long dx = 0 - prev_x;
    long long dy = 0 - prev_y;
    total_cost += hypot(dx, dy);

    // Print result with enough precision
    cout.precision(15);
    cout << fixed << total_cost << endl;

    return 0;
}