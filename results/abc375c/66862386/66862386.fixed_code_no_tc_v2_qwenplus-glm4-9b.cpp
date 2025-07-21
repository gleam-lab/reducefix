#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int N;
    cin >> N;

    long double cost = 0.0;
    long double totalCost = 0.0;
    long double originX = 0.0, originY = 0.0;
    long double currentX, currentY;

    for (int i = 0; i < N; i++) {
        cin >> currentX >> currentY;
        cost = sqrt(pow(currentX - originX, 2) + pow(currentY - originY, 2));
        totalCost += cost;
        originX = currentX;
        originY = currentY;
    }

    // Calculate the cost from the last point to the origin
    cost = sqrt(pow(currentX - originX, 2) + pow(currentY - originY, 2));
    totalCost += cost;

    cout.precision(10);
    cout << fixed << totalCost << endl;

    return 0;
}