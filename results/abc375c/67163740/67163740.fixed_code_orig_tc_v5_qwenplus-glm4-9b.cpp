#include <iostream>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    ll x = 0, y = 0;
    double total_cost = 0;

    while (n--) {
        int a, b;
        cin >> a >> b;
        total_cost += sqrt((x - a) * (x - a) + (y - b) * (y - b));
        x = a;
        y = b;
    }

    // After the loop, subtract the distance from the last point to the origin
    total_cost -= sqrt(x * x + y * y);

    cout << total_cost << endl;

    return 0;
}