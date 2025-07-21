#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    vector<long long> x(n), y(n);
    for (long long i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    double total_cost = 0.0;
    for (long long i = 0; i < n - 1; ++i) {
        total_cost += sqrt(pow(x[i+1] - x[i], 2) + pow(y[i+1] - y[i], 2));
    }
    total_cost += sqrt(pow(x[0] - x[n-1], 2) + pow(y[0] - y[n-1], 2));

    printf("%.10f\n", total_cost);

    return 0;
}