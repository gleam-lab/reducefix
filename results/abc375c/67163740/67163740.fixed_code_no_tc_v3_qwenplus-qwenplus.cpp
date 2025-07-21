#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    double x = 0, y = 0, total = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        double a, b;
        cin >> a >> b;
        total += hypot(x - a, y - b); // calculates sqrt((x-a)^2 + (y-b)^2)
        x = a;
        y = b;
    }
    total += hypot(x, y); // return to origin
    cout << fixed << setprecision(20) << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}