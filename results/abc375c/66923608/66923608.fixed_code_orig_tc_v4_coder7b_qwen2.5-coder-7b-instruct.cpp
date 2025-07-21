#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)

double Euclid(long long x1, long long x2, long long y1, long long y2) {
    long long dx = x1 - x2;
    long long dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n; cin >> n;
    double ans = 0; 

    vector<long long> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    
    // Add origin twice to simulate visiting it at the end
    x.push_back(0);
    y.push_back(0);

    rep(i, n) {
        ans += Euclid(x[i], x[i + 1], y[i], y[i + 1]);
    }

    cout << fixed << setprecision(12) << ans << endl;
}