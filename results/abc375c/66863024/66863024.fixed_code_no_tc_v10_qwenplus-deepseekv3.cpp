#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long double total_cost = 0.0;
    long double prevX = 0.0, prevY = 0.0;
    
    for (int i = 0; i < N; ++i) {
        long double X, Y;
        cin >> X >> Y;
        long double dx = prevX - X;
        long double dy = prevY - Y;
        total_cost += sqrtl(dx * dx + dy * dy);
        prevX = X;
        prevY = Y;
    }
    
    // Add the distance from the last point back to the origin
    total_cost += sqrtl(prevX * prevX + prevY * prevY);
    
    cout << fixed << setprecision(15) << total_cost << endl;
    return 0;
}