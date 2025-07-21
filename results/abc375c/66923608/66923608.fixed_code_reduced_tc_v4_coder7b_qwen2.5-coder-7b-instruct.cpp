#include <bits/stdc++.h>
using namespace std;

// Function to calculate Euclidean distance between two points
double Euclid(int x1, int x2, int y1, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n;
    cin >> n;
    double ans = 0;
    
    // Vectors to store the coordinates of the points
    vector<int> x(n + 1), y(n + 1);
    
    // Read the coordinates of the points
    for (int i = 1; i <= n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    // Calculate the total cost of visiting all points in order and returning to the origin
    for (int i = 1; i <= n; ++i) {
        ans += Euclid(x[i - 1], x[i], y[i - 1], y[i]);
    }
    
    // Print the result with high precision
    cout << fixed << setprecision(12) << ans << endl;
    
    return 0;
}