#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    double total_distance = 0.0;
    int prev_x = 0, prev_y = 0;
    
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        total_distance += sqrt(pow(prev_x - x, 2) + pow(prev_y - y, 2));
        prev_x = x;
        prev_y = y;
    }
    
    total_distance += sqrt(pow(prev_x, 2) + pow(prev_y, 2));
    cout << fixed << setprecision(10) << total_distance << endl;
    
    return 0;
}