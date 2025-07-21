#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    double x = 0, y = 0, t = 0;
    cin >> n;
    while (n--) {
        double a, b;
        cin >> a >> b;
        t += sqrt((x - a) * (x - a) + (y - b) * (y - b));
        x = a;
        y = b;
    }
    t += sqrt(x * x + y * y);
    cout << setprecision(20) << t << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout << endl;
    return 0;
}