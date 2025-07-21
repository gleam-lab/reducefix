#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    double x = 0, y = 0, total = 0;
    cin >> n;
    while (n--) {
        double a, b;
        cin >> a >> b;
        total += hypot(x - a, y - b); // more precise and safe than manual sqrt
        x = a;
        y = b;
    }
    total += hypot(x, y); // return to origin
    cout.precision(15);
    cout << fixed << total << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}