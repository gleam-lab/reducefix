#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    int N;
    long double currentX = 0, currentY = 0;
    long double nextX, nextY;

    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> nextX >> nextY;
        long double dx = currentX - nextX;
        long double dy = currentY - nextY;
        total_cost += sqrtl(dx * dx + dy * dy);
        currentX = nextX;
        currentY = nextY;
    }
    
    // Add the distance from the last point back to the origin
    total_cost += sqrtl(currentX * currentX + currentY * currentY);
    
    cout << fixed << setprecision(15) << total_cost << endl;
    
    return 0;
}