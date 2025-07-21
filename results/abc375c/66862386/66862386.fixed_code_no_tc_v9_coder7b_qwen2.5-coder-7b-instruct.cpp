#include <bits/stdc++.h>
using namespace std;

int main() {
    long double cost = 0;
    long double ans = 0;
    int n;
    int x, y;
    
    // Read number of points
    cin >> n;
    
    // Initialize current position to origin
    int nowX = 0, nowY = 0;
    
    // Process each point
    for(int i = 0; i < n; ++i) {
        cin >> x >> y;
        
        // Calculate the Euclidean distance from current position to the next point
        cost = sqrt(pow(x - nowX, 2.0) + pow(y - nowY, 2.0));
        
        // Add the distance to the total cost
        ans += cost;
        
        // Update current position to the next point
        nowX = x;
        nowY = y;
    }
    
    // Calculate the distance back to the origin
    cost = sqrt(pow(nowX, 2.0) + pow(nowY, 2.0));
    ans += cost;
    
    // Output the total cost
    cout << ans << endl;
    
    return 0;
}