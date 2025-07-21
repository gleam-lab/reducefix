#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    long double cost = 0;
    long double ans = 0;
    int operation;
    int nowX = 0, nowY = 0;
    int nextX, nextY;

    for(int i = 0; i < N; ++i) {
        cin >> nextX >> nextY;

        // Calculate Euclidean distance squared to avoid precision issues
        long double dx = nextX - nowX;
        long double dy = nextY - nowY;
        long double dist_squared = dx * dx + dy * dy;

        // Add the square root of the distance squared to the total cost
        ans += sqrt(dist_squared);

        nowX = nextX;
        nowY = nextY;
    }

    // Calculate the distance back to the origin
    long double dx = 0 - nowX;
    long double dy = 0 - nowY;
    long double dist_squared = dx * dx + dy * dy;
    ans += sqrt(dist_squared);

    cout << ans << endl;

    return 0;
}