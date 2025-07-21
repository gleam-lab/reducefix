#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

long double EuclideanDistance(long long x1, long long x2, long long y1, long long y2) {
    long double A = sqrtl((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return A;
}

int main() {
    int n; cin >> n;
    long double ans = 0; 

    vector<long long> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    x.push_back(x[0]);
    y.push_back(y[0]);

    rep(i, n) {
        ans += EuclideanDistance(x[i], x[i + 1], y[i], y[i + 1]);
    }

    cout << fixed << setprecision(12) << ans << endl;
}