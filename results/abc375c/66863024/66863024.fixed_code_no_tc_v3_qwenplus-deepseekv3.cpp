#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    long double current_x = 0, current_y = 0;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        long double next_x, next_y;
        cin >> next_x >> next_y;
        
        long double dx = current_x - next_x;
        long double dy = current_y - next_y;
        total_cost += sqrtl(dx * dx + dy * dy);
        
        current_x = next_x;
        current_y = next_y;
    }
    
    // Add the distance from the last point back to the origin
    total_cost += sqrtl(current_x * current_x + current_y * current_y);
    
    cout << fixed << setprecision(15) << total_cost << endl;
    
    return 0;
}