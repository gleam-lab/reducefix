#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double calculateDistance(long long x1, long long y1, long long x2, long long y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    int n;
    cin >> n;
    
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    
    double totalCost = 0.0;
    
    // Calculate the total cost of moving from one point to another
    for (int i = 0; i < n; ++i) {
        totalCost += calculateDistance(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
    
    cout << fixed << setprecision(12) << totalCost << endl;
    
    return 0;
}