#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    double x = 0, y = 0, total_cost = 0;
    
    for (int i = 0; i < N; ++i) {
        double nx, ny;
        cin >> nx >> ny;
        
        // Calculate the distance from current position to next point
        total_cost += sqrt((x - nx) * (x - nx) + (y - ny) * (y - ny));
        
        // Update current position
        x = nx;
        y = ny;
    }
    
    // Return to the origin
    total_cost += sqrt(x * x + y * y);
    
    cout << fixed << setprecision(6) << total_cost << endl;
    
    return 0;
}