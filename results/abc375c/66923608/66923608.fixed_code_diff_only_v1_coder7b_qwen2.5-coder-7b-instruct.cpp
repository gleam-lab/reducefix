#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double Euclid(int x1, int x2, int y1, int y2) {
    double A = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    return A;
}

int main() {
    int n; 
    cin >> n;
    double ans = 0; 

    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        // Calculate distance from current point to next point and add to total distance
        if (i > 0) {
            ans += Euclid(x[i-1], x[i], y[i-1], y[i]);
        }
    }

    // Return to the origin
    ans += Euclid(x[n-1], 0, y[n-1], 0);

    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}