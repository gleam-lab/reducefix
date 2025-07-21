#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long cost = 0;
    long long nowX = 0, nowY = 0;
    
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        long long x, y;
        cin >> x >> y;
        
        // Calculate the distance from the current position to the new point
        cost += sqrt((x - nowX) * (x - nowX) + (y - nowY) * (y - nowY));
        
        // Update the current position
        nowX = x;
        nowY = y;
    }
    
    // Calculate the distance from the last point back to the origin
    cost += sqrt((nowX - 0) * (nowX - 0) + (nowY - 0) * (nowY - 0));
    
    // Output the total cost
    cout << cost << endl;
    
    return 0;
}