#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int main() {
    int N;
    cin >> N;
    
    ll x = 0, y = 0;
    ld total_cost = 0.0;
    
    for (int i = 0; i < N; ++i) {
        ll xi, yi;
        cin >> xi >> yi;
        total_cost += sqrt(pow(xi - x, 2) + pow(yi - y, 2));
        x = xi;
        y = yi;
    }
    
    total_cost += sqrt(pow(x, 2) + pow(y, 2)); // Return to origin
    cout << fixed << setprecision(12) << total_cost << endl;
    return 0;
}