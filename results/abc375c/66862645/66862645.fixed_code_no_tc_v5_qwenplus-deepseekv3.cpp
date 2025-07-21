#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    int N;
    cin >> N;
    
    int prevX = 0, prevY = 0; // Starting at origin
    
    for (int i = 0; i < N; i++) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        
        long double dx = prevX - nextX;
        long double dy = prevY - nextY;
        total_cost += sqrtl(dx * dx + dy * dy);
        
        prevX = nextX;
        prevY = nextY;
    }
    
    // Add distance from last point back to origin
    long double dx = prevX - 0;
    long double dy = prevY - 0;
    total_cost += sqrtl(dx * dx + dy * dy);
    
    cout << fixed << setprecision(10) << total_cost << endl;
    
    return 0;
}