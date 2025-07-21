#include <iostream>
#include <cmath>
using namespace std;

int main() {
    // Read number of points
    int N;
    cin >> N;

    // Initialize current position at the origin
    long double nowX = 0, nowY = 0;
    long double ans = 0;

    // Loop through each point
    for(int i = 0; i < N; i++) {
        int nextX, nextY;
        cin >> nextX >> nextY;

        // Calculate the Euclidean distance from the current point to the next point
        long double distance = sqrt(pow(nextX - nowX, 2) + pow(nextY - nowY, 2));
        
        // Add the distance to the total cost
        ans += distance;

        // Update the current position to the next point
        nowX = nextX;
        nowY = nextY;
    }

    // Calculate the distance back to the origin
    long double finalDistance = sqrt(pow(nowX, 2) + pow(nowY, 2));
    
    // Add the final distance to the total cost
    ans += finalDistance;

    // Output the total cost
    cout << ans << endl;

    return 0;
}