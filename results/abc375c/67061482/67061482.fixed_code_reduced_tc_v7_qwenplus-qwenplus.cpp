#include <bits/stdc++.h>
using namespace std;

int main() {
    double a = 0.0, b = 0.0;
    int N;
    cin >> N;
    double total_cost = 0.0;
    double c, d;

    for (int i = 0; i < N; ++i) {
        cin >> c >> d;
        double dx = a - c;
        double dy = b - d;
        total_cost += sqrt(dx * dx + dy * dy);
        a = c;
        b = d;
    }

    // Return to origin
    total_cost += sqrt(a * a + b * b);

    // Ensure sufficient precision in output
    cout.precision(15);
    cout << fixed << total_cost << endl;

    return 0;
}