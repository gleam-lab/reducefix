#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    long double currentX = 0, currentY = 0;
    long double totalCost = 0.0;
    
    for (int i = 0; i < N; ++i) {
        long double nextX, nextY;
        cin >> nextX >> nextY;
        totalCost += sqrt((currentX - nextX) * (currentX - nextX) + (currentY - nextY) * (currentY - nextY));
        currentX = nextX;
        currentY = nextY;
    }
    
    // Add the cost to return to the origin
    totalCost += sqrt((currentX * currentX) + (currentY * currentY));
    
    cout.precision(10);
    cout << fixed << totalCost << endl;
    
    return 0;
}