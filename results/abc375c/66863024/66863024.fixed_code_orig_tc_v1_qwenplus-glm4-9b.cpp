#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    double cost = 0.0;
    double nowX = 0, nowY = 0;

    for (int i = 0; i < N; ++i) {
        int nextX, nextY;
        cin >> nextX >> nextY;
        
        cost += sqrt((nextX - nowX) * (nextX - nowX) + (nextY - nowY) * (nextY - nowY));

        // Update the current position to the next point
        nowX = nextX;
        nowY = nextY;
    }

    // Add the distance from the last point back to the origin
    cost += sqrt((nowX - 0) * (nowX - 0) + (nowY - 0) * (nowY - 0));

    cout << fixed << setprecision(9) << cost << endl;

    return 0;
}