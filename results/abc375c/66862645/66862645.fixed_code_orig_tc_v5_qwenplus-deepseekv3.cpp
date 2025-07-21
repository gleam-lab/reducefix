#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    int N;
    cin >> N;
    
    int prev_x = 0, prev_y = 0;
    
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        
        long double dx = x - prev_x;
        long double dy = y - prev_y;
        total_cost += sqrtl(dx * dx + dy * dy);
        
        prev_x = x;
        prev_y = y;
    }
    
    // Add distance from last point back to origin
    long double dx = 0 - prev_x;
    long double dy = 0 - prev_y;
    total_cost += sqrtl(dx * dx + dy * dy);
    
    cout << fixed << setprecision(20) << total_cost << endl;
    
    return 0;
}