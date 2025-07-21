#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    double total_cost = 0.0;
    int prev_x = 0, prev_y = 0;

    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        int dx = x - prev_x;
        int dy = y - prev_y;
        total_cost += sqrt(static_cast<double>(dx * dx + dy * dy));
        prev_x = x;
        prev_y = y;
    }

    // Return to origin
    int dx = 0 - prev_x;
    int dy = 0 - prev_y;
    total_cost += sqrt(static_cast<double>(dx * dx + dy * dy));

    cout << fixed << setprecision(10) << total_cost << endl;

    return 0;
}