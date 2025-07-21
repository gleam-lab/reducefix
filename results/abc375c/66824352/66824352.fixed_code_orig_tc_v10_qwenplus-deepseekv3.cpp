#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    long double total_distance = 0.0;
    long long prev_x = 0, prev_y = 0;
    
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        long long dx = x - prev_x;
        long long dy = y - prev_y;
        total_distance += sqrtl(dx * dx + dy * dy);
        prev_x = x;
        prev_y = y;
    }
    
    // Return to origin
    total_distance += sqrtl(prev_x * prev_x + prev_y * prev_y);
    
    cout << fixed << setprecision(10) << total_distance << endl;
    
    return 0;
}