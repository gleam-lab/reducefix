#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

double Euclid(double x1, double x2, double y1, double y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

int main() {
    int n; cin >> n;
    double ans = 0;
    
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    
    // Add distance from origin to first point
    ans += Euclid(0, x[0], 0, y[0]);
    
    // Add distances between consecutive points
    rep(i,n-1) {
        ans += Euclid(x[i], x[i+1], y[i], y[i+1]);
    }
    
    // Add distance from last point back to origin
    ans += Euclid(x[n-1], 0, y[n-1], 0);
    
    cout << fixed << setprecision(12) << ans << endl;
}