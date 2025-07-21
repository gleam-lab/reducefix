#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    int N;
    cin >> N;
    
    int prevX = 0, prevY = 0;
    for (int i = 0; i < N; ++i) {
        int currX, currY;
        cin >> currX >> currY;
        
        long double dx = prevX - currX;
        long double dy = prevY - currY;
        total_cost += sqrtl(dx * dx + dy * dy);
        
        prevX = currX;
        prevY = currY;
    }
    
    // Add the distance from the last point back to the origin
    long double dx = prevX - 0;
    long double dy = prevY - 0;
    total_cost += sqrtl(dx * dx + dy * dy);
    
    cout << fixed << setprecision(15) << total_cost << endl;
    
    return 0;
}