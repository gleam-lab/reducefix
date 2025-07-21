#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double Euclid(int x1, int x2, int y1, int y2) {
    double A = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return A;
}

int main() {
    int n; cin >> n;
    double ans = 0; 

    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        // Calculate distance from last visited point to current point
        if(i > 0) {
            ans += Euclid(x[i-1], x[i], y[i-1], y[i]);
        }
    }
    
    // Add the distance from the last point back to the origin
    ans += Euclid(x[n-1], x[0], y[n-1], y[0]);

    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}