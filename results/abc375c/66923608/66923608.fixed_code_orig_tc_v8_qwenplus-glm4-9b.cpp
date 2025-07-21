#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

double Euclid(double x1, double x2, double y1, double y2){
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n; cin >> n;
    double ans = 0; 

    vector<double> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    // Push the origin coordinates
    x.push_back(0.0);
    y.push_back(0.0);

    rep(i, n) {
        ans += Euclid(x[i], x[i + 1], y[i], y[i + 1]);
    }
    
    // Add the return to the origin
    ans += Euclid(x[n], x[0], y[n], y[0]);

    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}