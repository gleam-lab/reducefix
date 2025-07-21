#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    double c = 0;
    cin >> n;
    pair<int, int> prev, curr;
    cin >> prev.first >> prev.second; // Start at the first point
    for (int i = 1; i <= n; ++i) {
        cin >> curr.first >> curr.second;
        c += sqrt(pow(curr.first - prev.first, 2) + pow(curr.second - prev.second, 2)); // Calculate distance to current point
        prev = curr; // Update previous point to current point
    }
    c += sqrt(pow(prev.first, 2) + pow(prev.second, 2)); // Return to the origin
    cout << setprecision(10) << c << endl;
    return 0;
}