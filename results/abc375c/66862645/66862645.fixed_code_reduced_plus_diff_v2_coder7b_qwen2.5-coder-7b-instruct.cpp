#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    long double total_cost = 0;
    for (int i = 1; i < n; ++i) {
        long long dx = x[i] - x[i - 1];
        long long dy = y[i] - y[i - 1];
        total_cost += sqrt(dx * dx + dy * dy);
    }

    // Return to the origin
    long long dx = x[0];
    long long dy = y[0];
    total_cost += sqrt(dx * dx + dy * dy);

    cout << total_cost << endl;
    
    return 0;
}