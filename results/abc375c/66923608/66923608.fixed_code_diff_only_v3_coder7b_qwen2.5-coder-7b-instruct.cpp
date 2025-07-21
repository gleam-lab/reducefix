#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double Euclid(int x1, int x2, int y1, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
    int n; cin >> n;
    double ans = 0; 

    vector<int> x(n), y(n);
    for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];

    // Calculate the total cost of visiting all points and returning to the origin
    for(int i = 0; i < n; ++i) {
        ans += Euclid(x[i], x[(i + 1) % n], y[i], y[(i + 1) % n]);
    }

    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}