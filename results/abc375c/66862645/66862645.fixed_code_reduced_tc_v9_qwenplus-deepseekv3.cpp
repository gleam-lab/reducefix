#include <bits/stdc++.h>
using namespace std;

int main() {
    long double total_cost = 0;
    int N;
    cin >> N;
    
    int prevX = 0, prevY = 0;
    for (int i = 0; i < N; ++i) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        long double dx = nextX - prevX;
        long double dy = nextY - prevY;
        total_cost += sqrtl(dx * dx + dy * dy);
        prevX = nextX;
        prevY = nextY;
    }
    
    // Add the cost to return to the origin
    long double dx = 0 - prevX;
    long double dy = 0 - prevY;
    total_cost += sqrtl(dx * dx + dy * dy);
    
    cout << fixed << setprecision(15) << total_cost << endl;
    return 0;
}