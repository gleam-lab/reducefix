#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    int N;
    cin >> N;
    
    long double prev_x = 0, prev_y = 0;
    for (int i = 0; i < N; i++) {
        long double x, y;
        cin >> x >> y;
        long double dx = x - prev_x;
        long double dy = y - prev_y;
        total_cost += sqrtl(dx*dx + dy*dy);
        prev_x = x;
        prev_y = y;
    }
    
    // Add cost to return to origin
    total_cost += sqrtl(prev_x*prev_x + prev_y*prev_y);
    
    cout << fixed << setprecision(10) << total_cost << endl;
    return 0;
}