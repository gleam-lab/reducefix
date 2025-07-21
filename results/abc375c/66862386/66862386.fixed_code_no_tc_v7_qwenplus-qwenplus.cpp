#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long nowX = 0, nowY = 0;
    long long nextX, nextY;
    double totalCost = 0.0;

    for (int i = 0; i < N; ++i) {
        cin >> nextX >> nextY;

        long long dx = nowX - nextX;
        long long dy = nowY - nextY;
        totalCost += sqrt(static_cast<double>(dx * dx + dy * dy));

        nowX = nextX;
        nowY = nextY;
    }

    // Return to origin
    long long dx = nowX;
    long long dy = nowY;
    totalCost += sqrt(static_cast<double>(dx * dx + dy * dy));

    cout.precision(15);
    cout << fixed << totalCost << endl;

    return 0;
}