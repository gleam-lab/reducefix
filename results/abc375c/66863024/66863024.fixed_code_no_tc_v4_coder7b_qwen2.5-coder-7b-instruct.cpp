#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    // Initialize current position at the origin
    double nowX = 0, nowY = 0;
    double totalCost = 0;

    for (int i = 0; i < N; ++i) {
        double nextX, nextY;
        cin >> nextX >> nextY;
        
        // Calculate the cost from the current position to the next position
        double dx = nextX - nowX;
        double dy = nextY - nowY;
        double distance = sqrt(dx * dx + dy * dy);
        
        // Add the distance to the total cost
        totalCost += distance;
        
        // Update the current position
        nowX = nextX;
        nowY = nextY;
    }

    // Return to the origin
    double backToOriginDistance = sqrt(nowX * nowX + nowY * nowY);
    totalCost += backToOriginDistance;

    // Output the total cost
    printf("%.10f\n", totalCost);

    return 0;
}