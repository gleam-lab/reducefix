#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    long long px = 0, py = 0;
    double ans = 0;
    long long x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        ans += sqrt((long double)(x * x + y * y));
        px = x;
        py = y;
    }

    ans += sqrt((long double)(px * px + py * py));
    printf("%.10Lf\n", ans);
    return 0;
}