#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<long long> xs(n), ys(n);
    for (long long i = 0; i < n; ++i) {
        cin >> xs[i] >> ys[i];
    }

    long double total_cost = 0.0;

    // Calculate the cost from the origin to the first point
    total_cost += sqrtl(powl(xs[0], 2.0) + powl(ys[0], 2.0));

    // Calculate the cost between consecutive points
    for (long long i = 0; i < n - 1; ++i) {
        total_cost += sqrtl(powl(xs[i+1] - xs[i], 2.0) + powl(ys[i+1] - ys[i], 2.0));
    }

    // Calculate the cost from the last point back to the origin
    total_cost += sqrtl(powl(xs[n-1], 2.0) + powl(ys[n-1], 2.0));

    cout << total_cost << endl;

    return 0;
}