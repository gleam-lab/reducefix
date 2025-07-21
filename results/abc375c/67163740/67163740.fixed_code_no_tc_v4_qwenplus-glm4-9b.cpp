#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    double total_cost = 0;
    double x = 0, y = 0;

    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        double previous_dist = sqrt((x - a) * (x - a) + (y - b) * (y - b));
        total_cost += previous_dist;
        x = a;
        y = b;
    }

    // Calculate the distance from the last point to the origin and add it to the total cost
    double final_dist = sqrt(x * x + y * y);
    total_cost += final_dist;

    // Print the total cost with 6 decimal places
    cout << fixed << setprecision(6) << total_cost << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}