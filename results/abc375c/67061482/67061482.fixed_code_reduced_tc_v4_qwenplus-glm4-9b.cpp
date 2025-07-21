#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int N;
    cin >> N;
    if (N == 0) {
        cout << fixed << setprecision(10) << 0 << endl;
        return 0;
    }

    double x[2 * N + 2], y[2 * N + 2], total_cost = 0.0;
    x[0] = y[0] = 0.0; // Starting point is at the origin
    for (int i = 1; i <= N; ++i) {
        cin >> x[i] >> y[i];
    }
    x[N + 1] = 0.0; // End point is at the origin
    y[N + 1] = 0.0;

    for (int i = 0; i <= N + 1; i++) {
        total_cost += sqrt((x[i] - x[i + 1]) * (x[i] - x[i + 1]) + (y[i] - y[i + 1]) * (y[i] - y[i + 1]));
    }

    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}