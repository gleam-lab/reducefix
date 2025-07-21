#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n; cin >> n;
    double ans = 0; 
  
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
  
    // Add distance from the last point back to the origin
    x.push_back(x[0]);
    y.push_back(y[0]);
  
    // Loop through all points and add up the Euclidean distance to the next point
    for (int i = 0; i < n; i++) {
        ans += sqrt(pow(x[i] - x[i + 1], 2) + pow(y[i] - y[i + 1], 2));
    }
  
    cout << fixed << setprecision(12) << ans << endl;
    return 0;
}