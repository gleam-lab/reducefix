#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

ll solve() {
    int n;
    cin >> n;
    double x = 0, y = 0;
    double total_cost = 0.0;

    while (n--) {
        double a, b;
        cin >> a >> b;
        total_cost += sqrt((x - a) * (x - a) + (y - b) * (y - b));
        x = a;
        y = b;
    }

    total_cost += sqrt(x * x + y * y);
    return static_cast<ll>(total_cost * 1000000); // To ensure precision to at least 6 decimal places
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(6) << fixed; // Set precision for output
    cout << solve() << endl;
    return 0;
}