#include <bits/stdc++.h>
using namespace std;

double calculate_distance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n; cin >> n;
    vector<int> x(n + 1), y(n + 1);

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    // Add the origin (0, 0) to the end of the list
    x.push_back(0);
    y.push_back(0);

    double total_cost = 0.0;
    for (int i = 0; i < n; i++) {
        total_cost += calculate_distance(x[i], y[i], x[i+1], y[i+1]);
    }

    cout << fixed << setprecision(12) << total_cost << endl;

    return 0;
}